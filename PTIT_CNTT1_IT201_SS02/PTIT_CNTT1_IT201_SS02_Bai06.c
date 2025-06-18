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

int updatenumber(int arr[], int size) {
    int index = 0;
    int value = 0;
    printf("Moi ban nhap vi tri muon them: ");
    scanf("%d",&index);
    if (index < 0 || index > size) {
        printf("Gia tri ko hop le");
        return size;
    }
    printf("Moi ban nhap so muon them: ");
    scanf("%d", &value);
    for (int i = size; i > index; i--) {
        arr[i] = arr[i - 1];
    }
    arr[index] = value;
    return size + 1;
}

int primeNumber(int arr[], int size) {
    printf("Mang sau khi thay thé la : ");
    for (int i = 0; i < size; i++) {
        printf("%d  ", arr[i]);
    }
    printf("\n");
}
int main() {
    int arr[100];
    int size = number(arr);
    size = updatenumber(arr, size);
    primeNumber(arr, size);
    return 0;
}