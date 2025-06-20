#include <stdio.h>

void numbers(int arr[10][10],int row,int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("Arr[%d][%d] =  ",i,j);
            scanf("%d",&arr[i][j]);
        }
    }
}

void print(int arr[10][10],int row,int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d\t",arr[i][j]);
        }
        printf("\n");
    }
}

int sumnumbers(int arr[10][10],int row,int col) {
    int sum = 0;
    int k = 0;
    printf("Moi bạn nhap so hang muon tinh tong: ");
    scanf("%d",&k);
    for (int i = 0; i < row; i++) {
        if (row == k){
           sum += arr[i][0];
    }
    return sum;
}

int main() {
    int arr[10][10];
    int row,col;
    printf("Moi ban nhap row: ");
    scanf("%d",&row);
    printf("Moi ban nhap col: ");
    scanf("%d",&col);
    numbers(arr,row,col);
    print(arr,row,col);
    sum = sumnumbers(arr,row,col);
    printf("Tong can tim la: %d",sum);
    return 0;
}