#include <stdio.h>

int fibonaci(int n) {
    if (n == 0) return 0;
    else if (n == 1) return 1;
    else return fibonaci(n-1) + fibonaci(n-2);
}

int fibonacirever(int n) {
    if (n == 0) return 0;
    printf("%d\n", fibonaci(n-1));
    fibonacirever(n-1);
}

int main() {
    int n;
    printf("Moi ban  nhap mot so de tinh: ");
    scanf("%d",&n);
    printf("Chuoi fibonaci la:\n ");
    fibonacirever(n);
    return 0;
}