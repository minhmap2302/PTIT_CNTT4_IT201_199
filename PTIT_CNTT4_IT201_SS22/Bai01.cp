#include <stdio.h>
#include <stdlib.h>

int* createGraph(int n) {
    return (int*)calloc(n * n, sizeof(int));
}

void addEdge(int* graph, int n, int u, int v) {
    graph[u * n + v] = 1;
    graph[v * n + u] = 1;
}

void printGraph(int* graph, int n) {
    printf("Ma tran ke cua do thi:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", graph[i * n + j]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    printf("Nhap so luong dinh: ");
    scanf("%d", &n);

    int* graph = createGraph(n);

    addEdge(graph, n, 0, 1);
    addEdge(graph, n, 1, 2);
    addEdge(graph, n, 2, 3);

    printGraph(graph, n);

    free(graph);
    return 0;
}
