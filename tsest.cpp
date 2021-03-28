#include <stdio.h>
#include <conio.h>

int main() {

    char e[2], f[2], g[2], h[2];
    int a, b, c, d;
    scanf("%d", &a);
    getchar();
    fgets(e, sizeof(e), stdin);
    getchar();
    scanf("%d", &b);
    getchar(); 
    fgets(f, sizeof(f), stdin);
    getchar(); 
    scanf("%d", &c);
    getchar(); 
    fgets(g, sizeof(g), stdin);
    getchar(); 
    scanf("%d", &d);
    getchar(); 
    fgets(h, sizeof(h), stdin);
    printf("%d%d%d%d\n", a, b, c, d);
    printf("%s%s%s%s", e, f, g, h);
    return 0;
}