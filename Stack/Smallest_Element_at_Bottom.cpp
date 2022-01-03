/* Write a C++ program to create a stack such that the smallest element always stays at the bottom (also, largest element always stays at the top) of the stack */

#include <iostream>
#include <stack>
using namespace std;
/*———————————————————————————————————————————————————————————————————————————*/
struct Queue{
  stack<int> s1, s2;

  void enQueue(int x){
    // Move all elements from s1 to s2
    while (!s1.empty() && x < s1.top()) {
      s2.push(s1.top());
      s1.pop();
    }

    // Push item into s1
    s1.push(x);

    // Push everything back to s1
    while (!s2.empty()) {
      s1.push(s2.top());
      s2.pop();
    }
    cout << x << " — EnQueued Successfully\n";
  }
/*———————————————————————————————————————————————————————————————————————————*/
  // Dequeue an item from the queue
  int deQueue(){
    // if first stack is empty
    if (s1.empty()) {
      cout << "Queue is Empty";
      exit(0);
    }

    // Return top of s1
    int x = s1.top();
    s1.pop();
    cout << x << " — DeQueued Successfully\n";
    return x;
  }
/*———————————————————————————————————————————————————————————————————————————*/
  void display(){
      if (s1.empty()) {
      cout << "Queue is Empty\n";
      exit(0);
    }
    
      // Move all elements from s1 to s2
    while (!s1.empty()) {
        cout << s1.top() << endl;
      s2.push(s1.top());
      s1.pop();
    }

    // Push everything back to s1
    while (!s2.empty()) {
      s1.push(s2.top());
      s2.pop();
    }
    cout << endl;    
  }
};
/*———————————————————————————————————————————————————————————————————————————*/
// Driver code
int main(){
  Queue q;
  int elem;
  int num;
  
  do{        
        cout << "Enter \n1 ————> push\n2 ————> pop\n3 ————> display\n4 ————> exit\n";
        cout << "Please enter your choice : ";
        cin >> num;
        
        switch(num){
            case 1:
                cout << "\nEnter a Number : ";
                cin >> elem;
                q.enQueue(elem);
                break;
                
            case 2: 
                q.deQueue();
                break;
                 
            case 3: 
                cout << endl;
                q.display();
                break;
                
            case 4:
                break;
                 
            default : 
                cout << "Invalid Choice\n";
        }                   
        cout << endl;
    }while(num != 4);
    
  return 0;
}
/*———————————————————————————————————————————————————————————————————————————*/
