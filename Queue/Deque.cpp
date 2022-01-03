#include <iostream>
#include <stdio.h>  

using namespace std;

#define size 5    

int deque[size];  
int f = -1;
int r = -1; 
/*———————————————————————————————————————————————————————————————————————————*/
// enqueue_front function will insert the value from the front  
void enqueue_front(int x){
  
    if((f == 0 && r == size - 1) || (f == r + 1)){  
        cout << "Deque is full";  
    }
  
    else if((f == -1) && (r == -1)){  
        f = r = 0;  
        deque[f] = x;  
    }
  
    else if(f == 0){  
        f = size - 1;  
        deque[f] = x;  
    }
 
    else{  
        f--;  
        deque[f] = x;  
    }  
}  
/*———————————————————————————————————————————————————————————————————————————*/
// enqueue_rear function will insert the value from the rear  
void enqueue_rear(int x){

    if((f == 0 && r == size - 1) || (f == r + 1)){  
        cout << "Deque is full";  
    }
  
    else if((f == -1) && (r == -1)){  
        r = 0;  
        deque[r] = x;  
    }
  
    else if(r == size - 1){  
        r = 0;  
        deque[r] = x;  
    }
  
    else{  
        r++;  
        deque[r] = x;  
    }   
}  
/*———————————————————————————————————————————————————————————————————————————*/  
// display function prints all the value of deque.  
void display(){
  
    if((f == -1) && (r == -1)){  
        cout << "Deque is empty";  
    }
  
    else{
        int i = f;  
        cout << "Elements in the Deque : ";  
      
        while(i != r){  
            cout << deque[i] << " ";  
            i = (i + 1) % size;  
        }  
        cout << deque[r];
    }
    cout << endl;
}   
/*———————————————————————————————————————————————————————————————————————————*/  
// dequeue_front() function deletes the element from the front  
void dequeue_front(){
  
    if((f == -1) && (r == -1)){  
        cout << "Deque is empty";  
    }
  
    else if(f == r){  
        cout << "\nThe deleted element is " << deque[f];  
        f = -1;  
        r = -1;  
          
    }
  
    else if(f == (size - 1)){  
         cout << "\nThe deleted element is " << deque[f];  
         f = 0;  
     }
  
     else{  
          cout << "\nThe deleted element is " << deque[f];  
          f = f + 1;  
     }
     cout << endl;  
}    
/*———————————————————————————————————————————————————————————————————————————*/  
// dequeue_rear() function deletes the element from the rear  
void dequeue_rear(){  
   
    if((f == -1) && (r == -1)){  
        cout << "Deque is empty";  
    }
  
    else if(f == r){  
        cout << "\nThe deleted element is " << deque[r];  
        f = -1;  
        r = -1;            
    } 
  
    else if(r == 0){  
        cout << "\nThe deleted element is " << deque[r];  
        r = size - 1;  
    }
  
    else{  
        cout << "\nThe deleted element is " << deque[r];  
        r = r - 1;  
    }
    cout << endl;  
}  
/*———————————————————————————————————————————————————————————————————————————*/  
int main(){
    int code, num;
   
    do{
        cout << "Enter \n1 ————> EnQueue (front)\n2 ————> EnQueue (rear)\n3 ————> DeQueue (front)\n4 ————> DeQueue (rear)\n5 ————> Display\n6 ————> Exit\n";
        cout << "Please enter your choice : ";
        cin >> num;
        
        switch(num){
            case 1:
                cout << "\nEnter a Number : ";
                cin >> code;
                enqueue_front(code);
                break;
                
            case 2:
                cout << "\nEnter a Number : ";
                cin >> code;
                enqueue_rear(code);
                break;
                
            case 3: 
                dequeue_front();
                break;
                
            case 4: 
                dequeue_rear();
                break;
                 
            case 5: 
                cout << endl;
                display();
                break;
                 
            case 6:
                break;
            
            default : 
                cout << "Enter a number between 1 and 6\n";
        }                    
        cout << endl;
    }while(num != 6);
    
    return 0;
}
