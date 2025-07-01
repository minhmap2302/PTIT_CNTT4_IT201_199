#include <stdio.h>

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int binarySearch(int arr[], int n, int m) {
    int L = 0, R = n - 1;
    while (L <= R) {
        int mid = (L + R) / 2;
        if (arr[mid] == m) {
            return mid;
        } else if (arr[mid] > m) {
            R = mid - 1;
        } else {
            L = mid + 1;
        }
    }
    return -1;
}

int main() {
    int n, m;
    printf("Moi ban nhap so luong: ");
    scanf("%d", &n);

    if (n > 0 && n < 1000) {
        int arr[n];
        for (int i = 0; i < n; i++) {
            printf("Nhap phan tu thu %d: ", i);
            scanf("%d", &arr[i]);
        }
        bubbleSort(arr, n);
        printf("Mang sau khi sap xep: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");

        printf("Moi ban nhap so muon tim: ");
        scanf("%d", &m);
        int result = binarySearch(arr, n, m);
        if (result != -1) {
            printf("Gia tri %d duoc tim thay tai vi tri index %d trong mang.\n", m, result);
        } else {
            printf("Khong tim thay gia tri %d trong mang.\n", m);
        }
    } else {
        printf("So luong khong hop le. Vui long nhap so 0 < n < 1000.\n");
    }
    return 0;
}
// do phuc tap la 0(logn)
