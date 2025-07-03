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

struct  Node* deleteLast(struct Node *node) {
    if (node == NULL) {
        return NULL;
    }
    if (node -> next == NULL) {
        free(node);
        return NULL;
    }
    struct Node* temp = node;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    return node;
}

int main() {
    int n;
    struct Node *node = NULL;
    for (int i = 0; i < 10; i++) {
        struct Node *node1 = createNode(i);
        node1->next = node;
        node = node1;
    }
    printf("Danh sach lien ket: ");
    printList(node);
    node = deleteLast(node);
    printf("Danh sach sau khi sua: ");
    printList(node);
    return 0;
}