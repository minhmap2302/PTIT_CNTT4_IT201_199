#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

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

int pop(struct Stack *stack) {
    if (stack->top == -1) {
        printf("Stack is empty\n");
        return 0;
    }
    return stack->data[stack->top--];
}

int evaluatePostfix(const char *expr) {
    int len = strlen(expr);
    struct Stack *stack = createStack(len);
    for (int i = 0; i < len; i++) {
        char c = expr[i];
        if (isdigit(c)) {
            push(stack, c - '0');
        } else if (c == '+' || c == '-' || c == '*' || c == '/') {
            int b = pop(stack);
            int a = pop(stack);
            int result;
            switch (c) {
                case '+': result = a + b; break;
                case '-': result = a - b; break;
                case '*': result = a * b; break;
                case '/':
                    if (b == 0) {
                        printf("Lỗi: chia cho 0\n");
                        free(stack->data);
                        free(stack);
                        return 0;
                    }
                    result = a / b;
                    break;
                default:
                    printf("Toán tử không hợp lệ\n");
                    free(stack->data);
                    free(stack);
                    return 0;
            }
            push(stack, result);
        }
    }

    int finalResult = pop(stack);
    free(stack->data);
    free(stack);
    return finalResult;
}

int main() {
    char expr[100];
    printf("Nhap bieu thuc: ");
    fgets(expr, sizeof(expr), stdin);
    expr[strcspn(expr, "\n")] = '\0';
    int result = evaluatePostfix(expr);
    printf("Ket qua: %d\n", result);
    return 0;
}
