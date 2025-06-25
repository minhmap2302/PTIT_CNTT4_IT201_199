#include <stdio.h>

int main() {
    int arr[10];
    int n;
    int index;
    int found = 0;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i+1);
        scanf("%d", &arr[i]);
    }
    printf("Moi ban nhap so muon tim: ");
    scanf("%d", &index);
    printf("So lan xuat hien o cac vi tri la: ");
    for (int i = 0; i < n; i++) {
        if (arr[i] == index) {
            printf("%d ", i);
            found = 1;
        }
    }
    if (!found) {
        printf("khong tim thay");
    }
    return 0;
}