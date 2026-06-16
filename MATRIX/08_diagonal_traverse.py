"""
PROBLEM: Diagonal Traverse (LeetCode 498)
Difficulty: Medium
Company: Google, Meta, Amazon
Pattern: Matrix Diagonal Traversal

DESCRIPTION:
Given an m x n matrix, return an array of all elements in diagonal order.
Direction alternates: up-right, then down-left, etc.

APPROACH:
Simulation with direction changes:
1. Start at (0,0), direction = up-right (goingUp = True)
2. When hitting boundary, change direction and adjust position

TIME COMPLEXITY: O(M * N)
SPACE COMPLEXITY: O(1) excluding output array
"""

from typing import List


class Solution:
    def findDiagonalOrder(self, mat: List[List[int]]) -> List[int]:
        if not mat:
            return []

        m, n = len(mat), len(mat[0])
        result = []
        row, col = 0, 0
        going_up = True

        while len(result) < m * n:
            result.append(mat[row][col])

            if going_up:
                if col == n - 1:
                    row += 1
                    going_up = False
                elif row == 0:
                    col += 1
                    going_up = False
                else:
                    row -= 1
                    col += 1
            else:
                if row == m - 1:
                    col += 1
                    going_up = True
                elif col == 0:
                    row += 1
                    going_up = True
                else:
                    row += 1
                    col -= 1

        return result

    # Alternative: Group by diagonal sum
    def findDiagonalOrderGrouping(self, mat: List[List[int]]) -> List[int]:
        if not mat:
            return []

        m, n = len(mat), len(mat[0])
        diagonals = [[] for _ in range(m + n - 1)]

        for i in range(m):
            for j in range(n):
                diagonals[i + j].append(mat[i][j])

        result = []
        for d, diagonal in enumerate(diagonals):
            if d % 2 == 0:
                result.extend(reversed(diagonal))
            else:
                result.extend(diagonal)

        return result


if __name__ == "__main__":
    sol = Solution()

    mat = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
    print("Diagonal order:", sol.findDiagonalOrder(mat))  # [1,2,4,7,5,3,6,8,9]
