"""
PROBLEM: Longest Palindromic Subsequence (LeetCode 516)
DIFFICULTY: Medium
PATTERN: Interval DP / LCS Variant

DESCRIPTION:
Given a string s, find the longest palindromic subsequence's length in s.
A subsequence is a sequence that can be derived from another sequence by deleting 
some or no elements without changing the order of the remaining elements.

EXAMPLE:
Input: s = "bbbab"
Output: 4
Explanation: "bbbb" is the longest palindromic subsequence.

Input: s = "cbbd"
Output: 2
Explanation: "bb" is the longest palindromic subsequence.

Input: s = "abcabcabcabc"
Output: 7
Explanation: "abcbcba" is one of the longest palindromic subsequences.

TIME COMPLEXITY: O(n²)
SPACE COMPLEXITY: O(n²)
"""

from typing import List, Optional

class Solution:
    def longestPalindromeSubseq(self, s: str) -> int:
        # LCS-based approach: LPS(s) = LCS(s, reverse(s))
        rev = s[::-1]
        n = len(s)
        dp = [[0] * (n + 1) for _ in range(n + 1)]
        for i in range(1, n + 1):
            for j in range(1, n + 1):
                if s[i-1] == rev[j-1]:
                    dp[i][j] = dp[i-1][j-1] + 1
                else:
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1])
        return dp[n][n]

    def longestPalindromeSubseqDirect(self, s: str) -> int:
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

    def longestPalindromeSubseqMemo(self, s: str) -> int:
        from functools import lru_cache
        n = len(s)

        @lru_cache(maxsize=None)
        def dp(i, j):
            if i > j:
                return 0
            if i == j:
                return 1
            if s[i] == s[j]:
                return dp(i+1, j-1) + 2
            return max(dp(i+1, j), dp(i, j-1))

        return dp(0, n - 1)

    def getLPS(self, s: str) -> str:
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
        # Backtrack to construct the LPS string
        result = []
        i, j = 0, n - 1
        while i < j:
            if s[i] == s[j]:
                result.append(s[i])
                i += 1
                j -= 1
            elif dp[i+1][j] > dp[i][j-1]:
                i += 1
            else:
                j -= 1
        mid = [s[i]] if i == j else []
        return ''.join(result) + ''.join(mid) + ''.join(reversed(result))


if __name__ == "__main__":
    sol = Solution()
    print(f"Test Case 1:")
    s1 = "bbbab"
    print(f"String: {s1}")
    print(f"LPS Length (LCS): {sol.longestPalindromeSubseq(s1)}")
    print(f"LPS Length (Direct): {sol.longestPalindromeSubseqDirect(s1)}")
    print(f"LPS Length (Memo): {sol.longestPalindromeSubseqMemo(s1)}")
    print(f"One LPS: {sol.getLPS(s1)}")
    print(f"\nTest Case 2:")
    s2 = "cbbd"
    print(f"String: {s2}")
    print(f"LPS Length: {sol.longestPalindromeSubseq(s2)}")
    print(f"One LPS: {sol.getLPS(s2)}")
    print(f"\nTest Case 3:")
    s3 = "abcabcabcabc"
    print(f"String: {s3}")
    print(f"LPS Length: {sol.longestPalindromeSubseq(s3)}")
    print(f"One LPS: {sol.getLPS(s3)}")
    print(f"\nTest Case 4:")
    s4 = "racecar"
    print(f"String: {s4}")
    print(f"LPS Length: {sol.longestPalindromeSubseq(s4)}")
