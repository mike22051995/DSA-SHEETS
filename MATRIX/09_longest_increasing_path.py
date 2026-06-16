"""
PROBLEM: Longest Increasing Path in Matrix (LeetCode 329)
Difficulty: Hard
Company: Google, Meta, Microsoft, Amazon
Pattern: DFS with Memoization (DP on Matrix)

DESCRIPTION:
Given an m x n matrix, return the length of the longest increasing path.
From each cell, you can move in 4 directions. Cannot move diagonally or outside boundary.

APPROACH:
1. Use DFS from each cell
2. Only explore neighbors with strictly larger values
3. Memoize results to avoid recomputation
4. dp[i][j] = longest path starting from (i, j)

TIME COMPLEXITY: O(M * N)
SPACE COMPLEXITY: O(M * N) for memoization cache
"""

from typing import List


class Solution:
    def longestIncreasingPath(self, matrix: List[List[int]]) -> int:
        if not matrix:
            return 0

        m, n = len(matrix), len(matrix[0])
        memo = {}
        dirs = [(-1, 0), (1, 0), (0, -1), (0, 1)]

        def dfs(i: int, j: int) -> int:
            if (i, j) in memo:
                return memo[(i, j)]

            max_len = 1
            for di, dj in dirs:
                ni, nj = i + di, j + dj
                if 0 <= ni < m and 0 <= nj < n and matrix[ni][nj] > matrix[i][j]:
                    max_len = max(max_len, 1 + dfs(ni, nj))

            memo[(i, j)] = max_len
            return max_len

        return max(dfs(i, j) for i in range(m) for j in range(n))


if __name__ == "__main__":
    sol = Solution()

    matrix1 = [[9, 9, 4], [6, 6, 8], [2, 1, 1]]
    print("Longest path:", sol.longestIncreasingPath(matrix1))  # 4

    matrix2 = [[3, 4, 5], [3, 2, 6], [2, 2, 1]]
    print("Longest path:", sol.longestIncreasingPath(matrix2))  # 4
