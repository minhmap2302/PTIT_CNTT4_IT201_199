#include <stdio.h>

int count(int n) {
    if(n<=0) {
        return 0;
    }
    if(n==0) {
        return 1;
    }
    return count(n-1) + count(n-2);
}

int main() {
    int n;
    printf("Moi ban nhap so bac ");
    scanf("%d",&n);
    if (n<0) {
        printf("Khong hop le");
    } else {
        int vays = count(n);
        printf("So cach leo bac la: %d\n",vays);
    }
    return 0;
}