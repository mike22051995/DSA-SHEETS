"""
PROBLEM: Transpose Matrix (LeetCode 867)
Difficulty: Easy
Company: Google, Meta, Amazon
Pattern: Matrix Manipulation

DESCRIPTION:
Given a 2D integer array matrix, return the transpose of matrix.
The transpose flips the matrix over its main diagonal (rows become columns).

APPROACH:
Create new matrix with swapped dimensions.
result[j][i] = matrix[i][j]

TIME COMPLEXITY: O(M * N)
SPACE COMPLEXITY: O(M * N)
"""

from typing import List


class Solution:
    def transpose(self, matrix: List[List[int]]) -> List[List[int]]:
        m, n = len(matrix), len(matrix[0])
        result = [[0] * m for _ in range(n)]

        for i in range(m):
            for j in range(n):
                result[j][i] = matrix[i][j]

        return result

    # Pythonic one-liner
    def transposePythonic(self, matrix: List[List[int]]) -> List[List[int]]:
        return list(map(list, zip(*matrix)))


if __name__ == "__main__":
    sol = Solution()

    matrix1 = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
    print("Transposed:", sol.transpose(matrix1))  # [[1,4,7],[2,5,8],[3,6,9]]

    matrix2 = [[1, 2, 3], [4, 5, 6]]
    print("Transposed (2x3):", sol.transpose(matrix2))  # [[1,4],[2,5],[3,6]]
