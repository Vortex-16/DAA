# Greedy Algorithms In C

This folder contains two C programs that implement classic greedy strategies, along with CPU time and memory usage reporting.

Program list:

1. [CoinDenomination.c](CoinDenomination.c) - Greedy coin selection for a target amount.
2. [FractionalKnapsack.c](FractionalKnapsack.c) - Fractional knapsack using value/weight ratio.

## 1) Coin Denomination Problem

### Problem Statement

Given available coin denominations and a target amount, choose coins greedily (largest denomination first) until the amount is formed as much as possible.

### Algorithm In Pseudocode

```text
read n
read coins[0..n-1]
sort coins in nondecreasing order
read amount

count <- 0
for i from n-1 down to 0
    while amount >= coins[i]
        amount <- amount - coins[i]
        output coins[i]
        count <- count + 1

if amount != 0
    report remaining amount cannot be formed
print count
print CPU time and memory usage
```

### Build And Run

```bash
gcc CoinDenomination.c -o coin_denomination
./coin_denomination
```

### Sample Input And Output

```text
Enter number of coins: 4
Enter coin denominations: 1 2 5 10
Sorted coin denominations: 1 2 5 10
Enter amount: 28
Coins used: 10 10 5 2 1
Total coins used = 5
Execution Time: 0.000003 seconds
Memory Usage: 3048 KB
```

### Complexity

```text
Sorting: O(n log n)
Selection loop: O(n + k), where k is number of selected coins
Overall: O(n log n + k)
Extra space: O(1) auxiliary (excluding input storage)
```

## 2) Fractional Knapsack

### Problem Statement

Given item weights and values and a knapsack capacity, maximize value by taking whole items or fractions of items.

### Algorithm In Pseudocode

```text
read n
read item pairs (weight, value)
read capacity
sort items by value/weight in descending order

totalValue <- 0
for each item in sorted order
    if capacity >= item.weight
        take full item
        capacity <- capacity - item.weight
        totalValue <- totalValue + item.value
    else
        take fraction = capacity / item.weight
        totalValue <- totalValue + fraction * item.value
        break

print totalValue
print CPU time and memory usage
```

### Build And Run

```bash
gcc FractionalKnapsack.c -o fractional_knapsack
./fractional_knapsack
```

### Sample Input And Output

```text
Enter number of items: 3
Enter weight and value of each item:
10 60
20 100
30 120
Enter knapsack capacity: 50
Maximum value in Knapsack = 240.00
Execution Time: 0.000004 seconds
Memory Usage: 3056 KB
```

### Complexity

```text
Sorting: O(n log n)
Single pass fill: O(n)
Overall: O(n log n)
Extra space: O(1) auxiliary (excluding input storage)
```

## Notes

The coin denomination greedy strategy is optimal only for canonical coin systems (for example, common currency systems such as 1, 2, 5, 10). For arbitrary coin sets, greedy may not always produce the minimum number of coins.
