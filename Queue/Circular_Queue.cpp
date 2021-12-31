#include <iostream>
using namespace std;
/*---------------------------------------------------------------------------*/
class QUEUE{
    private:
        int cqueue[5];
        int front, rear, n;
  
    public:
        QUEUE();    //default constructor
        void insertCQ(int);
        void deleteCQ();
        void displayCQ();
};
/*---------------------------------------------------------------------------*/
QUEUE :: QUEUE(){
    front = -1;
    rear = -1;
    n = 5;
}
/*---------------------------------------------------------------------------*/
void QUEUE :: insertCQ(int val){
    
    if (front == (rear + 1) % n){
        cout << "Queue Overflow\n";
        return;
    }
  
    if (front == -1){
        front = 0;
        rear = 0;
    }
  
    else{
        rear = (rear + 1) % n;
    }
    cqueue[rear] = val;
}
/*---------------------------------------------------------------------------*/
void QUEUE::deleteCQ(){
  
    if(front == -1){
        cout << "Queue Underflow\n";
        return;
    }
  
    cout << "Element deleted from queue is " << cqueue[front] << endl;
 
    if (front == rear){
        front = -1;
        rear = -1;
    }
  
    else{
        front = (front + 1) % n;
    }
}
/*---------------------------------------------------------------------------*/
void QUEUE :: displayCQ(){
    int f = front;
    r = rear;
  
    if(f <= r){
        while(f <= r){
            cout << cqueue[f] << " ";
            f++;
        }
    }
  
    else{
        while(f <= (n - 1)){
            cout << cqueue[f] << " ";
            f++;
        }
        f = 0;
        while(f <= r){
            cout << cqueue[f] << " ";
            f++;
        }
    }
    cout << endl;
}
/*---------------------------------------------------------------------------*/
// Objects
QUEUE q1;
QUEUE q2;
/*---------------------------------------------------------------------------*/
int main(){
  
    int ch, val;
    cout << "1 —————> Insert in Queue 1\n";
    cout << "2 —————> Insert in Queue 2\n";
    cout << "3 —————> Delete from Queue 1\n";
    cout << "4 —————> Delete from Queue 2\n";
    cout << "5 —————> Display Queue 1\n";
    cout << "6 —————> Display Queue 2\n";
    cout << "7 —————> Exit\n";
  
    do{
        cout << "\nEnter your choice : ";
        cin >> ch;
  
        switch(ch){
    
            case (1):
                cout << "Enter the value to be inserted : ";
                cin >> val;
                q1.insertCQ(val);
                break;
      
            case (2):
                cout << "Enter the value to be inserted : ";
                cin >> val;
                q2.insertCQ(val);
                break;
      
            case (3):
                q1.deleteCQ();
                break;
        
            case (4):
                q2.deleteCQ();
                break;
    
            case (5):
                q1.displayCQ();
                break;
        
            case (6):
                q2.displayCQ();
                break;
        }
    }while(ch != 7);
}
/*---------------------------------------------------------------------------*/
