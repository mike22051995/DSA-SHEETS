# FAANG Interview Preparation - Top 30 Binary Search Problems

## Overview
This collection contains 30 carefully selected binary search problems covering all essential patterns for FAANG interviews. Each problem includes:
- Problem description
- Complete C++ solution
- Detailed explanation
- Time and space complexity analysis
- 2-3 test cases with input/output examples

## Difficulty Levels

### Easy (Problems 1-10)
Foundation problems covering basic binary search techniques:
1. **Binary Search** - Classic implementation
2. **Search Insert Position** - Finding insert position
3. **First Bad Version** - Binary search on answer
4. **Sqrt(x)** - Binary search for square root
5. **Search in Rotated Sorted Array** - Modified binary search
6. **Find Minimum in Rotated Sorted Array** - Finding pivot
7. **Search a 2D Matrix** - 2D binary search
8. **Find Peak Element** - Peak finding
9. **Kth Smallest Element in a Sorted Matrix** - Binary search on value range
10. **Capacity To Ship Packages** - Binary search on capacity

### Medium (Problems 11-20)
Advanced patterns and variations:
11. **Search in Rotated Sorted Array II** - With duplicates
12. **Find First and Last Position** - Range queries
13. **Koko Eating Bananas** - Binary search on speed
14. **Minimum Days to Make Bouquets** - Binary search on days
15. **Magnetic Force Between Two Balls** - Maximizing minimum distance
16. **Split Array Largest Sum** - Minimizing maximum sum
17. **Find K Closest Elements** - Window sliding with binary search
18. **Search Suggestions System** - Binary search with prefix matching
19. **Time Based Key-Value Store** - Binary search on timestamps
20. **Single Element in Sorted Array** - Parity-based binary search

### Hard (Problems 21-30)
Complex applications requiring deep understanding:
21. **Median of Two Sorted Arrays** - Binary search on partition
22. **Aggressive Cows** - Classic distance maximization
23. **Painter's Partition** - Resource allocation
24. **Book Allocation** - Similar to painter's partition
25. **Minimize Max Distance to Gas Station** - Binary search with precision
26. **Kth Smallest in Multiplication Table** - Virtual array binary search
27. **Find K-th Smallest Pair Distance** - Counting pairs
28. **Nth Magical Number** - LCM with binary search
29. **Maximum Number of Removable Characters** - Subsequence checking
30. **Minimum Limit of Balls in Bag** - Minimizing penalty

## Key Patterns Covered

### 1. **Basic Binary Search** (Problems 1, 2, 12)
- Standard template
- Finding exact value or insert position
- Time: O(log n)

### 2. **Modified Binary Search** (Problems 5, 6, 8, 11, 20)
- Rotated arrays
- Peak finding
- Handling duplicates

### 3. **Binary Search on Answer** (Problems 3, 4, 10, 13-16, 22-25, 30)
- Search space is the answer range
- Check if answer is achievable
- Minimize/maximize objective function

### 4. **Binary Search on Value Range** (Problems 9, 26, 27)
- Search on possible values not indices
- Count elements in range
- Virtual arrays

### 5. **Binary Search on Matrix** (Problems 7, 9)
- Treat 2D as 1D
- Row and column properties

### 6. **Binary Search with Precision** (Problem 25)
- Floating point binary search
- Epsilon-based convergence

### 7. **Binary Search on Sorted Data Structures** (Problems 18, 19)
- Application in system design
- Timestamp-based queries

### 8. **Binary Search with Math** (Problems 21, 28)
- Partition-based median
- GCD/LCM calculations

## Pattern Recognition Guide

### When to Use Binary Search?
1. **Array is sorted** → Standard binary search
2. **Find minimum/maximum that satisfies condition** → Binary search on answer
3. **Rotated sorted array** → Modified binary search
4. **Find kth smallest/largest** → Binary search on value range
5. **Minimize maximum or maximize minimum** → Binary search on answer
6. **Allocate resources optimally** → Binary search on answer

### Key Template Types:

#### Type 1: Find Exact Value
```cpp
while (left <= right) {
    int mid = left + (right - left) / 2;
    if (arr[mid] == target) return mid;
    else if (arr[mid] < target) left = mid + 1;
    else right = mid - 1;
}
```

#### Type 2: Find Leftmost/Rightmost
```cpp
while (left < right) {
    int mid = left + (right - left) / 2;
    if (condition) right = mid;  // leftmost
    else left = mid + 1;
}
```

#### Type 3: Binary Search on Answer
```cpp
while (left < right) {
    int mid = left + (right - left) / 2;
    if (isPossible(mid)) right = mid;
    else left = mid + 1;
}
```

## Problem Categories

### Search Space Types:
- **Index-based**: Problems 1, 2, 5-8, 11-12, 17, 20
- **Value-based**: Problems 3, 4, 9-10, 13-16, 21-30
- **Hybrid**: Problems 18-19

### Optimization Goals:
- **Minimize Maximum**: Problems 10, 16, 23-25, 30
- **Maximize Minimum**: Problems 15, 22
- **Find Kth**: Problems 9, 21, 26-27
- **Exact Match**: Problems 1, 5, 7, 11

## Compilation Instructions

To compile any problem:
```bash
g++ -std=c++17 <filename>.cpp -o <output_name>
```

Example:
```bash
g++ -std=c++17 01_binary_search.cpp -o binary_search
./binary_search
```

## Interview Tips

### 1. **Clarify Search Space**
- What are we searching: indices or values?
- What are the boundaries?
- Are there duplicates?

### 2. **Avoid Integer Overflow**
- Use `mid = left + (right - left) / 2`
- Use long long when needed
- Be careful with sum calculations

### 3. **Handle Edge Cases**
- Empty array
- Single element
- All elements same
- Target at boundaries

### 4. **Binary Search on Answer**
- Identify if problem is monotonic
- Define isPossible() function clearly
- Determine search boundaries

### 5. **Common Mistakes to Avoid**
- Infinite loops (wrong mid calculation)
- Off-by-one errors
- Wrong boundary updates
- Not handling edge cases

## Study Strategy

### Week 1: Fundamentals (Problems 1-10)
- Master basic template
- Understand search space
- Practice rotated array problems

### Week 2: Patterns (Problems 11-20)
- Binary search on answer
- Handling duplicates
- Application problems

### Week 3: Advanced (Problems 21-30)
- Complex optimization
- Mathematical binary search
- Real-world applications

### Practice Routine:
1. **Understand the pattern** before coding
2. **Write helper functions** for isPossible checks
3. **Test with edge cases** first
4. **Analyze time complexity** before optimizing

## Complexity Patterns

Most binary search problems follow:
- **Time**: O(n log m) where n = array size, m = search space
- **Space**: O(1) for iterative solutions

Specific patterns:
- Simple search: O(log n)
- Search on answer with O(n) check: O(n log m)
- Matrix problems: O(m log n) or O(n log m)

## Common Pitfalls

1. **Using `mid = (left + right) / 2`** → Can overflow
2. **Wrong loop condition** → `left < right` vs `left <= right`
3. **Not updating boundaries** → Infinite loop
4. **Forgetting to handle empty input** → Edge case
5. **Precision issues** → Use epsilon for floating point

## Good Luck! 🚀

Master these 30 problems and you'll be able to identify and solve any binary search problem in your FAANG interview. Focus on understanding the patterns rather than memorizing solutions!
