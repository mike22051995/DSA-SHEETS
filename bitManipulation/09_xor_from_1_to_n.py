"""
PROBLEM: XOR from 1 to N
==========================
Find the XOR of all numbers from 1 to n.

APPROACH:
- Pattern observation: XOR from 1 to n follows a pattern
- If n % 4 == 1, result = 1
- If n % 4 == 2, result = n + 1
- If n % 4 == 3, result = 0
- If n % 4 == 0, result = n

PATTERN: XOR Pattern Recognition - Mathematical Optimization

INPUT/OUTPUT:
Input: n = 5
Output: 1
Explanation: 1 ^ 2 ^ 3 ^ 4 ^ 5 = 1

Input: n = 6
Output: 7
Explanation: 1 ^ 2 ^ 3 ^ 4 ^ 5 ^ 6 = 7

Input: n = 7
Output: 0
Explanation: 1 ^ 2 ^ 3 ^ 4 ^ 5 ^ 6 ^ 7 = 0

TIME COMPLEXITY: O(1) - Using pattern
SPACE COMPLEXITY: O(1)
"""

from typing import List, Optional

class Solution:
    def xorFrom1ToN(self, n):
        remainder = n % 4
        if (remainder == 1) return 1
        if (remainder == 2) return n + 1
        if (remainder == 3) return 0
        return n; # remainder == 0


if __name__ == "__main__":
    sol = Solution()
    n1 = 5
    print(f"Input: {n1}")
    print(f"Output (Optimized): {sol.xorFrom1ToN(n1)}")
    print(f"Output (Brute Force): {sol.xorFrom1ToNBruteForce(n1)}")
    print(f"Explanation: 1^2^3^4^5 = 1")
    n2 = 6
    print(f"Input: {n2}")
    print(f"Output (Optimized): {sol.xorFrom1ToN(n2)}")
    print(f"Output (Brute Force): {sol.xorFrom1ToNBruteForce(n2)}")
    print(f"Explanation: 1^2^3^4^5^6 = 7")
    n3 = 7
    print(f"Input: {n3}")
    print(f"Output (Optimized): {sol.xorFrom1ToN(n3)}")
    print(f"Output (Brute Force): {sol.xorFrom1ToNBruteForce(n3)}")
    print(f"Explanation: 1^2^3^4^5^6^7 = 0")
