#include <stdio.h>

int inselectionsort(int n,int arr[]) {
    for(int i=0;i<n-1;i++) {
        int min = i;
        for(int j=i+1;j<n;j++) {
            if(arr[j] < arr[min]) {
                min = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

int main () {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    if (n>0 && n<1000) {
        int arr[n];
        for(int i=0;i<n;i++) {
            printf("Enter a number: ");
            scanf("%d", &arr[i]);
        }
        for(int i=0;i<n;i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
        inselectionsort(n,arr);
        printf("Mảng sau khi sắp xếp là: ");
        for(int i=0;i<n;i++) {
            printf("%d ", arr[i]);
        }
    } else {
        printf("Khon hop le");
    }
}