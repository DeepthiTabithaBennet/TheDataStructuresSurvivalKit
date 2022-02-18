#include <iostream>
using namespace std;

int main(){
	
	int i;
	int size;
	cout << "Enter the number of Elements in the Array : ";
	cin >> size;
	
	int arr[size];
	cout << "Input " << size << " elements in the array :\n";
	for (i = 0; i < size; i++){
		cin >> arr[i];
	}
	
	cout << "\nArray Elements: \n";
	for (i = 0; i < size; i++){
		cout << arr[i] << " ";
	}
	
	int *min;
	min = &arr[0];
	int *max;
	max = &arr[0];
	
	
	for (i = 0; i < size; i++){
		if (arr[i] > *max){
			max++;
			*max = arr[i];	
		}
		if (arr[i] < *min){
			min++;
			*min = arr[i];
		}
	}
	
	cout << "\n\nMax : " << *max;
	cout << "\nMin : " << *min;
	
	int diff;
	diff = *max - *min;
	cout << "\n\nThe Maximum Absolute Difference of the Array is " << diff;
	return 0;
}
