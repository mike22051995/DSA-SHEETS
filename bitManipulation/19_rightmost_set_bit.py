"""
PROBLEM: Find Position of Rightmost Set Bit
=============================================
Find the position of the rightmost set bit (1-indexed from right).

APPROACH:
- Use n & -n to isolate the rightmost set bit
- Take log2 of result to get position
- Or use bit manipulation to count position

PATTERN: Rightmost Set Bit Isolation

INPUT/OUTPUT:
Input: n = 18
Output: 2
Explanation: 18 in binary is 10010, rightmost set bit at position 2

Input: n = 12
Output: 3
Explanation: 12 in binary is 1100, rightmost set bit at position 3

TIME COMPLEXITY: O(log n) or O(1) with log2
SPACE COMPLEXITY: O(1)
"""

from typing import List, Optional

class Solution:
    def findRightmostSetBit(self, n):
        if (n == 0) return 0
        # Isolate rightmost set bit
        rightmostBit = n & -n
        # Find position using log2
        return log2(rightmostBit) + 1


if __name__ == "__main__":
    sol = Solution()
    n1 = 18
    print(f"Input: {n1}")
    print("Binary: ")
    printBinary(n1)
    print()
    print(f"Output: {sol.findRightmostSetBit(n1)}")
    print(f"Explanation: Rightmost set bit at position 2")
    n2 = 12
    print(f"Input: {n2}")
    print("Binary: ")
    printBinary(n2)
    print()
    print(f"Output: {sol.findRightmostSetBit(n2)}")
    print(f"Explanation: Rightmost set bit at position 3")
    n3 = 16
    print(f"Input: {n3}")
    print("Binary: ")
    printBinary(n3)
    print()
    print(f"Output: {sol.findRightmostSetBit(n3)}")
    print(f"Explanation: Rightmost set bit at position 5")
