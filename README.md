# Design And Analysis Of Algorithms (DAA)

This repository contains C implementations of fundamental algorithmic techniques:

1. Binary search with different sorting strategies.
2. Greedy algorithms.
3. Maximum-minimum finding methods.

Each module includes standalone programs that take console input and print execution details. Most programs also report CPU time and memory usage.

## Repository Structure

- [BinarySearch(Sorting)/](BinarySearch(Sorting)/)
- [Greedy/](Greedy/)
- [MaxMin/](MaxMin/)

## 1) Binary Search (Sorting)

Folder: [BinarySearch(Sorting)/](BinarySearch(Sorting)/)

Contains programs that perform binary search in different scenarios, including preprocessing with Bubble Sort, Merge Sort, and Quick Sort variants, plus a Heap Sort implementation.

Files:

- [BinarySearch(Sorting)/Binary_Search(Unsorted element).c](BinarySearch(Sorting)/Binary_Search(Unsorted%20element).c)
- [BinarySearch(Sorting)/Binary_Search(Sorted elemnts).c](BinarySearch(Sorting)/Binary_Search(Sorted%20elemnts).c)
- [BinarySearch(Sorting)/Binary_Search(Merge Sort)).c](BinarySearch(Sorting)/Binary_Search(Merge%20Sort%29%29.c)
- [BinarySearch(Sorting)/Binary_Search(Quick-Sort-Pivot(high)).c](BinarySearch(Sorting)/Binary_Search(Quick-Sort-Pivot(high)).c)
- [BinarySearch(Sorting)/Binary_Search(Quick-Sort-Pivot(Low)).c](BinarySearch(Sorting)/Binary_Search(Quick-Sort-Pivot(Low)).c)
- [BinarySearch(Sorting)/HeapSort.c](BinarySearch(Sorting)/HeapSort.c)

Detailed notes and examples: [BinarySearch(Sorting)/README.md](BinarySearch(Sorting)/README.md)

## 2) Greedy

Folder: [Greedy/](Greedy/)

Contains greedy strategy implementations:

- [Greedy/CoinDenomination.c](Greedy/CoinDenomination.c) - Coin change using largest denomination first.
- [Greedy/FractionalKnapsack.c](Greedy/FractionalKnapsack.c) - Fractional knapsack by value-to-weight ratio.

Detailed notes and examples: [Greedy/README.md](Greedy/README.md)

## 3) MaxMin

Folder: [MaxMin/](MaxMin/)

Contains two approaches for finding minimum and maximum values in an array:

- [MaxMin/MaxMin_Ussing_Ittreative.c](MaxMin/MaxMin_Ussing_Ittreative.c)
- [MaxMin/MaxMin_Ussing_Dvide&Conquer.c](MaxMin/MaxMin_Ussing_Dvide&Conquer.c)

Detailed notes and examples: [MaxMin/README.md](MaxMin/README.md)

## Build And Run (General)

Use GCC to compile any program, then execute the output binary.

```bash
gcc <source_file>.c -o <program_name>
./<program_name>
```

Example:

```bash
gcc Greedy/FractionalKnapsack.c -o fractional_knapsack
./fractional_knapsack
```

## Requirements

- GCC (or any C compiler)
- Linux/macOS/Windows terminal

## Learning Goals

- Understand asymptotic analysis in practical implementations.
- Compare iterative, divide-and-conquer, and greedy methods.
- Observe how input size affects runtime and memory usage.
