"""
PROBLEM: N-Queens
---------------------------------------------------------------------------
The n-queens puzzle is the problem of placing n queens on an n×n chessboard 
such that no two queens attack each other. Given an integer n, return all 
distinct solutions to the n-queens puzzle.

DIFFICULTY: Hard
PATTERN: Backtracking (Constraint Satisfaction)
TIME COMPLEXITY: O(n!)
SPACE COMPLEXITY: O(n²) - board + recursion stack

INPUT/OUTPUT EXAMPLES:
---------------------------------------------------------------------------
Example 1:
Input: n = 4
Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]

Example 2:
Input: n = 1
Output: [["Q"]]
"""

from typing import List


class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        result = []
        board = [['.' for _ in range(n)] for _ in range(n)]
        self._backtrack(board, 0, result)
        return result

    def _backtrack(self, board: List[List[str]], row: int,
                   result: List[List[str]]) -> None:
        if row >= len(board):
            result.append(["".join(r) for r in board])
            return
        for col in range(len(board)):
            if self._is_safe(board, row, col):
                board[row][col] = 'Q'
                self._backtrack(board, row + 1, result)
                board[row][col] = '.'

    def _is_safe(self, board: List[List[str]], row: int, col: int) -> bool:
        n = len(board)
        # Check column
        for i in range(row):
            if board[i][col] == 'Q':
                return False
        # Check upper-left diagonal
        i, j = row - 1, col - 1
        while i >= 0 and j >= 0:
            if board[i][j] == 'Q':
                return False
            i -= 1
            j -= 1
        # Check upper-right diagonal
        i, j = row - 1, col + 1
        while i >= 0 and j < n:
            if board[i][j] == 'Q':
                return False
            i -= 1
            j += 1
        return True


if __name__ == "__main__":
    sol = Solution()
    n1 = 4
    result1 = sol.solveNQueens(n1)
    print(f"Test 1: Total solutions for {n1}-Queens = {len(result1)}")
    n2 = 1
    result2 = sol.solveNQueens(n2)
    print(f"Test 2: Total solutions for {n2}-Queens = {len(result2)}")
