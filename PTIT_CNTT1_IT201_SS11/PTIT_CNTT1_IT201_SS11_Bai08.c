#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void append(struct Node** head, int value) {
    struct Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL)
            printf("<->");
        temp = temp->next;
    }
    printf("->NULL\n");
}

void deleteAtPosition(struct Node** head, int position) {
    if (*head == NULL || position < 0) {
        printf("Khong hop le.\n");
        return;
    }
    struct Node* temp = *head;
    if (position == 0) {
        *head = temp->next;
        if (*head != NULL)
            (*head)->prev = NULL;
        free(temp);
        return;
    }
    int i = 0;
    while (temp != NULL && i < position) {
        temp = temp->next;
        i++;
    }
    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    free(temp);
}
int main() {
    struct Node* head = NULL;
    append(&head, 1);
    append(&head, 2);
    append(&head, 3);
    append(&head, 4);
    append(&head, 5);
    printf("Danh sach la:\n");
    printList(head);
    int position;
    printf("\nNhap vi tri muon xoa: ");
    scanf("%d", &position);
    deleteAtPosition(&head, position);
    printf("\nDanh sach sau khi xoa\n");
    printList(head);
    return 0;
}
