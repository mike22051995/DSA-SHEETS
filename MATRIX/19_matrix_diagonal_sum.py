"""
PROBLEM: Matrix Diagonal Sum (LeetCode 1572)
Difficulty: Easy
Company: Amazon, Google
Pattern: Matrix Diagonal Traversal

DESCRIPTION:
Given a square matrix, return the sum of its diagonals.
Include primary and secondary diagonals; do not count center element twice for odd size.

APPROACH:
Traverse primary diagonal (i, i) and secondary diagonal (i, n-1-i).
Subtract center if n is odd (counted twice).

TIME COMPLEXITY: O(N)
SPACE COMPLEXITY: O(1)
"""

from typing import List


class Solution:
    def diagonalSum(self, mat: List[List[int]]) -> int:
        n = len(mat)
        total = 0

        for i in range(n):
            total += mat[i][i]           # Primary diagonal
            total += mat[i][n - 1 - i]   # Secondary diagonal

        # If odd size, center element was counted twice
        if n % 2 == 1:
            total -= mat[n // 2][n // 2]

        return total


if __name__ == "__main__":
    sol = Solution()

    mat1 = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
    print("Diagonal sum (3x3):", sol.diagonalSum(mat1))  # 25

    mat2 = [[1, 1, 1, 1], [1, 1, 1, 1], [1, 1, 1, 1], [1, 1, 1, 1]]
    print("Diagonal sum (4x4):", sol.diagonalSum(mat2))  # 8
