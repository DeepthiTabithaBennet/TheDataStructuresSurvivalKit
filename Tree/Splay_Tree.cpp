#include <iostream>
using namespace std;
/*———————————————————————————————————————————————————————————————————————————*/
class Node{
    public:
      int data;
      string info;
      Node *left;
      Node *right;
      int height;
};
/*———————————————————————————————————————————————————————————————————————————*/
int max(int a, int b){
  return (a > b)? a : b;
}
/*———————————————————————————————————————————————————————————————————————————*/
int height(Node *N){
  if (N == NULL)
    return 0;
  return N->height;
}
/*———————————————————————————————————————————————————————————————————————————*/
Node* minValueNode(Node* n){
    while (n->left != NULL)
        n = n->left;
    return n;
}
/*———————————————————————————————————————————————————————————————————————————*/
Node* newNode(int keydata, string keyinfo){

  Node* node = new Node();
  
  node->data = keydata;
  node->info = keyinfo;
  node->left = NULL;
  node->right = NULL;
  node->height = 1;

  return(node);
}
/*———————————————————————————————————————————————————————————————————————————*/
Node *rightRotate(Node *x){
  Node *y = x->left;
  x->left = y->right;
  y->right = x;
  Node *T2 = x->right;

  // Rotation
  y->right = x;
  x->left = T2;

  y->height = max(height(y->left), height(y->right)) + 1;
  x->height = max(height(x->left), height(x->right)) + 1;

  return y;
}
/*———————————————————————————————————————————————————————————————————————————*/
Node *leftRotate(Node *x){
  Node *y = x->right;
  x->right = y->left;
  y->left = x;
  Node *T2 = y->left;

  // Rotation
  y->left = x;
  x->right = T2;

  x->height = max(height(x->left), height(x->right)) + 1;
  y->height = max(height(y->left), height(y->right)) + 1;

  return y;
}
/*———————————————————————————————————————————————————————————————————————————*/
// This function brings the key at root if key is present in tree. If key is not present, then it brings the last accessed item at root. This function modifies the tree and returns the new root
Node *splay(Node *root, int key){
  // Base cases: root is NULL or key is present at root
  if (root == NULL || root->data == key)
    return root;

  // Key lies in left subtree
  if (root->data > key){
    // Key is not in tree, we are done
    if (root->left == NULL) return root;

    // Zig-Zig (Left Left)
    if (root->left->data > key){
      // First recursively bring the key as root of left-left
      root->left->left = splay(root->left->left, key);

      // Do first rotation for root, second rotation is done after else
      root = rightRotate(root);
    }
    
    // Zig-Zag (Left Right)
    else if (root->left->data < key) {
      // First recursively bring the key as root of left-right
      root->left->right = splay(root->left->right, key);

      // Do first rotation for root->left
      if (root->left->right != NULL)
        root->left = leftRotate(root->left);
    }

    // Do second rotation for root
    return (root->left == NULL)? root: rightRotate(root);
  }
  
  // Key lies in right subtree
  else{
    // Key is not in tree, we are done
    if (root->right == NULL) return root;

    // Zag-Zig (Right Left)
    if (root->right->data > key){
      // Bring the key as root of right-left
      root->right->left = splay(root->right->left, key);

      // Do first rotation for root->right
      if (root->right->left != NULL)
        root->right = rightRotate(root->right);
    }
    
    // Zag-Zag (Right Right)
    else if (root->right->data < key){
      // Bring the key as root of right-right and do first rotation
      root->right->right = splay(root->right->right, key);
      root = leftRotate(root);
    }

    // Do second rotation for root
    return (root->right == NULL)? root: leftRotate(root);
  }
}
/*———————————————————————————————————————————————————————————————————————————*/
Node* insNode(Node* root, int keydata, string keyinfo){
    // Simple Case: If tree is empty
    if (root == NULL) return newNode(keydata, keyinfo);
 
    // Bring the closest leaf node to root
    root = splay(root, keydata);
 
    // If key is already present, then return
    if (root->data == keydata) return root;
 
    // Otherwise allocate memory for new node
    Node *newnode = newNode(keydata, keyinfo);
 
    // If root's key is greater, make root as right child of newnode and copy the left child of root to newnode
    if (root->data > keydata){
        newnode->right = root;
        newnode->left = root->left;
        root->left = NULL;
    }
 
    // If root's key is smaller, make root as left child of newnode and copy the right child of root to newnode
    else{
        newnode->left = root;
        newnode->right = root->right;
        root->right = NULL;
    }
 
    return newnode; // newnode becomes new root
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
        
        root = splay(root, key);
        
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
void inorder(Node* n){ //LDR
    if (n != NULL){
        inorder(n->left);
        cout << n->data << " \n";
        cout << n->info << "\n";
        inorder(n->right);
    }
}
/*———————————————————————————————————————————————————————————————————————————*/
void preorder(Node* n){ //DLR
    if (n != NULL){
        cout << n->data << " \n";
        cout << n->info << "\n";
        preorder(n->left);
        preorder(n->right);
    }
}
/*———————————————————————————————————————————————————————————————————————————*/
void postorder(Node* n){ //LRD
    if (n != NULL){
        postorder(n->left);
        postorder(n->right);
        cout << n->data << " \n";
        cout << n->info << "\n";
    }
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
int main(){

    Node* root = NULL;
    
    int ch, a, b, count;
    string c;
    
    cout << "1 —————> Insert a Node \n";
    cout << "2 —————> Delete a Node \n";
    cout << "3 —————> Traversal : Inorder \n";
    cout << "4 —————> Traversal : Preorder \n";
    cout << "5 —————> Traversal : Postorder \n";
    cout << "6 —————> Number of Internal Nodes \n";
    cout << "7 —————> Exit\n\n";
  
  
    do{
        cout << "\nEnter your choice : ";
        cin >> ch;
  
        switch(ch){
    
            case (1):
                cout << "Enter the value to be Inserted to the Tree : ";
                cin >> a;
                cout << "Enter it's description : ";
                cin >> c;
                root = insNode(root, a, c);
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
