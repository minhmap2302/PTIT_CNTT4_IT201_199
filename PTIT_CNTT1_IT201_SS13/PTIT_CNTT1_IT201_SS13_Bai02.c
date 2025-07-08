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
    printf("elements are: [");
    for (int i = 0; i <= stack->top; i++) {
        printf("%d", stack->data[i]);
        if (i < stack->top) {
            printf(", ");
        }
    }
    printf("]}\n");
    printf("top = %d\n", stack->top);
    printf("size = %d\n", stack->size);
    printf("}\n");
}

int main () {
    struct Stack *stack = createStack(5);
    printf("Stack elements are:\n");
    for (int i = 0; i < 5; i++) {
        int value;
        scanf("%d", &value);
        push(stack, value);
    }
    print(stack);
    free(stack->data);
    free(stack);
    return 0;
}