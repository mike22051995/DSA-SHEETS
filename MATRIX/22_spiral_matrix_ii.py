"""
PROBLEM: Spiral Matrix II (LeetCode 59)
Difficulty: Medium
Company: Microsoft, Google, Meta, Amazon
Pattern: Matrix Generation - Spiral Pattern

DESCRIPTION:
Given a positive integer n, generate an n x n matrix filled with elements
from 1 to n² in spiral order.

APPROACH:
Use four boundaries (top, bottom, left, right) and fill in spiral order:
Right → Down → Left → Up → (repeat, shrink boundaries)

TIME COMPLEXITY: O(N²)
SPACE COMPLEXITY: O(N²) for output matrix
"""

from typing import List


class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        matrix = [[0] * n for _ in range(n)]
        top, bottom = 0, n - 1
        left, right = 0, n - 1
        num = 1

        while top <= bottom and left <= right:
            # Fill top row (left to right)
            for col in range(left, right + 1):
                matrix[top][col] = num
                num += 1
            top += 1

            # Fill right column (top to bottom)
            for row in range(top, bottom + 1):
                matrix[row][right] = num
                num += 1
            right -= 1

            # Fill bottom row (right to left)
            if top <= bottom:
                for col in range(right, left - 1, -1):
                    matrix[bottom][col] = num
                    num += 1
                bottom -= 1

            # Fill left column (bottom to top)
            if left <= right:
                for row in range(bottom, top - 1, -1):
                    matrix[row][left] = num
                    num += 1
                left += 1

        return matrix


if __name__ == "__main__":
    sol = Solution()

    print("n=3:", sol.generateMatrix(3))  # [[1,2,3],[8,9,4],[7,6,5]]
    print("n=1:", sol.generateMatrix(1))  # [[1]]
