"""
PROBLEM: Search a 2D Matrix II (LeetCode 240)
Difficulty: Medium
Company: Google, Meta, Amazon, Microsoft
Pattern: Matrix Search with Elimination

DESCRIPTION:
Search for a value in an m x n matrix where:
- Integers in each row are sorted ascending left to right
- Integers in each column are sorted ascending top to bottom

APPROACH:
Start from top-right corner:
1. If current element equals target, return True
2. If current element > target, move left
3. If current element < target, move down

TIME COMPLEXITY: O(M + N)
SPACE COMPLEXITY: O(1)
"""

from typing import List


class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        if not matrix or not matrix[0]:
            return False

        m, n = len(matrix), len(matrix[0])
        row, col = 0, n - 1  # Start from top-right

        while row < m and col >= 0:
            if matrix[row][col] == target:
                return True
            elif matrix[row][col] > target:
                col -= 1  # Move left
            else:
                row += 1  # Move down

        return False

    # Alternative: Start from bottom-left
    def searchMatrixBottomLeft(self, matrix: List[List[int]], target: int) -> bool:
        if not matrix or not matrix[0]:
            return False

        m, n = len(matrix), len(matrix[0])
        row, col = m - 1, 0  # Start from bottom-left

        while row >= 0 and col < n:
            if matrix[row][col] == target:
                return True
            elif matrix[row][col] > target:
                row -= 1  # Move up
            else:
                col += 1  # Move right

        return False


if __name__ == "__main__":
    sol = Solution()

    matrix = [
        [1,  4,  7,  11, 15],
        [2,  5,  8,  12, 19],
        [3,  6,  9,  16, 22],
        [10, 13, 14, 17, 24],
        [18, 21, 23, 26, 30]
    ]
    print("Search 5:", sol.searchMatrix(matrix, 5))   # True
    print("Search 20:", sol.searchMatrix(matrix, 20)) # False
