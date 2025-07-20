#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode() {
    int value;
    printf("Nhap gia tri so nguyen cho node: ");
    scanf("%d", &value);
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Cap phat bo nho that bai!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

#define MAX_QUEUE 100

typedef struct {
    Node* data[MAX_QUEUE];
    int front;
    int rear;
} Queue;

void initQueue(Queue* q) {
    q->front = 0;
    q->rear = 0;
}

bool isEmpty(Queue* q) {
    return q->front == q->rear;
}

void enqueue(Queue* q, Node* node) {
    if (q->rear < MAX_QUEUE) {
        q->data[q->rear++] = node;
    }
}

Node* dequeue(Queue* q) {
    if (!isEmpty(q)) {
        return q->data[q->front++];
    }
    return NULL;
}

bool searchBFS(Node* root, int target) {
    if (root == NULL) return false;
    Queue q;
    initQueue(&q);
    enqueue(&q, root);
    while (!isEmpty(&q)) {
        Node* current = dequeue(&q);
        if (current->data == target) return true;
        if (current->left != NULL) enqueue(&q, current->left);
        if (current->right != NULL) enqueue(&q, current->right);
    }
    return false;
}

int main() {
    printf("Tao node goc:\n");
    Node* root = createNode();
    printf("Tao node con trai:\n");
    root->left = createNode();
    printf("Tao node con phai:\n");
    root->right = createNode();
    int target;
    printf("Nhap gia tri can tim kiem: ");
    scanf("%d", &target);
    if (searchBFS(root, target)) {
        printf("Gia tri %d duoc tim thay trong cay (BFS).\n", target);
    } else {
        printf("Gia tri %d khong ton tai trong cay (BFS).\n", target);
    }
    return 0;
}
