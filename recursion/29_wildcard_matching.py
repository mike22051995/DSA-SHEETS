"""
PROBLEM: Wildcard Matching
---------------------------------------------------------------------------
Given an input string s and a pattern p, implement wildcard pattern matching 
with support for '?' and '*' where:
- '?' Matches any single character
- '*' Matches any sequence of characters (including empty)

DIFFICULTY: Hard
PATTERN: Recursion with Memoization
TIME COMPLEXITY: O(m * n) with memoization
SPACE COMPLEXITY: O(m * n)

INPUT/OUTPUT EXAMPLES:
---------------------------------------------------------------------------
Example 1:
Input: s = "aa", p = "a"
Output: False
Explanation: "a" does not match entire string "aa"

Example 2:
Input: s = "aa", p = "*"
Output: True
Explanation: '*' matches any sequence
"""

from typing import List, Dict, Tuple


class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        memo: Dict[Tuple[int, int], bool] = {}

        def dp(i: int, j: int) -> bool:
            if (i, j) in memo:
                return memo[(i, j)]
            if j >= len(p):
                result = i >= len(s)
            elif i >= len(s):
                # String exhausted, remaining pattern must be all '*'
                result = all(p[k] == '*' for k in range(j, len(p)))
            elif p[j] == '*':
                result = dp(i, j + 1) or dp(i + 1, j)
            elif p[j] == '?' or p[j] == s[i]:
                result = dp(i + 1, j + 1)
            else:
                result = False
            memo[(i, j)] = result
            return result

        return dp(0, 0)


if __name__ == "__main__":
    sol = Solution()
    s1, p1 = "aa", "a"
    print(f"Test 1: Does '{s1}' match '{p1}'? {sol.isMatch(s1, p1)}")
    s2, p2 = "aa", "*"
    print(f"Test 2: Does '{s2}' match '{p2}'? {sol.isMatch(s2, p2)}")
    s3, p3 = "cb", "?a"
    print(f"Test 3: Does '{s3}' match '{p3}'? {sol.isMatch(s3, p3)}")
