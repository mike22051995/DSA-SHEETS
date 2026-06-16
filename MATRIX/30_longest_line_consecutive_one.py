"""
PROBLEM: Longest Line of Consecutive One in Matrix (LeetCode 562)
Difficulty: Medium
Company: Google, Meta
Pattern: Dynamic Programming - Multiple Directions

DESCRIPTION:
Given an m x n binary matrix, return the length of the longest line of consecutive 1's.
Lines can be horizontal, vertical, diagonal, or anti-diagonal.

APPROACH:
DP with 4 direction states per cell:
dp[i][j][0] = horizontal consecutive 1's ending at (i, j)
dp[i][j][1] = vertical
dp[i][j][2] = diagonal (↘)
dp[i][j][3] = anti-diagonal (↙)

TIME COMPLEXITY: O(M * N)
SPACE COMPLEXITY: O(M * N) or O(N)
"""

from typing import List


class Solution:
    def longestLine(self, mat: List[List[int]]) -> int:
        if not mat or not mat[0]:
            return 0

        m, n = len(mat), len(mat[0])
        # dp[i][j] = [horizontal, vertical, diagonal, anti-diagonal]
        dp = [[[0] * 4 for _ in range(n)] for _ in range(m)]
        max_len = 0

        for i in range(m):
            for j in range(n):
                if mat[i][j] == 1:
                    dp[i][j][0] = (dp[i][j-1][0] + 1) if j > 0 else 1
                    dp[i][j][1] = (dp[i-1][j][1] + 1) if i > 0 else 1
                    dp[i][j][2] = (dp[i-1][j-1][2] + 1) if i > 0 and j > 0 else 1
                    dp[i][j][3] = (dp[i-1][j+1][3] + 1) if i > 0 and j < n - 1 else 1
                    max_len = max(max_len, max(dp[i][j]))

        return max_len

    # Space optimized: O(N)
    def longestLineOptimized(self, mat: List[List[int]]) -> int:
        if not mat or not mat[0]:
            return 0

        m, n = len(mat), len(mat[0])
        prev = [[0] * 4 for _ in range(n)]
        max_len = 0

        for i in range(m):
            curr = [[0] * 4 for _ in range(n)]
            for j in range(n):
                if mat[i][j] == 1:
                    curr[j][0] = (curr[j-1][0] + 1) if j > 0 else 1
                    curr[j][1] = (prev[j][1] + 1) if i > 0 else 1
                    curr[j][2] = (prev[j-1][2] + 1) if i > 0 and j > 0 else 1
                    curr[j][3] = (prev[j+1][3] + 1) if i > 0 and j < n - 1 else 1
                    max_len = max(max_len, max(curr[j]))
            prev = curr

        return max_len


if __name__ == "__main__":
    sol = Solution()

    mat1 = [[0, 1, 1, 0], [0, 1, 1, 0], [0, 0, 0, 1]]
    print("Longest line:", sol.longestLine(mat1))  # 3

    mat2 = [[1, 1, 1, 1], [0, 1, 1, 0], [0, 0, 0, 1]]
    print("Longest line:", sol.longestLine(mat2))  # 4
