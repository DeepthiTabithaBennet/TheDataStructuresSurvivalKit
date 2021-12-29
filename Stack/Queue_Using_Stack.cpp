#include <iostream>

using namespace std;

#define N 10 
/*---------------------------------------------------------------------------*/
int stack1[10], stack2[10];  // declaration of two stacks  
  
int top1 = -1, top2 = -1;  // declaration of top variables. 
int count = 0;
/*---------------------------------------------------------------------------*/
// inserting the elements in stack1.  
void push1(int data){
  
    // Condition to check whether the stack1 is full.    
    if(top1 == N - 1){  
        cout << "\nStack Overflow";  
    }
  
    else {  
        top1++;  // Incrementing the value of top1  
        stack1[top1] = data;  // pushing the data into stack1  
    }  
}
/*---------------------------------------------------------------------------*/
// Removing the elements from the stack1.  
int pop1(){
  
    // Condition to check whether the stack1 is empty.    
    if(top1 == -1){  
        cout << "\nStack is Empty";  
    }
  
    else{  
        int a = stack1[top1];  // Assigning the topmost value of stack1 to 'a' variable.
        top1--;  // decrementing the value of top1.    
        return a;   
    }  
}
/*---------------------------------------------------------------------------*/
// pushing the data into the stack2.  
void push2(int x){
  
    // Condition to check whether the stack2 is full. 
    if(top2 == N - 1){  
        cout << "\nStack is full";  
    }
  
    else{  
        top2++;  // incrementing the value of top2.  
        stack2[top2] = x;  // assigning the 'x' value to the Stack2   
    }  
}
/*---------------------------------------------------------------------------*/
// Removing the elements from the Stack2  
int pop2(){
  
    // Condition to check whether the stack2 is empty.    
    if(top2 == -1){  
        cout << "\nStack is Empty";  
    }

    else{
        int element = stack2[top2];  // assigning the topmost value to element  
        top2--;  // decrement the value of top2  
        return element;
    } 
}
/*---------------------------------------------------------------------------*/
void enqueue(int x){  
    push1(x);  
    count++;  
}
/*---------------------------------------------------------------------------*/
void dequeue(){
  
    if((top1 == -1) && (top2 == -1)){  
        cout << "\nQueue is empty";  
    }
  
    else{  
        for(int i = 0; i < count; i++){  
            int element = pop1();  
            push2(element);  
        } 
      
        int b = pop2();  
        cout << "\nThe dequeued element is " << b;  
        cout << endl;  
        count--;
      
        for(int i = 0; i < count; i++){  
            int a = pop2();  
            push1(a);   
        }  
    }
}
/*---------------------------------------------------------------------------*/
void display(){  
    for(int i = 0; i <= top1; i++){  
        cout << stack1[i] << " ";  
    }
    cout << endl;
}
/*---------------------------------------------------------------------------*/
int main(){
  
    int ch, num;
    cout << "1 —————> Insert\n";
    cout << "2 —————> Delete\n";
    cout << "3 —————> Display\n";
    cout << "4 —————> Exit\n";
  
    do{
        cout << "\nEnter your choice : ";
        cin >> ch;
  
        switch(ch){
    
            case (1):
                cout << "Enter the number to be inserted : ";
                cin >> num;
                enqueue(num);
                break;
      
            case (2):
                dequeue();
                break;
    
            case (3):
                display();
                break;
        
            case (4):
                break;
        
            default:
                cout << "Enter a number between 1 and 4";
      
        }
    }while(ch != 4);
    return 0;
}
/*---------------------------------------------------------------------------*/
