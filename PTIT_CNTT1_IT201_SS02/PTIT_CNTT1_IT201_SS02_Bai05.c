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

int delenumber(int arr[], int size) {
    int count = 0;
    int newsize = 0;
    printf("Moi ban mnhap số muốn xoa: ");
    scanf("%d", &count);
    for (int i = 0; i < size; i++) {
        if (arr[i] != count) {
            arr[newsize] = arr[i];
            newsize++;
        }
    }
    return newsize;
}

int primeNumber(int arr[], int size) {
    printf("Mang sau khi xoa la : ");
    for (int i = 0; i < size; i++) {
        printf("%d  ", arr[i]);
    }
    printf("\n");
}
int main() {
    int arr[100];
    int size = number(arr);
    size = delenumber(arr, size);
    primeNumber(arr, size);
    return 0;
}