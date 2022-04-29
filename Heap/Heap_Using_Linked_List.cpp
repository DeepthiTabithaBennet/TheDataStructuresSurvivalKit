#include <iostream>
#include <bits/stdc++.h>

using namespace std;
/*———————————————————————————————————————————————————————————————————————————*/
class HeapNode{
    public:
        int data;
        HeapNode* left;
        HeapNode* right;
        HeapNode* parent;
        
        HeapNode(int val){  // constructor
            data = val;
            left = NULL;
            right = NULL;
            parent = NULL;
         }
};
/*———————————————————————————————————————————————————————————————————————————*/
class Heap{
    public:
        HeapNode* root;
        Heap(){
            root = NULL;
        }
        HeapNode* lastparent();
        void upHeapify(HeapNode* temp);
        void insert(int data);
        void inorder(HeapNode* root);
        void print();
        bool isEmpty();
        HeapNode* lastnode();
        void downHeapify(HeapNode* temp);
        int ExtractMax();
        int GetMax();
};
/*———————————————————————————————————————————————————————————————————————————*/
HeapNode* Heap::lastparent(){
    queue <HeapNode*> q;
    q.push(root);
    HeapNode* temp;

    while(!q.empty()){
        temp = q.front();
        q.pop();
            
        if(temp->left && temp->right){
            q.push(temp->left);
            q.push(temp->right);
        }
        else{
            break;
        }
    }
    return temp;
}
/*———————————————————————————————————————————————————————————————————————————*/
void Heap::upHeapify(HeapNode* temp){
    if(temp->parent == NULL){
        return;
    }
    if(temp->parent->data < temp->data){
        swap(temp->parent->data,temp->data);
        upHeapify(temp->parent);
    }
}
/*———————————————————————————————————————————————————————————————————————————*/
void Heap::insert(int data){
    HeapNode* newnode = new HeapNode(data);

    if(root == NULL){
        root = newnode;
        return;
    }

    HeapNode* lpar = lastparent();

    if(lpar->left == NULL){
        lpar->left = newnode;
        newnode->parent = lpar;
    }
    else{
        lpar->right = newnode;
        newnode->parent = lpar;
    }
    upHeapify(newnode);
}
/*———————————————————————————————————————————————————————————————————————————*/
void Heap::inorder(HeapNode* root){
    if(root == NULL){
        return;
    }
        
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
/*———————————————————————————————————————————————————————————————————————————*/
void Heap::print(){
    HeapNode* temp = root;
    inorder(temp);
    cout << endl; 
}
/*———————————————————————————————————————————————————————————————————————————*/
bool Heap::isEmpty(){
    if(root == NULL){
        return true;
    }
    else
        return false;
}
/*———————————————————————————————————————————————————————————————————————————*/
HeapNode* Heap::lastnode(){
    queue <HeapNode*> q;
    q.push(root);
    HeapNode* last;
    
    while(!q.empty()){
        last = q.front();
        q.pop();
            
        if(last->left){
            q.push(last->left);
        }
        if(last->right){
            q.push(last->right);
        }
    }
    return last;
}
/*———————————————————————————————————————————————————————————————————————————*/
void Heap::downHeapify(HeapNode* temp){
    HeapNode* largest = temp;

    if(temp->left && temp->left->data > largest->data){
        largest = temp->left;
    }
    if(temp->right && temp->right->data > largest->data){
        largest = temp->right;
    }
    if(largest != temp){
        swap(largest->data,temp->data);
        downHeapify(largest);
    }
}
/*———————————————————————————————————————————————————————————————————————————*/
int Heap::ExtractMax(){
    
    int x;
    
    if(isEmpty()){
        cout << "MaxHeap is Empty!\n";
        return root->data;
    }
    
    HeapNode* last = lastnode();
        
    if(last == root){
        x = last->data;
        delete last;
        root = NULL;
        return root->data;
    } 
    swap(root->data, last->data);
    HeapNode* pr = last->parent;
    
    if(pr->left == last){
        x = last->data;
        delete last;
        pr->left = NULL;
    }
    else{
        x = last->data;
        delete last;
        pr->right = NULL;
    }
    downHeapify(root);
    return (x);
}
/*———————————————————————————————————————————————————————————————————————————*/
int Heap::GetMax(){
    return root->data;
}
/*———————————————————————————————————————————————————————————————————————————*/
int main() {
    Heap h;
    
    int ch, a;
    
    cout << "1 —————> Insert a Node \n";
    cout << "2 —————> Extract Max \n";
    cout << "3 —————> Get Max \n";
    cout << "4 —————> Print MaxHeap\n";
    cout << "5 —————> Exit\n\n";
  
  
    do{
        cout << "\nEnter your choice : ";
        cin >> ch;
  
        switch(ch){
    
            case (1):
                cout << "Enter the value to be Inserted to the MaxHeap : ";
                cin >> a;
                h.insert(a);
                break;
        
            case (2):
                cout << "Maximum Element Removed : " << h.ExtractMax() << endl;
                break;
                
            case (3):
                cout << "Maximum Element : " << h.GetMax() << endl;
                break;
                
            case (4):
                h.print();
                break;
                
            case (5):
                break;
                
            default:
                cout << "Enter a value between 1 and 5";
        }
    }while(ch != 5);

    return 0;
}
