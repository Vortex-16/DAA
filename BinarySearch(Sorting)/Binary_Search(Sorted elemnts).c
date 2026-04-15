#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/resource.h>
// Binary Search Function
int binarySearch(int arr[], int left, int right, int key) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}
int main() {
    int n, key;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    printf("Enter sorted elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    printf("Enter element to search: ");
    scanf("%d", &key);
    // ⏱Start CPU time
    clock_t start = clock();
    int result = binarySearch(arr, 0, n - 1, key);
    // End CPU time
    clock_t end = clock();
    // CPU time used
    double cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    // Memory usage
    struct rusage usage;
    getrusage(RUSAGE_SELF, &usage);
    // Output results
    if (result != -1)
        printf("Element found at index %d\n", result);
    else
        printf("Element not found\n");
    printf("CPU Time Used: %f seconds\n", cpu_time);
    printf("Memory Usage (Max Resident Set Size): %ld KB\n", usage.ru_maxrss);
    // Free memory
    free(arr);
    return 0;
}