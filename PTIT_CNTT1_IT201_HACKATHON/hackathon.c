#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Course {
    int id;
    char title[50];
    int credits;
} Course;

typedef struct SingleNode {
    Course course;
    struct SingleNode *next;
} SingleNode;

typedef struct DoubleNode {
    Course course;
    struct DoubleNode *next;
} DoubleNode;

SingleNode *createSingleNode(Course course) {
    SingleNode *node = (SingleNode *)malloc(sizeof(SingleNode));
    node->course = course;
    node->next = NULL;
    return node;
}

SingleNode *insertSingleNodeAtEnd(SingleNode *head, Course course) {
    struct SingleNode *newNode = createSingleNode(course);
    if (head == NULL) {
        head = newNode;
        return head;
    }
    SingleNode *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

void displaySingleNode(SingleNode *head) {
    struct SingleNode *temp = head;
    if (head == NULL) {
        return;
    }
    while (temp != NULL) {
        printf("id:%d ", temp->course.id);
        printf("id:%s ", temp->course.title);
        printf("id:%d ", temp->course.credits);
        temp = temp->next;
    }
}

void deleteSingleNode(SingleNode *head,int id) {
    SingleNode *prev = NULL;
    SingleNode *temp = head;
    while (temp != NULL && temp->course.id != id) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Khong tim thay id");
        return;
    }
    prev->next = temp->next;
    if (temp->next == NULL) {
        free(temp);
    }
    free(temp);
    return head;
}

void updateCourseById(SingleNode *head, int id) {
    if (head == NULL) {
        return;
    }
    SingleNode *temp = head;
    while (temp != NULL && temp->course.id != id) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Khong tim thay id");
        return;
    }
    printf("Course id:%d ", temp->course.id);
    printf("Title:%s ", temp->course.title);
    printf("Credits:%d ", temp->course.credits);
    printf("Nhap vao title moi: ");
    gets(temp->course.title);
    printf("Nhap vao credits moi: ");
    scanf("%d", &temp->course.credits);

}

DoubleNode *createDoubleNode(Course course) {
    DoubleNode *node = (DoubleNode *)malloc(sizeof(DoubleNode));
    node->course = course;
    node->next = NULL;
    return node;
}

DoubleNode *insertDoubleNodeAtEnd(DoubleNode *head, Course course) {
    DoubleNode *newNode = createDoubleNode(course);
    if (head == NULL) {
        head = newNode;
        return head;
    }
    DoubleNode *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;

}

int main(void){
    SingleNode *singleHead = NULL;
    DoubleNode *doubleHead = NULL;
    int choice;
    do {
        printf("-----MENU-----\n");
        printf("1.Them khoa hoc\n");
        printf("2.Hien thi danh sach khoa hoc\n");
        printf("3.Xoa khoa hoc\n");
        printf("4.Cap nhap thong tin khoa hoc\n");
        printf("5.Danh dau khao hoc da hoan thanh\n");
        printf("6.Sap xep khoa hoc theo so tin chi.\n");
        printf("7.Tim kiem khao hoc theo ten\n");
        printf("8.Thoat chuong trinh\n");
        printf("Moi ban nhap lụa chon: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                Course newCourse;
                printf("Nhap id: \n");
                scanf("%d", &newCourse.id);
                fflush(stdin);
                printf("Nhap title: \n");
                scanf("%s", newCourse.title);
                printf("Nhap credits: \n");
                scanf("%d", &newCourse.credits);
                singleHead = insertSingleNodeAtEnd(singleHead, newCourse);
                break;
            case 2:
                displaySingleNode(singleHead);
                break;
            case 3:
                int dele;
                printf("Moi ban nhap id muon xoa: ");
                scanf("%d", &dele);
                singleHead = deleteSingleNode(singleHead, dele);
                break;
            case 4:
                int up;
                printf("Moi ban nhap id muon cap nhap: ");
                scanf("%d", &up);
                updateCourseById(singleHead, up);
                break;
            case 5:
                int id;
                printf("Moi ban nhap id: ");
                scanf("%d", &id);
                singleHead = deleteSingleNode(singleHead, id);
                
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
                printf("Thoat chuong trinh\n");
                break;
            default:
                break;
        }
    } while(choice != 8);
    return 0;
}