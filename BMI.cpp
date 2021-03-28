#include <stdio.h>

int height, weight;

int main() {

    do{
        scanf("%d%d", &height, &weight);
    }while(height <= 0 || height >= 300 || weight <= 0 || weight >= 1000);
    double BMI = 1.0 * weight / (height * height);
    if(BMI < 0.00185) {
        printf("thieu can");
    } else if(BMI >= 0.00185 && BMI < 0.0025) {
        printf("trung binh");
    } else if(BMI >= 0.0025 && BMI < 0.003) {
        printf("thua can");
    } else if(BMI >= 0.003) {
        printf("beo phi");
    }
    
    return 0;
}