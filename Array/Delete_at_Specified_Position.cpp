#include <iostream>
using namespace std;

int main(){
    int arr[50], i, pos, n;
  
    cout << "Input the size of array : ";
    cin >> n;
   
    cout << "Input " << n << " elements in the array :\n";
    for(i = 0; i < n; i++){
        cin >> arr[i];
    } 

  	cout << "\nInput the position where to delete : ";
	  cin >> pos;
  
    // locate the position of i in the array
	  i = 0;
	  while(i != (pos-1))
        i++;
  
    // re-adjusting the array after deletion
	  while(i < n){
		    arr[i] = arr[i+1];
		    i++;
	  }
	  n--;
	
	  cout << "\nThe new array is : "; 
	  for(i = 0; i < n; i++){
        cout << arr[i] << " ";
	  }  
	  cout << "\n";
	  return 0;
}
