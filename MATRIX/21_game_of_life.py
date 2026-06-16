"""
PROBLEM: Game of Life (LeetCode 289)
Difficulty: Medium
Company: Google, Meta, Amazon, Microsoft, Netflix
Pattern: In-Place Matrix State Update

DESCRIPTION:
Given a board with live (1) and dead (0) cells, apply Conway's Game of Life rules simultaneously.
Rules:
1. Live cell with < 2 live neighbors dies (underpopulation)
2. Live cell with 2-3 live neighbors lives
3. Live cell with > 3 live neighbors dies (overpopulation)
4. Dead cell with exactly 3 live neighbors becomes alive (reproduction)

APPROACH:
In-place using bit encoding:
- 1st bit = current state, 2nd bit = new state
- 00: dead→dead, 01: live→dead, 10: dead→live, 11: live→live

TIME COMPLEXITY: O(M * N)
SPACE COMPLEXITY: O(1) - in-place
"""

from typing import List


class Solution:
    def gameOfLife(self, board: List[List[int]]) -> None:
        if not board:
            return

        m, n = len(board), len(board[0])
        dirs = [(-1, -1), (-1, 0), (-1, 1), (0, -1), (0, 1), (1, -1), (1, 0), (1, 1)]

        # First pass: encode new state in second bit
        for i in range(m):
            for j in range(n):
                live_neighbors = sum(
                    board[i + di][j + dj] & 1
                    for di, dj in dirs
                    if 0 <= i + di < m and 0 <= j + dj < n
                )

                if board[i][j] & 1 == 1:
                    if live_neighbors in (2, 3):
                        board[i][j] = 3  # 11: stays alive
                    # else stays 01: dies
                else:
                    if live_neighbors == 3:
                        board[i][j] = 2  # 10: becomes alive

        # Second pass: update to new state
        for i in range(m):
            for j in range(n):
                board[i][j] >>= 1


if __name__ == "__main__":
    sol = Solution()

    board = [[0, 1, 0], [0, 0, 1], [1, 1, 1], [0, 0, 0]]
    print("Before:", board)
    sol.gameOfLife(board)
    print("After:", board)  # [[0,0,0],[1,0,1],[0,1,1],[0,1,0]]
