#include <iostream>
using namespace std;
/*---------------------------------------------------------------------------*/
typedef struct Queue{
    int cqueue[5];
    int front, rear, n;
};
/*---------------------------------------------------------------------------*/
void insertCQ(Queue *q, int val){
  
    if (q->front == (q->rear + 1) % q->n){
        cout << "Queue Overflow\n";
        return;
    }
  
    if (q->front == -1){
        q->front = 0;
        q->rear = 0;
    }
  
    else{
        q->rear = (q->rear + 1) % q->n;
    }
    q->cqueue[q->rear] = val;
}
/*---------------------------------------------------------------------------*/
void deleteCQ(Queue *q){
  
    if(q->front == -1){
        cout << "Queue Underflow\n";
        return;
    }
  
    cout << "Element deleted from queue is " << q->cqueue[q->front] << endl;
 
    if (q->front == q->rear){
        q->front = -1;
        q->rear = -1;
    }
  
    else{
        q->front = (q->front + 1) % q->n;
    }
}
/*---------------------------------------------------------------------------*/
void displayCQ(Queue *q){
    int f = q->front;
    int r = q->rear;
  
    if(f <= r){
        while(f <= r){
            cout << q->cqueue[f] << " ";
            f++;
        }
    }
  
    else{
        while(f <= (q->n - 1)){
            cout << q->cqueue[f] << " ";
            f++;
        }  
        f = 0;
      
        while(f <= r){
            cout << q->cqueue[f] << " ";
            f++;
        }
    }
    cout << endl;
}
/*---------------------------------------------------------------------------*/
bool compare (Queue *q1, Queue *q2){
    int f1 = q1->front;
    int r1 = q1->rear;
    int n1 = q1->n;
    
    int f2 = q2->front;
    int r2 = q2->rear;
    int n2 = q2->n;
    
    if (f1 == -1 && f2 == -1){
        cout << "Queues are Empty\n";
        return true;
    }
  
    if (f1 == -1 || f2 == -1){
        return false;
    }
  
    while ((f1 != r1) && (f2 != r2)){
        if (q1->cqueue[f1] != q2->cqueue[f2]){
            return false;
        }
        if (f1 == (n1 - 1)){
            f1 = 0;
        }
        else{
            f1++;
        }
        if (f2 == (n2 - 1)){
            f2 = 0;
        }
        else{
            f2++;
        }
    }
  
    if (q1->cqueue[f1] != q2->cqueue[f2]){
        return false;
    }
  
    if ((f1 != r1) || (f2 != r2)){
        return false;
    }
  
    else{
      return true;
    }
}
/*---------------------------------------------------------------------------*/
int main(){
    Queue q1, q2;
  
    q1.front = -1;
    q2.front = -1;
    q1.rear = -1;
    q2.rear = -1;
    q1.n = 5;
    q2.n = 5;
  
    int ch, val;
    cout << "1 —————> Insert (Queue 1)\n";
    cout << "2 —————> Insert (Queue 2)\n";
    cout << "3 —————> Delete (Queue 1)\n";
    cout << "4 —————> Delete (Queue 2)\n";
    cout << "5 —————> Display (Queue 1)\n";
    cout << "6 —————> Display (Queue 2)\n";
    cout << "7 —————> Compare\n";
    cout << "8 —————> Exit\n";
  
    do{
        cout << "\nEnter your choice : ";
        cin >> ch;
  
        switch(ch){
    
            case (1):
                cout << "Enter the value to be inserted in Queue 1 : ";
                cin >> val;
                insertCQ(&q1, val);
                break;
        
            case (2):
                cout << "Enter the value to be inserted in Queue 2 : ";
                cin >> val;
                insertCQ(&q2, val);
                break;
      
            case (3):
                deleteCQ(&q1);
                break;
        
            case (4):
                deleteCQ(&q2);
                break;
    
            case (5):
                displayCQ(&q1);
                break;
        
            case (6):
                displayCQ(&q2);
                break;
      
            case (7):
                if (compare(&q1, &q2)){
                    cout << "The Queues are Equal\n";
                }
                else{
                    cout << "The Queues are Not Equal\n";
                }
                break;
      
            case (8):
                break;
        
            default:
                cout << "Enter a value between 1 and 8";
        }
    }while(ch != 8);
}
/*---------------------------------------------------------------------------*/
