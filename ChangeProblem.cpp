/*
A : so luong tien can
v1, v2, ... so luong to tien 
Tim so luong tien can phai tra it nhat

Solution : 
F(A) = 
        F(A - v1) + 1
        F(A - v2) + 1
        ... 

*/

#include <bits/stdc++.h>

int n, m;
int A[1000], v[1000];
int cash[] = {1, 2, 5, 10, 20, 50, 100, 200, 500};

int money(int a) {
    
}

int main() {

    scanf("%d", m);
    for(int i = 1; i <= m; i++) {
        scanf("%d", &A[i]);
    }
    for(int i = 1; i <= 9; i++) {
        scanf("%d", &v[i]);
    }
    for(int i = 1; i <= m; i++) {
        money(A[i]);
    }
    return 0;
}