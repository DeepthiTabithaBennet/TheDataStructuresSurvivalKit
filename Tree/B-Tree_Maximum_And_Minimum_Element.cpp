#include <iostream>
using namespace std;
/*———————————————————————————————————————————————————————————————————————————*/
class BTreeNode{
    int* keys;
    int t;
    BTreeNode** ChildPtr;
    int n;
    bool leaf;

public:

    BTreeNode(int t, bool leaf); // Constructor
    
    void traverse();
    BTreeNode* search(int k); 
    int FindKey(int k);
    void InsertNonFull(int k);
    void SplitChild(int i, BTreeNode* y);
    
    void maximum();
    void minimum();
    
    friend class BTree;
};
/*———————————————————————————————————————————————————————————————————————————*/
class BTree{
    BTreeNode* root;
    int t; 
    
public:

    BTree(int _t){
        root = NULL;
        t = _t;
    }

    void traverse(){
        if (root != NULL)
            root->traverse();
    }

    BTreeNode* search(int k){
       return (root == NULL)? NULL : root->search(k);
    }

    void insert(int k);
    void remove(int k);
    
    void maximum(){
        if (root != NULL)
            root->maximum();
    }
    
    void minimum(){
        if (root != NULL)
            root->minimum();
    }

};
/*———————————————————————————————————————————————————————————————————————————*/
BTreeNode::BTreeNode(int New_t, bool New_Leaf){
    t = New_t;
    leaf = New_Leaf;

    keys = new int[2*t-1];
    ChildPtr = new BTreeNode* [2*t];

    n = 0;
}
/*———————————————————————————————————————————————————————————————————————————*/
void BTree::insert(int k){

    if (root == NULL){

        root = new BTreeNode(t, true);
        root->keys[0] = k; 
        root->n = 1; 
    }
    
    else{ 
  
        // If root is full, then tree grows in height
        if (root->n == 2*t-1){

            BTreeNode* s = new BTreeNode(t, false);
            s->ChildPtr[0] = root;

            s->SplitChild(0, root);

            int i = 0;
            if (s->keys[0] < k)
                i++;
            s->ChildPtr[i]->InsertNonFull(k);

            root = s;
        }
        else
            root->InsertNonFull(k);
    }
}
/*———————————————————————————————————————————————————————————————————————————*/
void BTreeNode::InsertNonFull(int k){

    int i = n-1;

    if (leaf == true){
    
        while (i >= 0 && keys[i] > k){
            keys[i+1] = keys[i];
            i--;
        }
        keys[i+1] = k;
        n = n+1;
    }
    
    else{ 
 
        while (i >= 0 && keys[i] > k)
            i--;

        if (ChildPtr[i+1]->n == 2*t-1){
            SplitChild(i+1, ChildPtr[i+1]);

            if (keys[i+1] < k)
                i++;
        }
        ChildPtr[i+1]->InsertNonFull(k);
    }
}
/*———————————————————————————————————————————————————————————————————————————*/
void BTreeNode::SplitChild(int i, BTreeNode* y){
    
    BTreeNode* z = new BTreeNode(y->t, y->leaf);
    z->n = t - 1;

    for (int j = 0; j < t-1; j++)
        z->keys[j] = y->keys[j+t];

    if (y->leaf == false){
        for (int j = 0; j < t; j++)
            z->ChildPtr[j] = y->ChildPtr[j+t];
    }

    y->n = t - 1;

    for (int j = n; j >= i+1; j--)
        ChildPtr[j+1] = ChildPtr[j];

    ChildPtr[i+1] = z;

    for (int j = n-1; j >= i; j--)
        keys[j+1] = keys[j];

    keys[i] = y->keys[t-1];
    n = n + 1;
}
/*———————————————————————————————————————————————————————————————————————————*/
void BTreeNode::traverse(){

    int i;
    for (i = 0; i < n; i++){

    if (leaf == false)
        ChildPtr[i]->traverse();
        cout << " " << keys[i];
    }

    if (leaf == false)
        ChildPtr[i]->traverse();
}
/*———————————————————————————————————————————————————————————————————————————*/
void BTreeNode::maximum(){
    
    int i;
    if (leaf == false)
        ChildPtr[n-1]->maximum();

    if (leaf == false)
        ChildPtr[n-1]->maximum();
    cout << " " << keys[n-1];
}
/*———————————————————————————————————————————————————————————————————————————*/
void BTreeNode::minimum(){
    
    int i;

    if (leaf == false)
        ChildPtr[0]->minimum();
        
    if (leaf == false)
        ChildPtr[0]->minimum();
    cout << " " << keys[0];
}
/*———————————————————————————————————————————————————————————————————————————*/
int main(){

    int deg;
    cout << "Enter the Degree of the B-Tree : ";
    cin >> deg;
    
    cout << endl << "DEGREE OF THE B-TREE (t) : " << deg << endl;
    cout << "MAX NUMBER OF KEYS (2t-1) : " << (2 * deg) - 1 << endl;
    cout << "MIN NUMBER OF KEYS (t-1) : " << deg - 1 << endl << endl;
    
    
    BTree tree(deg);
    BTreeNode* position;
    
    int ch, a, b, c;
    
    cout << "1 —————> Insert an Element \n";
    cout << "2 —————> Print the Minimum element \n";
    cout << "3 —————> Print the Maximum element \n";
    cout << "4 —————> Traverse the B-Tree \n";
    cout << "5 —————> Exit\n\n";
  
  
    do{
        cout << "\nEnter your choice : ";
        cin >> ch;
  
        switch(ch){
    
            case (1):
                cout << "Enter the value to be Inserted to the Tree : ";
                cin >> a;
                tree.insert(a);
                break;
                
            case (2):
                tree.minimum();
                break;
        
            case (3):
                tree.maximum();
                break;
                
            case (4):
                tree.traverse();
                cout << endl;
                break;
                
            case (5):
                break;
                
            default:
                cout << "Enter a value between 1 and 5 \n";
        }
    }while(ch != 5);

    return 0;
}
