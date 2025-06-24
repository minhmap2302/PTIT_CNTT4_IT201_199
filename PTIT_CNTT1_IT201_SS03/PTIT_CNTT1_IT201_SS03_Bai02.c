#include <stdio.h>
#include <stdlib.h>

int numbers(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("arr[%d]: ",i + 1);
        scanf("%d",&arr[i]);
        if (arr[i] <= 0) {
            printf("Phan tu khong hop le");
        }
    }
    return 0;
}

int maxnumber(int arr[], int n) {
    int max = arr[0];
    for (int i = 0; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int main() {
    int n;
    printf("Nhap so luong trong mang: ");
    scanf("%d", &n);
    if (n < 1) {
        printf("Khong hop le");
        return 1;
    }
    int *arr = (int*)malloc(n * sizeof(int));
    numbers(arr, n);
    int max = maxnumber(arr, n);
    printf("So lon nhat trong mang la: %d", max);
    free(arr);
    return 0;
}