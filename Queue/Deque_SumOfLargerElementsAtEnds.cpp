/* You are given an array of N integers in which deletion can be performed at both the ends.
   Write a C++ program so that you remove exactly k elements out of the array from any end but always remove the greater element.
   Find the total of those elements.
Eg. :  N = 8   k = 4
       Array : 10   8   5   4   3   9   7   6
       Removed elements: 10, 8, 6, 7
       Sum of these elements = 31 */
/*———————————————————————————————————————————————————————————————————————————*/  
#include <iostream>
using namespace std;

#define size 100

int arr[size];
int n;
int f = 0, r = n - 1; 
int sum = 0;

/*———————————————————————————————————————————————————————————————————————————*/  
// dequeue_front() function deletes the element from the front  
int dequeue_front(){
    int x;
    if((f == -1) && (r == -1)){  
        cout << "Deque is empty";  
    }  
    else if(f == r){
        x = arr[f];
        cout << "\nThe deleted element is " << x;
        f = -1;  
        r = -1;  
          
    }  
     else if(f == (n - 1)){
         x = arr[f];
         cout << "\nThe deleted element is " << x;  
         f = 0;  
     }  
     else{
          x = arr[f];
          cout << "\nThe deleted element is " << x;
          f += 1;  
     }
     cout << endl;
     return x;
}    
/*———————————————————————————————————————————————————————————————————————————*/  
// dequeue_rear() function deletes the element from the rear  
int dequeue_rear(){
    int x;
    if((f == -1) && (r == -1)){  
        cout << "Deque is empty";
    }  
    else if(f == r){
        x = arr[r];
        cout << "\nThe deleted element is " << x;
        f = -1;  
        r = -1;            
    }  
     else if(r == 0){
         x = arr[r];
         cout << "\nThe deleted element is " << x;
         r = n - 1;  
     }  
     else{
          x = arr[r];
          cout << "\nThe deleted element is " << x;
          r = r - 1;  
     }
     cout << endl; 
     return x;
}  
/*———————————————————————————————————————————————————————————————————————————*/  
int main(){
    int k, z;
    
    cout << "Enter the number of elements in the array : ";
    cin >> n;
    r = n - 1;
    cout << "Enter the number of elements to be removed : ";
    cin >> z;
    
    cout << "Enter the elements of the array : \n";
    for (k = 0; k < n; k++)
        cin >> arr[k];
    
    for (k = 0; k < z; k++){
        if (arr[f] > arr[r]){
            sum += dequeue_front(); 
        }
        else {
            sum += dequeue_rear();
        }
    }
    cout << "\nsum = " << sum << endl;;   
    
    return 0;
}
