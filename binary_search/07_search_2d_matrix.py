"""
PROBLEM: Search a 2D Matrix
Difficulty: Medium
Pattern: Binary Search on Matrix

DESCRIPTION:
Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix.
This matrix has the following properties:
- Integers in each row are sorted from left to right.
- The first integer of each row is greater than the last integer of the previous row.

EXPLANATION:
Treat 2D matrix as 1D sorted array:
- Total elements = m * n
- For index i: row = i / n, col = i % n
- Apply standard binary search on indices [0, m*n-1]

Time Complexity: O(log(m*n))
Space Complexity: O(1)

INPUT-OUTPUT EXAMPLES:

Example 1:
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: True
Explanation: 3 is found in the matrix

Example 2:
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output: False
Explanation: 13 is not in the matrix

Example 3:
Input: matrix = [[1]], target = 1
Output: True
"""

from typing import List, Optional

class Solution:
    def searchMatrix(self, matrix, target):
        if not matrix or not matrix[0]:
            return False
        m = len(matrix)
        n = len(matrix[0])
        left = 0
        right = m * n - 1
        while left <= right:
            mid = left + (right - left) // 2
            row = mid // n
            col = mid % n
            mid_value = matrix[row][col]
            if mid_value == target:
                return True
            elif mid_value < target:
                left = mid + 1
            else:
                right = mid - 1
        return False


if __name__ == "__main__":
    solution = Solution()
    matrix1 = [[1, 3, 5, 7], [10, 11, 16, 20], [23, 30, 34, 60]]
    print(f"Test 1: {solution.searchMatrix(matrix1, 3)}")
    matrix2 = [[1, 3, 5, 7], [10, 11, 16, 20], [23, 30, 34, 60]]
    print(f"Test 2: {solution.searchMatrix(matrix2, 13)}")
    matrix3 = [[1]]
    print(f"Test 3: {solution.searchMatrix(matrix3, 1)}")
