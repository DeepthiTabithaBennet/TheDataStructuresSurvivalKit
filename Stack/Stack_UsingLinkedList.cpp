#include <iostream>
using namespace std;
/*———————————————————————————————————————————————————————————————————————————*/
class Node{
    public:
        int data;
        Node* next;
};
/*———————————————————————————————————————————————————————————————————————————*/
void Display(Node* n){
    if (n == NULL){
        cout << "Stack is Empty";
        return;
    }
    while (n != NULL){
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}
/*———————————————————————————————————————————————————————————————————————————*/
void Push(Node** head_ref, int new_data){
  
    // Allocate 'node'
    Node* new_node = new Node();
 
    // Input the data
    new_node->data = new_data;
 
    // Make 'next' of 'new node' as 'head'
    new_node->next = (*head_ref);
 
    // Move the 'head' to point to the 'new node'
    (*head_ref) = new_node;
}
/*———————————————————————————————————————————————————————————————————————————*/
void Pop(Node** head_ref){
  
    // Store 'head' node
    Node* temp = *head_ref;
    if (temp == NULL){
        cout << "Stack is Empty";
        return;
    }
    *head_ref = temp->next;  // Changed 'head'
    delete temp;  // free 'old head'
    return;
}
/*———————————————————————————————————————————————————————————————————————————*/
int main(){
  
    Node *head = NULL;
    
    int ch, a;
    cout << "1 —————> Push \n";
    cout << "2 —————> Pop \n";
    cout << "3 —————> Display \n";
    cout << "4 —————> Exit\n";
  
    do{
        cout << "\nEnter your choice : ";
        cin >> ch;
  
        switch(ch){
    
            case (1):
                cout << "Enter the value to be Pushed to the Stack : ";
                cin >> a;
                Push(&head, a);
                break;
        
            case (2):
                Pop(&head);
                break;
                
            case (3):
                Display(head);
                break;
                
            case (4):
                break;
                
            default:
                cout << "Enter a value between 1 and 4";
        }
    }while(ch != 4);

    return 0;
}
/*———————————————————————————————————————————————————————————————————————————*/
