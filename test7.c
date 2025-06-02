#include <stdio.h>

int main() {
    int n, p[10], w[10], used[10] = {0}, capacity, currentWeight;
    float totalProfit = 0;

    printf("Enter number of items: ");
    scanf("%d", &n);
    printf("Enter weight and profit of each item:\n");
    for (int i = 0; i < n; i++)
        scanf("%d %d", &w[i], &p[i]);

    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);

    currentWeight = capacity;

    while (currentWeight > 0) {
        int best = -1;
        for (int i = 0; i < n; i++) {
            if (!used[i]) {
                if (best == -1 || (float)p[i]/w[i] > (float)p[best]/w[best])
                    best = i;
            }
        }

        used[best] = 1;

        if (w[best] <= currentWeight) {
            currentWeight -= w[best];
            totalProfit += p[best];
            printf("Added full item %d\n", best + 1);
        } else {
            float fraction = (float)currentWeight / w[best];
            totalProfit += p[best] * fraction;
            printf("Added %.2f of item %d\n", fraction, best + 1);
            break;
        }
    }

    printf("Total profit = %.2f\n", totalProfit);
    return 0;
}
