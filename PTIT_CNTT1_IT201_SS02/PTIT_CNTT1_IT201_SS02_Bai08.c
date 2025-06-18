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

int maxnumber(int arr[], int size) {
    printf("các phần tử lớn hơn tất cả các phần tử đứng sau nó là: \n ");
    for (int i = 0; i < size; i++) {
        int max = 1;
        for (int j = i + 1; j < size; j++) {
            if (arr[i] <= arr[j]) {
                max = 0;
                break;
            }
        }
        if (max) {
            printf("%d  ", arr[i]);
        }
    }
    printf("\n");
}



int main() {
    int arr[100];
    int size = number(arr);
    maxnumber(arr, size);
    return 0;
}