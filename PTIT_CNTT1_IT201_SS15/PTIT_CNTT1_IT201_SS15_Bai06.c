#include <stdio.h>
#include <stdlib.h>

struct Queue {
    int* data;
    int size;
    int front;
    int rear;
};


struct Queue* createQueue(int size) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->size = size;
    queue->front = 0;
    queue->rear = -1;
    queue->data = (int*)malloc(size * sizeof(int));
    return queue;
}

void enQueue(struct Queue* q, int value) {
    if (q->rear < q->size - 1) {
        q->rear++;
        q->data[q->rear] = value;
    }
}

int deQueue(struct Queue* q) {
    if (q->front <= q->rear) {
        return q->data[q->front++];
    }
    return -1;
}

int isIncreasing(struct Queue* q) {
    if (q->rear - q->front < 1) return 1;

    int prev = deQueue(q);
    while (q->front <= q->rear) {
        int curr = deQueue(q);
        if (curr != prev + 1) {
            return 0;
        }
        prev = curr;
    }
    return 1;
}

int main() {
    int n, x;
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);

    struct Queue* q = createQueue(n);

    printf("Nhap cac so nguyen duong:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        enQueue(q, x);
    }

    if (isIncreasing(q)) {
        printf("Day tang dan deu 1.\n");
    } else {
        printf("Day KHONG tang dan deu 1.\n");
    }
    free(q->data);
    free(q);

    return 0;
}
