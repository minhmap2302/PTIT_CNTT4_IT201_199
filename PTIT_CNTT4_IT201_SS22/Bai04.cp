#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    if (n <= 0 || n >= 100) {
        printf("So dinh khong hop le.\n");
        return 1;
    }

    int matrix[100][100];
    int edgeCount = 0;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &matrix[i][j]);

    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (matrix[i][j] == 1)
                edgeCount++;

    printf("%d\n", edgeCount);
    return 0;
}
