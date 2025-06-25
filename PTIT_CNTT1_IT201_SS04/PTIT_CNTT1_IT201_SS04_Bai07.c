#include <stdio.h>

int main () {
    int n;
    int arr[100];
    int found = 0;
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu: ");
        scanf("%d", &arr[i]);
    }
    printf("\n");
    printf("Cac cap phan tu doi xung la: ");
    for (int i = 0; i < n / 2; i++) {
        if (arr[i] == arr[n - i - 1]) {
            printf("Cap doi xung: (%d, %d)\n", arr[i], arr[n - i - 1]);
            found = 1;
        }
    }
    if (!found) {
        printf("Khong hop le");
    }
    return 0;
}