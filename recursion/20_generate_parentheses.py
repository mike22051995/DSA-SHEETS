"""
PROBLEM: Generate Parentheses
---------------------------------------------------------------------------
Given n pairs of parentheses, write a function to generate all combinations 
of well-formed parentheses.

DIFFICULTY: Medium
PATTERN: Backtracking (Constraint-based)
TIME COMPLEXITY: O(4^n / sqrt(n)) - Catalan number
SPACE COMPLEXITY: O(n) - recursion depth

INPUT/OUTPUT EXAMPLES:
---------------------------------------------------------------------------
Example 1:
Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]

Example 2:
Input: n = 1
Output: ["()"]
"""

from typing import List


class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        result = []
        self._backtrack(n, 0, 0, "", result)
        return result

    def _backtrack(self, n: int, open_: int, close: int, current: str,
                   result: List[str]) -> None:
        if len(current) == 2 * n:
            result.append(current)
            return
        if open_ < n:
            self._backtrack(n, open_ + 1, close, current + "(", result)
        if close < open_:
            self._backtrack(n, open_, close + 1, current + ")", result)


if __name__ == "__main__":
    sol = Solution()
    n1 = 3
    result1 = sol.generateParenthesis(n1)
    print(f"Test 1: {result1}")
    n2 = 1
    result2 = sol.generateParenthesis(n2)
    print(f"Test 2: {result2}")
