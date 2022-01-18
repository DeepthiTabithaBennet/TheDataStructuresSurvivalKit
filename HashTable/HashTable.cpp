#include <iostream>
using namespace std;

int num;  // Global variable, number of Hash Buckets
/*---------------------------------------------------------------------------*/
class table{
    public:
        table *next;
        int data;
};
/*---------------------------------------------------------------------------*/
void insert(table *head[], int data){
    
    int i;
    
    table *new_data = new table();
    new_data->data = data; 
    new_data->next = NULL;
    
    i = data % num; // Hash Function
    table *n = head[i];
    
    if (head[i] == NULL)
        head[i] = new_data;
    
    else{
        while (n->next != NULL)
            n = n->next;
            
        n->next = new_data;
    }
}
/*---------------------------------------------------------------------------*/
void del(table *head[], int data){
    
    int p;
    p = data % num; // Hash Function
    
    table *n = head[p];
    table *prev = new table();
    
    if (head[p]->data == data){
        if (head[p]->next == NULL){
            head[p] = NULL;
        }
        else{
            head[p] = head[p]->next;
        }
    }
    
    else{
        while (n->data != data && n->next != NULL){
            prev = n;
            n = n->next;
        }
        if (n->data == data){
            prev->next = n->next;
            delete n;
        }
        else
            cout << data << " is not present in the Hash Table\n";
    }
}
/*---------------------------------------------------------------------------*/
int search(table *head[], int data) {
    
    int p;
    p = data % num; // Hash Function
    table *n = head[p];
    
    while (n != NULL){
        if (n->data == data)
            return p;
        else
            n = n->next;
    }
    return 0;
}
/*---------------------------------------------------------------------------*/
void display(table *head[]){
    table *n = new table;
    
    for (int p = 0; p < num; p++){
        cout << p << " : ";
        
        if (head[p] == NULL){
            cout << "Null";
        }
        else{
            for (n = head[p]; n != NULL; n = n->next){
                cout << n->data << " -> ";
            }
            cout << "Null";
        }
        cout << endl;
    }
}
/*---------------------------------------------------------------------------*/
int main(){

    cout << "Enter the Number of Hash Buckets : ";
    cin >> num;
    cout << endl;
    
    table *head[num] = {NULL};  // initialize all array elements as NULL
    int a, b, key, ch;

    do{
        cout << "1 —————> Insert \n";
        cout << "2 —————> Delete \n";
        cout << "3 —————> Display \n";
        cout << "4 —————> Check if an Element is Present \n";
        cout << "5 —————> Exit \n";
    
        cout << "\nEnter your choice : ";
        cin >> ch;
        
        switch (ch){
        
            case (1):
                cout << "Enter the value to be Inserted to the Hash Table : ";
                cin >> a;
                insert(head, a);
                break;
                
            case (2):
                cout << "Enter the value to be Deleted from the Hash Table : ";
                cin >> b;
                del(head, b);
                break;
                
            case (3):
                cout << "\nHash Table : \n\n";
                display(head);
                cout << endl;
                break;
                
            case (4):
                cout << "Enter the Element to be Checked : ";
                cin >> key;
                
                if (search(head, key))
                    cout << key << " is present in the Hash Table in bucket " << search(head, key) << endl;
                else
                    cout << key << " is not present in the Hash Table\n";
                break;
                
            case (5):
                break;
                
            default:
                cout << "Enter a value between 1 and 5";
        }
    }while (ch != 5);
}
