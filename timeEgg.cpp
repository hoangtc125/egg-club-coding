#include <stdio.h>
#include <string.h>

long long int a[7], add, mod;
char s[20];

int checkthu() {
    int thu;
    if(strcmp(s, "monday")) {
        thu = 2;
    }
    else if(strcmp(s, "tuesday")) {
        thu = 3;
    }else if(strcmp(s, "wednesday")) {
        thu = 4;
    }else if(strcmp(s, "thursday")) {
        thu = 5;
    }else if(strcmp(s, "friday")) {
        thu = 6;
    }else if(strcmp(s, "saturday")) {
        thu = 7;
    }else if(strcmp(s, "sunday")) {
        thu = 1;
    }
    return thu;
}

void gettime(int mod_add) {
    int thu = checkthu();
    thu += mod_add;
    switch(thu % 7) {
        case 1:
            strcpy(s, "sunday ");
            break;
        case 2:
            strcpy(s, "monday ");
            break;
        case 3:
            strcpy(s, "tuesday ");
            break;
        case 4:
            strcpy(s, "wednesday ");
            break;
        case 5:
            strcpy(s, "thursday ");
            break;
        case 6:
            strcpy(s, "friday ");
            break;
        case 0:
            strcpy(s, "saturday ");
            break;
    }
}

void getday(int add_tmp) {
    tt:
    int dom[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(a[0] % 4 == 0 && a[0] % 100 != 0) {
        dom[2] = 29;
    }
    for(int j = a[1]; j <= 12; j++) {
        if(add_tmp > dom[j]) {
            add_tmp -= dom[j];
            a[2] = add_tmp;
            a[1]++;
        } 
        if(add_tmp < dom[j]) {
            a[2] = add_tmp;
            break;
        }
        
    }
    if(add_tmp > 0 && a[1] > 12) {
        a[0]++;
        a[1] = 1;
        goto tt;
    }
}

void input() {
    FILE *fp = fopen("timeEggSource.txt", "r");
    fgets(s, sizeof(s), fp);
    s[strlen(s) - 1] = '\0';
    for(int i = 0; i < 7; i++) {
        fscanf(fp, "%lld", &a[i]);
    }
    fclose(fp);
}

void display() {
    printf("%s", s);
    for(int i = 0; i < 7; i++) {
        printf("%d ", a[i]);
    }
    printf("\n\n");
}

int main() {
    printf("input\n");
    input();
    display();

    mod = a[6];
    add = a[5] + mod;
    a[5] = add % 60;
    mod = add / 60;

    add = a[4] + mod;
    a[4] = add % 60;
    mod = add / 60;

    add = a[3] + mod;
    a[3] = add % 24;
    mod = add / 24;

    gettime(mod);

    add = a[2] + mod;
    getday(add);

    printf("display\n");
    display();
    return 0;
}