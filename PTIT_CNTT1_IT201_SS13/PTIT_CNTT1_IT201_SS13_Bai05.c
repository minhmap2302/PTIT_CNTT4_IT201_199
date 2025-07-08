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

int pop(struct Stack *stack) {
    if (stack->top == -1) {
        printf("Stack is empty\n");
        return -1;
    }
    return stack->data[stack->top--];
}

void print(int arr[], int n) {
    printf("[");
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) printf(", ");
    }
    printf("]\n");
}

void reverse(int arr[], int n) {
    struct Stack *stack = createStack(n);
    for (int i = 0; i < n; i++) {
        push(stack, arr[i]);
    }
    for (int i = 0; i < n; i++) {
        arr[i] = pop(stack);
    }
    free(stack->data);
    free(stack);
}

int main() {
    int n;
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    printf("Phan tu %d: \n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("mang ban dau \n");
    print(arr, n);
    reverse(arr, n);
    printf("mang sau khi dao\n");
    print(arr, n);
    free(arr);
    return 0;
}
