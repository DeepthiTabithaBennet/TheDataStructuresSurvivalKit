#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
};
/*———————————————————————————————————————————————————————————————————————————*/
void Display(Node* n){
    if (n == NULL){
        cout << "Queue is Empty";
        return;
    }
    while (n != NULL){
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}
/*———————————————————————————————————————————————————————————————————————————*/
void EnQueue(Node** head_ref, int new_data){
  
    // 1. allocate node 
    Node* new_node = new Node();   
  
    Node *last = *head_ref;   

    // 2. Put in the data 
    new_node->data = new_data;  

    // 3. This new node is going to be the last node, so make next of it as NULL
    new_node->next = NULL;  

    // 4. If the Linked List is empty, then make the new node as head 
    if (*head_ref == NULL){  
        *head_ref = new_node;  
        return;  
    } 

    // 5. Else traverse till the last node 
    while (last->next != NULL)  
        last = last->next;  

    // 6. Change the next of last node 
    last->next = new_node;  
    return;  
}  
/*———————————————————————————————————————————————————————————————————————————*/
void DeQueue(Node** head_ref){
  
    // Store head node
    Node* temp = *head_ref;
    if (temp == NULL){
        cout << "Queue is Empty";
        return;
    }
    *head_ref = temp->next; // Changed head
    delete temp; // free old head
    return;
}
/*———————————————————————————————————————————————————————————————————————————*/
int main(){
    Node *head = NULL;
    
    int ch, a;
    cout << "1 —————> EnQueue \n";
    cout << "2 —————> DeQueue \n";
    cout << "3 —————> Display \n";
    cout << "4 —————> Exit\n";
  
    do{
        cout << "\nEnter your choice : ";
        cin >> ch;
  
        switch(ch){
    
            case (1):
                cout << "Enter the value to be EnQueue to the Queue : ";
                cin >> a;
                EnQueue(&head, a);
                break;
        
            case (2):
                DeQueue(&head);
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
