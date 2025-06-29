#include <stdio.h>
#include <string.h>

int strin(char str[],int first,int last) {
    if (first >= last) return 1;
    if (str[first] != str[last]) return 0;
    return strin(str, first+1, last-1);
}

int main() {
    char str[100];
    printf("Mời bạn nhập chuỗi muốn tính: ");
    scanf("%s",str);
    int len = strlen(str);
    if (strin(str,0,len - 1)) {
        printf("Là mảng đối xứng");
    } else {
        printf("Ko phai là mang doi xung");
    }
    return 0;
}