"""
PROBLEM: Set ith Bit
=====================
Given a number n and an index i, set the ith bit to 1.

APPROACH:
- Create a mask by left shifting 1 by i positions
- OR the mask with n to set the bit

PATTERN: Bit Setting - Single Bit Operations

INPUT/OUTPUT:
Input: n = 5, i = 1
Output: 7
Explanation: 5 in binary is 101, setting bit at position 1 gives 111 = 7

Input: n = 10, i = 2
Output: 14
Explanation: 10 in binary is 1010, setting bit at position 2 gives 1110 = 14

TIME COMPLEXITY: O(1)
SPACE COMPLEXITY: O(1)
"""

from typing import List, Optional

class Solution:
    def setBit(self, n, i):
        # Create mask with 1 at ith position
        mask = 1 << i
        # OR with n to set the bit
        return n | mask


if __name__ == "__main__":
    sol = Solution()
    n1 = 5, i1 = 1
    print(f"Input: n = {n1}")
    print("Binary before: ")
    printBinary(n1)
    print(f" ({n1}")
    result1 = sol.setBit(n1, i1)
    print("Binary after:  ")
    printBinary(result1)
    print(f" ({result1}")
    print(f"Output: {result1}")
    n2 = 10, i2 = 2
    print(f"Input: n = {n2}")
    print("Binary before: ")
    printBinary(n2)
    print(f" ({n2}")
    result2 = sol.setBit(n2, i2)
    print("Binary after:  ")
    printBinary(result2)
    print(f" ({result2}")
    print(f"Output: {result2}")
