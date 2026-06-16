# Kth Largest Element in Stream

## Description
Maintain the k-th largest element as numbers are added to a stream.

## Input Format
- k: rank of the largest element to track
- nums: initial list of integers
- add(val): insert val and return current k-th largest

## Output Format
- integer after each add operation

## Approach (Min-Heap)
- Keep a min-heap of size k containing the k largest seen elements.
- The heap top is always the k-th largest.

## Complexity
- add: O(log k)
- Space: O(k)

## Sample Input/Output

Sample 1
```
Input:  k = 3, nums = [4,5,8,2], adds = [3,5,10,9,4]
Output: [4,5,5,8,8]
```

Sample 2
```
Input:  k = 1, nums = [], adds = [-1,-2,-3]
Output: [-1,-1,-1]
```

Sample 3
```
Input:  k = 2, nums = [0], adds = [-1,1]
Output: [-1,0]
```

Sample 4
```
Input:  k = 3, nums = [5,-1,2], adds = [4]
Output: [2]
```

Sample 5
```
Input:  k = 4, nums = [10,9,8,7], adds = [6,5]
Output: [7,7]
```
