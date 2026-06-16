"""
PROBLEM: Spiral Matrix
Difficulty: Medium
Pattern: Matrix Traversal, Simulation

DESCRIPTION:
Given an m x n matrix, return all elements of the matrix in spiral order.

EXPLANATION:
Use four boundaries: top, bottom, left, right
Traverse in spiral order: right -> down -> left -> up
After each direction, shrink the corresponding boundary
Continue until all elements are visited

Time Complexity: O(m * n)
Space Complexity: O(1) excluding output array

INPUT-OUTPUT EXAMPLES:

Example 1:
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]
Explanation: Spiral order traversal

Example 2:
Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
Explanation: Rectangle matrix spiral

Example 3:
Input: matrix = [[1]]
Output: [1]
Explanation: Single element
"""

from typing import List

class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        result = []
        if not matrix:
            return result
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
            # Traverse left
            if top <= bottom:
                for col in range(right, left - 1, -1):
                    result.append(matrix[bottom][col])
                bottom -= 1
            # Traverse up
            if left <= right:
                for row in range(bottom, top - 1, -1):
                    result.append(matrix[row][left])
                left += 1
        return result


if __name__ == "__main__":
    solution = Solution()
    matrix1 = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
    print(f"Test 1: {solution.spiralOrder(matrix1)}")
    matrix2 = [[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12]]
    print(f"Test 2: {solution.spiralOrder(matrix2)}")
    matrix3 = [[1]]
    print(f"Test 3: {solution.spiralOrder(matrix3)}")
