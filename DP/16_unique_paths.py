"""
PROBLEM: Unique Paths
Difficulty: Medium
Pattern: 2D Grid DP, Path Counting

DESCRIPTION:
A robot is located at the top-left corner of a m x n grid.
The robot can only move either down or right at any point in time.
The robot is trying to reach the bottom-right corner of the grid.
How many possible unique paths are there?

INPUT:
m = 3, n = 7

OUTPUT:
28

TIME COMPLEXITY: O(m * n)
SPACE COMPLEXITY: O(m * n), can be optimized to O(n)
"""

from typing import List, Optional

class Solution:
    def uniquePaths(self, m, n):
        # dp[i][j] = number of ways to reach cell (i, j)
        dp = [[1] * n for _ in range(m)]
        # First row and first column all have 1 way (only right or only down)
        for i in range(1, m):
            for j in range(1, n):
                # Ways to reach (i,j) = ways from top + ways from left
                dp[i][j] = dp[i-1][j] + dp[i][j-1]
        return dp[m-1][n-1]

    def uniquePathsOptimized(self, m, n):
        dp = [1] * n
        for i in range(1, m):
            for j in range(1, n):
                dp[j] += dp[j-1]
        return dp[n-1]

    def uniquePathsMath(self, m, n):
        from math import comb
        return comb(m + n - 2, n - 1)


if __name__ == "__main__":
    sol = Solution()
    m1, n1 = 3, 7
    print(f"Input: m = {m1}, n = {n1}")
    print(f"Output: {sol.uniquePaths(m1, n1)}")
    print(f"Output (Optimized): {sol.uniquePathsOptimized(m1, n1)}")
    print(f"Output (Math): {sol.uniquePathsMath(m1, n1)}")
    m2, n2 = 3, 3
    print(f"Input: m = {m2}, n = {n2}")
    print(f"Output: {sol.uniquePaths(m2, n2)}")
    print(f"Output (Optimized): {sol.uniquePathsOptimized(m2, n2)}")
    print(f"Output (Math): {sol.uniquePathsMath(m2, n2)}")
