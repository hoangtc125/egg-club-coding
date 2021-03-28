#include <bits/stdc++.h>

void display(int* a, int n) {
    printf("Danh sach: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    return;
}

int findPivot(int* a, int l, int mid, int r) {
    int tmp = a[mid];
    a[mid] = a[l];
    a[l] = tmp;
    int i = l + 1;
    int j = r;
    while(i <= j) {
        while(a[i] < a[l]) {
            i++;
        }
        while(a[j] > a[l]) {
            j--;
        }
        if(i <= j) {
            int tmp1 = a[i];
            a[i] = a[j];
            a[j] = tmp1;
            i++;
            j--;
        }
    }
    tmp = a[j];
    a[j] = a[l];
    a[l] = tmp;
    return j;
}

void quickSort(int* a, int l, int r) {
    if(l < r) {
        int mid = (l + r) / 2;
        int index = findPivot(a, l, mid, r);
        quickSort(a, l, index - 1);
        quickSort(a, index + 1, r);
    }
}

int main() {

    int a[10] = {3, 5, 2, 7, 5, 4, 7, 8, 3, 9};
    display(a, 9);
    quickSort(a, 0, 9);
    display(a, 9);

    return 0;
}