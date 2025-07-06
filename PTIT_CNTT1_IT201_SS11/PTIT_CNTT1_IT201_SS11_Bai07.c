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

void addlistpostion(struct Node** head,int value,int position){
	struct Node* newNode = createNode(value);
    if (position == 0){
		newNode->next = *head;
        if (*head == NULL){
        	(*head)->prev = newNode;
        }
        *head = newNode;
 		return;
	}
    struct Node* temp = head;
    int i = 0;
    while(temp != NULL && i < position - 1){
    	temp = temp->next;
        i++;
	}
    newNode->next = temp->next;
    if (temp->next == NULL){
		temp->next = newNode;
	}
    temp->next = newNode;
    newNode->prev = temp;
}

int main(){
    int value;
    int position;
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
    printf("Nhap gia tri muon them: ");
    scanf("%d",&value);
    printf("Nhap vi tri muon them: ");
    scanf("%d",&position);
    addlistpostion(&head,value,position);
    printf("Mang sau khi them la: ");
    printList(head);
    return 0;
}
