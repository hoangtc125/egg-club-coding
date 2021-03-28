#include <stdio.h>
#include <stdlib.h>

void display(int* a, int n) {
    for(int i = 0; i <= n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void input(int* a, int n) {
    FILE* fp = fopen("input.text", "r");
    fscanf(fp, "%d", &n);
    for(int i = 0; i <= 9; i ++) {
        fscanf(fp, "%d", &a[i]);
    }
    fclose(fp);
    printf("truoc khi sap xep: ");
    display(a, n);
}

void selectionSort(int* a, int n) {
    for(int i = 0; i < n; i++) {
        int m = i;
        for(int j = i + 1; j <= n; j++) {
            if(a[j] < a[m]) {
                int x = a[j];
                a[j] = a[m];
                a[m] = x;
            }
        }
    }
    display(a, n);
}

void insertionSort(int* a, int n) {
    for(int i = 1; i <= 9; i++) {
        int x = a[i];
        int j = i - 1;
        while(x < a[j]) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = x;
    }
    display(a, n);
}

int pivot(int* a, int n, int l, int index, int r) {
    int x = a[l];
    a[l] = a[index];
    a[index] = x;
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
            int x = a[i];
            a[i] = a[j];
            a[j] = x;
            i++;
            j--;
        }
    }
    int tmp = a[l];
    a[l] = a[j];
    a[j] = tmp;
    return j;
}

void quickSort(int* a, int n, int l, int r) {
    if(l > r) {
        return;
    }
    int mid = (l + r) / 2;
    int index = pivot(a, n, l, mid, r);
    quickSort(a, n, l, index - 1);
    quickSort(a, n, index + 1, r);
}

void merge(int* a, int n, int l, int mid, int r) {
    int i = l;
    int j = mid + 1;
    int k = l;
    int b[n];
    while(i <= mid && j <= r) {
        if(a[i] < a[j]) {
            b[k] = a[i];
            k++;
            i++;
        } else {
            b[k] = a[j];
            k++;
            j++;
        }
    }
    while(i <= mid) {
        b[k] = a[i];
        k++;
        i++;
    }
    while(j <= r) {
        b[k] = a[j];
        k++;
        j++;
    }
    for(int x = l; x <= r; x++) {
        a[x] = b[x];
    }
    //exit(1);
}

void mergeSort(int* a, int n, int l, int r) {
    if(l >= r) {
        return;
    }
    int mid = (l + r) / 2;
    mergeSort(a, n, l, mid);
    mergeSort(a, n, mid + 1, r);
    merge(a, n, l, mid, r);
}

void makeHeap(int* a, int i, int n) {
    int key = a[i];
    int j = 2 * i + 1;
    while(j <= n) {
        if(j < n && a[j] < a[j + 1]) {
            j++;
        }
        if(a[j] < key) {
            return;
        } else {
            a[(j - 1) / 2] = a[j];
            j = 2 * j + 1;
        }
        a[(j - 1) / 2] = key;
        key = a[(j - 1) / 2];
    }
    printf("make heap: "); display(a, n);
}

void heapSort(int* a, int n) {
    for(int i = n / 2 + 2; i >= 0; i--) {
        makeHeap(a, i, n);
    }
    printf("\nheap: "); display(a, n);
    for(int i = n - 1; i >= 0; i--) {
        int tmp = a[0];
        a[0] = a[i + 1];
        a[i + 1] = tmp;
        makeHeap(a, 1, i);
        printf("heap: "); display(a, i);
    }
}

int main() {

    int n = 9;
    int a[10] = {1, 5, 4, 8, 3, 1, 0, 5, 6, 10};

    // input(a, n);
    printf("truoc khi sap xep: ");
    display(a, n);

    printf("sau khi sap xep: ");
    // insertionSort(a, n);

    // quickSort(a, n, 0, 9);
    // display(a, n);

    // mergeSort(a, n, 0, 9);
    // display(a, n);
    
    heapSort(a, n);
    display(a, n);

    return 0;
}


