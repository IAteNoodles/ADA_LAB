#include <stdio.h>

#define INF 999

int cost[10][10], n;

void readGraph() {
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter cost adjacency matrix (0 if no edge):\n");
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0 && i != j)
                cost[i][j] = INF;
        }
}

void prim() {
    int selected[10] = {0};
    int no_of_edges = 0, mincost = 0;

    selected[1] = 1; // Start from vertex 1

    printf("Edges in MST:\n");

    while (no_of_edges < n - 1) {
        int min = INF, a = -1, b = -1;

        for (int i = 1; i <= n; i++) {
            if (selected[i]) {
                for (int j = 1; j <= n; j++) {
                    if (!selected[j] && cost[i][j] < min) {
                        min = cost[i][j];
                        a = i;
                        b = j;
                    }
                }
            }
        }

        if (a != -1 && b != -1) {
            printf("(%d, %d) = %d\n", a, b, min);
            selected[b] = 1;
            mincost += min;
            no_of_edges++;
        }
    }

    printf("Minimum cost = %d\n", mincost);
}

int main() {
    readGraph();
    prim();
    return 0;
}
