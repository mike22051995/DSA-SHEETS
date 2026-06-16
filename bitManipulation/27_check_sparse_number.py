"""
PROBLEM: Check if Number is Sparse
====================================
A number is Sparse if there are no consecutive 1s in its binary representation.
Check if a given number is sparse.

APPROACH:
- If n is sparse, then n & (n << 1) should be 0
- Left shifting by 1 moves all bits left
- If there were consecutive 1s, AND will produce non-zero

PATTERN: Consecutive Bits Detection

INPUT/OUTPUT:
Input: n = 5
Output: True
Explanation: 5 = 101 (binary), no consecutive 1s

Input: n = 7
Output: False
Explanation: 7 = 111 (binary), has consecutive 1s

Input: n = 2
Output: True
Explanation: 2 = 10 (binary), no consecutive 1s

TIME COMPLEXITY: O(1)
SPACE COMPLEXITY: O(1)
"""

from typing import List, Optional

class Solution:
    def isSparse(self, n):
        # If there are consecutive 1s, n & (n<<1) will be non-zero
        return (n & (n << 1)) == 0


if __name__ == "__main__":
    sol = Solution()
    n1 = 5
    print(f"Input: {n1}")
    print("Binary: ")
    printBinary(n1)
    print(f" ({n1}")
    print(f"Output: {(sol.isSparse(n1)}")
    print(f"Explanation: 101 has no consecutive 1s")
    n2 = 7
    print(f"Input: {n2}")
    print("Binary: ")
    printBinary(n2)
    print(f" ({n2}")
    print(f"Output: {(sol.isSparse(n2)}")
    print(f"Explanation: 111 has consecutive 1s")
    n3 = 2
    print(f"Input: {n3}")
    print("Binary: ")
    printBinary(n3)
    print(f" ({n3}")
    print(f"Output: {(sol.isSparse(n3)}")
    print(f"Explanation: 10 has no consecutive 1s")
    n4 = 72
    print(f"Input: {n4}")
    print("Binary: ")
    printBinary(n4)
    print(f" ({n4}")
    print(f"Output: {(sol.isSparse(n4)}")
    print(f"Explanation: 1001000 has no consecutive 1s")
