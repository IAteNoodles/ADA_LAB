#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void swap(int* a, int* b)
{
int t = *a;
*a = *b;
*b = t;
}
int partition(int arr[], int low, int high)
{
int pivot = arr[high];
int i = (low - 1);
for (int j = low; j <= high - 1; j++)
{
if (arr[j] < pivot)
{
i++;
swap(&arr[i], &arr[j]);
}
}
swap(&arr[i + 1], &arr[high]);
return (i + 1);
}
void quickSort(int arr[], int low, int high)
{
if (low < high)
{
int pi = partition(arr, low, high);
quickSort(arr, low, pi - 1);
quickSort(arr, pi + 1, high);
}
}
void generateRandomNumbers(int arr[], int n)
{
for (int i = 0; i < n; i++)
{
arr[i] = rand() % 100000;
}
}
int main()
{
int n;
printf("Enter number of elements: ");
scanf("%d", &n);
if (n <= 5000)
{
printf("Please enter a value greater than 5000\n");
return 1;
}
int *arr = (int *)malloc(n * sizeof(int));
if (arr == NULL)
{
printf("Memory allocation failed\n");
return 1;
}
generateRandomNumbers(arr, n);
for(int i = 0; i<n;i++)
{
printf("%d ", arr[i]);
}
printf("\n\n");
clock_t start = clock();
quickSort(arr, 0, n - 1);
clock_t end = clock();
double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
printf("Time taken to sort %d elements: %f seconds\n", n, time_taken);
printf("\n\n");
for(int i = 0; i<n;i++)
{
printf("%d ", arr[i]);
}
free(arr);
return 0;
}