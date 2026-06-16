"""
PROBLEM: Lucky Numbers in a Matrix (LeetCode 1380)
Difficulty: Easy
Company: Amazon, Google
Pattern: Matrix Row/Column Min/Max

DESCRIPTION:
Given an m x n matrix of distinct numbers, return all lucky numbers.
A lucky number is minimum in its row AND maximum in its column.

APPROACH:
1. Find minimum in each row
2. Find maximum in each column
3. Check intersection (element that is both row min and col max)

TIME COMPLEXITY: O(M * N)
SPACE COMPLEXITY: O(M + N)
"""

from typing import List


class Solution:
    def luckyNumbers(self, matrix: List[List[int]]) -> List[int]:
        m, n = len(matrix), len(matrix[0])

        row_mins = [min(row) for row in matrix]
        col_maxs = [max(matrix[i][j] for i in range(m)) for j in range(n)]

        result = []
        for i in range(m):
            for j in range(n):
                if matrix[i][j] == row_mins[i] and matrix[i][j] == col_maxs[j]:
                    result.append(matrix[i][j])

        return result

    # Optimized: Use sets
    def luckyNumbersOptimized(self, matrix: List[List[int]]) -> List[int]:
        row_min_set = {min(row) for row in matrix}
        col_max_set = {max(col) for col in zip(*matrix)}
        return list(row_min_set & col_max_set)


if __name__ == "__main__":
    sol = Solution()

    matrix1 = [[3, 7, 8], [9, 11, 13], [15, 16, 17]]
    print("Lucky numbers:", sol.luckyNumbers(matrix1))  # [15]

    matrix2 = [[1, 10, 4, 2], [9, 3, 8, 7], [15, 16, 17, 12]]
    print("Lucky numbers:", sol.luckyNumbers(matrix2))  # [12]
