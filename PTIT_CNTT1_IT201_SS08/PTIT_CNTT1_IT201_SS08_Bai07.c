#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *arr, int l, int h) {
    int pivot = arr[h];
    int i = l - 1;
    for (int j = l; j < h; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[h]);
    return i + 1;
}

void quickSort(int *arr, int l, int h) {
    if (l < h) {
        int pi = partition(arr, l, h);
        quickSort(arr, l, pi - 1);
        quickSort(arr, pi + 1, h);
    }
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    if (n > 0 && n <=1000) {
        for (int i = 0; i < n; i++) {
            printf("Enter element %d: ", i + 1);
            scanf("%d", &arr[i]);
        }
        quickSort(arr, 0, n - 1);
        printf("Sorted array: \n");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        return 0;
    }
}