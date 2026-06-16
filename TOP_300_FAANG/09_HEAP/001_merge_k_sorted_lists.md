# Merge K Sorted Lists

## Description
Merge k sorted linked lists and return a single sorted list.

## Input Format
- lists: vector of list heads, each list is sorted ascending

## Output Format
- head of the merged sorted list

## Approach (Heap)
- Push the head of each non-empty list into a min-heap by value.
- Repeatedly pop the smallest node, append to output, and push its next node.
- Continue until the heap is empty.

## Complexity
- Time: O(N log k), where N is total nodes
- Space: O(k) for the heap (excluding output list)

## Sample Input/Output

Sample 1
```
Input:  lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
```

Sample 2
```
Input:  lists = [[],[1],[0,2]]
Output: [0,1,2]
```

Sample 3
```
Input:  lists = [[1],[1],[1]]
Output: [1,1,1]
```

Sample 4
```
Input:  lists = [[-2,-1,3],[0,2,2],[5]]
Output: [-2,-1,0,2,2,3,5]
```

Sample 5
```
Input:  lists = []
Output: []
```
