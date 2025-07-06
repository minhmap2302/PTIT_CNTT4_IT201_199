#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node* createNode(int value){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void printList(struct Node* head){
    struct Node* temp = head;
    printf("Linked List: ");
    while(temp != NULL){
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void addList(struct Node** head,int value) {
    struct Node* newnode = createNode(value);
    newnode->next = *head;
    if(head != NULL) {
        (*head)->prev = newnode;
    }
    (*head) = newnode;
}

int main(){
    int n;
    struct Node* head = NULL;
    struct Node* second = NULL;
    struct Node* third = NULL;
    struct Node* fourth = NULL;
    head = createNode(1);
    second = createNode(2);
    third = createNode(3);
    fourth = createNode(4);
    head->next = second;
    second->prev = head;
    second->next = third;
    third->prev = second;
    third->next = fourth;
    fourth->prev = third;
    printList(head);
    printf("Moi ban nhap 1 so nguyn duong: ");
    scanf("%d",&n);
    if (n > 0 ) {
        addList(&head,n);
        printf("Danh sach sau khi them la: ");
        printList(head);
    } else {
        printf("gia tri la so nguyen duong\n");
    }
    return 0;
}
