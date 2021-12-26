#include <iostream>
#include <string.h>

using namespace std;
/*---------------------------------------------------------------------------*/
#define MAX 100
int TOP = -1; // Global Variable
/*---------------------------------------------------------------------------*/
struct stack_s{
    int code;
    char desc[100];
};
stack_s STACK[MAX]; // Array of Structures
/*---------------------------------------------------------------------------*/
// check if Stack is Empty
int isEmpty(){
    if(TOP == -1)
        return 1;
    else
        return 0;
}
/*---------------------------------------------------------------------------*/
// check if Stack is Full
int isFull(){
    if(TOP == (MAX - 1))
        return 1;
    else
        return 0;
}
/*---------------------------------------------------------------------------*/
// Push Function
void push(int code, char desc[]){
    if(isFull()){
        cout << "STACK is FULL." << endl;
        return;
    }
    TOP++;
    STACK[TOP].code = code;
    strcpy(STACK[TOP].desc, desc);
  
    cout << code << " " << desc << " - Pushed Successfully" << endl;
}
/*---------------------------------------------------------------------------*/
// Displays the current elements in the Stack
void display(){
    int i;
    if(isEmpty()){
        cout << "STACK is EMPTY." << endl;
        return;
    }
    for(i = TOP; i >= 0; i--){
        cout << STACK[i].code << " " << STACK[i].desc << endl;
    }
}
/*---------------------------------------------------------------------------*/
// Pop Function
void pop(int code, char desc[]){
    if(isEmpty()){
        cout << "STACK is EMPTY." << endl;
        return;
    }
    
    STACK[TOP].code = code;
    strcpy(STACK[TOP].desc, desc);
    --TOP;
  
    cout << code << " " << desc << " - Popped Successfully" << endl; 
}
/*---------------------------------------------------------------------------*/
// Main Function
int main(){
    int code;
    char desc[100];
    
    char ch;
     
    do{
        int num;
        cout << "Enter \n1 ————> push\n2 ————> pop\n3 ————> display\n";
        cout << "Please enter your choice : ";
        cin >> num;
        
        switch(num){
            
            case 1:
                cout << "\nEnter a Number : ";
                cin >> code;
                cout << "Enter it\'s description : ";
                cin >> desc;
                push(code, desc);
                break;
                
            case 2: 
                pop(code, desc);
                break;
                 
            case 3: 
                cout << endl;
                display();
                break;
                 
            default : 
                cout << "Invalid Choice\n";
        }
        cout << "\nDo you want to continue? (Y / N) : ";
        cin >> ch;
      
        cout << endl;
    }while(ch == 'Y' || ch == 'y');
    
    return 0;
}
/*---------------------------------------------------------------------------*/
