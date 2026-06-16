"""
PROBLEM: Regular Expression Matching
---------------------------------------------------------------------------
Given an input string s and a pattern p, implement regular expression 
matching with support for '.' and '*' where:
- '.' Matches any single character
- '*' Matches zero or more of the preceding element

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
Input: s = "aa", p = "a*"
Output: True
Explanation: '*' means zero or more 'a', so "aa" matches
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
            else:
                first_match = i < len(s) and (p[j] == s[i] or p[j] == '.')
                if j + 1 < len(p) and p[j + 1] == '*':
                    result = dp(i, j + 2) or (first_match and dp(i + 1, j))
                else:
                    result = first_match and dp(i + 1, j + 1)
            memo[(i, j)] = result
            return result

        return dp(0, 0)


if __name__ == "__main__":
    sol = Solution()
    s1, p1 = "aa", "a"
    print(f"Test 1: Does '{s1}' match '{p1}'? {sol.isMatch(s1, p1)}")
    s2, p2 = "aa", "a*"
    print(f"Test 2: Does '{s2}' match '{p2}'? {sol.isMatch(s2, p2)}")
    s3, p3 = "ab", ".*"
    print(f"Test 3: Does '{s3}' match '{p3}'? {sol.isMatch(s3, p3)}")
