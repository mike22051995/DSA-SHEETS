"""
PROBLEM: Sum of Subarray Minimums (LeetCode 907)
DIFFICULTY: Hard
PATTERN: Monotonic Stack for Contribution Counting

DESCRIPTION:
Given an array of integers arr, find the sum of min(b), where b ranges over every 
(contiguous) subarray of arr. Since the answer may be large, return the answer modulo 10^9 + 7.

INPUT: arr = [3,1,2,4]
OUTPUT: 17
Explanation: 
Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4]
Minimums are  3,   1,   2,   4,    1,     1,     2,      1,       1,       1
Sum = 17

TIME COMPLEXITY: O(n) where n is the length of array
SPACE COMPLEXITY: O(n) for the stacks

EXPLANATION:
For each element, calculate how many subarrays it is the minimum of.
Use two monotonic stacks to find:
- Previous Less Element (PLE): nearest smaller element to the left
- Next Less Element (NLE): nearest smaller element to the right
For each element, contribution = arr[i] * (i - PLE[i]) * (NLE[i] - i)
"""



from typing import List


def sumSubarrayMins(arr: List[int]) -> int:
    MOD = 10**9 + 7
    n = len(arr)
    left = [0] * n   # distance to previous less element
    right = [0] * n  # distance to next less element
    stack = []

    # Previous less element
    for i in range(n):
        while stack and arr[stack[-1]] > arr[i]:
            stack.pop()
        left[i] = i - stack[-1] if stack else i + 1
        stack.append(i)

    stack.clear()

    # Next less element (use >= for duplicates)
    for i in range(n - 1, -1, -1):
        while stack and arr[stack[-1]] >= arr[i]:
            stack.pop()
        right[i] = stack[-1] - i if stack else n - i
        stack.append(i)

    result = 0
    for i in range(n):
        result = (result + arr[i] * left[i] * right[i]) % MOD

    return result


if __name__ == "__main__":
    test_cases = [
        [3, 1, 2, 4],
        [11, 81, 94, 43, 3],
        [71, 55, 82, 55],
        [1, 2, 3, 4, 5],
    ]
    for arr in test_cases:
        result = sumSubarrayMins(arr)
        print(f"Array: {arr}")
        print(f"Sum of subarray minimums: {result}")
        print()
