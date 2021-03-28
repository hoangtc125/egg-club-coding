#include <bits/stdc++.h>

int main() {

    int n;
    int sum = 0;
    int count = 0;
    do{
        scanf("%d", &n);
    }while(n < 1 || n > 5 * pow(10, 5));
    int a[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        sum += a[i];
    }
    if(sum % 3 != 0) {
        printf("0");
    } else {
        int sum1 = 0, sum2 = 0;
        int mark;
        for(int i = 0; i < n; i++) {
            sum1 += a[i];
            if(sum1 == sum / 3) {
                mark = i;
                for(int j = mark + 1; j < n; j++) {
                    sum2 += a[j];
                    if(sum2 == sum / 3 && j < n - 1) {
                        count++;
                    }
                }
            }
        }
    }
    printf("%d\n", count);

    return 0;
}