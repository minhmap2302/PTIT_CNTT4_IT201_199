#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX 100;

typedef struct {
    int id;
    char issue[100];
    int priority;
} Request;

typedef struct {
    Request data[MAX];
    int rear;
    int front;
} Queue;

void initQueue(Queue* q) {
    q->front = 0;
    q->rear = -1;
}

int isEmpty(Queue* q) {
    return q->rear < q->front;
}

int isFull(Queue* q) {
    return q->rear == MAX - 1;
}

void enQueue(Queue* q, Request data) {
    if (isFull(q)) {
        printf("Queue is full\n");
        return;
    }
    q->data[++q->rear] = data;
}

Request deQueue(Queue* q) {
    if (isEmpty(q)) {
        Request data = {-1, "",-1};
        return data;
    }
    return q->data[q->front++];
}

Request peek(Queue* q) {
    if (isEmpty(q)) {
            Request data = {-1, -1};
            return data;
    }
    return q->data[q->front];
}

void printQueue(Queue* q) {
    if (isEmpty(q)) {
        printf("NULL\n");
        return;
    }
    for (int i = q->front; i <= q->rear; i++) {
        printf("ID: %d | Issue: %s | Priority: %d\n",q->data[i].id, q->data[i].issue, q->data[i].priority);
    }
}

Queue highQueue,lowQueue;
int idCounter = 1;

void sendRequest() {
    Request data;
    data.id = idCounter++;
    printf("Nhap noi dung yeu cau: ");
    getchar();
    fgets(data.issue,sizeof(data.issue),stdin);
    data.issue[strcspn(data.issue, "\n")] = '\0';
    do {
        printf("Nhap muc do uu tien(1.cao) va (2.thap): ");
        scanf("%d",&data.priority);
    } while (data.priority != 1 && data.priority != 2);
    if (data.priority == 1) {
        enQueue(&highQueue, data);
    } else {
        enQueue(&lowQueue, data);
    }
    printf("Da gui yeu cau thanh cong");
}

void handleRequest() {
    if (!isEmpty(&highQueue)) {
        Request data = deQueue(&highQueue);
        printf("Dang xu ly yeu cau (HIGH): %s [ID: %d]\n", data.issue, data.id);
    } else if (!isEmpty(&lowQueue)) {
        Request data = deQueue(&lowQueue);
        printf("Dang xu ly yeu cau (LOW): %s [ID: %d]\n", data.issue, data.id);
    } else {
        printf("Khong co yeu cau nao can xu ly.\n");
    }
}

void print() {
    printf("Danh sach yeu cau cao:");
    printQueue(&highQueue);
    printf("Danh sach yeu cau thap:");
    printQueue(&lowQueue);
}

int main () {
    initQueue(&highQueue);
    initQueue(&lowQueue);
    int choice;
    do {
        printf("-----REQUEST-----\n");
        printf("1.Gui yeu cau ho tro\n");
        printf("2.Xu ly yeu cau\n");
        printf("3.Xem yeu cau gan nhat can xu ly\n");
        printf("4.Hien thi toan bo yeu cau\n");
        printf("5. Thoat\n");
        printf("Chon chuc nang: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                sendRequest();
                break;
            case 2:
                handleRequest();
                break;
            case 3:
                break;
            case 4:
                print();
                break;
            case 5:
                printf("Thoat\n");
                break;
            default:
                printf("Invalid\n");
                break;
        }
    } while (choice !=5 );
}