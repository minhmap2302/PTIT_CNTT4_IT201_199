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

void Node* addlast(struct Node *node, int value) {
    struct Node *newNode = createNode(value);
    if (node == NULL) {
        return newNode;
    }
    struct Node *temp = node;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
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
    print("Danh sach lien ket: ");
    printList(node);
    printf("Moi ban nhap 1 so de them: ");
    scanf("%d", &n);
    if (n > 1) {
        node = addlast(node, 1);
        printf("Danh sach sau khi thme: ");
        printList(node);
    } else {
        printf("Khong hop le");
    }
    return 0;
}