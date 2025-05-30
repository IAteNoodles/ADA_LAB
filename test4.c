#include <stdio.h>
#define INF 9999
#define MAX 10

int cost[MAX][MAX], distance[MAX], visited[MAX], n;

void readGraph() {
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter cost adjacency matrix (0 if no edge):\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            if (i != j && cost[i][j] == 0)
                cost[i][j] = INF;
        }
}

void dijkstra(int source) {
    for (int i = 0; i < n; i++) {
        distance[i] = cost[source][i];  // Direct distance
        visited[i] = 0;
    }
    distance[source] = 0;
    visited[source] = 1;

    for (int count = 1; count < n; count++) {
        int min = INF, u;
        // Find the unvisited vertex with smallest distance
        for (int i = 0; i < n; i++)
            if (!visited[i] && distance[i] < min) {
                min = distance[i];
                u = i;
            }

        visited[u] = 1;

        // Relaxation: update distances from u
        for (int v = 0; v < n; v++)
            if (!visited[v] && distance[u] + cost[u][v] < distance[v])
                distance[v] = distance[u] + cost[u][v];
    }

    printf("Shortest distances from node %d:\n", source);
    for (int i = 0; i < n; i++)
        printf("To %d = %d\n", i, distance[i]);
}

int main() {
    readGraph();
    int source;
    printf("Enter source vertex: ");
    scanf("%d", &source);
    dijkstra(source);
    return 0;
}
