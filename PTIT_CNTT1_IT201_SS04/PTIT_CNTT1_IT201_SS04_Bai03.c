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
int numbermin(int arr[], int size) {
    int min = arr[0];
    int count = 0;
    for (int i = 1; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
            count = i;
        }
    }
    printf("Min = %d, index = %d\n", min, count);
    return min;
}

int main() {
    int arr[100];
    int size = number(arr);
    numbermin(arr, size);
    return 0;
}