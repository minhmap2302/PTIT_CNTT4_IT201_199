#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Stack {
    struct Node* top;
};

struct Node* createNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

struct Stack* createStack() {
    struct Stack* temp = (struct Stack*)malloc(sizeof(struct Stack));
    temp->top = NULL;
    return temp;
}

int main () {
    struct Stack* stack = createStack();
    if (stack->top == NULL) {
        printf("Stack is empty\n");
    }
    return 0;
}

