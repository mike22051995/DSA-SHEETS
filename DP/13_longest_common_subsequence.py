"""
PROBLEM: Longest Common Subsequence (LCS)
Difficulty: Medium
Pattern: 2D DP, String Matching

DESCRIPTION:
Given two strings text1 and text2, return the length of their longest common subsequence.
A subsequence is a sequence that can be derived from another sequence by deleting some or no 
elements without changing the order of the remaining elements.

INPUT:
text1 = "abcde", text2 = "ace"

OUTPUT:
3
Explanation: The longest common subsequence is "ace" and its length is 3.

TIME COMPLEXITY: O(m * n) where m, n are lengths of strings
SPACE COMPLEXITY: O(m * n), can be optimized to O(min(m, n))
"""

from typing import List, Optional

class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        m = len(text1)
        n = len(text2)
        # dp[i][j] = LCS length of text1[0...i-1] and text2[0...j-1]
        dp = [[0] * (n + 1) for _ in range(m + 1)]
        
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                if text1[i-1] == text2[j-1]:
                    # Characters match, add 1 to LCS without these characters
                    dp[i][j] = dp[i-1][j-1] + 1
                else:
                    # Characters don't match, take max of excluding one character
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1])
        
        return dp[m][n]


if __name__ == "__main__":
    sol = Solution()
    
    text1_1, text2_1 = "abcde", "ace"
    print(f"Input: text1 = {text1_1}, text2 = {text2_1}")
    print(f"Output: {sol.longestCommonSubsequence(text1_1, text2_1)}")
    
    text1_2, text2_2 = "abc", "abc"
    print(f"\nInput: text1 = {text1_2}, text2 = {text2_2}")
    print(f"Output: {sol.longestCommonSubsequence(text1_2, text2_2)}")
    
    text1_3, text2_3 = "abc", "def"
    print(f"\nInput: text1 = {text1_3}, text2 = {text2_3}")
    print(f"Output: {sol.longestCommonSubsequence(text1_3, text2_3)}")
