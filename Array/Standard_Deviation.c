#include <stdio.h>
#include <math.h>

int main(){
    int i, n = 0;
    float sum = 0.0, mean, sd = 0.0;
    
    scanf("%d", &n);
    
    float data[n];
    
    for(i = 0; i < n; i++){
        scanf("%f", &data[i]);
    }
        
    for(i = 0; i < n; i++){
        sum += data[i];
        mean = sum / n;
    }
    
    for(i = 0; i < n; i++){
        sd += pow((data[i] - mean), 2);
    }
         
    printf("Standard Deviation = %.6f", (sd / n));   
    
    return 0;
}
