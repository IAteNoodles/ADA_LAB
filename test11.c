#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int arr[], int left, int mid, int right) {
    int i = left, j = mid + 1, k = 0;
    int size = right - left + 1;
    int *temp = (int *)malloc(size * sizeof(int));

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while (i <= mid)
        temp[k++] = arr[i++];

    while (j <= right)
        temp[k++] = arr[j++];

    // Copy back to original array
    for (i = 0; i < size; i++)
        arr[left + i] = temp[i];

    free(temp);
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;

        mergeSort(arr, left, mid);       // Sort left half
        mergeSort(arr, mid + 1, right);  // Sort right half
        merge(arr, left, mid, right);    // Merge both halves
    }
}

int main() {
    int n;
    printf("Enter the number of elements (must be > 5000): ");
    scanf("%d", &n);

    if (n <= 5000) {
        printf("Please enter a value greater than 5000.\n");
        return 1;
    }

    int *arr = (int *)malloc(n * sizeof(int));
    if (!arr) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Fill array with random values
    srand(time(NULL));
    for (int i = 0; i < n; i++)
        arr[i] = rand() % 100000;

    clock_t start = clock();
    mergeSort(arr, 0, n - 1);
    clock_t end = clock();

    double timeTaken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken to sort %d elements: %f seconds\n", n, timeTaken);

    free(arr);
    return 0;
}
