# Find Median from Data Stream

## Description
Design a data structure that supports adding numbers and retrieving the median.

## Input Format
- stream of integers, inserted one by one

## Output Format
- median as a double after queries

## Approach (Two Heaps)
- Max-heap for the lower half, min-heap for the upper half.
- Keep sizes balanced so max-heap has either equal or one extra element.
- Median is top of max-heap, or average of both tops.

## Complexity
- addNum: O(log n)
- findMedian: O(1)
- Space: O(n)

## Sample Input/Output

Sample 1
```
Input:  stream = [1,2]
Output: median = 1.5
```

Sample 2
```
Input:  stream = [1,2,3]
Output: median = 2
```

Sample 3
```
Input:  stream = [5]
Output: median = 5
```

Sample 4
```
Input:  stream = [2,3,4,5]
Output: median = 3.5
```

Sample 5
```
Input:  stream = [1,1,1,1]
Output: median = 1
```
