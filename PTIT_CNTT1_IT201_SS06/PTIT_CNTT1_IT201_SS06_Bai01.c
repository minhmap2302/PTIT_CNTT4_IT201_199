#include <stdio.h>

int binary(int n){
    if (n == 0)return 1;
    binary(n/2);
    printf("%d ",n%2);
}

int main(){
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    if (n == 0){
        printf("Nhi phan: 0\n");
    } else {
        printf("Nhi phan: ");
        binary(n);
        printf("\n");
    }
    return 0;
}
