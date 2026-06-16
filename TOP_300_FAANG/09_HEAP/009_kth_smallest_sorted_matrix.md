# Kth Smallest Element in a Sorted Matrix

## Description
Given an n x n matrix where rows and columns are sorted, return the k-th
smallest element.

## Input Format
- matrix: n x n sorted rows and columns
- k: 1-based index

## Output Format
- integer value of the k-th smallest element

## Approach
- Heap: keep a max-heap of size k while scanning all elements.
- Binary search: count numbers <= mid using a staircase walk.

## Complexity
- Heap: O(n^2 log k) time, O(k) space
- Binary search: O(n log range) time, O(1) space

## Sample Input/Output

Sample 1
```
Input:  matrix = [[1,5,9],[10,11,13],[12,13,15]], k = 8
Output: 13
```

Sample 2
```
Input:  matrix = [[-5]], k = 1
Output: -5
```

Sample 3
```
Input:  matrix = [[1,2],[1,3]], k = 2
Output: 1
```

Sample 4
```
Input:  matrix = [[1,3,5],[6,7,12],[11,14,14]], k = 6
Output: 11
```

Sample 5
```
Input:  matrix = [[1,2,3],[2,3,4],[3,4,5]], k = 5
Output: 3
```
