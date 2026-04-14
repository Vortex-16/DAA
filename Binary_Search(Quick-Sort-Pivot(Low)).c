#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/resource.h>

// Quick Sort Partition 
int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low + 1;
    int j = high;

    while (1) {
        while (i <= high && arr[i] <= pivot)
            i++;

        while (arr[j] > pivot)
            j--;

        if (i >= j)
            break;

        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    // Place pivot in correct position
    int temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;

    return j;
}

// Quick Sort Function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int p = partition(arr, low, high);
        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}

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

    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    // Sort using Quick Sort
    quickSort(arr, 0, n - 1);

    printf("Enter element to search: ");
    scanf("%d", &key);

    // ⏱ Start CPU time
    clock_t start = clock();

    int result = binarySearch(arr, 0, n - 1, key);

    // ⏱ End CPU time
    clock_t end = clock();

    double cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;

    // Memory usage
    struct rusage usage;
    getrusage(RUSAGE_SELF, &usage);

    // Output
    if (result != -1)
        printf("Element found at index %d\n", result);
    else
        printf("Element not found\n");

    printf("CPU Time Used: %f seconds\n", cpu_time);
    printf("Memory Usage (Max Resident Set Size): %ld KB\n", usage.ru_maxrss);

    free(arr);
    return 0;
}