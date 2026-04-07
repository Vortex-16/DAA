#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i;
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

    int max = arr[0];
    int min = arr[0];

    for (i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    printf("Maximum element: %d\n", max);
    printf("Minimum element: %d\n", min);

    free(arr);
    return 0;
}


/*
The no. of comparisons required to solve this problem is: 
1. Recurense Relation: T(n) = 2T(n/2) + 2
   - n/2: for finding max and min in the left half
    - n/2: for finding max and min in the right half
    - 2: for comparing the max and min of the left and right halves
2. Solving the recurrence relation using the Master Theorem:
   - a = 2 (number of subproblems)
    - b = 2 (size of each subproblem)
    - f(n) = 2 (the cost of combining the results)
    - Since f(n) = O(n^log_b(a)) = O(n^log_2(2)) = O(n), we are in the case where f(n) is polynomially larger than n^log_b(a).
    - Therefore, T(n) = O(f(n)) = O(n).
*/