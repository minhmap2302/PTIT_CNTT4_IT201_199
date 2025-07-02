#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* create(int data){
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

void print(struct Node* head){
    struct Node* temp = head;
    int count = 1;
    while(temp != NULL){
        printf("Node %d : %d \n",count, temp->data);
        temp = temp->next;
        count++;
    }
}

int main(){
    struct Node* head = NULL;
    struct Node* temp = NULL;
    head = create(10);
    temp = head;
    temp->next = create(20);
    temp = temp->next;
    temp->next = create(30);
    temp = temp->next;
    temp->next = create(40);
    temp = temp->next;
    temp->next = create(50);
    print(head);
    return 0;
}