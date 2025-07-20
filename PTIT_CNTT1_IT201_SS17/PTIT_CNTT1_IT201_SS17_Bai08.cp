#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

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

Node* createNodeFromInput() {
    int value;
    printf("Nhap gia tri cho node: ");
    scanf("%d", &value);
    return createNodeWithValue(value);
}

int treeHeight(Node* root) {
    if (root == NULL) return 0;
    int leftHeight = treeHeight(root->left);
    int rightHeight = treeHeight(root->right);
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

int main() {
    printf("Tao node goc:\n");
    Node* root = createNodeFromInput();
    printf("Tao node con trai:\n");
    root->left = createNodeFromInput();
    printf("Tao node con phai:\n");
    root->right = createNodeFromInput();
    int height = treeHeight(root);
    printf("Chieu cao cua cay la: %d\n", height);
    return 0;
}
