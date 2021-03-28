#include <bits/stdc++.h>

int main() {

    int R, C;
    int shake = 0;
    int max = 0;
    do{
        scanf("%d%d", &R, &C);
    }while(R < 1 || C < 1 || R > 50|| C > 50);
    getchar();
    char c[R + 1][C + 1];
    int dem[R + 1][C + 1];
    for(int i = 1; i <= R; i++) {
        for(int j = 1; j <= C; j++) {
            dem[i][j] = 0;
        }
    }
    for(int i = 1; i <= R; i++){
        for(int j = 1; j <= C; j++){
            c[i][j] = getchar();
            if(j - 1 > 0) {
                if(c[i][j - 1] == 'o') {
                    if(c[i][j] == 'o') {
                        shake++;
                    } else if(c[i][j] == '.') {
                        dem[i][j]++;
                    }
                } else {
                    if(c[i][j] == 'o') {
                        dem[i][j - 1]++;
                    }
                }
            }
            if(i - 1 > 0 && j - 1 > 0) {
                if(c[i - 1][j - 1] == 'o') {
                    if(c[i][j] == 'o') {
                        shake++;
                    } else if(c[i][j] == '.') {
                        dem[i][j]++;
                    }
                } else {
                    if(c[i][j] == 'o') {
                        dem[i - 1][j - 1]++;
                    }
                }
            }
            if(i - 1 > 0) {
                if(c[i - 1][j] == 'o') {
                    if(c[i][j] == 'o') {
                        shake++;
                    } else if(c[i][j] == '.') {
                        dem[i][j]++;
                    }
                } else {
                    if(c[i][j] == 'o') {
                        dem[i - 1][j]++;
                    }
                }
            }
            if(i - 1 > 0 && j + 1 <= C) {
                if(c[i - 1][j + 1] == 'o') {
                    if(c[i][j] == 'o') {
                        shake++;
                    } else if(c[i][j] == '.') {
                        dem[i][j]++;
                    }
                } else {
                    if(c[i][j] == 'o') {
                        dem[i - 1][j + 1]++;
                    }
                }
            }
        }
        getchar();
    }
    for(int i = 1; i <= R; i++) {
        for(int j = 1; j <= C; j++) {
            if(dem[i][j] > max) {
                max = dem[i][j];
            }
        }
    }
    printf("%d\n", max + shake);
    return 0;
}