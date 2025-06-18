#include <stdio.h>

int number(int arr[]) {
    int count;
    printf("Moi ban nhap so luong trong mang: ");
    scanf("%d", &count);
    for (int i = 0; i < count; i++) {
        printf("Mời bạn nhập số thứ %d:  ", i + 1);
        scanf("%d", &arr[i]);
    }
    return count;
}

int findnumber(int arr[], int size) {
    int index = 0;
    int n ;
    printf("Moi ban nhap so nguyen can tim tong: ");
    scanf("%d", &n);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (arr[i] + arr[j] == n) {
                printf("tim thay %d + %d == %d\n",arr[i],arr[j],n);
                index = 1;
            }
        }
    }
    if (!index) {
        printf("Khong tim thay");
    }
}

int main() {
    int arr[100];
    int size = number(arr);
    findnumber(arr, size);
    return 0;
}