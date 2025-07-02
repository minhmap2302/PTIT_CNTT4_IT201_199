#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* create(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

int countNodes(struct Node* head) {
    int count = 0;
    struct Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = create(1);
    struct Node* temp = head;
    temp->next = create(2);
    temp = temp->next;
    temp->next = create(3);
    temp = temp->next;
    temp->next = create(4);
    temp = temp->next;
    temp->next = create(5);
    printf("Danh sach lien ket: ");
    printList(head);
    int total = countNodes(head);
    printf("Danh sach lien ket co %d phan tu\n", total);
    return 0;
}
