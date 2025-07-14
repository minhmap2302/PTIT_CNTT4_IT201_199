#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Queue {
    struct Node *front;
    struct Node *rear;
};

struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

int main() {
    struct Queue* queue = createQueue();
    if (queue->front == NULL && queue->rear == NULL) {
        printf("Queue is empty\n");
    }
    free(queue);
    return 0;
}