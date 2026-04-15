#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/resource.h>

// Merge function
void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Temporary arrays
    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    // Copy remaining elements
    while (i < n1)
        arr[k++] = L[i++];

    while (j < n2)
        arr[k++] = R[j++];

    free(L);
    free(R);
}

// Merge Sort function
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
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

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    // ⏱ Start CPU time for sorting
    clock_t sort_start = clock();

    mergeSort(arr, 0, n - 1);

    clock_t sort_end = clock();
    double sort_time = ((double)(sort_end - sort_start)) / CLOCKS_PER_SEC;

    printf("Enter element to search: ");
    scanf("%d", &key);

    // ⏱ Start CPU time for searching
    clock_t start = clock();

    int result = binarySearch(arr, 0, n - 1, key);

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

    printf("Merge Sort Time: %f seconds\n", sort_time);
    printf("Binary Search Time: %f seconds\n", cpu_time);
    printf("Memory Usage (Max Resident Set Size): %ld KB\n", usage.ru_maxrss);

    free(arr);
    return 0;
}