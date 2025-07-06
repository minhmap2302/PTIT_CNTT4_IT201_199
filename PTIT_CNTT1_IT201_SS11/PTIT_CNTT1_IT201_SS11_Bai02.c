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
    int count = 1;
    struct Node* temp = head;
    printf("Linked List:\n");
    while(temp != NULL){
        printf("Node % d : %d \n<-> ",count, temp->data);
        temp = temp->next;
        count++;
    }
}

int main(){
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
    return 0;
}
