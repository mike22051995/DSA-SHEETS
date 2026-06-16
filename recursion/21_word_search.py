"""
PROBLEM: Word Search
---------------------------------------------------------------------------
Given an m x n grid of characters board and a string word, return True if 
word exists in the grid. The word can be constructed from letters of 
sequentially adjacent cells (horizontally or vertically). The same cell 
may not be used more than once.

DIFFICULTY: Medium
PATTERN: Backtracking (2D Grid DFS)
TIME COMPLEXITY: O(m * n * 4^L) where L is word length
SPACE COMPLEXITY: O(L) - recursion depth

INPUT/OUTPUT EXAMPLES:
---------------------------------------------------------------------------
Example 1:
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: True

Example 2:
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
Output: True
"""

from typing import List


class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        m = len(board)
        n = len(board[0])

        def dfs(i: int, j: int, index: int) -> bool:
            if index >= len(word):
                return True
            if i < 0 or i >= m or j < 0 or j >= n or board[i][j] != word[index]:
                return False
            temp = board[i][j]
            board[i][j] = '#'
            found = (dfs(i + 1, j, index + 1) or
                     dfs(i - 1, j, index + 1) or
                     dfs(i, j + 1, index + 1) or
                     dfs(i, j - 1, index + 1))
            board[i][j] = temp
            return found

        for i in range(m):
            for j in range(n):
                if dfs(i, j, 0):
                    return True
        return False


if __name__ == "__main__":
    sol = Solution()
    board1 = [
        ['A', 'B', 'C', 'E'],
        ['S', 'F', 'C', 'S'],
        ['A', 'D', 'E', 'E']
    ]
    word1 = "ABCCED"
    print(f"Test 1: Word '{word1}' exists? {sol.exist(board1, word1)}")
    board2 = [
        ['A', 'B', 'C', 'E'],
        ['S', 'F', 'C', 'S'],
        ['A', 'D', 'E', 'E']
    ]
    word2 = "SEE"
    print(f"Test 2: Word '{word2}' exists? {sol.exist(board2, word2)}")
