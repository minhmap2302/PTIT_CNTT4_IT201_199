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

    printf("Danh sach lien ket gom 5pt: ");
    temp = head;
    while (temp != NULL) {
        printf("%d ->", temp->data);
        temp = temp->next;
    }
    printf("Null\n");
    return 0;
}