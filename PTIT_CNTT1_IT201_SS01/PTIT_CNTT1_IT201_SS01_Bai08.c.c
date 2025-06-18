#include <stdio.h>
int phantuxhnn(int arr[], int n) {
    int mang[100]= {0};
    int maxmang = 0;
    int phantu = -1;
    for (int i = 0; i < n; i++) {
        mang[arr[i]]++;
        if (mang[arr[i]]> maxmang) {
            maxmang = mang[arr[i]];
            phantu = arr[i];
        }
    }
    return phantu;
}
int main() {
    int arr[] = {1, 1, 3, 2, 2, 2, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int phantu = phantuxhnn(arr, n);
    printf(("Phan tu xuar hien nhieu nhat la: %d\n"),phantu);
    return 0;
}
// độ phức tạp là : O(n)
