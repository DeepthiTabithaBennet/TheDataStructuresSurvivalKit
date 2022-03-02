#include <iostream>

int main(){  
	int arr[100]; 
	int size;		 
	int i, j, k;	  

	std::cout << "Enter size of the array : ";
	std::cin >> size;

	std::cout << "Enter elements in array :\n";
	for(i = 0; i < size; i++){
		std::cin >> arr[i];
	}

	for(i = 0; i < size; i++){
		for(j = i + 1; j < size;){
			if(arr[i] == arr[j]){
				for(k = j; k < size; k++){
					arr[k] = arr[k + 1];
				}
				size--;
			}
			else{
				j++;
			}
		}
	}
	
	std::cout << "Array Elements After Removing Duplicates:\n";
	for(i = 0; i < size; i++){
		std::cout << "  " << arr[i];
	}
		
	return 0;
}
