"""
PROBLEM: Reshape the Matrix (LeetCode 566)
Difficulty: Easy
Company: Microsoft, Amazon, Google
Pattern: Matrix Manipulation

DESCRIPTION:
Given an m x n matrix and integers r and c, return the reshaped matrix if possible,
otherwise return the original matrix.

APPROACH:
1. Check if reshape is possible: m * n must equal r * c
2. Use index mapping: flat_index -> new_i = flat_index // c, new_j = flat_index % c

TIME COMPLEXITY: O(M * N)
SPACE COMPLEXITY: O(r * c) for output
"""

from typing import List


class Solution:
    def matrixReshape(self, mat: List[List[int]], r: int, c: int) -> List[List[int]]:
        m, n = len(mat), len(mat[0])

        if m * n != r * c:
            return mat

        reshaped = [[0] * c for _ in range(r)]

        for i in range(m * n):
            reshaped[i // c][i % c] = mat[i // n][i % n]

        return reshaped

    # Pythonic approach
    def matrixReshapePythonic(self, mat: List[List[int]], r: int, c: int) -> List[List[int]]:
        m, n = len(mat), len(mat[0])
        if m * n != r * c:
            return mat

        flat = [mat[i][j] for i in range(m) for j in range(n)]
        return [flat[i * c:(i + 1) * c] for i in range(r)]


if __name__ == "__main__":
    sol = Solution()

    mat = [[1, 2], [3, 4]]
    print("Reshape to 1x4:", sol.matrixReshape(mat, 1, 4))  # [[1,2,3,4]]
    print("Reshape to 4x1:", sol.matrixReshape(mat, 4, 1))  # [[1],[2],[3],[4]]
    print("Reshape to 2x3:", sol.matrixReshape(mat, 2, 3))  # [[1,2],[3,4]] (impossible)
