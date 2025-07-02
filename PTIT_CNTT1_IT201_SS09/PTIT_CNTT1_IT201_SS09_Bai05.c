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

int addNode(struct Node** head_ref,int value) {
    struct Node* newnode = createNode(value);
    newnode->next = *head_ref;
    *head_ref = newnode;
}

void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ->", node->data);
        node = node->next;
    }
    printf("Null\n");
}

int main() {
    int n;
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
    printf("Danh sach lien ket ban dau la: ");
    printList(head);
    printf("Ban muon them vao danh sach la: ");
    scanf("%d",&n);
    addNode(&head,n);
    printf("Danh sach la: ");
    return 0;
}