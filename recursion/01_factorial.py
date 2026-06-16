"""
PROBLEM: Factorial of a Number
---------------------------------------------------------------------------
Given a non-negative integer n, calculate and return the factorial of n.
Factorial of n (n!) = n * (n-1) * (n-2) * ... * 1
By definition, 0! = 1

DIFFICULTY: Easy
PATTERN: Basic Recursion (Linear)
TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(n) - recursion stack

INPUT/OUTPUT EXAMPLES:
---------------------------------------------------------------------------
Example 1:
Input: n = 5
Output: 120
Explanation: 5! = 5 * 4 * 3 * 2 * 1 = 120

Example 2:
Input: n = 0
Output: 1
Explanation: 0! is defined as 1
"""

from typing import List


class Solution:
    def factorial(self, n: int) -> int:
        # Base case
        if n == 0 or n == 1:
            return 1
        # Recursive case
        return n * self.factorial(n - 1)

    def factorialTail(self, n: int, acc: int = 1) -> int:
        # Tail recursive optimization
        if n == 0 or n == 1:
            return acc
        return self.factorialTail(n - 1, n * acc)


if __name__ == "__main__":
    sol = Solution()
    n1 = 5
    print(f"Test 1: {n1}! = {sol.factorial(n1)}")
    n2 = 0
    print(f"Test 2: {n2}! = {sol.factorial(n2)}")
    print(f"Tail recursive 5! = {sol.factorialTail(5)}")
