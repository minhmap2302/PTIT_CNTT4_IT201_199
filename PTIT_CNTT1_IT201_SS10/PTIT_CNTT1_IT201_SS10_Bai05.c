#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* createNode(int value){
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = value;
    node->next = NULL;
    return node;
}

void printList(struct Node* node){
    struct Node* temp = node;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void deleteNode(struct Node* node,int n) {
    while (node != NULL && node->data != n) {
        struct Node* temp = node;
        node = node->next;
        free(temp);
    }
    struct Node* current = node;
    while (current != NULL && current->data != n) {
        if (current->next->data == n) {
            struct Node* temp = current->next;
            current->next = current->next->next;
            free(temp);
        } else {
            current = current->next;
        }
    }
    return node;
}

int main(){
    int n;
    struct Node* node = createNode(10);
    node->next = createNode(20);
    node->next->next = createNode(30);
    node->next->next->next = createNode(40);
    printf("Danh sach ban dau: ");
    printList(node);
    printf("Nhap gia tri can xoa: ");
    scanf("%d",&n);
    node = deleteNode(node,n);
    printf("Danh sach sau khi xoa: ");
    return 0;
}
