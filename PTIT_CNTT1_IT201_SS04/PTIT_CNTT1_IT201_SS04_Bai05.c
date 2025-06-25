#include <stdio.h>

int main () {
    int arr[100];
    int n;
    int k;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter number %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("Nhap gia tri can tim: ");
    scanf("%d", &k);
    int left = 0; int right = n - 1;
    int found = 0;
    while (left <= right) {
        int mid = (left + right)/2;
        if (arr[mid] == k) {
            found = 1;
            printf("Index = %d\n",mid);
            break;
        } else if (arr[mid] < k) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    if (!found) {
        printf(" gia tri khong ton tai: ");
    }
    return 0;
}