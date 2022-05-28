#include <iostream>
using namespace std;

int sum = 0;

/*———————————————————————————————————————————————————————————————————————————*/
// AVL Tree
class Node{
    public:
      int data; // data to be stored in each node
      string info; // data to be stored in each node
      Node* left; // pointer to the left child of that node
      Node* right; // pointer to the right child of that node
      int height; // height of the node
};
/*———————————————————————————————————————————————————————————————————————————*/
// returns the maximum of two numbers
// used as a helper function to compute the balance factor of a node
int max(int a, int b){
  return (a > b)? a : b;
}
/*———————————————————————————————————————————————————————————————————————————*/
// returns the height of the node
int height(Node* n){
  if (n == NULL)
    return 0;
  return n->height;
}
/*———————————————————————————————————————————————————————————————————————————*/
// returns the node with the smallest data element in the AVl Tree
// does so by returning the left-most node in the whole tree.
Node* minValueNode(Node* n){
    while (n->left != NULL)
        n = n->left;
    return n;
}
/*———————————————————————————————————————————————————————————————————————————*/
// creates a new node storing the given data (integer and string), and initialises both the child pointers to NULL & height to 1
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
Node* rightRotate(Node *x){
  Node* y = x->left;
  Node* T2 = y->right;

  // Rotation
  y->right = x;
  x->left = T2;

  x->height = max(height(x->left), height(x->right)) + 1;
  y->height = max(height(y->left), height(y->right)) + 1;

  return y;
}
/*———————————————————————————————————————————————————————————————————————————*/
Node* leftRotate(Node *x){
  Node* y = x->right;
  Node* T2 = y->left;

  // Rotation
  y->left = x;
  x->right = T2;

  x->height = max(height(x->left), height(x->right)) + 1;
  y->height = max(height(y->left), height(y->right)) + 1;

  return y;
}
/*———————————————————————————————————————————————————————————————————————————*/
// returns the balance factor of the node
int getBalance(Node* N){
  if (N == NULL)
    return 0;
  return height(N->left) - height(N->right);
}
/*———————————————————————————————————————————————————————————————————————————*/
Node* insNode(Node* node, int keydata, string keyinfo){

  if (node == NULL)
    return(newNode(keydata, keyinfo));

  if (keydata < node->data)
    node->left = insNode(node->left, keydata, keyinfo);
    
  else if (keydata > node->data)
    node->right = insNode(node->right, keydata, keyinfo);
    
  //else 
    //return node;

  node->height = 1 + max(height(node->left), height(node->right));
  int balance = getBalance(node);

  // Left Left Case
  if (balance > 1 && keydata < node->left->data)
    return rightRotate(node);

  // Right Right Case
  if (balance < -1 && keydata > node->right->data)
    return leftRotate(node);

  // Left Right Case
  if (balance > 1 && keydata > node->left->data){
    node->left = leftRotate(node->left);
    return rightRotate(node);
  }

  // Right Left Case
  if (balance < -1 && keydata < node->right->data){
    node->right = rightRotate(node->right);
    return leftRotate(node);
  }

  return node;
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

    root->height = 1 + max(height(root->left), height(root->right));
    int balance = getBalance(root);
 
    // Left Left Case
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);
        
    // Right Right Case
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);
 
    // Left Right Case
    if (balance > 1 && getBalance(root->left) < 0){
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
 
    // Right Left Case
    if (balance < -1 && getBalance(root->right) > 0){
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
 
    return root;
}
/*———————————————————————————————————————————————————————————————————————————*/
void getSum(Node* n){ //LDR
    if (n != NULL){
        getSum(n->left);
        sum += n->data;
        getSum(n->right);
    }
}
/*———————————————————————————————————————————————————————————————————————————*/
void inorder(Node* n){ //LDR
    if (n != NULL){
        inorder(n->left);
        cout << n->data << " - ";
        cout << n->info << "\n";
        inorder(n->right);
    }
}
/*———————————————————————————————————————————————————————————————————————————*/
void preorder(Node* n){ //DLR
    if (n != NULL){
        cout << n->data << " - ";
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
        cout << n->data << " - ";
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
    cout << "7 —————> Sum of Nodes \n";
    cout << "8 —————> Height of the AVL Tree \n";
    cout << "9 —————> Exit \n\n";
  
  
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
                getSum(root);
                cout << "Sum of Nodes : " << sum << endl;
                break;
            
            case (8):
                cout << "Height of the AVL Tree : " << root->height - 1 << endl;
                break;
            
            case (9):
                break;
                
            default:
                cout << "Enter a value between 1 and 9";
        }
    }while(ch != 9);

    return 0;
}


