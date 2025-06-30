#include <stdio.h>

int bublesort(int n,int arr[]) {
    for(int i=0;i<n;i++) {
        for(int j=i+1;j<n;j++) {
            if(arr[i]>arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    return n;
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
        bublesort(n,arr);
        printf("Mảng sau khi sắp xếp là: ");
        for(int i=0;i<n;i++) {
            printf("%d ", arr[i]);
        }
    } else {
        printf("Khon hop le");
    }
}