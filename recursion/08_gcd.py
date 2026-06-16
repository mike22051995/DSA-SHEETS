"""
PROBLEM: Greatest Common Divisor (GCD) - Euclidean Algorithm
---------------------------------------------------------------------------
Given two non-negative integers a and b, find their GCD using recursion.
GCD is the largest positive integer that divides both numbers.

DIFFICULTY: Easy
PATTERN: Euclidean Algorithm (Divide and Conquer)
TIME COMPLEXITY: O(log(min(a,b)))
SPACE COMPLEXITY: O(log(min(a,b))) - recursion stack

INPUT/OUTPUT EXAMPLES:
---------------------------------------------------------------------------
Example 1:
Input: a = 48, b = 18
Output: 6
Explanation: Divisors of 48: 1,2,3,4,6,8,12,16,24,48. Divisors of 18: 1,2,3,6,9,18. GCD = 6

Example 2:
Input: a = 100, b = 50
Output: 50
Explanation: 50 divides both 100 and 50
"""

from typing import List


class Solution:
    def gcd(self, a: int, b: int) -> int:
        # Base case
        if b == 0:
            return a
        # Recursive case (Euclidean algorithm)
        return self.gcd(b, a % b)

    def lcm(self, a: int, b: int) -> int:
        return a * b // self.gcd(a, b)


if __name__ == "__main__":
    sol = Solution()
    a1, b1 = 48, 18
    print(f"Test 1: GCD({a1}, {b1}) = {sol.gcd(a1, b1)}")
    a2, b2 = 100, 50
    print(f"Test 2: GCD({a2}, {b2}) = {sol.gcd(a2, b2)}")
    print(f"         LCM({a2}, {b2}) = {sol.lcm(a2, b2)}")
