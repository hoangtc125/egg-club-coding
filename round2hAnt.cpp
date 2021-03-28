#include <bits/stdc++.h>

int main() {

    int r, c;
    int count = 0;
    char s;
    do{
        scanf("%d%d", &r, &c);
    }while(r < 2 || c < 0 || c > 10);
    int markCol[c + 1] = {0};
    int markRow[r + 1] = {0};
    getchar();
    for(int i = 1; i <= r; i++) {
        for(int j = 1; j <= c; j++) {
            s = getchar();
            if(s == 'S') {
                markRow[i] = 1;
                markCol[j] = 1;
            }
        }
        getchar();
    }

    for(int i = 1; i <= r; i++) {
        for(int j = 1; j <= c; j++) {
            if(markCol[j] + markRow[i] != 2) {
                count++;
            }
        }
    }
    printf("%d\n", count);

    return 0;
}