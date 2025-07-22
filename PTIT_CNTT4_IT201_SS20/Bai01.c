#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode() {
    int value;
    printf("Nhap gia tri cho node: ");
    scanf("%d", &value);
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int main() {
    Node* root = createNode();
    printf("\nnode = {\n   data: %d,\n   left->%s,\n   right->%s\n}\n",
           root->data,
           root->left == NULL ? "NULL" : "NOT NULL",
           root->right == NULL ? "NULL" : "NOT NULL");
    return 0;
}
