#include <stdio.h>

#define SIZE 3

void initGraph(int graph[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            graph[i][j] = 0;
        }
    }
}

void addEdge(int graph[SIZE][SIZE], int firstNode, int secondNode) {
    firstNode--;
    secondNode--;
    if (firstNode >= 0 && firstNode < SIZE && secondNode >= 0 && secondNode < SIZE) {
        graph[firstNode][secondNode] = 1;
        graph[secondNode][firstNode] = 1;
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
    printf("Ban dau:\n");
    printGraph(graph);
    addEdge(graph, 1, 2);
    printf("\nSau khi them canh giua 1 va 2:\n");
    printGraph(graph);
    return 0;
}
