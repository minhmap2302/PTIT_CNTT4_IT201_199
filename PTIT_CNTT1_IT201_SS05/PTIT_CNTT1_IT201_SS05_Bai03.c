#include <stdio.h>

int giaithua(int n) {
    if(n==0) return 1;
    return giaithua(n-1)*n;
}

int main() {
    int n;
    printf("Nhap vao sau : ");
    scanf("%d",&n);
    if(n>0) {
        int tich = giaithua(n);
        printf("%d", tich);
    } else {
        printf("Không hợp lệ");
    }
}