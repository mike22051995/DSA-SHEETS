"""
PROBLEM: Rotate Image (LeetCode 48)
Difficulty: Medium
Company: Microsoft, Google, Meta, Amazon
Pattern: Matrix Manipulation

DESCRIPTION:
Rotate an n x n 2D matrix by 90 degrees clockwise in-place.

APPROACH:
1. Transpose the matrix (swap matrix[i][j] with matrix[j][i])
2. Reverse each row

TIME COMPLEXITY: O(N²)
SPACE COMPLEXITY: O(1) - in-place rotation
"""

from typing import List


class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        n = len(matrix)

        # Step 1: Transpose the matrix
        for i in range(n):
            for j in range(i + 1, n):
                matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]

        # Step 2: Reverse each row
        for i in range(n):
            matrix[i].reverse()

    # Alternative: Layer by layer rotation
    def rotateLayers(self, matrix: List[List[int]]) -> None:
        n = len(matrix)

        for layer in range(n // 2):
            first = layer
            last = n - 1 - layer

            for i in range(first, last):
                offset = i - first
                top = matrix[first][i]
                matrix[first][i] = matrix[last - offset][first]
                matrix[last - offset][first] = matrix[last][last - offset]
                matrix[last][last - offset] = matrix[i][last]
                matrix[i][last] = top


if __name__ == "__main__":
    sol = Solution()

    matrix = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
    print("Original:", matrix)
    sol.rotate(matrix)
    print("Rotated 90° clockwise:", matrix)  # [[7,4,1],[8,5,2],[9,6,3]]
