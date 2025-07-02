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

void deleNode(struct Node** head_ref, int value, int position) {
    struct Node* temp = *head_ref;
    if (position == 0) {
        *head_ref = temp->next;
        free(temp);
        return;
    }
    for (int i = 1; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) {
        printf("Vi tri xoa ko hop le");
        return;
    }
    struct Node* del = temp->next;
    temp->next = del->next;
    free(del);
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
    printf("Vi tri muon xoa: ");
    scanf("%d", &position);
    deleNode(&head, value, position);
    printf("Danh sach sau khi xoa: ");
    printList(head);
    return 0;
}
