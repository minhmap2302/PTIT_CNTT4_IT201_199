#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 3

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Khong the cap phat bo nho!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void addEdge(Node* graph[], int start, int end) {
    Node* newNode1 = createNode(end);
    newNode1->next = graph[start];
    graph[start] = newNode1;

    Node* newNode2 = createNode(start);
    newNode2->next = graph[end];
    graph[end] = newNode2;
}

void printGraph(Node* graph[]) {
    for (int i = 0; i < MAX_NODES; i++) {
        printf("%d: ", i);
        Node* temp = graph[i];
        while (temp != NULL) {
            printf("%d->", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    Node* graph[MAX_NODES] = {NULL};
    printf("Ban dau:\n");
    printGraph(graph);
    printf("\nThem canh (1, 2):\n");
    addEdge(graph, 1, 2);
    printGraph(graph);
    printf("\nThem canh (0, 1):\n");
    addEdge(graph, 0, 1);
    printGraph(graph);
    return 0;
}
