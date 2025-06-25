#include <stdio.h>

int main() {
    int arr[100];
    int n;
    int lastindex = -1;
    int k = 0;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    printf("Enter value to find last index of: ");
    scanf("%d", &k);
    for (int i = 0; i < n; i++) {
        if (arr[i] == k) {
            lastindex = i;
        }
    }
    if (lastindex != -1) {
        printf("%d is the last element at index %d\n", k, lastindex);
    } else {
        printf("%d is not found in the array\n", k);
    }
}