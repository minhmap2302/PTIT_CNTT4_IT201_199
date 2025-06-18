#include <stdio.h>
int cach1(int arr[], int n){
    for (int i = 0; i < n; i++) {
         for (int j = 0; j < n; j++) {
            if (arr[i] == arr[j]) {
                return 1;
            }
        }
    }
    return 0;
}
int cach2(int arr[], int n) {
    int count[1001] = {0};
    for (int i = 0; i < n; i++) {
        if (count[arr[i]] == 1) {
            return 1;
        }
        count[arr[i]] = 1;
    }
    return 0;
}

int main(){
    int arr[] = {1, 4, 2, 6, 8, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    if (cach1(arr, n)) {
        printf("cách 1: có trùng lặp");
    } else {
        printf("cách 1: không trùng lặp");
    }
    if (cach2(arr, n)) {
        printf("cách 2: có trùng lặp");
    } else {
        printf("cách 2: không trùng lặp");
    }
    return 0;
}
//c1 có độ phức tạp là 0(n^2)
//c2 có đ phức tạp là o(n)
