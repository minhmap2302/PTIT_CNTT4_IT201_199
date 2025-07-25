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

void addEdge(Node* adjList[], int u, int v) {
    Node* nodeV = createNode(v);
    nodeV->next = adjList[u];
    adjList[u] = nodeV;

    Node* nodeU = createNode(u);
    nodeU->next = adjList[v];
    adjList[v] = nodeU;
}

int countAdjacent(Node* adjList[], int k) {
    int count = 0;
    Node* temp = adjList[k];
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

int main() {
    int n, v;
    printf("Nhap so dinh va so canh: ");
    scanf("%d %d", &n, &v);

    if (n <= 0 || v <= 0 || n >= 100 || v >= 100) {
        printf("Du lieu khong hop le.\n");
        return 1;
    }

    Node* adjList[100];
    for (int i = 0; i < n; i++)
        adjList[i] = NULL;

    printf("Nhap cac canh:\n");
    for (int i = 0; i < v; i++) {
        int u, w;
        scanf("%d %d", &u, &w);
        if (u >= 0 && u < n && w >= 0 && w < n) {
            addEdge(adjList, u, w);
        }
    }

    int k;
    printf("Nhap dinh k muon kiem tra: ");
    scanf("%d", &k);

    if (k < 0 || k >= n) {
        printf("Dinh khong hop le.\n");
        return 1;
    }

    int result = countAdjacent(adjList, k);
    printf("So dinh ke voi %d la: %d\n", k, result);

    return 0;
}
