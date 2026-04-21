# Max-Min In C (Iterative And Divide & Conquer)

This folder contains two C programs for finding the minimum and maximum elements in an array, with CPU time and memory usage reporting.

Program list:

1. [MaxMin_Ussing_Ittreative.c](MaxMin_Ussing_Ittreative.c) - Iterative approach.
2. [MaxMin_Ussing_Dvide&Conquer.c](MaxMin_Ussing_Dvide&Conquer.c) - Divide and conquer approach.

## 1) Maximum And Minimum Using Iterative Approach

### Problem Statement

Find the maximum and minimum elements in an array using a single scan. Print CPU time and memory usage.

### Algorithm In Pseudocode

```text
read n
read array[0..n-1]

max <- array[0]
min <- array[0]

for i from 1 to n-1
    if array[i] > max
        max <- array[i]
    if array[i] < min
        min <- array[i]

print max and min
print CPU time and memory usage
```

### Build And Run

```bash
gcc MaxMin_Ussing_Ittreative.c -o maxmin_iterative
./maxmin_iterative
```

### Sample Input And Output

```text
Enter the number of elements: 6
Enter the elements:
12 -3 7 19 0 5
Maximum element: 19
Minimum element: -3
CPU Time Used: 0.000002 seconds
Memory Usage (Max Resident Set Size): 3052 KB
```

### Complexity

```text
Comparisons: 2n - 2
Time: Theta(n)
Space: O(1) auxiliary, plus O(n) input array
```

## 2) Maximum And Minimum Using Divide And Conquer

### Problem Statement

Find the maximum and minimum elements by recursively splitting the array into halves. Print CPU time and memory usage.

### Algorithm In Pseudocode

```text
MaxMin(arr, low, high):
    if low == high
        return (arr[low], arr[low])

    if high == low + 1
        return ordered pair of (min, max)

    mid <- (low + high) / 2
    (min1, max1) <- MaxMin(left half)
    (min2, max2) <- MaxMin(right half)

    return (min(min1, min2), max(max1, max2))
```

### Build And Run

```bash
gcc MaxMin_Ussing_Dvide\&Conquer.c -o maxmin_divide_conquer
./maxmin_divide_conquer
```

### Sample Input And Output

```text
Enter number of elements: 6
Enter elements:
12 -3 7 19 0 5
Minimum element: -3
Maximum element: 19
CPU Time Used: 0.000004 seconds
Memory Usage (Max Resident Set Size): 3052 KB
```

### Complexity

```text
Recurrence: T(n) = 2T(n/2) + O(1)
Comparisons: about 3n/2 - 2
Time: Theta(n)
Space: O(log n) recursion stack, plus O(n) input array
```

## Comparison Summary

| Method | Comparisons | Time Complexity | Extra Space |
|---|---:|---:|---:|
| Iterative | 2n - 2 | Theta(n) | O(1) |
| Divide and Conquer | around 3n/2 - 2 | Theta(n) | O(log n) |

Both methods are linear in time. Divide and conquer usually performs fewer comparisons, while the iterative approach uses constant auxiliary space.