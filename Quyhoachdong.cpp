/*
f[i][j] : so mon do nhieu nhat co the lay duoc den mon thu i va khoi luong da lay la j
can tinh f[n][m1] sao cho m1 nho hon max khoi luong tui co the mang
Set up:
    - da lay mon i : f[i - 1][j - mi] + 1
    - khong lay mon i : f[i - 1][j]
        j la khoi luong;
Solution :
    for i : 0 -> n
    for j : 0 -> m

Alternative:
 
f[i] : so luong mon do toi da khi da lay mon i, khoi luong lay ra < m;

*/
#include <bits/stdc++.h>

int n, m;
int f[1000][1000];

void sort(int* x) {
    for(int i = 1; i <= n; i++) {
        for(int j = n; j >= i + 1; j--) {
            if(x[j] < x[j - 1]) {
                int tmp = x[j];
                x[j] = x[j - 1];
                x[j - 1] = tmp;
            }
        }
    }
}

int main() {

    printf("so luong mon do: ");
    scanf("%d", &n);
    printf("khoi luong cua tui: ");
    scanf("%d", &m);
    int weight[n + 1];
    printf("nhap khoi luong cua %d tui: \n", n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &weight[i]);
    }
    sort(weight);
    int dem = 0;
    int sum = 0;
    for(int i = 1; i <= n; i++) {
        sum += weight[i];
        dem++;
        if(sum >= m) break;
    }
    printf("%d", dem);
    return 0;
}