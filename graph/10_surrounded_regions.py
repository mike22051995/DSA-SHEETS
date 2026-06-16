"""
PROBLEM: Surrounded Regions (LeetCode 130)
Difficulty: Medium
Pattern: DFS/BFS from Boundary

DESCRIPTION:
Capture all regions that are surrounded by 'X'. A region is captured by flipping
all 'O's into 'X's in that surrounded region.
A region is surrounded if it's not connected to the boundary.

APPROACH:
1. Start DFS/BFS from all 'O's on the boundary
2. Mark all boundary-connected 'O's as safe (change to temporary marker)
3. Flip all remaining 'O's to 'X' (these are surrounded)
4. Restore safe 'O's back to 'O'

TIME COMPLEXITY: O(M * N)
SPACE COMPLEXITY: O(M * N) for recursion stack
"""

from typing import List


class Solution:
    def dfs(self, board: List[List[str]], i: int, j: int):
        m, n = len(board), len(board[0])
        if i < 0 or i >= m or j < 0 or j >= n or board[i][j] != 'O':
            return
        # Mark as safe (boundary-connected)
        board[i][j] = 'S'
        # Visit all 4 directions
        self.dfs(board, i + 1, j)
        self.dfs(board, i - 1, j)
        self.dfs(board, i, j + 1)
        self.dfs(board, i, j - 1)

    def solve(self, board: List[List[str]]) -> None:
        m, n = len(board), len(board[0])
        # Mark boundary-connected O's as safe
        for i in range(m):
            self.dfs(board, i, 0)
            self.dfs(board, i, n - 1)
        for j in range(n):
            self.dfs(board, 0, j)
            self.dfs(board, m - 1, j)
        # Flip remaining O's to X, restore S's to O
        for i in range(m):
            for j in range(n):
                if board[i][j] == 'O':
                    board[i][j] = 'X'
                elif board[i][j] == 'S':
                    board[i][j] = 'O'


if __name__ == "__main__":
    sol = Solution()
    board = [
        ['X', 'X', 'X', 'X'],
        ['X', 'O', 'O', 'X'],
        ['X', 'X', 'O', 'X'],
        ['X', 'O', 'X', 'X']
    ]
    print("Before:")
    for row in board:
        print(" ".join(row))
    sol.solve(board)
    print("\nAfter:")
    for row in board:
        print(" ".join(row))
