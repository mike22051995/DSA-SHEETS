# Task Scheduler

## Description
Given a list of CPU tasks and a cooldown n, return the minimum time units to
finish all tasks. The same task must be separated by at least n units.

## Input Format
- tasks: list of uppercase letters
- n: non-negative integer cooldown

## Output Format
- minimum total time units

## Approach
- Greedy math: arrange the most frequent tasks first and count idle slots.
- Heap simulation: process cycles of size n+1 using a max-heap of frequencies.

## Complexity
- Time: O(N)
- Space: O(1) to O(26)

## Sample Input/Output

Sample 1
```
Input:  tasks = [A,A,A,B,B,B], n = 2
Output: 8
```

Sample 2
```
Input:  tasks = [A,A,A,B,B,B], n = 0
Output: 6
```

Sample 3
```
Input:  tasks = [A,A,A,A,B,B,B,C,C], n = 2
Output: 10
```

Sample 4
```
Input:  tasks = [A,A,A,A,A,A,B,C,D,E,F,G], n = 2
Output: 16
```

Sample 5
```
Input:  tasks = [A,B,C,D], n = 3
Output: 4
```
