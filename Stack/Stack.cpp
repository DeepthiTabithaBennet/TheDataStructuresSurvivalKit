#include <iostream>
using namespace std;

#define SIZE 15
/*———————————————————————————————————————————————————————————————————————————*/  
class STACK{
    private:
       int stack[SIZE];
       int top;
  
    public:
       STACK();  //defualt constructor
       int push(int);
       int pop();
       bool isEmpty();
       int isFull();
       void displayItems();
};
/*———————————————————————————————————————————————————————————————————————————*/  
STACK :: STACK(){
    top =- 1;
}
/*———————————————————————————————————————————————————————————————————————————*/  
bool STACK :: isEmpty(){
    if(top == -1)
        return true;
    else
        return false;  
}
/*———————————————————————————————————————————————————————————————————————————*/  
int STACK :: isFull(){
    if(top == (SIZE - 1))
        return 1;
    else
        return 0;
}
/*———————————————————————————————————————————————————————————————————————————*/  
int STACK :: push(int n){
  
    // first, check stack is full
    if(isFull())
        return 0;
        
    ++top;
    stack[top] = n;
    return n;
}
/*———————————————————————————————————————————————————————————————————————————*/  
int STACK :: pop(){
  
    // to store and print which number is deleted
    int temp;
  
    // check if empty
    if(isEmpty())
        return 0;
        
    temp = stack[top];
    --top;
    return temp;   
}
/*———————————————————————————————————————————————————————————————————————————*/  
void STACK :: displayItems(){
    int i;
    if (top == -1){
        cout << "STACK is empty" << endl << endl;
    }
  
    else{
        for(i = top; i >= 0; i--)
            cout << stack[i] << " ";
        
        cout << endl << endl;
    }
}
/*———————————————————————————————————————————————————————————————————————————*/  
 // Objects
 STACK stk1;
 STACK stk2;
/*———————————————————————————————————————————————————————————————————————————*/  
int main(){
  
    int choice, n, temp;
  
    cout << "0 - Exit." << endl;
    cout << "1 - Push Item in Stack 1." << endl;
    cout << "2 - Push Item in Stack 2." << endl;
    cout << "3 - Pop Item from Stack 1." << endl;
    cout << "4 - Pop Item from Stack 2." << endl;
    cout << "5 - Display Stack 1." << endl;
    cout << "6 - Display Stack 2." << endl << endl;
    
    do{   
        cout << "Enter your choice : ";
        cin >> choice;
       
        switch(choice){
            
            case 0:
                break;
           
            case 1:
                cout << "Enter item to insert : ";
                cin >> n;
                temp = stk1.push(n);
                if(temp == 0)
                    cout << "STACK is FULL." << endl << endl;
                else
                    cout << temp << " is inserted (pushed) in Stack 1." << endl << endl;
                break;
            
            case 2:
                cout << "Enter item to insert : ";
                cin >> n;
                temp = stk2.push(n);
                if(temp == 0)
                    cout << "STACK is FULL." << endl << endl;
                else
                    cout << temp << " is inserted (pushed) in Stack 2." << endl << endl;
                break;
               
            case 3:
                temp = stk1.pop();
                if(temp == 0)
                    cout << "STACK is EMPTY." << endl << endl;
                else
                    cout << temp << " is removed (popped) from Stack 1." << endl << endl;
                break;
               
            case 4:
                temp = stk2.pop();
                if(temp == 0)
                    cout << "STACK is EMPTY." << endl << endl;
                else
                    cout << temp << " is removed (popped) from Stack 2." << endl << endl;
                break;
           
            case 5:
                cout << "STACK 1 :\n";
                stk1.displayItems();
                break;
           
            case 6:
                cout << "STACK 2 :\n";
                stk2.displayItems();
                break;
               
            default:
               cout << "Invalid choice." << endl;
       }  
   }while(choice != 0);
   
   return 0;
}
/*———————————————————————————————————————————————————————————————————————————*/   
