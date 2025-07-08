#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct Stack {
    int top;
    char *data;
    int size;
};

struct Stack* createStack(int size) {
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->top = -1;
    stack->data = (char *)malloc(size * sizeof(char));
    stack->size = size;
    return stack;
}

void push(struct Stack *stack, char value) {
    if (stack->top == stack->size - 1) {
        printf("Stack is full\n");
        return;
    }
    stack->data[++stack->top] = value;
}

char pop(struct Stack *stack) {
    if (stack->top == -1) {
        return '\0';
    }
    return stack->data[stack->top--];
}
bool isPalindrome(char str[]) {
    int len = strlen(str);
    struct Stack *stack = createStack(len);
    for (int i = 0; i < len; i++) {
        push(stack, str[i]);
    }
    for (int i = 0; i < len; i++) {
        char c = pop(stack);
        if (str[i] != c) {
            free(stack->data);
            free(stack);
            return false;
        }
    }
    free(stack->data);
    free(stack);
    return true;
}

int main() {
    char str[100];
    printf("Nhap chuoi: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';

    if (isPalindrome(str)) {
        printf("true\n");
    } else {
        printf("false\n");
    }
    return 0;
}
