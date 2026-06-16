"""
PROBLEM: Check if ith Bit is Set
==================================
Given a number n and an index i, check if the ith bit is set (1) or not (0).

APPROACH:
- Method 1: Left shift 1 by i positions and AND with n
- Method 2: Right shift n by i positions and AND with 1

PATTERN: Bit Checking - Single Bit Operations

INPUT/OUTPUT:
Input: n = 5, i = 0
Output: True
Explanation: 5 in binary is 101, 0th bit (rightmost) is 1

Input: n = 5, i = 1
Output: False
Explanation: 5 in binary is 101, 1st bit is 0

Input: n = 5, i = 2
Output: True
Explanation: 5 in binary is 101, 2nd bit is 1

TIME COMPLEXITY: O(1)
SPACE COMPLEXITY: O(1)
"""

from typing import List, Optional

class Solution:
    def isSetMethod1(self, n, i):
        return (n & (1 << i)) != 0


if __name__ == "__main__":
    sol = Solution()
    n = 5; # Binary: 101
    print(f"Number: {n}")
    i1 = 0
    print(f"Check bit at position {i1}")
    print(f"Output: {(sol.isSetMethod1(n,}")
    print(f"Explanation: Rightmost bit (position 0) is 1")
    i2 = 1
    print(f"Check bit at position {i2}")
    print(f"Output: {(sol.isSetMethod1(n,}")
    print(f"Explanation: Middle bit (position 1) is 0")
    i3 = 2
    print(f"Check bit at position {i3}")
    print(f"Output: {(sol.isSetMethod1(n,}")
    print(f"Explanation: Leftmost bit (position 2) is 1")
