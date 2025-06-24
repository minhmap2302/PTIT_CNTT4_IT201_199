#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    int m;
    printf("Moi ban nhap so luong phan tu: ");
    scanf("%d",&n);
    int *arr1 = (int*)calloc(n,sizeof(int));
    for (int i = 0; i < n; i++) {
        printf("Moi ban nhap phan tu %d: ",i+1);
        scanf("%d",&arr1[i]);
    }
    printf("Moi ban nhap so phan tu muon them m: ");
    scanf("%d",&m);
    arr1 = (int*)realloc(arr1,(n+m)*sizeof(int));
    for (int i = n; i < n + m; i++) {
        printf("Moi ban nhap phan tu %d: ",i+1);
        scanf("%d",&arr1[i]);
    }
    printf("Mang sau khi them: ");
    for (int i = 0; i < n + m; i++) {
        printf("%d ",arr1[i]);
    }
    printf("\n");
    free(arr1);
    return 0;
}
