#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Lỗi cấp phát bộ nhớ!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ->", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {
    struct Node* node = createNode(10);
    node->next = createNode(20);
    node->next->next = createNode(30);
    node->next->next->next = createNode(40);
    printf("Danh sach ban dau: ");
    printList(node);
    printf("Null");
    return 0;
}
