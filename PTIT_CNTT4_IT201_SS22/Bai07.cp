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
    Node* nodeV = createNode(v);
    nodeV->next = adjList[u];
    adjList[u] = nodeV;

    Node* nodeU = createNode(u);
    nodeU->next = adjList[v];
    adjList[v] = nodeU;
}

void BFS(Node* adjList[], int start, int v) {
    int visited[MAX] = {0};
    int queue[MAX];
    int front = 0, rear = 0;

    visited[start] = 1;
    queue[rear++] = start;

    printf("Cac dinh duoc duyet theo BFS tu %d: ", start);

    while (front < rear) {
        int current = queue[front++];
        printf("%d ", current);

        Node* temp = adjList[current];
        while (temp != NULL) {
            int neighbor = temp->vertex;
            if (!visited[neighbor]) {
                visited[neighbor] = 1;
                queue[rear++] = neighbor;
            }
            temp = temp->next;
        }
    }
    printf("\n");
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

    printf("Nhap danh sach %d canh (u v):\n", e);
    for (int i = 0; i < e; i++) {
        int u, w;
        scanf("%d %d", &u, &w);
        if (u >= 0 && u < v && w >= 0 && w < v) {
            addEdge(adjList, u, w);
        }
    }

    int start;
    printf("Nhap dinh bat dau BFS: ");
    scanf("%d", &start);

    if (start < 0 || start >= v) {
        printf("Dinh bat dau khong hop le.\n");
        return 1;
    }

    BFS(adjList, start, v);

    return 0;
}
