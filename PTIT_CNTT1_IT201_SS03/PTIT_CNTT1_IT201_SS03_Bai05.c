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

int maindiagonal(int arr[10][10],int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i][i];
    }
    return sum;
}

int seconddiagonal(int arr[10][10],int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i][size - 1 - i];
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
    int summain = maindiagonal(arr,row);
    int sumsecond = seconddiagonal(arr,row);

    printf("Duong cheo chinh = %d\n",summain);
    printf("Duong cheo phu = %d\n",sumsecond);
    return 0;
}