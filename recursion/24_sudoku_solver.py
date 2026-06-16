"""
PROBLEM: Sudoku Solver
---------------------------------------------------------------------------
Write a program to solve a Sudoku puzzle by filling the empty cells.
A sudoku solution must satisfy all of the following rules:
1. Each of the digits 1-9 must occur exactly once in each row
2. Each of the digits 1-9 must occur exactly once in each column
3. Each of the digits 1-9 must occur exactly once in each 3x3 sub-box

DIFFICULTY: Hard
PATTERN: Backtracking (Constraint Satisfaction)
TIME COMPLEXITY: O(9^(n*n)) worst case
SPACE COMPLEXITY: O(n*n) - recursion depth

INPUT/OUTPUT EXAMPLES:
---------------------------------------------------------------------------
Example 1:
Input: board = 
[["5","3",".",".","7",".",".",".","."],
 ["6",".",".","1","9","5",".",".","."],
 [".","9","8",".",".",".",".","6","."],
 ["8",".",".",".","6",".",".",".","3"],
 ["4",".",".","8",".","3",".",".","1"],
 ["7",".",".",".","2",".",".",".","6"],
 [".","6",".",".",".",".","2","8","."],
 [".",".",".","4","1","9",".",".","5"],
 [".",".",".",".","8",".",".","7","9"]]
Output: Solved board with all cells filled

Example 2:
Input: Any valid partially filled 9x9 board
Output: Complete valid solution
"""

from typing import List


class Solution:
    def solveSudoku(self, board: List[List[str]]) -> None:
        self._solve(board)

    def _solve(self, board: List[List[str]]) -> bool:
        for row in range(9):
            for col in range(9):
                if board[row][col] == '.':
                    for digit in '123456789':
                        if self._is_valid(board, row, col, digit):
                            board[row][col] = digit
                            if self._solve(board):
                                return True
                            board[row][col] = '.'
                    return False
        return True

    def _is_valid(self, board: List[List[str]], row: int, col: int, digit: str) -> bool:
        # Check row
        if digit in board[row]:
            return False
        # Check column
        if digit in [board[i][col] for i in range(9)]:
            return False
        # Check 3x3 box
        box_row, box_col = (row // 3) * 3, (col // 3) * 3
        for i in range(box_row, box_row + 3):
            for j in range(box_col, box_col + 3):
                if board[i][j] == digit:
                    return False
        return True


if __name__ == "__main__":
    sol = Solution()
    board = [
        ['5', '3', '.', '.', '7', '.', '.', '.', '.'],
        ['6', '.', '.', '1', '9', '5', '.', '.', '.'],
        ['.', '9', '8', '.', '.', '.', '.', '6', '.'],
        ['8', '.', '.', '.', '6', '.', '.', '.', '3'],
        ['4', '.', '.', '8', '.', '3', '.', '.', '1'],
        ['7', '.', '.', '.', '2', '.', '.', '.', '6'],
        ['.', '6', '.', '.', '.', '.', '2', '8', '.'],
        ['.', '.', '.', '4', '1', '9', '.', '.', '5'],
        ['.', '.', '.', '.', '8', '.', '.', '7', '9']
    ]
    print("Test 1: Solving Sudoku...")
    sol.solveSudoku(board)
    print("Solved!")
    for row in board:
        print(row)
