#include <iostream>
using namespace std;

int main(){

    int arr[100], n, i, large, small;
    cout << "Enter the number of Elements in the array : ";
    cin >> n;

    cout << "Input " << n << " elements in the array :\n";
    for (i = 0 ; i < n ; i++){
	    cin >> arr[i];
    }

    large = arr[0];
    small = arr[0];

    for (i = 1 ; i < n ; i++){
	
	    if (arr[i] < small){
		    small = arr[i];
	    }
	    if (arr[i] > large){
		    large = arr[i];
	    }
    }

    cout << "\nThe Largest number is " << large << endl;
    cout << "The Smallest number is " << small << endl;

	return 0;
}
