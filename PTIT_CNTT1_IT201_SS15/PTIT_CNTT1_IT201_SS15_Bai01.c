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

int main() {
    int size = 5;
    struct Queue* q = createQueue(size);
    printf("Khoi tao thanh cong\n");
    printf("front = %d\n", q->front);
    printf("rear = %d\n", q->rear);
    printf("size = %d\n", q->size);
    free(q->array);
    free(q);
    return 0;
}
