#include <stdio.h>

int set[10], tempSet[10], n, target, found = 0;

void display(int count) {
    printf("{ ");
    for (int i = 0; i < count; i++)
        printf("%d ", tempSet[i]);
    printf("}\n");
}

void subsetSum(int index, int sum, int count) {
    if (sum == target) {
        found = 1;
        display(count);
        return;
    }
    if (sum > target || index == n)
        return;

    tempSet[count] = set[index];
    subsetSum(index + 1, sum + set[index], count + 1);  // Include
    subsetSum(index + 1, sum, count);                  // Exclude
}

int main() {
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &set[i]);
    printf("Enter target sum: ");
    scanf("%d", &target);

    printf("Subsets that sum to %d are:\n", target);
    subsetSum(0, 0, 0);
    if (!found)
        printf("No subset found.\n");
    return 0;
}
