"""
PROBLEM: Reverse Bits
======================
Reverse the bits of a given 32-bit unsigned integer.

APPROACH:
- Process each bit from right to left
- Shift result left and add the current bit
- Shift n right to process next bit

PATTERN: Bit-by-Bit Processing

INPUT/OUTPUT:
Input: n = 00000010100101000001111010011100
Output:    964176192 (00111001011110000010100101000000)

Input: n = 11111111111111111111111111111101
Output:   3221225471 (10111111111111111111111111111111)

TIME COMPLEXITY: O(32) = O(1) - Fixed 32 iterations
SPACE COMPLEXITY: O(1)
"""

from typing import List, Optional

class Solution:
    def reverseBits(self, n):
        uint32_t result = 0
        for i in range(32):
        # Shift result left to make room for next bit
        result <<= 1
        # Add the rightmost bit of n to result
        result |= (n & 1)
        # Shift n right to process next bit
        n >>= 1
        return result


if __name__ == "__main__":
    sol = Solution()
    uint32_t n1 = 43261596; # Binary: 00000010100101000001111010011100
    print(f"Input: {n1}")
    print(f"Output: {sol.reverseBits(n1)}")
    print(f"Explanation: Reverse bits of 43261596")
    uint32_t n2 = 4294967293; # Binary: 11111111111111111111111111111101
    print(f"Input: {n2}")
    print(f"Output: {sol.reverseBits(n2)}")
    print(f"Explanation: Reverse bits of 4294967293")
