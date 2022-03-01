#include <iostream>

int Mode(int a[], int n){
    int MaxVal = 0, MaxCt = 0, i, j;
    
    for(i = 0; i < n; i++){
        int count = 0;
    
        for(j = 0; j < n; j++){
            if (a[j] == a[i]){
                ++count;
            }
        }
        if (count > MaxCt){
            MaxCt = count;
            MaxVal = a[i];
        }
    }
    std::cout << "\nThe value " << MaxVal << " occurs " << MaxCt << " times";
    std::cout << "\nMode : " << MaxVal;
    return MaxVal, MaxCt;
}

int main(){
    int n;
    std::cout << "Enter the number of elements in the Array : ";
    std::cin >> n;
    
    int a[100];
    std::cout << "Enter the elements of the Array : \n";
    for (int i = 0; i < n; i++){
        std::cin >> a[i];
    }
    Mode(a,n);
    return 0;
}
