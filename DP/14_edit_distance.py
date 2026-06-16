"""
PROBLEM: Edit Distance (Levenshtein Distance)
Difficulty: Medium
Pattern: 2D DP, String Transformation

DESCRIPTION:
Given two strings word1 and word2, return the minimum number of operations required to convert 
word1 to word2.
You have the following three operations permitted on a word:
- Insert a character
- Delete a character
- Replace a character

INPUT:
word1 = "horse", word2 = "ros"

OUTPUT:
3
Explanation:
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')

TIME COMPLEXITY: O(m * n) where m, n are lengths of strings
SPACE COMPLEXITY: O(m * n), can be optimized to O(min(m, n))
"""

from typing import List, Optional

class Solution:
    def minDistance(self, word1, word2):
        m = len(word1)
        n = len(word2)
        # dp[i][j] = min operations to convert word1[0...i-1] to word2[0...j-1]
        dp = [[0] * (n + 1) for _ in range(m + 1)]
        # Base cases
        for i in range(m + 1):
            dp[i][0] = i  # Delete all characters from word1
        for j in range(n + 1):
            dp[0][j] = j  # Insert all characters from word2
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                if word1[i-1] == word2[j-1]:
                    # Characters match, no operation needed
                    dp[i][j] = dp[i-1][j-1]
                else:
                    # Take minimum of three operations
                    dp[i][j] = 1 + min(
                        dp[i-1][j],    # Delete from word1
                        dp[i][j-1],    # Insert to word1
                        dp[i-1][j-1]   # Replace in word1
                    )
        return dp[m][n]


if __name__ == "__main__":
    sol = Solution()
    word1_1, word2_1 = "horse", "ros"
    print(f"Input: word1 = {word1_1}, word2 = {word2_1}")
    print(f"Output: {sol.minDistance(word1_1, word2_1)}")
    word1_2, word2_2 = "intention", "execution"
    print(f"Input: word1 = {word1_2}, word2 = {word2_2}")
    print(f"Output: {sol.minDistance(word1_2, word2_2)}")
    word1_3, word2_3 = "abc", "abc"
    print(f"Input: word1 = {word1_3}, word2 = {word2_3}")
    print(f"Output: {sol.minDistance(word1_3, word2_3)}")
