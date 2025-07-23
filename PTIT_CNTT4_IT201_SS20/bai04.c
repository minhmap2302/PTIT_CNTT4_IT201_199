#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNodeWithValue(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* createNode() {
    int value;
    printf("Nhap gia tri cho node: ");
    scanf("%d", &value);
    return createNodeWithValue(value);
}

typedef struct QueueNode {
    Node* treeNode;
    struct QueueNode* next;
} QueueNode;

typedef struct {
    QueueNode* front;
    QueueNode* rear;
} Queue;

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

void enqueue(Queue* q, Node* node) {
    QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));
    temp->treeNode = node;
    temp->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = temp;
    } else {
        q->rear->next = temp;
        q->rear = temp;
    }
}

Node* dequeue(Queue* q) {
    if (q->front == NULL) return NULL;
    QueueNode* temp = q->front;
    Node* result = temp->treeNode;
    q->front = q->front->next;
    if (q->front == NULL) q->rear = NULL;
    free(temp);
    return result;
}

int isEmpty(Queue* q) {
    return q->front == NULL;
}

void addNode(Node* root, int value) {
    if (root == NULL) return;
    Queue* q = createQueue();
    enqueue(q, root);

    while (!isEmpty(q)) {
        Node* current = dequeue(q);
        if (current->left == NULL) {
            current->left = createNodeWithValue(value);
            break;
        } else {
            enqueue(q, current->left);
        }

        if (current->right == NULL) {
            current->right = createNodeWithValue(value);
            break;
        } else {
            enqueue(q, current->right);
        }
    }
}

int countLeaves(Node* root) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return 1;
    return countLeaves(root->left) + countLeaves(root->right);
}

void levelOrder(Node* root) {
    if (root == NULL) return;
    Queue* q = createQueue();
    enqueue(q, root);
    while (!isEmpty(q)) {
        Node* curr = dequeue(q);
        printf("%d ", curr->data);
        if (curr->left != NULL) enqueue(q, curr->left);
        if (curr->right != NULL) enqueue(q, curr->right);
    }
}

int main() {
    Node* root = createNode();
    int soLuong;
    printf("Nhap so luong phan tu muon them: ");
    scanf("%d", &soLuong);
    for (int i = 0; i < soLuong; i++) {
        int value;
        printf("Nhap gia tri can them: ");
        scanf("%d", &value);
        addNode(root, value);
    }
    printf("Cay nhi phan (duyet theo tang): ");
    levelOrder(root);
    int leaves = countLeaves(root);
    printf("\nSo la trong cay: %d\n", leaves);
    return 0;
}
