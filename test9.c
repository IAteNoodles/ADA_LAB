#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selectionSort(int arr[], int n) {
    int i, j, minIdx, temp;

    for (i = 0; i < n - 1; i++) {
        minIdx = i;

        // Find the smallest element in the unsorted part
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx])
                minIdx = j;
        }

        // Swap the found minimum with current element
        temp = arr[minIdx];
        arr[minIdx] = arr[i];
        arr[i] = temp;
    }
}

int main() {
    int n = 6000;
    int arr[n];

    // Fill array with random numbers
    srand(time(NULL));
    for (int i = 0; i < n; i++)
        arr[i] = rand() % 1000;

    // Measure time
    clock_t start = clock();
    selectionSort(arr, n);
    clock_t end = clock();

    double timeTaken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Time taken to sort %d elements: %f seconds\n", n, timeTaken);

    return 0;
}
