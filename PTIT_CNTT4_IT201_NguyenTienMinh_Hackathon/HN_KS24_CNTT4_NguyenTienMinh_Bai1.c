#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX 100

typedef struct {
    int id;
    char name[50];
    bool status;
    int avg;
} Student;

typedef struct Node {
    Student data;
    struct Node* prev;
    struct Node* next;
} Node;

Student studentList[MAX];
int studentCount = 0;
Node* inactiveHead = NULL;
Node* inactiveTail = NULL;

void addStudent() {
    if (studentCount >= MAX) {
        printf("Danh sach da day.\n");
        return;
    }
    Student sv;
    printf("Nhap ID: "); scanf("%d", &sv.id);
    printf("Nhap ten: "); getchar(); fgets(sv.name, sizeof(sv.name), stdin);
    sv.name[strcspn(sv.name, "\n")] = '\0';
    printf("Nhap diem trung binh: "); scanf("%d", &sv.avg);
    sv.status = true;

    studentList[studentCount++] = sv;
    printf("Da them sinh vien thanh cong.\n");
}

void displayStudents() {
    if (studentCount == 0) {
        printf("Danh sach trong.\n");
        return;
    }

    printf("\n--- Danh sach sinh vien ---\n");
    for (int i = 0; i < studentCount; i++) {
        printf("ID: %d | Ten: %s | Diem: %d | Trang thai: %s\n",
               studentList[i].id, studentList[i].name, studentList[i].avg,
               studentList[i].status ? "Hoat dong" : "Khong hoat dong");
    }
}

void deleteStudent() {
    int id;
    printf("Nhap ID sinh vien can xoa: ");
    scanf("%d", &id);

    int found = 0;
    for (int i = 0; i < studentCount; i++) {
        if (studentList[i].id == id) {
            for (int j = i; j < studentCount - 1; j++) {
                studentList[j] = studentList[j + 1];
            }
            studentCount--;
            found = 1;
            printf("Da xoa sinh vien.\n");
            break;
        }
    }

    if (!found) printf("Khong tim thay sinh vien.\n");
}

void updateStudent() {
    int id;
    printf("Nhap ID sinh vien can cap nhat: ");
    scanf("%d", &id);

    for (int i = 0; i < studentCount; i++) {
        if (studentList[i].id == id) {
            printf("Nhap ten moi: ");
            getchar(); fgets(studentList[i].name, sizeof(studentList[i].name), stdin);
            studentList[i].name[strcspn(studentList[i].name, "\n")] = '\0';
            printf("Nhap diem moi: ");
            scanf("%d", &studentList[i].avg);
            printf("Cap nhat thanh cong.\n");
            return;
        }
    }

    printf("Khong tim thay sinh vien.\n");
}

void insertInactive(Student sv) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = sv;
    newNode->prev = NULL;
    newNode->next = NULL;

    if (!inactiveHead) {
        inactiveHead = inactiveTail = newNode;
    } else {
        inactiveTail->next = newNode;
        newNode->prev = inactiveTail;
        inactiveTail = newNode;
    }
}

void changeStatus() {
    int id;
    printf("Nhap ID sinh vien can thay doi trang thai: ");
    scanf("%d", &id);
    for (int i = 0; i < studentCount; i++) {
        if (studentList[i].id == id) {
            studentList[i].status = !studentList[i].status;
            printf("Da thay doi trang thai thanh %s\n", studentList[i].status ? "Hoat dong" : "Khong hoat dong");

            if (!studentList[i].status) {
                insertInactive(studentList[i]);
            }

            return;
        }
    }

    printf("Khong tim thay sinh vien.\n");
}

void merge(Student arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    Student L[n1], R[n2];
    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i].avg <= R[j].avg) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(Student arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void sortStudents() {
    mergeSort(studentList, 0, studentCount - 1);
    printf("Da sap xep sinh vien theo diem tang dan.\n");
}

void searchStudent() {
    int id;
    printf("Nhap ID sinh vien can tim: ");
    scanf("%d", &id);
    int l = 0;
    int r = studentCount - 1;
    while (l <= r) {
        int m = (l + r) / 2;
        if (studentList[m].id == id) {
            printf("Tim thay: %s | Diem: %d | Trang thai: %s\n",
                   studentList[m].name, studentList[m].avg,
                   studentList[m].status ? "Hoat dong" : "Khong hoat dong");
            return;
        } else if (studentList[m].id < id)
            l = m + 1;
        else
            r = m - 1;
    }

    printf("Khong tim thay sinh vien.\n");
}

int main() {
    int choice;
    do {
        printf("\n-----STUDENT MANAGER-----\n");
        printf("1. Them sinh vien\n");
        printf("2. Hien thi danh sach sinh vien\n");
        printf("3. Xoa sinh vien\n");
        printf("4. Cap nhat thong tin sinh vien\n");
        printf("5. Thay doi trang thai sinh vien\n");
        printf("6. Sap xep sinh vien\n");
        printf("7. Tim kiem sinh vien\n");
        printf("8. Thoat\n");
        printf("Chon chuc nang: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                displayStudents();
                break;
            case 3:
                deleteStudent();
                break;
            case 4:
                updateStudent();
                break;
            case 5:
                changeStatus();
                break;
            case 6:
                sortStudents();
                break;
            case 7:
                searchStudent();
                break;
            case 8:
                printf("Exit\n");
                break;
            default:
                printf("Lua chon khong hop le!\n");
                break;
        }
    } while (choice != 8);
    return 0;
}