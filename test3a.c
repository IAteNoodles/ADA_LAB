#include <stdio.h>
#define INF 999

int cost[10][10], n;

void readGraph() {
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter weighted matrix (0 if no direct path, INF = 999):\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            if (i != j && cost[i][j] == 0)
                cost[i][j] = INF;
        }
}

void floyd() {
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (cost[i][j] > cost[i][k] + cost[k][j])
                    cost[i][j] = cost[i][k] + cost[k][j];

    printf("All-Pairs Shortest Path Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%4d ", cost[i][j]);
        printf("\n");
    }
}

int main() {
    readGraph();
    floyd();
    return 0;
}
