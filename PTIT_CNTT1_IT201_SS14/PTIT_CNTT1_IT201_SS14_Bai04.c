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

void push(struct Stack* stack, int data) {
    struct Node* temp = createNode(data);
    temp->next = stack->top;
    stack->top = temp;
}

void printStack(struct Stack* stack) {
    struct Node* temp = stack->top;
    printf("Stack elements are:\n");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int pop(struct Stack* stack) {
    struct Node* temp = stack->top;
    int data = temp->data;
    stack->top = stack->top->next;
    free(temp);
    return data;
}

int main () {
    struct Stack* stack = createStack(10);
    int m;
    printf("Enter number of elements: ");
    scanf("%d", &m);
    for (int i = 1; i <= m; i++) {
        int n;
        printf("Enter number: ");
        scanf("%d", &n);
        if (n>0) {
            push(stack, n);
        } else {
            printf("Loi");
        }
    }
    printStack(stack);
    int popped = pop(stack);
    printf("Popped element: %d\n", popped);
    printStack(stack);
    return 0;
}

