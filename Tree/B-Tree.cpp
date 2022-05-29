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
    void remove(int k);
    void RemoveFromLeaf(int idx);
    void RemoveFromNonLeaf(int idx);
    int GetPredecessor(int idx);
    int GetSuccessor(int idx);
    void fill(int idx);
    void BorrowFromPrev(int idx);
    void BorrowFromNext(int idx);
    void merge(int idx);
    
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
int BTreeNode::FindKey(int k){
    int idx = 0;
    while (idx < n && keys[idx] < k)
        ++idx;
        
    return idx;
}
/*———————————————————————————————————————————————————————————————————————————*/
void BTreeNode::remove(int k){
    int idx = FindKey(k);

    if (idx < n && keys[idx] == k){
  
        if (leaf)
            RemoveFromLeaf(idx);
        else
            RemoveFromNonLeaf(idx);
    }
    
    else{

        if (leaf){
            cout << k << " Does not Exist in the Tree\n";
            return;
        }
        bool flag = ((idx==n)? true : false);

        if (ChildPtr[idx]->n < t)
            fill(idx);

        if (flag && idx > n)
            ChildPtr[idx-1]->remove(k);
        else
            ChildPtr[idx]->remove(k);
    }
    return;
}
/*———————————————————————————————————————————————————————————————————————————*/
void BTreeNode::RemoveFromLeaf (int idx){

    for (int i = idx+1; i < n; ++i)
        keys[i-1] = keys[i];

    n--;
    return;
}
/*———————————————————————————————————————————————————————————————————————————*/
void BTreeNode::RemoveFromNonLeaf(int idx){

    int k = keys[idx];

    if (ChildPtr[idx]->n >= t){
        int pred = GetPredecessor(idx);
        keys[idx] = pred;
        ChildPtr[idx]->remove(pred);
    }

    else if (ChildPtr[idx+1]->n >= t){
        int succ = GetSuccessor(idx);
        keys[idx] = succ;
        ChildPtr[idx+1]->remove(succ);
    }
    
    else{
        merge(idx);
        ChildPtr[idx]->remove(k);
    }
    return;
}
/*———————————————————————————————————————————————————————————————————————————*/
int BTreeNode::GetPredecessor(int idx){

    BTreeNode *cur = ChildPtr[idx];
    while (!cur->leaf)
        cur = cur->ChildPtr[cur->n];

    return cur->keys[cur->n-1];
}
/*———————————————————————————————————————————————————————————————————————————*/
int BTreeNode::GetSuccessor(int idx){

    BTreeNode *cur = ChildPtr[idx+1];
    while (!cur->leaf)
        cur = cur->ChildPtr[0];

    return cur->keys[0];
}
/*———————————————————————————————————————————————————————————————————————————*/
void BTreeNode::fill(int idx){

    // If the previous child(C[idx-1]) has more than t-1 keys, borrow a key from that child
    if (idx!=0 && ChildPtr[idx-1]->n >= t)
        BorrowFromPrev(idx);

    // If the next child(C[idx+1]) has more than t-1 keys, borrow a key from that child
    else if (idx != n && ChildPtr[idx+1]->n >= t)
        BorrowFromNext(idx);

    // Merge C[idx] with its sibling
    // If C[idx] is the last child, merge it with with its previous sibling
    // Otherwise merge it with its next sibling
    else{
        if (idx != n)
            merge(idx);
        else
            merge(idx-1);
    }
    return;
}
/*———————————————————————————————————————————————————————————————————————————*/
void BTreeNode::BorrowFromPrev(int idx){

    BTreeNode* child = ChildPtr[idx];
    BTreeNode* sibling = ChildPtr[idx-1];

    // The last key from C[idx-1] goes up to the parent and key[idx-1] from parent is inserted as the first key in C[idx]. Thus, the loses sibling one key and child gains one key

    for (int i = child->n-1; i >= 0; --i)
        child->keys[i+1] = child->keys[i];

    if (!child->leaf){
        for(int i = child->n; i >= 0; --i)
            child->ChildPtr[i+1] = child->ChildPtr[i];
    }

    child->keys[0] = keys[idx-1];

    // Moving sibling's last child as C[idx]'s first child
    if(!child->leaf)
        child->ChildPtr[0] = sibling->ChildPtr[sibling->n];

    // Moving the key from the sibling to the parent.
    keys[idx-1] = sibling->keys[sibling->n-1];

    child->n += 1;
    sibling->n -= 1;

    return;
}
/*———————————————————————————————————————————————————————————————————————————*/
void BTreeNode::BorrowFromNext(int idx){

    BTreeNode* child = ChildPtr[idx];
    BTreeNode* sibling = ChildPtr[idx+1];

    child->keys[(child->n)] = keys[idx];

    if (!(child->leaf))
        child->ChildPtr[(child->n)+1] = sibling->ChildPtr[0];

    keys[idx] = sibling->keys[0];

    for (int i = 1; i < sibling->n; ++i)
        sibling->keys[i-1] = sibling->keys[i];

    if (!sibling->leaf){
        for(int i = 1; i <= sibling->n; ++i)
            sibling->ChildPtr[i-1] = sibling->ChildPtr[i];
    }

    child->n += 1;
    sibling->n -= 1;

    return;
}
/*———————————————————————————————————————————————————————————————————————————*/
void BTreeNode::merge(int idx){
    BTreeNode* child = ChildPtr[idx];
    BTreeNode* sibling = ChildPtr[idx+1];

    child->keys[t-1] = keys[idx];

    // Copying the keys from C[idx+1] to C[idx] at the end
    for (int i = 0; i < sibling->n; ++i)
        child->keys[i+t] = sibling->keys[i];

    // Copying the child pointers from C[idx+1] to C[idx]
    if (!child->leaf){
        for(int i = 0; i <= sibling->n; ++i)
            child->ChildPtr[i+t] = sibling->ChildPtr[i];
    }

    for (int i = idx+1; i < n; ++i)
        keys[i-1] = keys[i];

    for (int i = idx+2; i <= n; ++i)
        ChildPtr[i-1] = ChildPtr[i];

    child->n += sibling->n+1;
    n--;

    delete(sibling);
    return;
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
BTreeNode* BTreeNode::search(int k){
  
    int i = 0;
    while (i < n && k > keys[i])
        i++;

    if (keys[i] == k)
        return this;

    if (leaf == true)
        return NULL;

    return ChildPtr[i]->search(k);
}
/*———————————————————————————————————————————————————————————————————————————*/
void BTree::remove(int k){
    if (!root){
        cout << "The tree is empty\n";
        return;
    }
    root->remove(k);

    if (root->n==0){
        BTreeNode* temp = root;
        
        if (root->leaf)
            root = NULL;
        else
            root = root->ChildPtr[0];

        delete temp;
    }
    return;
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
    cout << "2 —————> Delete an Element \n";
    cout << "3 —————> Traverse the B-Tree \n";
    cout << "4 —————> Search for an Element \n";
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
                cout << "Enter the element to be Deleted from the Tree : ";
                cin >> b;
                tree.remove(b);
                break;
                
            case (3):
                tree.traverse();
                cout << endl;
                break;
                
            case (4):
                cout << "Enter the element to be Searched in the Tree : ";
                cin >> c;
                
                if (tree.search(c)){
                    cout << c << " Exists in the Tree";
                }
                else{
                    cout << c << " Does not Exist in the Tree";
                }
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
