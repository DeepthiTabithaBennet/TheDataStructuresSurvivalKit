#include <iostream>

int main(){

	int n1, n2, i, j, *p, *q, a[10], b[10];
	std::cout << "Enter the number of elements in the First Array : ";
	std::cin >> n1;

	std::cout << "Enter the elements : \n";
	for(i = 0; i < n1; i++){
		std::cin >> a[i];
	}
	std::cout << "Enter the number of elements in the Second Array : ";
	std::cin >> n2;
  
	std::cout << "Enter the elements : \n";
	for(i = 0; i < n2; i++){
		std::cin >> b[i];
	}

	// MERGING THE ARRAY
	p = a;
	q = b;
	for(i = 0, j = n1; i < n2; i++, j++){
		*(p + j) = *(q + i);
	}
	
	std::cout << "\nThe merged array is : ";
	for(i = 0; i < j; i++)
		std::cout << a[i] << " ";

	std::cout << "\n";
	return 0;
}
