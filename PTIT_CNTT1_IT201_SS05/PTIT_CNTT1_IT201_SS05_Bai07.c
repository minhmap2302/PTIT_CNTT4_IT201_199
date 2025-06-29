#include <stdio.h>

int fibonacci(int i) {
    if (i == 0 ) return 0;
    if (i == 1) return 1;
    return fibonacci(i - 1) + fibonacci(i - 2);
}

int main() {
    int n;
    printf("Moi ban nhap 1 so de tinh fibonaci: ");
    scanf("%d", &n);
    if (n<=0) {
        printf("Invalid input\n");
        return 1;
    }

    int arr[n];
    for (int i = 0; i < n; i++) {
        arr[i] = fibonacci(i);
    }
    printf("Tinh fibonaci: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}