"""
PROBLEM: Power of Four
========================
Given an integer n, return True if it is a power of four.

APPROACH:
- First check if it's a power of 2: n & (n-1) == 0
- Power of 4 has set bit only at even positions (0, 2, 4, 6...)
- Use mask 0xAAAAAAAA to check odd positions are all 0
- Or check if (n-1) is divisible by 3

PATTERN: Power Checking with Bit Positions

INPUT/OUTPUT:
Input: n = 16
Output: True
Explanation: 16 = 4^2

Input: n = 5
Output: False

Input: n = 1
Output: True
Explanation: 1 = 4^0

TIME COMPLEXITY: O(1)
SPACE COMPLEXITY: O(1)
"""

from typing import List, Optional

class Solution:
    def isPowerOfFour(self, n):
        if (n <= 0) return False
        # Check if power of 2
        if ((n & (n - 1)) != 0) return False
        # Check if set bit is at even position
        # 0x55555555 = 01010101010101010101010101010101 (set bits at even positions)
        return (n & 0x55555555) != 0


if __name__ == "__main__":
    sol = Solution()
    n1 = 16
    print(f"Input: {n1}")
    print(f"Output: {(sol.isPowerOfFour(n1)}")
    print(f"Explanation: 16 = 4^2")
    n2 = 5
    print(f"Input: {n2}")
    print(f"Output: {(sol.isPowerOfFour(n2)}")
    print(f"Explanation: 5 is not a power of 4")
    n3 = 1
    print(f"Input: {n3}")
    print(f"Output: {(sol.isPowerOfFour(n3)}")
    print(f"Explanation: 1 = 4^0")
    n4 = 8
    print(f"Input: {n4}")
    print(f"Output: {(sol.isPowerOfFour(n4)}")
    print(f"Explanation: 8 is 2^3, not power of 4")
