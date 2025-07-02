#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *create(int data) {
    struct Node *node = (struct Node *) malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

int search(struct Node *node, int n) {
    struct Node *temp = node;
    while (temp != NULL) {
        if (temp->data == n) {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

void printList(struct Node *head) {
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int n;
    struct Node *head = create(1);
    struct Node *temp = head;
    temp->next = create(2);
    temp = temp->next;
    temp->next = create(3);
    temp = temp->next;
    temp->next = create(4);
    temp = temp->next;
    temp->next = create(5);
    printf("Danh sach lien ket: ");
    printList(head);
    printf("Nhap so can tim: ");
    scanf("%d", &n);
    if (search(head, n)) {
        printf("True\n");
    } else {
        printf("False\n");
    }
    return 0;
}
