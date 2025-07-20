#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Call {
    char *phone;
    int time;
} Call;

typedef struct Stack {
    Call *calls;
    int top;
    int capacity;
} Stack;

typedef struct Queue {
    Call *calls;
    int front;
    int rear;
    int capacity;
} Queue;

Stack *createStack(int capacity) {
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->top = -1;
    stack->capacity = capacity;
    stack->calls = (Call *)malloc(stack->capacity * sizeof(Call));
    return stack;
}

Queue *createQueue(int capacity) {
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->front = 0;
    queue->rear = -1;
    queue->capacity = capacity;
    queue->calls = (Call *)malloc(queue->capacity * sizeof(Call));
    return queue;
}

int isQueueFull(Queue *queue) {
    return queue->rear == queue->capacity - 1;
}

int isStackFull(Stack *stack) {
    return stack->top == stack->capacity - 1;
}

void push(Stack *stack, Call call) {
    if (isStackFull(stack)) {
        printf("Stack is full\n");
        return;
    }
    stack->top++;
    stack->calls[stack->top] = call;
}

void enqueue(Queue *queue, Call call) {
    if (isQueueFull(queue)) {
        printf("Queue is full\n");
        return;
    }
    queue->rear++;
    queue->calls[queue->rear] = call;
}

int isStackEmpty(Stack *stack) {
    return stack->top == -1;
}

Call* pop(Stack *stack) {
    if (isStackEmpty(stack)) {
        printf("Stack is empty\n");
        return NULL;
    }
    return &stack->calls[stack->top--];
}

void printHistory(Queue *queue) {
    if (queue->rear < queue->front) {
        printf("No history.\n");
        return;
    }
    printf("Call History:\n");
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("%s (%d min)\n", queue->calls[i].phone, queue->calls[i].time);
    }
}

void displayQueue(Queue *queue) {
    if (isQueueFull(queue)) {
        printf("Queue is full\n");
        return;
    }
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("Phone: %s %d\n", queue->calls[i].phone);
        printf("Time: %d\n", queue->calls[i].time);
    }
}

int main() {
    Stack *backStack = createStack(10);
    Queue *historyQueue = createQueue(10);
    Stack *forwardStack = createStack(10);
    int choice;
    do {
        printf("\n1.Call\n");
        printf("2.Back\n");
        printf("3.Redial\n");
        printf("4.History\n");
        printf("5.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // clear newline
        switch (choice) {
            case 1: {
                Call newCall;
                newCall.phone = (char *)malloc(100 * sizeof(char));
                printf("Enter the phone number: ");
                scanf(" %[^\n]", newCall.phone);
                newCall.time = 10;
                push(backStack, newCall);
                enqueue(historyQueue, newCall);
                forwardStack = createStack(10); // clear forward stack
                break;
            }
            case 2: {
                Call *backCall = pop(backStack);
                if (backCall) {
                    push(forwardStack, *backCall);
                    printf("Went back to: %s\n", backCall->phone);
                }
                break;
            }
            case 3: {
                Call *forwardCall = pop(forwardStack);
                if (forwardCall) {
                    push(backStack, *forwardCall);
                    enqueue(historyQueue, *forwardCall);
                    printf("Redialed: %s\n", forwardCall->phone);
                }
                break;
            }
            case 4:
                printHistory(historyQueue);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    } while (choice != 5);
    return 0;
}
