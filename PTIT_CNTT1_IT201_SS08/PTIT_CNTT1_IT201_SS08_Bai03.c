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
    } else {
        printf("So luong khong hop le. Vui long nhap so 0 < n < 1000.\n");
    }
    return 0;
}
// do phuc tap la 0(n)
