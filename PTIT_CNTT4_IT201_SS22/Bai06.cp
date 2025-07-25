#include <stdio.h>
#include <stdlib.h>

#define MAX 100

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

void addEdge(Node* adjList[], int u, int v) {
    Node* newNode = createNode(v);
    newNode->next = adjList[u];
    adjList[u] = newNode;

    newNode = createNode(u);
    newNode->next = adjList[v];
    adjList[v] = newNode;
}

void DFS(Node* adjList[], int visited[], int v) {
    printf("%d ", v);
    visited[v] = 1;

    Node* temp = adjList[v];
    while (temp != NULL) {
        int u = temp->vertex;
        if (!visited[u]) {
            DFS(adjList, visited, u);
        }
        temp = temp->next;
    }
}

int main() {
    int v, e;
    printf("Nhap so dinh (v) va so canh (e): ");
    scanf("%d %d", &v, &e);

    if (v <= 0 || v >= MAX || e <= 0 || e >= MAX) {
        printf("Du lieu khong hop le.\n");
        return 1;
    }

    Node* adjList[MAX] = {NULL};
    int visited[MAX] = {0};

    printf("Nhap danh sach %d canh (u v):\n", e);
    for (int i = 0; i < e; i++) {
        int u, w;
        scanf("%d %d", &u, &w);
        if (u >= 0 && u < v && w >= 0 && w < v) {
            addEdge(adjList, u, w);
        }
    }

    int start;
    printf("Nhap dinh bat dau DFS: ");
    scanf("%d", &start);

    if (start < 0 || start >= v) {
        printf("Dinh bat dau khong hop le.\n");
        return 1;
    }

    printf("Cac dinh duoc duyet theo DFS tu %d: ", start);
    DFS(adjList, visited, start);
    printf("\n");

    return 0;
}
