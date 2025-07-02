#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* createNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    if (node == NULL) {
        printf("Memory allocation error!");
        exit(1);
    }
    node->data = data;
    node->next = NULL;
    return node;
}

void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ->", node->data);
        node = node->next;
    }
    printf("Null\n");
}

void deleteNode(struct Node** head_ref) {
    struct Node* temp = *head_ref;
    *head_ref = (*head_ref)->next;
    free(temp);
}

int main() {
    struct Node* head = NULL;
    struct Node* temp = NULL;
    head = createNode(10);
    temp = head;
    temp->next = createNode(20);
    temp = temp->next;
    temp->next = createNode(30);
    temp = temp->next;
    temp->next = createNode(40);
    temp = temp->next;
    temp->next = createNode(50);
    printf("Danh sach ban dau: ");
    printList(head);
    deleteNode(&head);
    printf("Danh sach sau khi xoa: ");
    printList(head);
    return 0;
}