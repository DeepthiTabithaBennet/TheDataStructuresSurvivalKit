#include <iostream>
using namespace std;
/*———————————————————————————————————————————————————————————————————————————*/
class Node{
    public:
        int data;
        Node* left;
        Node* right;
};
/*———————————————————————————————————————————————————————————————————————————*/
Node* minValueNode(Node* n){
    while (n->left != NULL)
        n = n->left;
    return n;
}
/*———————————————————————————————————————————————————————————————————————————*/
int CountInternalNodes(Node* root){
    if (root == NULL)
        return 0;
        
    if (root->left == NULL && root->right == NULL)
        return 0;
     
    return 1+CountInternalNodes(root->left)+CountInternalNodes(root->right);
}
/*———————————————————————————————————————————————————————————————————————————*/
Node* insNode(Node* root, int key){

    Node* newnode = new Node();
    newnode->data = key;
    newnode->left = NULL;
    newnode->right = NULL;
    
    Node* x = root;
    Node* y = NULL;
    
    if (root == NULL){
        root = newnode;
        return root;
    }
    
    while (x != NULL){
        y = x;
        if (key < x->data)
            x = x->left;
        else
            x = x->right;
    }
    if (y == NULL){
        y = newnode;
        return root;
    }
    else if (key < y->data){
        y->left = newnode;
        return root;
    }
        
    else{
        y->right = newnode;
        return root;
    }
}
/*———————————————————————————————————————————————————————————————————————————*/
void inorder(Node* n){ //LDR
    if (n != NULL){
        inorder(n->left);
        cout << n->data << " ";
        inorder(n->right);
    }
}
/*———————————————————————————————————————————————————————————————————————————*/
void preorder(Node* n){ //DLR
    if (n != NULL){
        cout << n->data << " ";
        preorder(n->left);
        preorder(n->right);
    }
}
/*———————————————————————————————————————————————————————————————————————————*/
void postorder(Node* n){ //LRD
    if (n != NULL){
        postorder(n->left);
        postorder(n->right);
        cout << n->data << " ";
    }
}
/*———————————————————————————————————————————————————————————————————————————*/
Node* delNode(Node* root, int key){
    
    //base case
    if (root == NULL){
        return root;
    }
    
    //if key to be deleted is smaller than the root's data, then it lies in the left subtree
    if (key < root->data){
        root->left = delNode(root->left, key);
    }
    
    //if key to be deleted is greater than the root's data, then it lies in the right subtree
    else if (key > root->data){
        root->right = delNode(root->right, key);
    }
    
    //if key is the same as the root's data, then this is the node to be deleted
    else{
        //node has no child
        if (root->left == NULL && root->right == NULL){
            delete root;
            root = NULL;
        }
            
        //node with only one child
        
        //right child
        else if (root->left == NULL){
            Node* temp = root;
            root = root->right;
            delete temp;
        }
        
        //left child
        else if (root->right == NULL){
            Node* temp = root;
            root = root->left;
            delete temp;
        }
        
        //node with two children
        else{
            Node* temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = delNode(root->right, temp->data);
        }
    }
    return root;
}

/*———————————————————————————————————————————————————————————————————————————*/
int main(){
    Node* root = NULL;
    
    int ch, a, b, count;
    cout << "1 —————> Insert a Node \n";
    cout << "2 —————> Delete a Node \n";
    cout << "3 —————> Traversal : Inorder \n";
    cout << "4 —————> Traversal : Preorder \n";
    cout << "5 —————> Traversal : Postorder \n";
    cout << "6 —————> Number of Internal Nodes\n";
    cout << "7 —————> Exit\n\n";
  
  
    do{
        cout << "\nEnter your choice : ";
        cin >> ch;
  
        switch(ch){
    
            case (1):
                cout << "Enter the value to be Inserted to the Tree : ";
                cin >> a;
                root = insNode(root, a);
                break;
        
            case (2):
                cout << "Enter the element to be Deleted from the Tree : ";
                cin >> b;
                delNode(root, b);
                break;
                
            case (3):
                inorder(root);
                cout << endl;
                break;
                
            case (4):
                preorder(root);
                cout << endl;
                break;
                
            case (5):
                postorder(root);
                cout << endl;
                break;
                
            case (6):
                count = CountInternalNodes(root);
                cout << "Number of Internal Nodes : " << count << endl;
            
            case (7):
                break;
                
            default:
                cout << "Enter a value between 1 and 7";
        }
    }while(ch != 7);

    return 0;
}
