#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Stack {
    int top;
    char *data;
    int size;
};

struct Stack* createStack(int size) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = -1;
    stack->data = (char*)malloc(size * sizeof(char));
    stack->size = size;
    return stack;
}

void push(struct Stack *stack, char c) {
    if (stack->top == stack->size - 1) {
        return;
    }
    stack->data[++stack->top] = c;
}

char pop(struct Stack *stack) {
    if (stack->top == -1) {
        return '\0';
    }
    return stack->data[stack->top--];
}

char peek(struct Stack *stack) {
    if (stack->top == -1) {
        return '\0';
    }
    return stack->data[stack->top];
}

bool isMatching(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '[' && close == ']') ||
           (open == '{' && close == '}');
}

bool isValidBrackets(const char *expr) {
    int len = strlen(expr);
    struct Stack* stack = createStack(len);
    for (int i = 0; i < len; i++) {
        char c = expr[i];
        if (c == '(' || c == '[' || c == '{') {
            push(stack, c);
        } else if (c == ')' || c == ']' || c == '}') {
            char top = pop(stack);
            if (!isMatching(top, c)) {
                free(stack->data);
                free(stack);
                return false;
            }
        }
    }
    bool valid = (stack->top == -1);
    free(stack->data);
    free(stack);
    return valid;
}

int main() {
    char expr[100];
    printf("Nhap bieu thuc: ");
    fgets(expr, sizeof(expr), stdin);
    expr[strcspn(expr, "\n")] = '\0';

    if (isValidBrackets(expr)) {
        printf("true\n");
    } else {
        printf("false\n");
    }

    return 0;
}
