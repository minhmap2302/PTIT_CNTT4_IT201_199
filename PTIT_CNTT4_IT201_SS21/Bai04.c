#include <stdio.h>

#define SIZE 3

void initGraph(int graph[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            graph[i][j] = 0;
        }
    }
}

void addEdge(int graph[SIZE][SIZE], int fromNode, int toNode) {
    if (fromNode >= 0 && fromNode < SIZE && toNode >= 0 && toNode < SIZE) {
        graph[fromNode][toNode] = 1;
    }
}

void printGraph(int graph[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf(" %d", graph[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int graph[SIZE][SIZE];
    initGraph(graph);
    addEdge(graph, 1, 0);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 0);
    printf("Ma tran ke cua do thi co huong:\n");
    printGraph(graph);
    return 0;
}
