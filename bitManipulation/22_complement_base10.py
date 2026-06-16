"""
PROBLEM: Complement of Base 10 Integer
========================================
Given a positive integer n, return its complement (flip all bits).
The complement is obtained by flipping all bits in its binary representation.

APPROACH:
- Find the number of bits in n
- Create a mask with all 1s of same length
- XOR n with mask to flip all bits

PATTERN: Bit Flipping with Mask

INPUT/OUTPUT:
Input: n = 5
Output: 2
Explanation: 5 is 101, complement is 010 = 2

Input: n = 1
Output: 0
Explanation: 1 is 1, complement is 0

TIME COMPLEXITY: O(log n)
SPACE COMPLEXITY: O(1)
"""

from typing import List, Optional

class Solution:
    def findComplement(self, num):
        # Find number of bits
        bitCount = 0
        temp = num
        while temp > 0:
        bitCount += 1
        temp >>= 1
        # Create mask with all 1s
        unsigned mask = (1U << bitCount) - 1
        # XOR to get complement
        return num ^ mask


if __name__ == "__main__":
    sol = Solution()
    n1 = 5
    print(f"Input: {n1}")
    print("Binary: ")
    printBinary(n1, 3)
    print()
    result1 = sol.findComplement(n1)
    print("Complement: ")
    printBinary(result1, 3)
    print()
    print(f"Output: {result1}")
    n2 = 1
    print(f"Input: {n2}")
    print("Binary: ")
    printBinary(n2, 1)
    print()
    result2 = sol.findComplement(n2)
    print("Complement: ")
    printBinary(result2, 1)
    print()
    print(f"Output: {result2}")
    n3 = 10
    print(f"Input: {n3}")
    print("Binary: ")
    printBinary(n3, 4)
    print()
    result3 = sol.findComplement(n3)
    print("Complement: ")
    printBinary(result3, 4)
    print()
    print(f"Output: {result3}")
