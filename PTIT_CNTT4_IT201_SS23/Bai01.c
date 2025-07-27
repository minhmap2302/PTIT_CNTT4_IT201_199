#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE 100

typedef struct Task {
    int id;
    char title[MAX_TITLE];
    int priority;
    char deadline[20];
} Task;

typedef struct TaskNode {
    Task data;
    struct TaskNode* next;
} TaskNode;

typedef struct HistoryNode {
    Task data;
    struct HistoryNode* prev;
    struct HistoryNode* next;
} HistoryNode;

TaskNode* headTaskList = NULL;
HistoryNode* headHistory = NULL;
HistoryNode* tailHistory = NULL;
int currentId = 1;

Task createTask() {
    Task t;
    t.id = currentId++;
    printf("Nhap tieu de: ");
    getchar();
    fgets(t.title, MAX_TITLE, stdin);
    t.title[strcspn(t.title, "\n")] = '\0';
    printf("Nhap muc do uu tien (so): ");
    scanf("%d", &t.priority);
    printf("Nhap deadline (dd/mm/yyyy): ");
    scanf("%s", t.deadline);
    return t;
}

void addTask() {
    TaskNode* newNode = (TaskNode*)malloc(sizeof(TaskNode));
    newNode->data = createTask();
    newNode->next = NULL;
    if (headTaskList == NULL)
        headTaskList = newNode;
    else {
        TaskNode* temp = headTaskList;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }
    printf("Da them nhiem vu!\n");
}

void displayTasks() {
    TaskNode* temp = headTaskList;
    if (!temp) {
        printf("Danh sach rong.\n");
        return;
    }
    printf("\nDANH SACH NHIEM VU:\n");
    while (temp) {
        printf("ID: %d | Tieu de: %s | Uu tien: %d | Deadline: %s\n",
               temp->data.id, temp->data.title, temp->data.priority, temp->data.deadline);
        temp = temp->next;
    }
}

void deleteTask() {
    int id;
    printf("Nhap ID can xoa: ");
    scanf("%d", &id);
    TaskNode *temp = headTaskList, *prev = NULL;
    while (temp && temp->data.id != id) {
        prev = temp;
        temp = temp->next;
    }
    if (!temp) {
        printf(" Khong tim thay ID.\n");
        return;
    }
    if (!prev)
        headTaskList = temp->next;
    else
        prev->next = temp->next;
    free(temp);
    printf(" Da xoa nhiem vu co ID %d.\n", id);
}

void updateTask() {
    int id;
    printf("Nhap ID can cap nhat: ");
    scanf("%d", &id);

    TaskNode* temp = headTaskList;
    while (temp && temp->data.id != id)
        temp = temp->next;

    if (!temp) {
        printf(" Khong tim thay ID.\n");
        return;
    }

    printf("Nhap tieu de moi: ");
    getchar();
    fgets(temp->data.title, MAX_TITLE, stdin);
    temp->data.title[strcspn(temp->data.title, "\n")] = '\0';
    printf("Nhap uu tien moi: ");
    scanf("%d", &temp->data.priority);
    printf("Nhap deadline moi: ");
    scanf("%s", temp->data.deadline);
    printf(" Da cap nhat.\n");
}

void completeTask() {
    int id;
    printf("Nhap ID da hoan thanh: ");
    scanf("%d", &id);
    TaskNode *temp = headTaskList, *prev = NULL;
    while (temp && temp->data.id != id) {
        prev = temp;
        temp = temp->next;
    }

    if (!temp) {
        printf("Khong tim thay ID.\n");
        return;
    }

    HistoryNode* hNode = (HistoryNode*)malloc(sizeof(HistoryNode));
    hNode->data = temp->data;
    hNode->next = NULL;
    hNode->prev = tailHistory;

    if (tailHistory)
        tailHistory->next = hNode;
    else
        headHistory = hNode;

    tailHistory = hNode;

    if (!prev)
        headTaskList = temp->next;
    else
        prev->next = temp->next;

    free(temp);
    printf("Da chuyen vao lich su hoan thanh.\n");
}

void sortTasks() {
    if (!headTaskList || !headTaskList->next) return;

    int swapped;
    TaskNode *ptr;
    Task temp;

    do {
        swapped = 0;
        ptr = headTaskList;
        while (ptr->next) {
            if (ptr->data.priority > ptr->next->data.priority) {
                temp = ptr->data;
                ptr->data = ptr->next->data;
                ptr->next->data = temp;
                swapped = 1;
            }
            ptr = ptr->next;
        }
    } while (swapped);

    printf("Da sap xep theo do uu tien.\n");
}

void searchTask() {
    char keyword[MAX_TITLE];
    printf("Nhap tu khoa tieu de can tim: ");
    getchar();
    fgets(keyword, MAX_TITLE, stdin);
    keyword[strcspn(keyword, "\n")] = '\0';

    TaskNode* temp = headTaskList;
    int found = 0;
    while (temp) {
        if (strstr(temp->data.title, keyword)) {
            printf("ID: %d | Tieu de: %s | Uu tien: %d | Deadline: %s\n",
                   temp->data.id, temp->data.title, temp->data.priority, temp->data.deadline);
            found = 1;
        }
        temp = temp->next;
    }

    if (!found)
        printf("Khong tim thay nhiem vu.\n");
}

void displayHistory() {
    HistoryNode* temp = headHistory;
    if (!temp) {
        printf("Lich su trong.\n");
        return;
    }

    printf("\nLICH SU NHIEM VU DA HOAN THANH:\n");
    while (temp) {
        printf("ID: %d | Tieu de: %s | Uu tien: %d | Deadline: %s\n",
               temp->data.id, temp->data.title, temp->data.priority, temp->data.deadline);
        temp = temp->next;
    }
}

void menu() {
    printf("\n—————————— TASK MANAGER ———————————\n");
    printf("1. Them nhiem vu\n");
    printf("2. Hien thi danh sach nhiem vu\n");
    printf("3. Xoa nhiem vu\n");
    printf("4. Cap nhat thong tin nhiem vu\n");
    printf("5. Danh dau nhiem vu hoan thanh\n");
    printf("6. Sap xep nhiem vu theo uu tien\n");
    printf("7. Tim kiem nhiem vu theo tieu de\n");
    printf("8. Hien thi lich su hoan thanh\n");
    printf("9. Thoat\n");
    printf("Chon chuc nang: ");
}

int main() {
    int choice;
    do {
        menu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                displayTasks();
                break;
            case 3:
                deleteTask();
                break;
            case 4:
                updateTask();
                break;
            case 5:
                completeTask();
                break;
            case 6:
                sortTasks();
                break;
            case 7:
                searchTask();
                break;
            case 8:
                displayHistory();
                break;
            case 9:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le.\n");
                break;
        }
    } while (choice != 9);
    return 0;
}
