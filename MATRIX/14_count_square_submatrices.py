"""
PROBLEM: Count Square Submatrices with All Ones (LeetCode 1277)
Difficulty: Medium
Company: Google, Meta, Amazon
Pattern: Dynamic Programming on Matrix

DESCRIPTION:
Given an m x n binary matrix, return the number of square submatrices that have all ones.

APPROACH:
dp[i][j] = side length of largest square with bottom-right at (i, j).
This also equals the count of squares ending at (i, j).
Sum all dp values for total count.

TIME COMPLEXITY: O(M * N)
SPACE COMPLEXITY: O(M * N) or O(1) in-place
"""

from typing import List


class Solution:
    def countSquares(self, matrix: List[List[int]]) -> int:
        if not matrix:
            return 0

        m, n = len(matrix), len(matrix[0])
        dp = [[0] * n for _ in range(m)]
        total = 0

        for i in range(m):
            for j in range(n):
                if matrix[i][j] == 1:
                    if i == 0 or j == 0:
                        dp[i][j] = 1
                    else:
                        dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1
                    total += dp[i][j]

        return total

    # In-place space optimized
    def countSquaresInPlace(self, matrix: List[List[int]]) -> int:
        total = 0
        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                if matrix[i][j] == 1 and i > 0 and j > 0:
                    matrix[i][j] = min(matrix[i-1][j], matrix[i][j-1], matrix[i-1][j-1]) + 1
                total += matrix[i][j]
        return total


if __name__ == "__main__":
    sol = Solution()

    matrix = [[0, 1, 1, 1], [1, 1, 1, 1], [0, 1, 1, 1]]
    print("Count squares:", sol.countSquares(matrix))  # 15
