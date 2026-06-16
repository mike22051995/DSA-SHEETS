"""
PROBLEM: Minimum Path Sum (LeetCode 64)
Difficulty: Medium
Company: Google, Meta, Amazon, Microsoft, Netflix
Pattern: Dynamic Programming - Grid Path

DESCRIPTION:
Given an m x n grid of non-negative numbers, find a path from top-left to bottom-right
that minimizes the sum. You can only move right or down.

APPROACH:
DP where dp[i][j] = minimum path sum to reach (i, j).
Formula: dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1])

TIME COMPLEXITY: O(M * N)
SPACE COMPLEXITY: O(M * N) or O(N) with optimization
"""

from typing import List


class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        if not grid or not grid[0]:
            return 0

        m, n = len(grid), len(grid[0])
        dp = [[0] * n for _ in range(m)]
        dp[0][0] = grid[0][0]

        for j in range(1, n):
            dp[0][j] = dp[0][j-1] + grid[0][j]

        for i in range(1, m):
            dp[i][0] = dp[i-1][0] + grid[i][0]

        for i in range(1, m):
            for j in range(1, n):
                dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1])

        return dp[m-1][n-1]

    # Space optimized: O(N)
    def minPathSumOptimized(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        dp = [float('inf')] * n
        dp[0] = 0

        for i in range(m):
            dp[0] += grid[i][0]
            for j in range(1, n):
                dp[j] = grid[i][j] + min(dp[j], dp[j-1])

        return dp[n-1]


if __name__ == "__main__":
    sol = Solution()

    grid = [[1, 3, 1], [1, 5, 1], [4, 2, 1]]
    print("Min path sum:", sol.minPathSum(grid))  # 7
