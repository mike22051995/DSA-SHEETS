"""
PROBLEM: Find MSB Position (Most Significant Bit)
===================================================
Find the position of the most significant bit (leftmost set bit) in a number.

APPROACH:
- Method 1: Keep right shifting until number becomes 0
- Method 2: Use log2 function
- Method 3: Set all bits after MSB and count

PATTERN: MSB Detection - Bit Position Finding

INPUT/OUTPUT:
Input: n = 18
Output: 5
Explanation: 18 = 10010 (binary), MSB at position 5

Input: n = 10
Output: 4
Explanation: 10 = 1010 (binary), MSB at position 4

TIME COMPLEXITY: O(log n)
SPACE COMPLEXITY: O(1)
"""

from typing import List, Optional

class Solution:
    def findMSB(self, n):
        if (n == 0) return 0
        pos = 0
        while n > 0:
        n >>= 1
        pos += 1
        return pos


if __name__ == "__main__":
    sol = Solution()
    n1 = 18
    print(f"Input: {n1}")
    print("Binary: ")
    printBinary(n1)
    print()
    print(f"MSB Position: {sol.findMSB(n1)}")
    print(f"MSB Value: {sol.getMSBValue(n1)}")
    n2 = 10
    print(f"Input: {n2}")
    print("Binary: ")
    printBinary(n2)
    print()
    print(f"MSB Position: {sol.findMSB(n2)}")
    print(f"MSB Value: {sol.getMSBValue(n2)}")
    n3 = 255
    print(f"Input: {n3}")
    print("Binary: ")
    printBinary(n3)
    print()
    print(f"MSB Position: {sol.findMSB(n3)}")
    print(f"MSB Value: {sol.getMSBValue(n3)}")
