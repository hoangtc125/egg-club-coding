#include <stdio.h>
#include <conio.h>
#include <string.h>

int time = 0, C, player, N, loser = 0;
char answer[2];

int main() {
    
    scanf("%d", &player);
    scanf("%d", &N);
    tt:
    scanf("%d", &C);
    getchar();
    time += C;
    if(time >= 210 && loser == 0) {
        loser = player;
        printf("DONE LOSER\n");
    }
    N--;
    if(N == 0 && loser == 0) {
        loser = player;
    }
    fgets(answer, sizeof(answer), stdin);
    getchar();
    if(answer[0] == 'T') {
        printf("DONE\n");
        player++;
        if(player > 8) {
            player = 1;
        }
    }
    if(N != 0) {
        goto tt;
    }
    printf("%d", loser);
    
    return 0;
}