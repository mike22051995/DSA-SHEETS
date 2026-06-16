"""
PROBLEM: Word Search II (LeetCode 212)
Difficulty: Hard
Company: Google, Meta, Amazon, Microsoft, Netflix
Pattern: Trie + Backtracking

DESCRIPTION:
Given a board and a list of words, return all words found on the board.
Words are constructed from sequentially adjacent cells (4-directionally).
Same cell may not be used more than once per word.

APPROACH:
1. Build Trie from all words
2. DFS from each cell following Trie branches
3. When word end reached, add to result and remove from Trie to avoid duplicates

TIME COMPLEXITY: O(M * N * 4^L) where L = max word length
SPACE COMPLEXITY: O(W * L) for Trie
"""

from typing import List


class TrieNode:
    def __init__(self):
        self.children = {}
        self.word = ""


class Solution:
    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        root = TrieNode()

        # Build Trie
        for word in words:
            node = root
            for ch in word:
                if ch not in node.children:
                    node.children[ch] = TrieNode()
                node = node.children[ch]
            node.word = word

        m, n = len(board), len(board[0])
        result = []
        dirs = [(-1, 0), (1, 0), (0, -1), (0, 1)]

        def dfs(i: int, j: int, node: TrieNode) -> None:
            ch = board[i][j]
            if ch not in node.children:
                return

            next_node = node.children[ch]

            if next_node.word:
                result.append(next_node.word)
                next_node.word = ""  # Avoid duplicates

            board[i][j] = '#'  # Mark visited

            for di, dj in dirs:
                ni, nj = i + di, j + dj
                if 0 <= ni < m and 0 <= nj < n and board[ni][nj] != '#':
                    dfs(ni, nj, next_node)

            board[i][j] = ch  # Backtrack

            # Prune empty branches
            if not next_node.children:
                del node.children[ch]

        for i in range(m):
            for j in range(n):
                dfs(i, j, root)

        return result


if __name__ == "__main__":
    sol = Solution()

    board = [['o', 'a', 'a', 'n'], ['e', 't', 'a', 'e'],
             ['i', 'h', 'k', 'r'], ['i', 'f', 'l', 'v']]
    words = ["oath", "pea", "eat", "rain"]
    print("Found words:", sorted(sol.findWords(board, words)))  # ["eat","oath"]
