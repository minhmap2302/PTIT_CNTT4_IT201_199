#include <stdio.h>

int sum(int n) {
    if (n == 0)return 0;
    return n % 10 + sum(n/10);
}

int main() {
    int n;
    printf("Nhap mot so de tinh tong cac so: ");
    scanf("%d",&n);
    int result = sum(n);
    printf("Tong cac chu so la %d",result);
    return 0;

}