"""
PROBLEM: Minimum Insertion Steps to Make String Palindrome (LeetCode 1312)
DIFFICULTY: Hard
PATTERN: LPS Application

DESCRIPTION:
Given a string s, find the minimum number of insertions to make it a palindrome.
In one step you can insert any character at any position of the string.

EXAMPLE:
Input: s = "zzazz"
Output: 0
Explanation: Already a palindrome

Input: s = "mbadm"
Output: 2
Explanation: Insert "mb" → "mbdadbm" or "am" → "amdadma"

Input: s = "leetcode"
Output: 5
Explanation: Insert "ecodt" → "leetcodocteel"

TIME COMPLEXITY: O(n²)
SPACE COMPLEXITY: O(n²)
"""

from typing import List, Optional

class Solution:
    def longestPalindromeSubseq(self, s: str) -> int:
        n = len(s)
        dp = [[0] * n for _ in range(n)]
        for i in range(n):
            dp[i][i] = 1
        for length in range(2, n + 1):
            for i in range(n - length + 1):
                j = i + length - 1
                if s[i] == s[j]:
                    dp[i][j] = (dp[i+1][j-1] if length > 2 else 0) + 2
                else:
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1])
        return dp[0][n-1]

    def minInsertions(self, s: str) -> int:
        n = len(s)
        lps = self.longestPalindromeSubseq(s)
        return n - lps

    def minInsertionsDirect(self, s: str) -> int:
        n = len(s)
        dp = [[0] * n for _ in range(n)]
        for length in range(2, n + 1):
            for i in range(n - length + 1):
                j = i + length - 1
                if s[i] == s[j]:
                    dp[i][j] = dp[i+1][j-1] if length > 2 else 0
                else:
                    dp[i][j] = 1 + min(dp[i+1][j], dp[i][j-1])
        return dp[0][n-1]

    def constructPalindrome(self, s: str) -> str:
        n = len(s)
        dp = [[0] * n for _ in range(n)]
        for length in range(2, n + 1):
            for i in range(n - length + 1):
                j = i + length - 1
                if s[i] == s[j]:
                    dp[i][j] = dp[i+1][j-1] if length > 2 else 0
                else:
                    dp[i][j] = 1 + min(dp[i+1][j], dp[i][j-1])

        def build(i, j):
            if i > j:
                return ""
            if i == j:
                return s[i]
            if s[i] == s[j]:
                return s[i] + build(i+1, j-1) + s[j]
            if dp[i+1][j] < dp[i][j-1]:
                return s[i] + build(i+1, j) + s[i]
            else:
                return s[j] + build(i, j-1) + s[j]

        return build(0, n - 1)


if __name__ == "__main__":
    sol = Solution()
    print(f"Test Case 1:")
    s1 = "zzazz"
    print(f"String: {s1}")
    print(f"Minimum insertions (LPS): {sol.minInsertions(s1)}")
    print(f"Minimum insertions (Direct): {sol.minInsertionsDirect(s1)}")
    print(f"\nTest Case 2:")
    s2 = "mbadm"
    print(f"String: {s2}")
    print(f"Minimum insertions: {sol.minInsertions(s2)}")
    print(f"Resulting palindrome: {sol.constructPalindrome(s2)}")
    print(f"\nTest Case 3:")
    s3 = "leetcode"
    print(f"String: {s3}")
    print(f"Minimum insertions: {sol.minInsertions(s3)}")
    print(f"\nTest Case 4:")
    s4 = "abc"
    print(f"String: {s4}")
    print(f"Minimum insertions: {sol.minInsertions(s4)}")
    print(f"Resulting palindrome: {sol.constructPalindrome(s4)}")
    print(f"\nTest Case 5:")
    s5 = "racecar"
    print(f"String: {s5}")
    print(f"Minimum insertions: {sol.minInsertions(s5)}")
