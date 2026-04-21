#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/resource.h>

// Structure to return both min and max
struct Pair {
    int min;
    int max;
};

struct Pair maxMin(int arr[], int low, int high) {
    struct Pair result, left, right;
    int mid;

    // Base case: one element
    if (low == high) {
        result.min = arr[low];
        result.max = arr[low];
        return result;
    }

    // Base case: two elements
    if (high == low + 1) {
        if (arr[low] < arr[high]) {
            result.min = arr[low];
            result.max = arr[high];
        } else {
            result.min = arr[high];
            result.max = arr[low];
        }
        return result;
    }

    // Divide
    mid = (low + high) / 2;

    // Conquer
    left = maxMin(arr, low, mid);
    right = maxMin(arr, mid + 1, high);

    // Combine
    result.min = (left.min < right.min) ? left.min : right.min;
    result.max = (left.max > right.max) ? left.max : right.max;

    return result;
}

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // ⏱ Start time
    clock_t start = clock();

    struct Pair result = maxMin(arr, 0, n - 1);

    // ⏱ End time
    clock_t end = clock();

    double cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;

    // Memory usage
    struct rusage usage;
    getrusage(RUSAGE_SELF, &usage);

    printf("Minimum element: %d\n", result.min);
    printf("Maximum element: %d\n", result.max);
    printf("CPU Time Used: %f seconds\n", cpu_time);
    printf("Memory Usage (Max Resident Set Size): %ld KB\n", usage.ru_maxrss);

    free(arr);
    return 0;
}