#include <stdio.h>
#include <stdlib.h>

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
    if (newNode == NULL) {
        printf("Cap phat bo nho that bai!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void preorderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

int main() {
    printf("Tao node goc:\n");
    Node* root = createNode();
    printf("Tao node con trai:\n");
    root->left = createNode();
    printf("Tao node con phai:\n");
    root->right = createNode();
    printf("Duyet cay theo thu tu tien tu: ");
    preorderTraversal(root);
    printf("\n");
    return 0;
}
