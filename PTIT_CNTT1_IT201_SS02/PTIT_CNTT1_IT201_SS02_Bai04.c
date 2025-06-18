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

int repairnumber(int arr[], int size) {
    int index = 0;
    int value = 0;
    printf("Moi ban nhap vi tri muon thay sua : ");
    scanf("%d",&index);
    if (index >= 0 && index < size) {
        printf("Moi ban nhap so muon thay: ");
        scanf("%d", &value);
        arr[index] = value;
    } else {
        printf("Gia tri ko hop le");
    }
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
    repairnumber(arr, size);
    primeNumber(arr, size);
    return 0;
}