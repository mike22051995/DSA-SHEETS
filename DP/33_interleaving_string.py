"""
PROBLEM: Interleaving String (LeetCode 97)
DIFFICULTY: Medium
PATTERN: 2D String DP

DESCRIPTION:
Given strings s1, s2, and s3, find whether s3 is formed by an interleaving 
of s1 and s2. An interleaving of two strings s and t is a configuration where 
s and t are divided into n and m non-empty substrings respectively, such that:
s = s1 + s2 + ... + sn
t = t1 + t2 + ... + tm
s3 = s1 + t1 + s2 + t2 + s3 + t3 + ... or t1 + s1 + t2 + s2 + ...

EXAMPLE:
Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
Output: True
Explanation: s3 can be formed by:
"aa" (from s1) + "dbbc" (from s2) + "b" (from s1) + "c" (from s2) + "ac" (from s1)

Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
Output: False

Input: s1 = "", s2 = "b", s3 = "b"
Output: True

TIME COMPLEXITY: O(m*n) where m=len(s1), n=len(s2)
SPACE COMPLEXITY: O(m*n)
"""

from typing import List, Optional

class Solution:
    def isInterleave(self, s1, s2, s3):
        m = len(s1)
        n = len(s2)
        # Quick check
        if m + n != len(s3):
            return False
        # dp[i][j] = True if s3[0..i+j-1] can be formed by s1[0..i-1] and s2[0..j-1]
        dp = [[False] * (n + 1) for _ in range(m + 1)]
        # Base case
        dp[0][0] = True
        # Fill first row (only s2 used)
        for j in range(1, n + 1):
            dp[0][j] = dp[0][j-1] and s2[j-1] == s3[j-1]
        # Fill first column (only s1 used)
        for i in range(1, m + 1):
            dp[i][0] = dp[i-1][0] and s1[i-1] == s3[i-1]
        # Fill rest of table
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                k = i + j - 1  # Position in s3
                # Take from s1
                from_s1 = dp[i-1][j] and s1[i-1] == s3[k]
                # Take from s2
                from_s2 = dp[i][j-1] and s2[j-1] == s3[k]
                dp[i][j] = from_s1 or from_s2
        return dp[m][n]

    def isInterleaveOptimized(self, s1, s2, s3):
        m, n = len(s1), len(s2)
        if m + n != len(s3):
            return False
        dp = [False] * (n + 1)
        dp[0] = True
        for j in range(1, n + 1):
            dp[j] = dp[j-1] and s2[j-1] == s3[j-1]
        for i in range(1, m + 1):
            dp[0] = dp[0] and s1[i-1] == s3[i-1]
            for j in range(1, n + 1):
                k = i + j - 1
                dp[j] = (dp[j] and s1[i-1] == s3[k]) or (dp[j-1] and s2[j-1] == s3[k])
        return dp[n]


if __name__ == "__main__":
    sol = Solution()
    print(f"Test Case 1:")
    s1_1, s2_1, s3_1 = "aabcc", "dbbca", "aadbbcbcac"
    print(f"s1 = {s1_1}, s2 = {s2_1}")
    print(f"Is Interleave: {sol.isInterleave(s1_1, s2_1, s3_1)}")
    print(f"Is Interleave (Optimized): {sol.isInterleaveOptimized(s1_1, s2_1, s3_1)}")
    print(f"\nTest Case 2:")
    s1_2, s2_2, s3_2 = "aabcc", "dbbca", "aadbbbaccc"
    print(f"s1 = {s1_2}, s2 = {s2_2}")
    print(f"Is Interleave: {sol.isInterleave(s1_2, s2_2, s3_2)}")
    print(f"\nTest Case 3:")
    s1_3, s2_3, s3_3 = "", "b", "b"
    print(f"s1 = '{s1_3}', s2 = {s2_3}")
    print(f"Is Interleave: {sol.isInterleave(s1_3, s2_3, s3_3)}")
    print(f"\nTest Case 4:")
    s1_4, s2_4, s3_4 = "ab", "bc", "babc"
    print(f"s1 = {s1_4}, s2 = {s2_4}")
    print(f"Is Interleave: {sol.isInterleave(s1_4, s2_4, s3_4)}")
