"""
PROBLEM: Count Digits
---------------------------------------------------------------------------
Given a non-negative integer n, count the number of digits using recursion.

DIFFICULTY: Easy
PATTERN: Linear Recursion
TIME COMPLEXITY: O(log₁₀ n)
SPACE COMPLEXITY: O(log₁₀ n) - recursion stack

INPUT/OUTPUT EXAMPLES:
---------------------------------------------------------------------------
Example 1:
Input: n = 12345
Output: 5
Explanation: The number has 5 digits

Example 2:
Input: n = 7
Output: 1
Explanation: Single digit number
"""

from typing import List


class Solution:
    def countDigits(self, n: int) -> int:
        # Base case
        if n < 10:
            return 1
        # Recursive case
        return 1 + self.countDigits(n // 10)


if __name__ == "__main__":
    sol = Solution()
    n1 = 12345
    print(f"Test 1: Number of digits in {n1} = {sol.countDigits(n1)}")
    n2 = 7
    print(f"Test 2: Number of digits in {n2} = {sol.countDigits(n2)}")
