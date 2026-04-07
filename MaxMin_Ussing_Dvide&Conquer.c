#include <stdio.h>
#include <stdlib.h>
struct Pair {
    int min;
    int max;
};

struct Pair findMinMax(int arr[], int low, int high) {
    struct Pair result, left, right, midPair;
    int mid;

    // Base case: only one element
    if (low == high) {
        result.min = result.max = arr[low];
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
    left = findMinMax(arr, low, mid);
    right = findMinMax(arr, mid + 1, high);

    // Combine
    result.min = (left.min < right.min) ? left.min : right.min;
    result.max = (left.max > right.max) ? left.max : right.max;

    return result;
}

int main() {
    int n,i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct Pair ans = findMinMax(arr, 0, n - 1);

    printf("Minimum: %d\n", ans.min);
    printf("Maximum: %d\n", ans.max);

    return 0;
}


/*
Recurrence Relation: T(n) = 2T(n/2) + 2
- n/2: for finding max and min in the left half
- n/2: for finding max and min in the right half
- 2: for comparing the max and min of the left and right halves
Solving the recurrence relation using the Master Theorem:
- a = 2 (number of subproblems)
- b = 2 (size of each subproblem)
- f(n) = 2 (the cost of combining the results)
- Since f(n) = O(n^log_b(a)) = O(n^log_2(2)) = O(n), we are in the case where f(n) is polynomially larger than n^log_b(a).
- Therefore, T(n) = O(f(n)) = O(n).
*/