"""
PROBLEM: Clear ith Bit
=======================
Given a number n and an index i, clear (set to 0) the ith bit.

APPROACH:
- Create a mask by left shifting 1 by i positions
- Take complement of mask (all bits 1 except ith bit)
- AND with n to clear the bit

PATTERN: Bit Clearing - Single Bit Operations

INPUT/OUTPUT:
Input: n = 7, i = 1
Output: 5
Explanation: 7 in binary is 111, clearing bit at position 1 gives 101 = 5

Input: n = 15, i = 2
Output: 11
Explanation: 15 in binary is 1111, clearing bit at position 2 gives 1011 = 11

TIME COMPLEXITY: O(1)
SPACE COMPLEXITY: O(1)
"""

from typing import List, Optional

class Solution:
    def clearBit(self, n, i):
        # Create mask with 0 at ith position and 1s elsewhere
        mask = ~(1 << i)
        # AND with n to clear the bit
        return n & mask


if __name__ == "__main__":
    sol = Solution()
    n1 = 7, i1 = 1
    print(f"Input: n = {n1}")
    print("Binary before: ")
    printBinary(n1)
    print(f" ({n1}")
    result1 = sol.clearBit(n1, i1)
    print("Binary after:  ")
    printBinary(result1)
    print(f" ({result1}")
    print(f"Output: {result1}")
    n2 = 15, i2 = 2
    print(f"Input: n = {n2}")
    print("Binary before: ")
    printBinary(n2)
    print(f" ({n2}")
    result2 = sol.clearBit(n2, i2)
    print("Binary after:  ")
    printBinary(result2)
    print(f" ({result2}")
    print(f"Output: {result2}")
