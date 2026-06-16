"""
PROBLEM: Nth Magical Number
Difficulty: Hard
Pattern: Binary Search on Answer with LCM

DESCRIPTION:
A positive integer is magical if it is divisible by either a or b.
Given the three integers n, a, and b, return the nth magical number. Since the answer may be 
very large, return it modulo 10^9 + 7.

EXPLANATION:
Binary search on value with inclusion-exclusion:
- Count magical numbers <= x using: x/a + x/b - x/lcm(a,b)
- Binary search to find smallest x where count >= n
- Use LCM to handle numbers divisible by both a and b

Time Complexity: O(log(n * min(a, b)))
Space Complexity: O(1)

INPUT-OUTPUT EXAMPLES:

Example 1:
Input: n = 1, a = 2, b = 3
Output: 2
Explanation: First magical number is 2

Example 2:
Input: n = 4, a = 2, b = 3
Output: 6
Explanation: First 4 magical numbers are [2,3,4,6]

Example 3:
Input: n = 5, a = 2, b = 4
Output: 10
"""

from typing import List, Optional
import math


class Solution:
    def nthMagicalNumber(self, n, a, b):
        MOD = 10**9 + 7
        lcm = a // math.gcd(a, b) * b
        left = 1
        right = n * min(a, b)
        while left < right:
            mid = left + (right - left) // 2
            count = mid // a + mid // b - mid // lcm
            if count < n:
                left = mid + 1
            else:
                right = mid
        return left % MOD


if __name__ == "__main__":
    solution = Solution()
    print(f"Test 1: {solution.nthMagicalNumber(1, 2, 3)}")
    print(f"Test 2: {solution.nthMagicalNumber(4, 2, 3)}")
    print(f"Test 3: {solution.nthMagicalNumber(5, 2, 4)}")
