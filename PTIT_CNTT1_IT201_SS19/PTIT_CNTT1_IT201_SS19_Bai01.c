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

int main() {
    Node* root = createNode();
    printf("Da tao node co gia tri: %d\n", root->data);
    free(root);
    return 0;
}
