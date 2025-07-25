#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

Node* createNode(int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

void addEdge(Node** adjList, int u, int v) {
    Node* newNode = createNode(v);
    newNode->next = adjList[u];
    adjList[u] = newNode;
}

void printAdjList(Node** adjList, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d:", i);
        Node* temp = adjList[i];
        while (temp != NULL) {
            printf(" %d ->", temp->vertex);
            temp = temp->next;
        }
        printf(" NULL\n");
    }
}

int main() {
    int n;
    scanf("%d", &n);

    if (n <= 0 || n >= 100) {
        printf("So dinh khong hop le.\n");
        return 1;
    }

    int matrix[100][100];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &matrix[i][j]);

    Node* adjList[100];
    for (int i = 0; i < n; i++)
        adjList[i] = NULL;

    for (int i = 0; i < n; i++)
        for (int j = n - 1; j >= 0; j--)
            if (matrix[i][j] == 1)
                addEdge(adjList, i, j);

    printAdjList(adjList, n);

    return 0;
}
