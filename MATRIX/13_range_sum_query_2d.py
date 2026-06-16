"""
PROBLEM: Range Sum Query 2D - Immutable (LeetCode 304)
Difficulty: Medium
Company: Google, Meta, Amazon, Microsoft, Netflix
Pattern: Prefix Sum 2D

DESCRIPTION:
Given a 2D matrix, handle multiple queries of sum of elements inside a rectangle.

APPROACH:
Preprocessing: Build 2D prefix sum matrix.
Query: Use inclusion-exclusion with prefix sums.
Formula: sum = prefix[r2+1][c2+1] - prefix[r1][c2+1] - prefix[r2+1][c1] + prefix[r1][c1]

TIME COMPLEXITY: Preprocessing O(M*N), Query O(1)
SPACE COMPLEXITY: O(M * N)
"""

from typing import List


class NumMatrix:
    def __init__(self, matrix: List[List[int]]):
        if not matrix or not matrix[0]:
            return

        m, n = len(matrix), len(matrix[0])
        self.prefix = [[0] * (n + 1) for _ in range(m + 1)]

        for i in range(1, m + 1):
            for j in range(1, n + 1):
                self.prefix[i][j] = (matrix[i-1][j-1]
                                     + self.prefix[i-1][j]
                                     + self.prefix[i][j-1]
                                     - self.prefix[i-1][j-1])

    def sumRegion(self, row1: int, col1: int, row2: int, col2: int) -> int:
        return (self.prefix[row2 + 1][col2 + 1]
                - self.prefix[row1][col2 + 1]
                - self.prefix[row2 + 1][col1]
                + self.prefix[row1][col1])


if __name__ == "__main__":
    matrix = [
        [3, 0, 1, 4, 2],
        [5, 6, 3, 2, 1],
        [1, 2, 0, 1, 5],
        [4, 1, 0, 1, 7],
        [1, 0, 3, 0, 5]
    ]
    obj = NumMatrix(matrix)
    print("sumRegion(2,1,4,3):", obj.sumRegion(2, 1, 4, 3))  # 8
    print("sumRegion(1,1,2,2):", obj.sumRegion(1, 1, 2, 2))  # 11
    print("sumRegion(1,2,2,4):", obj.sumRegion(1, 2, 2, 4))  # 12
