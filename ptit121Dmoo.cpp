#include <bits/stdc++.h>

long long int n;
int c[100];
int j = 0;

void devide(int jj, int l, int a, int b, int r) {
    if(jj < 0) {
        return;
    }
    if(n >= a && n <= b) {
        if(n == a + 1) {
            printf("m");
            return;
        } else {
            printf("o");
            return;
        }
    } else {
        if(n <= a) {
            if(a - 2 == l) {
                if(n == l) {
                    printf("m");
                    return;
                } else {
                    printf("o");
                    return;
                }
            } else {
                devide(jj - 1, l, l + c[jj - 1] - 1, l + c[jj - 1] + jj + 3 - 1, a);
            }
        }
        if(n > b) {
            if(b + 3 == r) {
                if(n == b + 1) {
                    printf("m");
                    return;
                } else {
                    printf("o");
                    return;
                }
            } else {
                devide(jj - 1, b + 1, b + c[jj - 1], b + c[jj - 1] + jj + 3, r);
            }
        }
    }
}

int S(int n) {
    if(n == 0) {
        return c[0];
    } else {
        c[n] = 2 * S(n - 1) + n + 3;
        return c[n];
    }
}

int main() {

    do{
        scanf("%lld", &n);
    }while(n < 1 || n > pow(10,9));
    if(n > 3) {
        c[0] = 3;
        while(S(j) < n) {
            j++;
        }
        devide(j - 1, 1, c[j - 1], c[j - 1] + j + 3, c[j]);
    } else {
        if(n == 1) {
            printf("m");
        } else {
            printf("o");
        }
    }

    return 0;
}