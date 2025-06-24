#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void numbers(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("arr[%d]:  ", i + 1);
        scanf("%d",&arr[i]);
        if (arr[i] <= 0) {
            printf("Khong hop le");
        }
    }
    return 0;
}

void avarages(int arr[], int n) {
    char even[100];
    even[0] = '\0';
    int sum = 0;
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            char temp[100];
            sprintf(temp, "%d", arr[i]);
            strcat(even, temp);
            sum += arr[i];
            count++;
        }
    }
    if (count > 0) {
        printf("Cac so chan la %s\n",even);
        printf("Trung binh cong là: %2f\n",(float)sum / count);
    } else {
        printf("Cac so chan la 0");
    }
}

int main() {
    char even[100];
    int n;
    printf("Moi ban nhap so phan tu: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("Khong hop le");
        return 1;
    }
    int *arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Malloc Error");
        return 1;
    }
    numbers(arr, n);
    avarages(arr, n);
    free(arr);
    return 0;
}
