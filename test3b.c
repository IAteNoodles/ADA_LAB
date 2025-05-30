#include <stdio.h>

int graph[10][10], n;

void readGraph() {
    int edges, u, v;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &edges);

    // Initialize all to 0 (no paths)
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            graph[i][j] = 0;

    printf("Enter edges as pairs (u v):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        graph[u][v] = 1; // direct path exists
    }
}

void warshall() {
    for (int k = 0; k < n; k++)         // Intermediate
        for (int i = 0; i < n; i++)     // From node
            for (int j = 0; j < n; j++) // To node
                graph[i][j] = graph[i][j] || (graph[i][k] && graph[k][j]);
}

void printMatrix() {
    printf("Transitive closure matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", graph[i][j]);
        printf("\n");
    }
}

int main() {
    readGraph();
    warshall();
    printMatrix();
    return 0;
}
