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
int numeberduplicate(int arr[], int size) {
    int temp = 0;
    int flat = 0;
    printf("Mời bạn nhập số muốn kiểm tra: ");
    scanf("%d", &temp);
    for (int i = 0; i < size; i++) {
        if (arr[i] == temp) {
            flat++;
        } else {
            printf("0");
        }
    }
    return flat;
}

int main() {
    int arr[100];
    int size = number(arr);
    int result = numeberduplicate(arr, size);
    printf("Số lần lặp của số đó là : %d",result);
    return 0;
}