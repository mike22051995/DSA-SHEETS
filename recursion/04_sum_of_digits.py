"""
PROBLEM: Sum of Digits
---------------------------------------------------------------------------
Given a non-negative integer n, return the sum of its digits using recursion.

DIFFICULTY: Easy
PATTERN: Linear Recursion
TIME COMPLEXITY: O(log₁₀ n) - number of digits
SPACE COMPLEXITY: O(log₁₀ n) - recursion stack

INPUT/OUTPUT EXAMPLES:
---------------------------------------------------------------------------
Example 1:
Input: n = 1234
Output: 10
Explanation: 1 + 2 + 3 + 4 = 10

Example 2:
Input: n = 999
Output: 27
Explanation: 9 + 9 + 9 = 27
"""

from typing import List, Optional

class Solution:
    def sumOfDigits(self, n):
        # Base case
        if n == 0:
            return 0
        # Recursive case
        return (n % 10) + self.sumOfDigits(n // 10)


if __name__ == "__main__":
    sol = Solution()
    n1 = 1234
    print(f"Test 1: Sum of digits of {n1} = {sol.sumOfDigits(n1)}")
    n2 = 999
    print(f"Test 2: Sum of digits of {n2} = {sol.sumOfDigits(n2)}")
