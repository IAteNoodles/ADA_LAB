#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int knapsack(int w[], int p[], int n, int capacity) {
    if (n == 0 || capacity == 0)
        return 0;

    if (w[n-1] > capacity)
        return knapsack(w, p, n - 1, capacity);

    return max(
        knapsack(w, p, n - 1, capacity),
        p[n-1] + knapsack(w, p, n - 1, capacity - w[n-1])
    );
}

int main() {
    int w[10], p[10], n, capacity;
    printf("Enter number of items: ");
    scanf("%d", &n);
    printf("Enter weight and profit of each item:\n");
    for (int i = 0; i < n; i++)
        scanf("%d %d", &w[i], &p[i]);

    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);

    int maxProfit = knapsack(w, p, n, capacity);
    printf("Maximum Profit = %d\n", maxProfit);
    return 0;
}
