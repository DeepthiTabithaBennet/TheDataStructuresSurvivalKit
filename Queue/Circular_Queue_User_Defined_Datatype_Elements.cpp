// This program stores the data of various batsmen in a corcular queue and prints the data of the batsman with the highest number of runs

#include <iostream>
#include <string.h>

using namespace std;

int front = -1;
int rear = -1;
int n = 5;
/*---------------------------------------------------------------------------*/
struct queue{
    char name[100];
    int runs ;
    char team[100];
};
queue cqueue[5];
/*---------------------------------------------------------------------------*/
void insertCQ(char name[], int runs, char team[]){
  
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
  
    strcpy(cqueue[rear].name, name);
    cqueue[rear].runs = runs;
    strcpy(cqueue[rear].team, team);
}
/*---------------------------------------------------------------------------*/
void deleteCQ(){
  
    if(front == -1){
        cout << "Queue Underflow\n";
        return;
    }
    cout << "Element deleted from queue is " << cqueue[front].name << " " << cqueue[front].runs << " " << cqueue[front].team << endl;
 
    if (front == rear){
        front = -1;
        rear = -1;
    }
 
    else{
        front = (front + 1) % n;
    }
}
/*---------------------------------------------------------------------------*/
void displayCQ(){
  
    int f = front
    int r = rear;
    cout << endl;
  
    if(f <= r){
        while(f <= r){
            cout << cqueue[f].name << " " <<  cqueue[f].runs << " " << cqueue[f].team << " \n";
            f++;
        }
    }
  
    else{
        while(f <= (n - 1)){
            cout << cqueue[f].name << " " << cqueue[f].runs << " " << cqueue[f].team << " \n";
            f++;
        }
        f = 0;
        
        while(f <= r){
            cout << cqueue[f].name << " " << cqueue[f].runs << " " << cqueue[f].team << " \n";
            f++;
        }
    }
}
/*---------------------------------------------------------------------------*/
// function to print info about the batsman with the hughest number of runs
void best_batsman(){
    char great_name[100];
    char great_team[100];
  
    strcpy(great_name, cqueue[0].name);
    int great_runs = cqueue[0].runs;
    strcpy(great_team, cqueue[0].team);
  
    for (int i = 0; i < 5; i++){
        if (cqueue[i].runs > great_runs){
            strcpy(great_name, cqueue[i].name);
            great_runs = cqueue[i].runs;
            strcpy(great_team, cqueue[i].team);
        }
    } 
    cout << "The best batsman is "<< great_name << " with " << great_runs << " runs, belonging to team " << great_team << " \n";
}
/*---------------------------------------------------------------------------*/
int main(){
  
    int ch, run;
    char name[100], team[100];
  
    cout << "1 —————> Insert\n";
    cout << "2 —————> Delete\n";
    cout << "3 —————> Display\n";
    cout << "4 —————> The Best Batsman\n";
    cout << "5 —————> Exit\n";
  
    do{
        cout << "\nEnter your choice : ";
        cin >> ch;
  
        switch(ch){
    
            case (1):
            
                cout << "Enter the name of the Cricketer : ";
                cin >> name;
            
                cout << "Enter the runs scored by the Cricketer : ";
                cin >> run;
       
                cout << "Enter the team of the Cricketer : ";
                cin >> team;
       
                insertCQ(name, run, team);
                break;
      
            case (2):
                deleteCQ();
                break;
    
            case (3):
                displayCQ();
                break;
        
            case (4):
                best_batsman();
                break;
        }
    }while(ch != 5);
}
