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

struct Node* deleteNode(struct Node* head, int value){
    struct Node* temp = head;
    while(temp != NULL){
        struct Node* nextnode = temp->next;
        if(temp->data == value){
            if(temp->prev == NULL){
                head = temp->next;
                if(head != NULL){
                    head->prev = NULL;
                }
            }
            else {
                temp->prev->next = temp->next;
                if (temp->next != NULL) {
                    temp->next->prev = temp->prev;
                }
            }
            free(temp);
        }
        temp = nextnode;
    }
    return head;
}

int main(){
    int n;
    struct Node* head = NULL;
    struct Node* second = NULL;
    struct Node* third = NULL;
    struct Node* fourth = NULL;
    struct Node* fifth = NULL;
    head = createNode(1);
    second = createNode(2);
    third = createNode(3);
    fourth = createNode(4);
    fifth = createNode(4);
    head->next = second;
    second->prev = head;
    second->next = third;
    third->prev = second;
    third->next = fourth;
    fourth->prev = third;
    fourth->next = fifth;
    fifth->prev = fourth;
    printList(head);
    printf("Nhap so nguyen duong muon xoa: ");
    scanf("%d", &n);
    if (n>0) {
        head = deleteNode(head, n);
        printList(head);
    } else {
        printf("Khong hop le");
    }
    return 0;
}
