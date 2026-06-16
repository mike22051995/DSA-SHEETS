"""
PROBLEM: Maximal Square (LeetCode 221)
Difficulty: Medium
Company: Google, Meta, Amazon, Microsoft
Pattern: Dynamic Programming on Matrix

DESCRIPTION:
Given an m x n binary matrix filled with '0's and '1's, find the largest square
containing only '1's and return its area.

APPROACH:
DP where dp[i][j] = side length of largest square with bottom-right at (i, j).
Formula: dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1

TIME COMPLEXITY: O(M * N)
SPACE COMPLEXITY: O(M * N) or O(N) with optimization
"""

from typing import List


class Solution:
    def maximalSquare(self, matrix: List[List[str]]) -> int:
        if not matrix or not matrix[0]:
            return 0

        m, n = len(matrix), len(matrix[0])
        dp = [[0] * n for _ in range(m)]
        max_side = 0

        for i in range(m):
            for j in range(n):
                if matrix[i][j] == '1':
                    if i == 0 or j == 0:
                        dp[i][j] = 1
                    else:
                        dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1
                    max_side = max(max_side, dp[i][j])

        return max_side * max_side

    # Space optimized: O(N) space
    def maximalSquareOptimized(self, matrix: List[List[str]]) -> int:
        if not matrix or not matrix[0]:
            return 0

        m, n = len(matrix), len(matrix[0])
        dp = [0] * (n + 1)
        max_side = 0
        prev = 0

        for i in range(1, m + 1):
            for j in range(1, n + 1):
                temp = dp[j]
                if matrix[i-1][j-1] == '1':
                    dp[j] = min(dp[j], dp[j-1], prev) + 1
                    max_side = max(max_side, dp[j])
                else:
                    dp[j] = 0
                prev = temp

        return max_side * max_side


if __name__ == "__main__":
    sol = Solution()

    matrix = [
        ["1", "0", "1", "0", "0"],
        ["1", "0", "1", "1", "1"],
        ["1", "1", "1", "1", "1"],
        ["1", "0", "0", "1", "0"]
    ]
    print("Maximal square area:", sol.maximalSquare(matrix))  # 4
