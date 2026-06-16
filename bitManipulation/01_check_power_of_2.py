"""
PROBLEM: Check if a Number is Power of 2
=============================================
Given a positive integer n, check if it is a power of 2 or not.

APPROACH:
- A power of 2 has exactly one set bit in its binary representation
- Using n & (n-1) clears the rightmost set bit
- If result is 0, then n is a power of 2

PATTERN: Basic Bit Manipulation - Clear Rightmost Set Bit

INPUT/OUTPUT:
Input: n = 16
Output: True
Explanation: 16 = 2^4

Input: n = 18
Output: False
Explanation: 18 is not a power of 2

TIME COMPLEXITY: O(1)
SPACE COMPLEXITY: O(1)
"""

from typing import List, Optional

class Solution:
    def isPowerOfTwo(self, n):
        # Power of 2 must be positive and have only one set bit
        # n & (n-1) removes the rightmost set bit
        if (n <= 0) return False
        return (n & (n - 1)) == 0


if __name__ == "__main__":
    sol = Solution()
    n1 = 16
    print(f"Input: {n1}")
    print(f"Output: {(sol.isPowerOfTwo(n1)}")
    print(f"Explanation: 16 = 2^4")
    n2 = 18
    print(f"Input: {n2}")
    print(f"Output: {(sol.isPowerOfTwo(n2)}")
    print(f"Explanation: 18 is not a power of 2")
    n3 = 1
    print(f"Input: {n3}")
    print(f"Output: {(sol.isPowerOfTwo(n3)}")
    print(f"Explanation: 1 = 2^0")
