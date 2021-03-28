#include <bits/stdc++.h>

int main() {

    int r1, r2, c1, c2;
    do{
        scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
    }while(r1 < 1|| c1 < 1|| r2 < 1 || c2 < 1 || r1 > 8 || c2 > 8 || r2 >8 || c1 > 8);

    if(r1 == r2) {
        if(c1 == c2) {
            printf("0 0 0");
            return 0;
        } else {
            printf("1 ");
        }
    } else if(c1 == c2) {
        printf("1 ");
    } else {
        printf("2 ");
    }
    
    if((r1 + c1) % 2 != (r2 + c2) % 2) {
        printf("0 ");
    } else {
        if(r1 + c1 == r2 + c2 || r1 - c1 == r2 - c2) {
            printf("1 ");
        }
    }

    if(r1 == r2) {
        printf("%d", abs(c1 - c2));
    } else if(c1 == c2) {
        printf("%d", abs(r1 - r2));
    } else {
        printf("%d", abs(r1 - r2) > abs(c1 - c2) ? abs(r1 - r2) : abs(c1 - c2));
    }

    return 0;
}