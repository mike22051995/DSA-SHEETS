"""
PROBLEM: Swap Two Numbers Without Temporary Variable
======================================================
Swap two numbers without using a temporary variable using bit manipulation.

APPROACH:
- Use XOR properties: a ^ a = 0 and a ^ 0 = a
- a = a ^ b
- b = a ^ b (now b becomes original a)
- a = a ^ b (now a becomes original b)

PATTERN: XOR Swap - Variable Exchange

INPUT/OUTPUT:
Input: a = 5, b = 10
Output: a = 10, b = 5

Input: a = 3, b = 7
Output: a = 7, b = 3

TIME COMPLEXITY: O(1)
SPACE COMPLEXITY: O(1)
"""

from typing import List, Optional

class Solution:
    def swapNumbers(self, a, b):
        if (a == b) return; # Avoid XOR with same values
        cout << "Before swap: a = " << a << ", b = " << b << 
        a = a ^ b; # a now contains XOR of both
        cout << "After a = a ^ b: a = " << a << ", b = " << b << 
        b = a ^ b; # b becomes original a (a ^ b ^ b = a)
        cout << "After b = a ^ b: a = " << a << ", b = " << b << 
        a = a ^ b; # a becomes original b (a ^ b ^ a = b)
        cout << "After a = a ^ b: a = " << a << ", b = " << b << 


if __name__ == "__main__":
    sol = Solution()
    print(f"Test Case 1:")
    a1 = 5, b1 = 10
    sol.swapNumbers(a1, b1)
    print(f"Final: a = {a1}")
    print(f"Test Case 2:")
    a2 = 3, b2 = 7
    sol.swapNumbers(a2, b2)
    print(f"Final: a = {a2}")
