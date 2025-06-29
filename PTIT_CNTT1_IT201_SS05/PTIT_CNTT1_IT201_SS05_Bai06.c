#include <stdio.h>

int tongmang(int arr[],int n) {
    if (n == 0) return 0;
    return tongmang(arr, n-1) + arr[n-1];
}

int main() {
    int arr[100];
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i+1);
        scanf("%d", &arr[i]);
        if (arr[i] < 0) {
            printf("Invalid input\n");
            return 0;
        }
    }
    int sum = tongmang(arr, n);
    printf("The sum is: %d\n", sum);
}