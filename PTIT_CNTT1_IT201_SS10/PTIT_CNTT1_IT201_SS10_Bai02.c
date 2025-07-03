#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *createNode(int value) {
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = value;
    node->next = NULL;
    return node;
}

void printList(struct Node *node) {
    struct Node *temp = node;
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void print(struct Node *node) {
    struct Node *temp = node;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    struct Node *node = NULL;
    for (int i = 0; i < 10; i++) {
        struct Node *node1 = createNode(i);
        node1->next = node;
        node = node1;
    }
    print("Danh sach lien ket: ");
    printList(node);
    printf("Chi tiet phan tu la: ");
    struct Node *temp = node;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
    return 0;
}