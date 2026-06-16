# Reorganize String

## Description
Rearrange a string so that no two adjacent characters are the same. If
impossible, return an empty string.

## Input Format
- s: input string

## Output Format
- reorganized string or empty string

## Approach (Heap)
- Count frequencies and use a max-heap by count.
- Always place the most frequent character, then reinsert the previous one.

## Complexity
- Time: O(n log sigma)
- Space: O(sigma)

## Sample Input/Output

Sample 1
```
Input:  s = "aab"
Output: "aba"
```

Sample 2
```
Input:  s = "aaab"
Output: ""
```

Sample 3
```
Input:  s = "vvvlo"
Output: "vlvov"
```

Sample 4
```
Input:  s = "aabb"
Output: "abab"
```

Sample 5
```
Input:  s = "aaabc"
Output: "abaca"
```
