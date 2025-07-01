#include <stdio.h>

int search(int arr[], int n, int m) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == m) {
            return i;
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
        printf("Moi ban nhap so muon tim: ");
        scanf("%d", &m);
        int index = search(arr, n, m);
        if (index != -1) {
            printf("Gia tri %d duoc tim thay tai vi tri %d trong mang.\n", m, index);
        } else {
            printf("Khong tim thay gia tri %d trong mang.\n", m);
        }
    } else {
        printf("So luong khong hop le. Vui long nhap so 0 < n < 1000.\n");
    }
    return 0;
}
//độ phức tạp thời gian là 0(n)
