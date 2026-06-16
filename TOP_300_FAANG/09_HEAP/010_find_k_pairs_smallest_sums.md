# Find K Pairs with Smallest Sums

## Description
Return the k pairs (u,v) with the smallest sums from two sorted arrays.

## Input Format
- nums1: sorted list of integers
- nums2: sorted list of integers
- k: number of pairs to return

## Output Format
- list of pairs, ordered by non-decreasing sum

## Approach (Min-Heap)
- Push (i,0) for the first min(k, n1) rows.
- Pop smallest sum and push (i, j+1) to advance in nums2.

## Complexity
- Time: O(k log min(n1, k))
- Space: O(min(n1, k))

## Sample Input/Output

Sample 1
```
Input:  nums1 = [1,7,11], nums2 = [2,4,6], k = 3
Output: [[1,2],[1,4],[1,6]]
```

Sample 2
```
Input:  nums1 = [1,1,2], nums2 = [1,2,3], k = 2
Output: [[1,1],[1,1]]
```

Sample 3
```
Input:  nums1 = [1,2], nums2 = [3], k = 3
Output: [[1,3],[2,3]]
```

Sample 4
```
Input:  nums1 = [-1,0,1], nums2 = [-2,3], k = 4
Output: [[-1,-2],[0,-2],[1,-2],[-1,3]]
```

Sample 5
```
Input:  nums1 = [1], nums2 = [1], k = 1
Output: [[1,1]]
```
