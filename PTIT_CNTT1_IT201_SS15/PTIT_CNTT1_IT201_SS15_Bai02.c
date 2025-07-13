#include <stdio.h>
#include <stdlib.h>

struct Queue {
    int *array;
    int front;
    int rear;
    int size;
};

struct Queue* createQueue(int size) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->array = (int*)malloc(size * sizeof(int));
    queue->front = 0;
    queue->rear = -1;
    queue->size = size;
    return queue;
}

int isFull(struct Queue* queue) {
    return queue->rear == queue->size - 1;
}

void enQueue(struct Queue* queue, int value) {
    if (isFull(queue)) {
        printf("Queue is full\n");
        return;
    }
    queue->rear++;
    queue->array[queue->rear] = value;
    printf("%d\n", value);
}

void printQueue(struct Queue* queue) {
    printf("queue = {\n   array = [");
    for (int i = queue->front; i < queue->rear; i++) {
        printf("%d, ", queue->array[i]);
        if (i != queue->rear - 1) {
            printf(", ");
        }
    }
    printf("],\n   front = %d,\n   rear = %d,\n   sizze = %d\n",queue -> front, queue -> rear, queue -> size);
}

int main() {
    int size = 5;
    struct Queue* q = createQueue(size);
    printf("Nhap 5 so nguyen\n ");
    for (int i = 0; i < 5; i++) {
        int n;
        printf("Nhap so nguyen : ");
        scanf("%d", &n);
        enQueue(q, n);
        printQueue(q);
    }
    int m;
    printf("Nhap so nguyen : ");
    scanf("%d", &m);
    enQueue(q, m);
    printQueue(q);
    free(q->array);
    free(q);
    return 0;
}
