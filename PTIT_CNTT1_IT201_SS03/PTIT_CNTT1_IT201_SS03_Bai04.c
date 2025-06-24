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

int maxnumbers(int arr[10][10],int row,int col) {
    int max = arr[0][0];
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (arr[i][j] > max) {
                max = arr[i][j];
            }
        }
    }
    return max;
}

int minnumbers(int arr[10][10],int row,int col) {
    int min = arr[0][0];
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (arr[i][j] < min) {
                min = arr[i][j];
            }
        }
    }
    return min;
}

int main() {
    int row,col;
    printf("Enter number of rows : ");
    scanf("%d",&row);
    printf("Enter number of columns : ");
    scanf("%d",&col);
    int arr[10][10];
    numbers(arr,row,col);
    print(arr,row,col);
    int max = maxnumbers(arr,row,col);
    int min = minnumbers(arr,row,col);
    printf("Max = %d\n",max);
    printf("Min = %d\n",min);
    return 0;
}