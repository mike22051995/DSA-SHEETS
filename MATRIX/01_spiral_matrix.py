"""
PROBLEM: Spiral Matrix (LeetCode 54)
Difficulty: Medium
Company: Microsoft, Google, Meta, Amazon, Netflix
Pattern: Matrix Traversal

DESCRIPTION:
Given an m x n matrix, return all elements of the matrix in spiral order.

APPROACH:
1. Use four pointers: top, bottom, left, right
2. Traverse right: left to right (top row)
3. Traverse down: top to bottom (right column)
4. Traverse left: right to left (bottom row)
5. Traverse up: bottom to top (left column)
6. Shrink boundaries after each traversal

TIME COMPLEXITY: O(M * N)
SPACE COMPLEXITY: O(1) excluding output array
"""

from typing import List


class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        if not matrix:
            return []

        result = []
        top, bottom = 0, len(matrix) - 1
        left, right = 0, len(matrix[0]) - 1

        while top <= bottom and left <= right:
            # Traverse right
            for col in range(left, right + 1):
                result.append(matrix[top][col])
            top += 1

            # Traverse down
            for row in range(top, bottom + 1):
                result.append(matrix[row][right])
            right -= 1

            # Traverse left (if there's a row remaining)
            if top <= bottom:
                for col in range(right, left - 1, -1):
                    result.append(matrix[bottom][col])
                bottom -= 1

            # Traverse up (if there's a column remaining)
            if left <= right:
                for row in range(bottom, top - 1, -1):
                    result.append(matrix[row][left])
                left += 1

        return result


if __name__ == "__main__":
    sol = Solution()

    matrix1 = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
    print("Spiral order:", sol.spiralOrder(matrix1))  # [1,2,3,6,9,8,7,4,5]

    matrix2 = [[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12]]
    print("Spiral order:", sol.spiralOrder(matrix2))  # [1,2,3,4,8,12,11,10,9,5,6,7]
