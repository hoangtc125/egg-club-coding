#include <stdio.h>
int n, h, min, s;
int main() {

    do{
        scanf("%d", &n);
    }while(n < 0 || n > 300000);

    s = n % 60;
    min = (n / 60) % 60;
    h = (n / 3600);
    printf("%.2d:%.2d:%.2d", h, min, s);

    return 0;
}
