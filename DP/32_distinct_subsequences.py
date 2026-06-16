"""
PROBLEM: Distinct Subsequences (LeetCode 115)
DIFFICULTY: Hard
PATTERN: String DP / Counting Paths

DESCRIPTION:
Given two strings s and t, return the number of distinct subsequences of s which equals t.
The test cases are generated so that the answer fits on a 32-bit signed integer.

EXAMPLE:
Input: s = "rabbbit", t = "rabbit"
Output: 3
Explanation:
rabbb̲it (remove 1st b)
rabb̲bit (remove 2nd b)  
rabbi̲t (remove 3rd b)

Input: s = "babgbag", t = "bag"
Output: 5
Explanation:
b̲abgbag̲
b̲abgb̲ag
b̲a̲bgba̲g̲
ba̲bgb̲ag̲
babgbag̲

TIME COMPLEXITY: O(m*n) where m = len(s), n = len(t)
SPACE COMPLEXITY: O(m*n)
"""

from typing import List, Optional

class Solution:
    def numDistinct(self, s, t):
        m = len(s)
        n = len(t)
        # dp[i][j] = number of distinct subsequences of s[0..i-1] that equal t[0..j-1]
        dp = [[0] * (n + 1) for _ in range(m + 1)]
        # Base case: empty t can be formed by any prefix of s (empty subsequence)
        for i in range(m + 1):
            dp[i][0] = 1
        # Fill DP table
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                # Don't use s[i-1]
                dp[i][j] = dp[i-1][j]
                # Use s[i-1] if it matches t[j-1]
                if s[i-1] == t[j-1]:
                    dp[i][j] += dp[i-1][j-1]
        return dp[m][n]

    def numDistinctOptimized(self, s, t):
        n = len(t)
        dp = [0] * (n + 1)
        dp[0] = 1
        for ch in s:
            for j in range(n, 0, -1):
                if ch == t[j-1]:
                    dp[j] += dp[j-1]
        return dp[n]


if __name__ == "__main__":
    sol = Solution()
    print(f"Test Case 1:")
    s1, t1 = "rabbbit", "rabbit"
    print(f"s = {s1}, t = {t1}")
    print(f"Distinct subsequences: {sol.numDistinct(s1, t1)}")
    print(f"Distinct subsequences (Optimized): {sol.numDistinctOptimized(s1, t1)}")
    print(f"\nTest Case 2:")
    s2, t2 = "babgbag", "bag"
    print(f"s = {s2}, t = {t2}")
    print(f"Distinct subsequences: {sol.numDistinct(s2, t2)}")
    print(f"\nTest Case 3:")
    s3, t3 = "abc", "abc"
    print(f"s = {s3}, t = {t3}")
    print(f"Distinct subsequences: {sol.numDistinct(s3, t3)}")
    print(f"\nTest Case 4:")
    s4, t4 = "aaaa", "aa"
    print(f"s = {s4}, t = {t4}")
    print(f"Distinct subsequences: {sol.numDistinct(s4, t4)}")
