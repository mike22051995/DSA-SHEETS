"""
PROBLEM: Toggle ith Bit
========================
Given a number n and an index i, toggle (flip) the ith bit.
If bit is 0, make it 1. If bit is 1, make it 0.

APPROACH:
- Create a mask by left shifting 1 by i positions
- XOR with n to toggle the bit
- XOR with 1 flips the bit, XOR with 0 keeps it same

PATTERN: Bit Toggling - Single Bit Operations

INPUT/OUTPUT:
Input: n = 5, i = 1
Output: 7
Explanation: 5 in binary is 101, toggling bit at position 1 gives 111 = 7

Input: n = 7, i = 1
Output: 5
Explanation: 7 in binary is 111, toggling bit at position 1 gives 101 = 5

TIME COMPLEXITY: O(1)
SPACE COMPLEXITY: O(1)
"""

from typing import List, Optional

class Solution:
    def toggleBit(self, n, i):
        # Create mask with 1 at ith position
        mask = 1 << i
        # XOR with n to toggle the bit
        return n ^ mask


if __name__ == "__main__":
    sol = Solution()
    n1 = 5, i1 = 1
    print(f"Input: n = {n1}")
    print("Binary before: ")
    printBinary(n1)
    print(f" ({n1}")
    result1 = sol.toggleBit(n1, i1)
    print("Binary after:  ")
    printBinary(result1)
    print(f" ({result1}")
    print(f"Output: {result1}")
    n2 = 7, i2 = 1
    print(f"Input: n = {n2}")
    print("Binary before: ")
    printBinary(n2)
    print(f" ({n2}")
    result2 = sol.toggleBit(n2, i2)
    print("Binary after:  ")
    printBinary(result2)
    print(f" ({result2}")
    print(f"Output: {result2}")
