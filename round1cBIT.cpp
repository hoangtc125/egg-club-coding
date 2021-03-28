#include <bits/stdc++.h>

int main() {

    int n;
    int x = 0;
    do{
        scanf("%d", &n);
    }while(n < 0 || n > 150);
    getchar();
    while(n > 0) { 
        printf("n = %d\n", n);
        getchar();
        char c = getchar();
        getchar();
        getchar();
        if(c == '+') {
            x++;
        } else {
            x--;
        }
        n--;
    }
    printf("%d", x);

    return 0;
}