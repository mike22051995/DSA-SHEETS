# Minimum Cost to Hire K Workers

## Description
Hire exactly k workers with minimum total cost. Each worker must be paid at least
their wage, and pay is proportional to quality for all chosen workers.

## Input Format
- quality: list of worker quality
- wage: list of minimum wage
- k: number of workers to hire

## Output Format
- minimum possible total cost (double)

## Approach
- Sort workers by wage/quality ratio.
- Maintain a max-heap of qualities to keep the smallest total quality for k.
- For each ratio, compute cost = ratio * sum(qualities).

## Complexity
- Time: O(n log n)
- Space: O(n)

## Sample Input/Output

Sample 1
```
Input:  quality = [10,20,5], wage = [70,50,30], k = 2
Output: 105.0
```

Sample 2
```
Input:  quality = [3,1,10,10,1], wage = [4,8,2,2,7], k = 3
Output: 30.6667
```

Sample 3
```
Input:  quality = [5,5,5], wage = [10,10,10], k = 2
Output: 20.0
```

Sample 4
```
Input:  quality = [4,8,2,6], wage = [8,16,6,12], k = 2
Output: 18.0
```

Sample 5
```
Input:  quality = [1,2,3], wage = [5,6,9], k = 2
Output: 15.0
```
