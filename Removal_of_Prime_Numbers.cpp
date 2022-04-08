#include <iostream>

int main(){
	int a[50], i, n, j;
    
    std::cout << "Enter the number of Elements : ";
    std::cin >> n;
	
	for(i = 0; i < n; i++){
		std::cin >> a[i];
	}
	
	std::cout << "The array with all the Prime Numbers removed is : \n\n";
	
	for(i = 0; i < n; i++){
		for(j = 2; j < a[i]; j++){
			if(a[i] % j == 0){
				std::cout << a[i] << " ";
				break;
			}
		}
	}
	return 0;
}
