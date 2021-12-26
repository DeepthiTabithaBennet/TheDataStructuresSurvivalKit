#include <iostream>

using namespace std;

#define SIZE 20
/*---------------------------------------------------------------------------*/
int stack[SIZE];
int top1 = -1;  
int top2 = SIZE;  
/*---------------------------------------------------------------------------*/
//Function to push data into stack1  
void push1 (int data){  
      
    if (top1 < top2 - 1){  // Checking the overflow condition
        top1++;  
        stack[top1] = data;
        cout << data << " - Pushed successfully to Stack 1\n";
    }
  
    else {  
        cout << "Stack is full";
    }  
}
/*---------------------------------------------------------------------------*/
// Function to push data into stack2  
void push2 (int data){  
        
    if (top1 < top2 - 1){  // checking overflow condition
        top2--;  
        stack[top2] = data;
        cout << data << " - Pushed successfully to Stack 2\n";
    }
  
    else{  
        cout << "Stack is full\n";  
    }  
}  
/*---------------------------------------------------------------------------*/
//Function to pop data from the Stack1  
void pop1 (){  
       
    if (top1 >= 0){  // Checking the underflow condition
        int popped_element = stack[top1];  
        top1--;  
        cout << popped_element << " - Popped successfully from Stack 1\n"; 
    }
  
    else{  
        cout << "Stack is Empty\n";  
    }  
}
/*---------------------------------------------------------------------------*/
// Function to remove the element from the Stack2  
void pop2 (){  
        
    if (top2 < SIZE){  // Checking underflow condition
        int popped_element = stack[top2];  
        top2++;  
        cout << popped_element << " - Popped successfully from Stack 2\n"; 
    }
  
    else{  
        cout << "Stack is Empty\n";  
    }  
}
/*---------------------------------------------------------------------------*/
//Functions to Print the values of Stack1  
void display_stack1(){  
     int i;  
     for (i = top1; i >= 0; --i){  
         cout << stack[i];  
     }  
     cout << endl;  
}
/*---------------------------------------------------------------------------*/
// Function to print the values of Stack2  
void display_stack2(){  
    int i;  
    for (i = top2; i < SIZE; ++i){  
        cout << stack[i];  
    }  
    cout << endl;  
}  
/*---------------------------------------------------------------------------*/
// Main Function
int main(){
    int code;
    
    char ch;
    cout << "Enter \n1 ————> push (Stack 1)\n2 ————> push (Stack 2)\n3 ————> pop (Stack 1)\n4 ————> pop (Stack 2)\n5 ————> display (Stack 1)\n6 ————> display (Stack 2)\n\n";
     
    do{
        int num;
        cout << "\nEnter a number corresponding to your choice : ";
        cin >> num;
        
        switch(num){
            
            case 1:
                cout << "Enter a Number : ";
                cin >> code;
                push1(code);
                break;
                 
            case 2:
                cout << "Enter a Number : ";
                cin >> code;
                push2(code);
                break;
                
            case 3: 
                pop1();
                break;
                
            case 4: 
                pop2();
                break;
                 
            case 5: 
                cout << endl;
                display_stack1();
                break;
                
            case 6: 
                cout << endl;
                display_stack2();
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
