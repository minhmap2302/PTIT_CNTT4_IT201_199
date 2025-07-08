#include <stdio.h>
#include <stdlib.h>

struct Stack {
    int top;
    int *data;
    int size;
};

struct Stack *createStack(int size) {
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->top = -1;
    stack->data = (int *)malloc(size * sizeof(int));
    stack->size = size;
    return stack;
}

void push(struct Stack *stack, int value) {
    if (stack->top == stack->size - 1) {
        printf("Stack is full\n");
        return;
    }
    stack->data[++stack->top] = value;
}

void print(struct Stack *stack) {
    printf("stack = {\n");
    printf("    elements: [");
    for (int i = 0; i <= stack->top; i++) {
        printf("%d", stack->data[i]);
        if (i < stack->top) {
            printf(", ");
        }
    }
    printf("],\n");
    printf("    top: %d,\n", stack->top);
    printf("    size: %d\n", stack->size);
    printf("}\n");
}

void viewstack(struct Stack *stack) {
    if (stack->top == -1) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack view (top -> bottom):\n");
    for (int i = stack->top; i >= 0; i--) {
        printf("%d\n", stack->data[i]);
    }
}

int main () {
    struct Stack *stack = createStack(5);
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    push(stack, 40);
    push(stack, 50);
    print(stack);
    viewstack(stack);
    print(stack);
    free(stack->data);
    free(stack);
    return 0;
}
