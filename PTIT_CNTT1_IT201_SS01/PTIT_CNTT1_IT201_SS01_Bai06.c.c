#include <stdio.h>
int main() {
    int n;
    int temp = 0;
    int arr[] = {1, 2, 2, 3, 4, 3, 5, 2, 6, 7, 7, 8, 9, 10};
    printf(" Mình có mảng như sau: ");
    for ( int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
        printf(" %d", arr[i]);
    }
    printf("Mời bạn nhập số muốn kiểm tra lặp: ");
    scanf("%d", &n);
    for (int j = 0; j < sizeof(arr) / sizeof(arr[0]); j++) {
        if (arr[j] == n) {
            temp++;
        }
    }
    printf("có số lần lặp là: %d\n",temp);
    return 0;
}
//độ phức tạp là O(n);