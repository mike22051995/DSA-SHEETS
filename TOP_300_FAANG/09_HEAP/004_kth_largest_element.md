# Kth Largest Element in Array

## Description
Find the k-th largest element in an unsorted array.

## Input Format
- nums: list of integers
- k: 1-based rank for largest element

## Output Format
- integer value of the k-th largest element

## Approach (Min-Heap)
- Maintain a min-heap of size k.
- Push each number; if size exceeds k, pop the smallest.
- Heap top is the k-th largest.

## Complexity
- Time: O(n log k)
- Space: O(k)

## Sample Input/Output

Sample 1
```
Input:  nums = [3,2,1,5,6,4], k = 2
Output: 5
```

Sample 2
```
Input:  nums = [3,2,3,1,2,4,5,5,6], k = 4
Output: 4
```

Sample 3
```
Input:  nums = [1], k = 1
Output: 1
```

Sample 4
```
Input:  nums = [7,6,5,4,3,2,1], k = 7
Output: 1
```

Sample 5
```
Input:  nums = [2,1], k = 1
Output: 2
```
