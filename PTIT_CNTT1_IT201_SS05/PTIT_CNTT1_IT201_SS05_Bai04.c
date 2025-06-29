#include <stdio.h>

int tong(int first, int last) {
    if (first > last) return 0;
    return first + (tong(first + 1, last));
}

int main() {
    int first = 0;
    int second = 0;
    printf("Moi ban nhap so thu nhat: ");
    scanf("%d", &first);
    printf("Moi ban nhap so thu hai: ");
    scanf("%d", &second);
    if (first>second) {
        int temp = first;
        first = second;
        second = temp;
    }
    if (first > 0 && second > 0) {
        int sum = tong(first, second);
        printf("%d", sum);
    }
    return 0;
}