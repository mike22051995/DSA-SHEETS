# Top K Frequent Elements

## Description
Return the k most frequent elements from the input array. Order can be any.

## Input Format
- nums: list of integers
- k: number of elements to return

## Output Format
- list of k integers with highest frequency (any order)

## Approach (Heap)
- Count frequencies with a hash map.
- Maintain a min-heap of size k by frequency.
- Pop the smallest frequency when size exceeds k.

## Complexity
- Time: O(n log k)
- Space: O(n)

## Sample Input/Output

Sample 1
```
Input:  nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
```

Sample 2
```
Input:  nums = [1], k = 1
Output: [1]
```

Sample 3
```
Input:  nums = [4,4,4,6,6,5,5,5,5], k = 2
Output: [5,4]
```

Sample 4
```
Input:  nums = [-1,-1,-2,-2,-2,3], k = 2
Output: [-2,-1]
```

Sample 5
```
Input:  nums = [7,7,7,7,8,8,9], k = 3
Output: [7,8,9]
```
