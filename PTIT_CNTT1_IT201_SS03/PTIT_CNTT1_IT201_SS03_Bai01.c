#include <stdio.h>
#include <stdlib.h>

int number(int arr[],int count) {
    for (int i = 0; i < count; i++) {
        printf("arr[%d]:  ", i + 1);
        scanf("%d", &arr[i]);
        if (arr[i] == 0) {
            printf("So luong phan tu phai lon hon 0\n", i + 1);
        } else if (arr[i] < 0) {
            printf("So luong phan tu khong duoc am\n");
        }
    }
    return count;
}

void print(int arr[],int size) {
    for (int i = 0; i < size; i++) {
        printf("arr[%d]: %d, ", i + 1,arr[i]);
    }
}

int main() {
    int n;
    printf("Moi ban nhap so luong trong mang: ");
    scanf("%d", &n);
    if (n<0) {
        printf("So luong phan tu phai lon hon 0\n");
        return 1;
    }
    int *arr = (int*)malloc(n* sizeof(int));
    number(arr,n);
    print(arr,n);
    free(arr);
    return 0;
}