#include <stdio.h>
#include <stdlib.h>

typedef struct Queue {
    Node **arr;
    int size;
    int front;
    int rear;
}Queue;

Queue *createQueue(int size) {
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->arr = (Node **)malloc(sizeof(Node *)*size);
    queue->size = 0;
    queue->front = 0;
    queue->rear = -1;
    return queue;
}

int isEmpty(Queue *queue) {
    return queue->front == queue->rear;
}

void enqueue(Queue *queue, Node *node) {
    if (queue->rear == queue->size - 1) {
        printf("Queue is full\n");
        return;
    }
    queue->rear++;
    queue->rear(queue->rear) = node;
}

void levelorderBFS(Node *root) {
    if (root == NULL) {
        printf("Queue is empty\n");
        return;
    }
    Queue *queue = createQueue(queue->size);
    enqueue(queue, root);
    while (isEmpty(queue)) {
        Node *node = queue->arr[queue->front++];
        printf("%d ", node->data);
        if (node->right != NULL) {
            enqueue(queue, node->right);
        }
        if (node->left != NULL) {
            enqueue(queue, node->left);
        }


    }
}

int main () {

}
