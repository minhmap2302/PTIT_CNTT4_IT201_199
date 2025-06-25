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
int numbermax(int arr[], int size) {
    int max = arr[0];
    int count = 0;
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
            count = i;
        }
    }
    printf("max = %d, index = %d\n", max, count);
    return max;
}

int main() {
    int arr[100];
    int size = number(arr);
    numbermax(arr, size);
    return 0;
}