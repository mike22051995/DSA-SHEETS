"""
PROBLEM: Valid Sudoku (LeetCode 36)
Difficulty: Medium
Company: Google, Meta, Amazon, Microsoft, Netflix
Pattern: Hash Set Validation

DESCRIPTION:
Determine if a 9x9 Sudoku board is valid:
1. Each row must contain digits 1-9 without repetition
2. Each column must contain digits 1-9 without repetition
3. Each 3x3 sub-box must contain digits 1-9 without repetition

APPROACH:
Use hash sets to track seen numbers for rows, columns, and boxes.
Box index = (row // 3) * 3 + (col // 3)

TIME COMPLEXITY: O(1) - constant 9x9 board
SPACE COMPLEXITY: O(1) - constant space for sets
"""

from typing import List


class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        rows = [set() for _ in range(9)]
        cols = [set() for _ in range(9)]
        boxes = [set() for _ in range(9)]

        for i in range(9):
            for j in range(9):
                num = board[i][j]
                if num == '.':
                    continue

                box_index = (i // 3) * 3 + (j // 3)

                if num in rows[i] or num in cols[j] or num in boxes[box_index]:
                    return False

                rows[i].add(num)
                cols[j].add(num)
                boxes[box_index].add(num)

        return True


if __name__ == "__main__":
    sol = Solution()

    board = [
        ["5", "3", ".", ".", "7", ".", ".", ".", "."],
        ["6", ".", ".", "1", "9", "5", ".", ".", "."],
        [".", "9", "8", ".", ".", ".", ".", "6", "."],
        ["8", ".", ".", ".", "6", ".", ".", ".", "3"],
        ["4", ".", ".", "8", ".", "3", ".", ".", "1"],
        ["7", ".", ".", ".", "2", ".", ".", ".", "6"],
        [".", "6", ".", ".", ".", ".", "2", "8", "."],
        [".", ".", ".", "4", "1", "9", ".", ".", "5"],
        [".", ".", ".", ".", "8", ".", ".", "7", "9"]
    ]
    print("Is valid Sudoku:", sol.isValidSudoku(board))  # True
