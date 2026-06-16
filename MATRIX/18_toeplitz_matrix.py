"""
PROBLEM: Toeplitz Matrix (LeetCode 766)
Difficulty: Easy
Company: Google, Meta, Amazon
Pattern: Matrix Diagonal Check

DESCRIPTION:
A matrix is Toeplitz if every diagonal from top-left to bottom-right has the same elements.
Return true if the matrix is Toeplitz.

APPROACH:
For each cell (i, j) where i > 0 and j > 0, check matrix[i][j] == matrix[i-1][j-1].

TIME COMPLEXITY: O(M * N)
SPACE COMPLEXITY: O(1)
"""

from typing import List


class Solution:
    def isToeplitzMatrix(self, matrix: List[List[int]]) -> bool:
        m, n = len(matrix), len(matrix[0])

        for i in range(1, m):
            for j in range(1, n):
                if matrix[i][j] != matrix[i-1][j-1]:
                    return False

        return True

    # Follow-up: memory-limited (one row at a time)
    def isToeplitzMatrixOneRow(self, matrix: List[List[int]]) -> bool:
        prev_row = matrix[0]
        for row in matrix[1:]:
            if row[:-1] != prev_row[1:]:
                return False
            prev_row = row
        return True


if __name__ == "__main__":
    sol = Solution()

    matrix1 = [[1, 2, 3, 4], [5, 1, 2, 3], [9, 5, 1, 2]]
    print("Is Toeplitz:", sol.isToeplitzMatrix(matrix1))  # True

    matrix2 = [[1, 2], [2, 2]]
    print("Is Toeplitz:", sol.isToeplitzMatrix(matrix2))  # False
