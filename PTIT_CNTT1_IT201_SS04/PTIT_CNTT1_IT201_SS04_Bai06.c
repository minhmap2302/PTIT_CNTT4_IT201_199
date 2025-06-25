#include <stdio.h>
#include <string.h>

struct student {
    int id;
    char name[50];
    int age;
};

int main() {
    struct student students[100];
    int n;
    int search;
    int found = 0;
    printf("Nhap so luong hoc sinh: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        students[i].id = i + 1;
        printf("id: %d \n",i+1);
        printf("name: ");
        getchar();
        fgets(students[i].name, sizeof(students[i].name), stdin);
        students[i].name[strcspn(students[i].name, "\n")] = '\0';
        printf("age: ");
        scanf("%d", &students[i].age);
    }
    printf("Mang sau khi nhap la: ");
    for (int i = 0; i < n; i++) {
        printf("id: %d ",i+1);
        printf("name: %s ",students[i].name);
        printf("age: %d\n",students[i].age);
    }
    printf(("Moi ban nhap id can tim: "));
    scanf("%d", &search);
    for (int i = 0; i < n; i++) {
        if (search == students[i].id) {
            printf("id: %d ",search);
            printf("name: %s ",students[i].name);
            printf("age: %d\n",students[i].age);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Khong thay sinh vien");
    }
    return 0;
}