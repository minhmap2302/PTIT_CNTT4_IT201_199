
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
    if (newNode == NULL) {
        printf("Cap phat bo nho that bai!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

bool searchDFS(Node* root, int target) {
    if (root == NULL) return false;
    if (root->data == target) return true;
    return searchDFS(root->left, target) || searchDFS(root->right, target);
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
    if (searchDFS(root, target)) {
        printf("Gia tri %d duoc tim thay trong cay.\n", target);
    } else {
        printf("Gia tri %d khong ton tai trong cay.\n", target);
    }
    return 0;
}
