#include <bits/stdc++.h>

int main() {

    int mark = 0;
    char c[5][5];
    int dem[5][5];
    for(int i = 1; i <= 4; i++) {
        for(int j = 1; j <= 4; j++) {
            dem[i][j] = 0;
        }
    }
    for(int i = 1; i <= 4; i++) {
        for(int j = 1; j <= 4; j++) {
            c[i][j] = getchar();
            if(j - 1 > 0) {
                if(c[i][j - 1] != c[i][j]) {
                    dem[i][j]++;
                    if(dem[i][j] == 3) {
                        mark = 1;
                    }
                }
            }
            if(i - 1 > 0 && j - 1 > 0) {
                if(c[i - 1][j - 1] != c[i][j]) {
                    dem[i][j]++;
                    if(dem[i][j] == 3) {
                        mark = 1;
                    }
                }
            }
            if(i - 1 >= 0) {
                if(c[i - 1][j] != c[i][j]) {
                    dem[i][j]++;
                    if(dem[i][j] == 3) {
                        mark = 1;
                    }
                }
            } 
        }
        getchar();
    }
    if(mark) {
        printf("YES");
    } else {
        printf("NO");
    }

    return 0;
}