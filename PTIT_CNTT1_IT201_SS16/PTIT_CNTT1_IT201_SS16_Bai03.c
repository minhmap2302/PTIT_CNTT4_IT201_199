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

struct Node* createNode(int data) {
    int n;
    printf("Enter number: ");
    scanf("%d", &n);
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = n;
    newnode->next = NULL;
    return newnode;
}

void enqueue(struct Queue* queue) {
    struct Node* newnode = creareNode();
    if (queue->rear == NULL) {
        queue->rear = newnode;
        queue->front = NULL;
    } else {
        queue->rear->next = newnode;
        queue->rear = newnode;
    }
}

void printQueue(struct Queue* queue) {
    struct Node* temp = queue->front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
    if (queue->rear != NULL) {
        printf("%d-NULL\n ", queue->rear->data);
    } else {
        printf("NULL\n");
    }
    printf("}\n");
}

void peek(struct Queue* queue) {
    if (queue->front == NULL) {
        printf("Queue is empty\n");
    } else {
        printf("%d ", queue->front->data);
    }
}

int main() {
    struct Queue* queue = createQueue();
    printQueue(queue);
    peek(queue);
    printQueue(queue);
    enqueue(queue);
    enqueue(queue);
    enqueue(queue);
    printQueue(queue);
    peek(queue);
    free(queue);
    return 0;
}