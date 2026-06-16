# Meeting Rooms II

## Description
Given meeting time intervals, return the minimum number of rooms required.

## Input Format
- intervals: list of [start, end] pairs

## Output Format
- single integer = minimum rooms needed

## Approach (Heap)
- Sort intervals by start time.
- Use a min-heap of end times; reuse a room if the earliest end <= next start.
- Heap size is the number of rooms in use.

## Complexity
- Time: O(n log n)
- Space: O(n)

## Sample Input/Output

Sample 1
```
Input:  intervals = [[0,30],[5,10],[15,20]]
Output: 2
```

Sample 2
```
Input:  intervals = [[7,10],[2,4]]
Output: 1
```

Sample 3
```
Input:  intervals = [[1,5],[8,9],[8,9]]
Output: 2
```

Sample 4
```
Input:  intervals = [[1,4],[2,3],[3,5]]
Output: 2
```

Sample 5
```
Input:  intervals = [[1,2],[2,3],[3,4],[4,5]]
Output: 1
```
