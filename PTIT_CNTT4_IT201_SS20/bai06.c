#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void insertNode(Node** root, int value) {
    Node* newNode = createNode(value);
    if (*root == NULL) {
        *root = newNode;
        return;
    }
    Node* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = *root;
    while (front < rear) {
        Node* current = queue[front++];
        if (current->left == NULL) {
            current->left = newNode;
            return;
        } else {
            queue[rear++] = current->left;
        }
        if (current->right == NULL) {
            current->right = newNode;
            return;
        } else {
            queue[rear++] = current->right;
        }
    }
}

int treeHeight(Node* root) {
    if (root == NULL) return 0;
    int left = treeHeight(root->left);
    int right = treeHeight(root->right);
    return (left > right ? left : right) + 1;
}

int countLeaves(Node* root) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return 1;
    return countLeaves(root->left) + countLeaves(root->right);
}

int findMax(Node* root) {
    if (root == NULL) return -1;
    int max = root->data;
    int leftMax = findMax(root->left);
    int rightMax = findMax(root->right);
    if (leftMax > max) max = leftMax;
    if (rightMax > max) max = rightMax;
    return max;
}

int findLevel(Node* root, int target, int level) {
    if (root == NULL) return -1;
    if (root->data == target) return level;
    int left = findLevel(root->left, target, level + 1);
    if (left != -1) return left;
    return findLevel(root->right, target, level + 1);
}

void preorder(Node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

int main() {
    Node* root = NULL;
    insertNode(&root, 10);
    insertNode(&root, 5);
    insertNode(&root, 15);
    insertNode(&root, 3);
    insertNode(&root, 7);
    insertNode(&root, 12);
    insertNode(&root, 18);
    printf("Duyet tien tu: ");
    preorder(root);
    printf("\n");
    printf("Chieu cao cua cay: %d\n", treeHeight(root));
    printf("So la trong cay: %d\n", countLeaves(root));
    printf("Gia tri lon nhat: %d\n", findMax(root));
    int value;
    printf("Nhap gia tri de tim tang: ");
    scanf("%d", &value);
    int level = findLevel(root, value, 0);
    if (level != -1)
        printf("Gia tri %d o tang %d\n", value, level);
    else
        printf("Khong tim thay gia tri %d trong cay\n", value);
    return 0;
}
