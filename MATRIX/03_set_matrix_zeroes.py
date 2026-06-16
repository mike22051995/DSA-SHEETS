"""
PROBLEM: Set Matrix Zeroes (LeetCode 73)
Difficulty: Medium
Company: Microsoft, Google, Meta, Amazon, Netflix
Pattern: Matrix In-place Modification

DESCRIPTION:
Given an m x n matrix, if an element is 0, set its entire row and column to 0.
Do it in-place with O(1) extra space.

APPROACH:
1. Use first row and column as markers
2. Use separate variables for first row and column themselves
3. Mark zeros in first row/column
4. Use markers to set zeros in rest of matrix
5. Finally handle first row and column

TIME COMPLEXITY: O(M * N)
SPACE COMPLEXITY: O(1)
"""

from typing import List


class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        if not matrix:
            return

        m, n = len(matrix), len(matrix[0])
        first_row_zero = any(matrix[0][j] == 0 for j in range(n))
        first_col_zero = any(matrix[i][0] == 0 for i in range(m))

        # Use first row and column as markers
        for i in range(1, m):
            for j in range(1, n):
                if matrix[i][j] == 0:
                    matrix[i][0] = 0
                    matrix[0][j] = 0

        # Set zeros based on markers
        for i in range(1, m):
            for j in range(1, n):
                if matrix[i][0] == 0 or matrix[0][j] == 0:
                    matrix[i][j] = 0

        # Handle first row
        if first_row_zero:
            for j in range(n):
                matrix[0][j] = 0

        # Handle first column
        if first_col_zero:
            for i in range(m):
                matrix[i][0] = 0


if __name__ == "__main__":
    sol = Solution()

    matrix = [[1, 1, 1], [1, 0, 1], [1, 1, 1]]
    print("Original:", matrix)
    sol.setZeroes(matrix)
    print("After setZeroes:", matrix)  # [[1,0,1],[0,0,0],[1,0,1]]
