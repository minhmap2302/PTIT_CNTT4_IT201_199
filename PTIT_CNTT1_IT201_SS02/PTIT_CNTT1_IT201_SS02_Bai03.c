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

int reverse(int arr[], int size) {
    for (int i = size - 1; i >= 0; i--) {
         printf("%d  ", arr[i]);
    }
    printf("\n");
    return size;
}

int main() {
    int arr[100];
    int size = number(arr);
    reverse(arr, size);
    return 0;
}
