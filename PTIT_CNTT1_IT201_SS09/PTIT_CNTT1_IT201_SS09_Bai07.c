#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("Null\n");
}

void addNode(struct Node** head_ref, int value, int position) {
    struct Node* new_node = createNode(value);
    if (position == 0) {
        new_node->next = *head_ref;
        *head_ref = new_node;
        return;
    }

    struct Node* temp = *head_ref;
    int count = 0;
    while (temp != NULL && count < position - 1) {
        temp = temp->next;
        count++;
    }
    if (temp == NULL) {
        printf("Vi tri khong hop le!\n");
        free(new_node);
        return;
    }
    new_node->next = temp->next;
    temp->next = new_node;
}

int main () {
    int value;
    int position;
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
    printf("Nhap gia tri muon them: ");
    scanf("%d", &value);
    printf("Vi tri muon them la: ");
    scanf("%d", &position);
    addNode(&head, value, position);
    printf("Danh sach sau khi chen: ");
    printList(head);
    return 0;
}
