#include <stdio.h>

int main(){
    int arr[100];
    int n = 0;
    int k;
    int index = 0;
    int flag = 0;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        printf("Enter number %d: ", i+1);
        scanf("%d", &arr[i]);
    }
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("Moi ban nhap vao 1 gia tri: \n");
    scanf("%d",&k);
    if (k >= 0) {
        for(int i = 0; i < n; i++) {
            if(arr[i] == k) {
                printf("Phan tu can tim nam o vi tri %d\n",i);
                flag = 1;
            }
        }
        if(!flag) {
            printf("Phan tu can tim không có");
        }
    } else {
        printf("Sorry, number %d is out of range\n", k);
    }
    return 0;
}