#include <bits/stdc++.h>

int count = 0;
int dem = 1;
int n;
int a[5001];
int x[5000];
int sum;
int m;

void check(int i, int v, int k) {
    if(m == 0) {
        return;
    }
    for(int j = v; j < i; j++) {
        sum += a[j];
        if(k == 3) {
            if(sum == a[i]) {
                count++;
                x[dem++] = a[i];
                m = 0;
                return;
            } else {
                sum -= a[j];
            }
        } else {
            check(i, j, k + 1);
            sum -= a[j];
        }
    }
}

void input() {
    FILE* p = fopen("ptit136dList.txt", "r");
    fscanf(p, "%d", &n);
    for(int i = 1; i <= n; i++) {
        fscanf(p, "%d", &a[i]);
    }
    fclose(p);
    for(int i = 1; i <= n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main() {

    x[1] = 100001;
    input();
    for(int i = 2; i <= n; i++) {
        int mark = 1;
        sum = 0;
        for(int j = 1; j < dem; j++) {
            if(a[i] == x[j]) {
                count++;
                mark = 0;
                break;
            }
        }
        if(mark) {
            m = 1;
            check(i, 1, 1);
        }
    }
    printf("%d", count);

    return 0;
}