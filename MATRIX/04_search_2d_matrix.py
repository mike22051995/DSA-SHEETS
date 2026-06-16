"""
PROBLEM: Search a 2D Matrix (LeetCode 74)
Difficulty: Medium
Company: Microsoft, Google, Meta, Amazon
Pattern: Binary Search on Matrix

DESCRIPTION:
Write an efficient algorithm to search for a value in an m x n matrix.
- Integers in each row are sorted left to right
- First integer of each row is greater than last integer of previous row

APPROACH:
Treat as sorted 1D array and binary search.
- Convert index: row = mid // n, col = mid % n

TIME COMPLEXITY: O(log(M * N))
SPACE COMPLEXITY: O(1)
"""

from typing import List


class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        if not matrix or not matrix[0]:
            return False

        m, n = len(matrix), len(matrix[0])
        left, right = 0, m * n - 1

        while left <= right:
            mid = (left + right) // 2
            mid_val = matrix[mid // n][mid % n]

            if mid_val == target:
                return True
            elif mid_val < target:
                left = mid + 1
            else:
                right = mid - 1

        return False

    # Alternative: Two binary searches
    def searchMatrixTwoBS(self, matrix: List[List[int]], target: int) -> bool:
        if not matrix or not matrix[0]:
            return False

        m, n = len(matrix), len(matrix[0])

        # Binary search for the row
        top, bottom = 0, m - 1
        target_row = -1

        while top <= bottom:
            mid = (top + bottom) // 2
            if matrix[mid][0] <= target <= matrix[mid][n - 1]:
                target_row = mid
                break
            elif matrix[mid][0] > target:
                bottom = mid - 1
            else:
                top = mid + 1

        if target_row == -1:
            return False

        # Binary search within the row
        left, right = 0, n - 1
        while left <= right:
            mid = (left + right) // 2
            if matrix[target_row][mid] == target:
                return True
            elif matrix[target_row][mid] < target:
                left = mid + 1
            else:
                right = mid - 1

        return False


if __name__ == "__main__":
    sol = Solution()

    matrix = [[1, 3, 5, 7], [10, 11, 16, 20], [23, 30, 34, 60]]
    print("Search 3:", sol.searchMatrix(matrix, 3))    # True
    print("Search 13:", sol.searchMatrix(matrix, 13))  # False
