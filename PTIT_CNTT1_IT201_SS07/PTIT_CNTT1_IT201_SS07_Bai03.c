#include <stdio.h>

int insertionsort(int n,int arr[]) {
    for (int i = 1; i < n; i++) {
        int temp = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > temp) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
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
        insertionsort(n,arr);
        printf("Mảng sau khi sắp xếp là: ");
        for(int i=0;i<n;i++) {
            printf("%d ", arr[i]);
        }
    } else {
        printf("Khon hop le");
    }
}