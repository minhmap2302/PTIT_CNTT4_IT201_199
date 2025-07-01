#include <stdio.h>

int maxnumber(int arr[],int n) {
    if (n==1) return arr[0];
    int max = maxnumber(arr,n-1);
    return (arr[n-1] > max) ? arr[n-1] : max;
}

int minnumber(int arr[],int n) {
    if (n==1) return arr[0];
    int min = minnumber(arr,n-1);
    return (arr[n-1] < min) ? arr[n-1] : min;
}

int main() {
    int n;
    printf("Nhap so phan tu: ");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++) {
        printf("Nhap phan tu: ");
        scanf("%d",&arr[i]);
    }
    int max = maxnumber(arr,n);
    printf("So phan tu lon nhat la: %d\n",max);
    int min = minnumber(arr,n);
    printf("So phan tu lon nhat la: %d\n",min);
    return 0;
}