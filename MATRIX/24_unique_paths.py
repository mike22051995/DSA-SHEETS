"""
PROBLEM: Unique Paths (LeetCode 62)
Difficulty: Medium
Company: Google, Meta, Amazon, Microsoft, Netflix
Pattern: Dynamic Programming - Combinatorics

DESCRIPTION:
A robot at top-left of an m x n grid wants to reach bottom-right.
It can only move right or down. How many unique paths?

APPROACH:
Method 1: 2D DP - dp[i][j] = paths to (i,j) = dp[i-1][j] + dp[i][j-1]
Method 2: 1D DP (space optimized)
Method 3: Combinatorics - C(m+n-2, m-1)

TIME COMPLEXITY: O(M * N) for DP, O(M + N) for math
SPACE COMPLEXITY: O(M * N) or O(N) or O(1)
"""

from math import comb


class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        dp = [[1] * n for _ in range(m)]

        for i in range(1, m):
            for j in range(1, n):
                dp[i][j] = dp[i-1][j] + dp[i][j-1]

        return dp[m-1][n-1]

    # Space optimized: O(N)
    def uniquePathsOptimized(self, m: int, n: int) -> int:
        dp = [1] * n

        for _ in range(1, m):
            for j in range(1, n):
                dp[j] += dp[j-1]

        return dp[n-1]

    # Combinatorics: C(m+n-2, m-1)
    def uniquePathsMath(self, m: int, n: int) -> int:
        return comb(m + n - 2, m - 1)


if __name__ == "__main__":
    sol = Solution()

    print("3x7:", sol.uniquePaths(3, 7))  # 28
    print("3x2:", sol.uniquePaths(3, 2))  # 3
