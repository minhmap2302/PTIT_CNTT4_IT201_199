#include <stdio.h>
#include <string.h>

void swap(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

void sortString(char arr[]) {
    int len = strlen(arr);
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[i] > arr[j]) {
                swap(&arr[i], &arr[j]);
            }
        }
    }
}

int main() {
    char arr[100];
    printf("Enter a string: ");
    fgets(arr, sizeof(arr), stdin);
    size_t len = strlen(arr);
    if (len > 0 && arr[len - 1] == '\n') {
        arr[len - 1] = '\0';
        len--;
    }

    if (len == 0) {
        printf("Chuỗi không hợp lệ\n");
    } else {
        sortString(arr);
        printf("Chuỗi sau khi sắp xếp là: %s\n", arr);
    }

    return 0;
}
