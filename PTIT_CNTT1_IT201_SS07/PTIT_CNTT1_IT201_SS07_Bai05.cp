#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Nhập số lượng phần tử trong mảng (0 < n < 1000): ");
    scanf("%d", &n);

    if (n <= 0 || n >= 1000) {
        printf("Số lượng không hợp lệ.\n");
        return 1;
    }

    int arr[n];
    for (int i = 0; i < n; i++) {
        printf("Nhập phần tử arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }

    printf("Mảng trước khi sắp xếp: ");
    printArray(arr, n);

    quickSort(arr, 0, n - 1);

    printf("Mảng sau khi sắp xếp (tăng dần): ");
    printArray(arr, n);

    return 0;
}