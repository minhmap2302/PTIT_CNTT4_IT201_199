#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_QUEUE 100

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

typedef struct {
    Node* data[MAX_QUEUE];
    int front;
    int rear;
} Queue;

void initQueue(Queue* q) {
    q->front = q->rear = 0;
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

Node* createNodeWithValue(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Cap phat bo nho that bai!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void addNode(Node* root, int value) {
    if (root == NULL) {
        return;
    }
    Queue q;
    initQueue(&q);
    enqueue(&q, root);
    while (!isEmpty(&q)) {
        Node* current = dequeue(&q);
        if (current->left == NULL) {
            current->left = createNodeWithValue(value);
            return;
        } else {
            enqueue(&q, current->left);
        }
        if (current->right == NULL) {
            current->right = createNodeWithValue(value);
            return;
        } else {
            enqueue(&q, current->right);
        }
    }
}

void inorderTraversal(Node* root) {
    if (root == NULL) return;
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

Node* createNodeFromInput() {
    int value;
    printf("Nhap gia tri cho node: ");
    scanf("%d", &value);
    return createNodeWithValue(value);
}

int main() {
    printf("Tao node goc:\n");
    Node* root = createNodeFromInput();
    printf("Tao node con trai:\n");
    root->left = createNodeFromInput();
    printf("Tao node con phai:\n");
    root->right = createNodeFromInput();
    int newValue;
    printf("Nhap gia tri can them vao cay: ");
    scanf("%d", &newValue);
    addNode(root, newValue);
    printf("Duyet cay (Inorder) sau khi them: ");
    inorderTraversal(root);
    printf("\n");
    return 0;
}
