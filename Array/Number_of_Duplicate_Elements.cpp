#include <iostream>

int main(){   
	int count = 0;
	int arr[100]; 
	int size;		 
	int i, j;	  

	std::cout << "Enter the size of the array : ";
	std::cin >> size;

	std::cout << "Enter elements in array :\n";
	for(i = 0; i < size; i++){
		std::cin >> arr[i];
	}

	for(i = 0; i < size; i++){
		for(j = i + 1; j < size; j++){
			if(arr[i] == arr[j]){
				count++;
				break;
			}
		}
	}

	std::cout << "\nNo. of Duplicate elements : " << (count + 1);
	
	return 0;
}
