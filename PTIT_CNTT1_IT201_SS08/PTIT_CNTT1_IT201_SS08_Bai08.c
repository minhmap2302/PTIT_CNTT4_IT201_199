#include <stdio.h>

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int linearSearch(int arr[], int n, int count) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == count) {
            return i;
        }
    }
    return -1;
}

int binarySearch(int arr[], int l, int r, int count) {
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == count) {
            return mid;
        } else if (arr[mid] > count) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return -1;
}

int main() {
    int n;
    int m;
    printf("Enter Number:");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        printf("Enter Number:");
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
        printf("\n");
    }
    printf("Mang ban dau la: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    insertionSort(arr, n);
    printf("Mang sau khi sắp xếp là: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("Nhap gia tri can tim: ");
    scanf("%d", &m);
    int linear = linearSearch(arr, m, n);
    if (linear != -1) {
        printf("tim kiem tuyen tinh: %d ", linear);
    } else {
        printf("Khong tim thay");
    }

    int binary = binarySearch(arr, 0, n, n);
    if (binary != -1) {
        printf("tim kiem nhi phan: %d ", binary);
    } else {
        printf("Khong tim thay");
    }
    return 0;

}