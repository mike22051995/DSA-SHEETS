"""
PROBLEM: Fibonacci Number
---------------------------------------------------------------------------
The Fibonacci numbers form a sequence where each number is the sum of the 
two preceding ones, starting from 0 and 1.
F(0) = 0, F(1) = 1, F(n) = F(n-1) + F(n-2) for n > 1

DIFFICULTY: Easy
PATTERN: Multiple Recursion (Tree Recursion)
TIME COMPLEXITY: O(2^n) - naive, O(n) - memoization
SPACE COMPLEXITY: O(n) - recursion stack

INPUT/OUTPUT EXAMPLES:
---------------------------------------------------------------------------
Example 1:
Input: n = 5
Output: 5
Explanation: F(5) = F(4) + F(3) = 3 + 2 = 5

Example 2:
Input: n = 10
Output: 55
Explanation: F(10) = 55
"""

from typing import List


class Solution:
    def fibNaive(self, n: int) -> int:
        if n <= 1:
            return n
        return self.fibNaive(n - 1) + self.fibNaive(n - 2)

    def fibMemo(self, n: int, memo: dict = None) -> int:
        if memo is None:
            memo = {}
        if n <= 1:
            return n
        if n in memo:
            return memo[n]
        memo[n] = self.fibMemo(n - 1, memo) + self.fibMemo(n - 2, memo)
        return memo[n]


if __name__ == "__main__":
    sol = Solution()
    n1 = 5
    print(f"Test 1: F({n1}) = {sol.fibNaive(n1)}")
    n2 = 10
    print(f"Test 2: F({n2}) = {sol.fibMemo(n2)}")
