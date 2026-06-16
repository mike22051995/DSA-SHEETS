"""
PROBLEM: Word Search (LeetCode 79)
Difficulty: Medium
Company: Microsoft, Google, Meta, Amazon, Netflix
Pattern: Backtracking on Matrix

DESCRIPTION:
Given an m x n grid of characters and a string word, return true if word exists in the grid.
The word can be constructed from letters of sequentially adjacent cells.
The same cell cannot be used more than once.

APPROACH:
1. For each cell, start DFS if it matches first character
2. Use backtracking to explore all possible paths
3. Mark current cell as visited temporarily
4. Try all 4 directions recursively
5. Backtrack: unmark cell

TIME COMPLEXITY: O(M * N * 4^L) where L = word length
SPACE COMPLEXITY: O(L) for recursion stack
"""

from typing import List


class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        if not board or not word:
            return False

        m, n = len(board), len(board[0])

        def dfs(index: int, i: int, j: int) -> bool:
            if index == len(word):
                return True
            if i < 0 or i >= m or j < 0 or j >= n or board[i][j] != word[index]:
                return False

            # Mark as visited
            temp = board[i][j]
            board[i][j] = '#'

            # Try all 4 directions
            found = (dfs(index + 1, i + 1, j) or
                     dfs(index + 1, i - 1, j) or
                     dfs(index + 1, i, j + 1) or
                     dfs(index + 1, i, j - 1))

            # Backtrack
            board[i][j] = temp
            return found

        for i in range(m):
            for j in range(n):
                if board[i][j] == word[0] and dfs(0, i, j):
                    return True

        return False


if __name__ == "__main__":
    sol = Solution()

    board = [['A', 'B', 'C', 'E'], ['S', 'F', 'C', 'S'], ['A', 'D', 'E', 'E']]
    print("Exist 'ABCCED':", sol.exist(board, "ABCCED"))  # True
    print("Exist 'SEE':", sol.exist(board, "SEE"))        # True
    print("Exist 'ABCB':", sol.exist(board, "ABCB"))      # False
