"""
PROBLEM: Minimum Operations to Make Array Equal (LeetCode 1551)
DIFFICULTY: Easy
PATTERN: Mathematical Greedy (Median/Mean Strategy)

DESCRIPTION:
You have an array arr of length n where arr[i] = (2 * i) + 1 for all valid values of i 
(i.e., 0 <= i < n). In one operation, you can select two indices x and y where 0 <= x, y < n 
and subtract 1 from arr[x] and add 1 to arr[y] (i.e., arr[x] -= 1 and arr[y] += 1).
The goal is to make all the elements of the array equal. Return the minimum number of operations.

INPUT:
- n: length of array (array is [1, 3, 5, 7, ..., 2n-1])

OUTPUT:
- Minimum operations to make all elements equal

APPROACH:
Array is [1, 3, 5, ..., 2n-1]
- All elements should become equal to median (which equals n)
- Sum of differences from median gives answer
- Mathematical formula: for n even: n²/4, for n odd: (n²-1)/4

WHY GREEDY WORKS:
Optimal target is always the median. Moving values toward median minimizes total operations.
"""

from typing import List, Optional

class Solution:
    def minOperations(self, n):
        # Formula derivation:
        # Array: [1, 3, 5, ..., 2n-1]
        # Target: each element becomes n
        # Operations = sum of |arr[i] - n| / 2
        # Mathematical formula:
        if n % 2 == 0:
        return (n * n) / 4
        } else 
        return (n * n - 1) / 4


if __name__ == "__main__":
    sol = Solution()
    print(f"Test 1 - n=3 (array [1,3,5])")
    print(f"Output: {sol.minOperations(3)}")
    print(f"Expected: 2 (make all elements 3)")
    print(f"Test 2 - n=6 (array [1,3,5,7,9,11])")
    print(f"Output: {sol.minOperations(6)}")
    print(f"Expected: 9 (make all elements 6)")
    print(f"Test 3 - n=4 (array [1,3,5,7])")
    print(f"Output: {sol.minOperations(4)}")
    print(f"Expected: 4 (make all elements 4)")
    print(f"Test 4 - n=1 (array [1])")
    print(f"Output: {sol.minOperations(1)}")
    print(f"Expected: 0")
