#include <stdio.h>

int tong(int n) {
    if(n==0) return 0;
    return tong(n-1)+n;
}

int main(){
    int n;
    printf("Moi ban nhap so muon tinh: ");
    scanf("%d",&n);
    int sum = tong(n);
    printf("Tong sau trong muon tinh: %d",sum);
    return 0;
}