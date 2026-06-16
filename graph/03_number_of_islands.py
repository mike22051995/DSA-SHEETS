"""
PROBLEM: Number of Islands (LeetCode 200)
Difficulty: Easy-Medium
Pattern: DFS/BFS on Grid

DESCRIPTION:
Given a 2D grid of '1's (land) and '0's (water), count the number of islands.
An island is surrounded by water and formed by connecting adjacent lands horizontally or vertically.

APPROACH:
1. Iterate through each cell in the grid
2. When we find an unvisited land ('1'), increment island count
3. Use DFS to mark all connected land cells as visited
4. Continue until all cells are processed

TIME COMPLEXITY: O(M * N) where M = rows, N = columns
SPACE COMPLEXITY: O(M * N) for recursion stack in worst case
"""

from typing import List


class Solution:
    def dfs(self, grid: List[List[str]], i: int, j: int):
        m, n = len(grid), len(grid[0])
        # Base cases: out of bounds or water or already visited
        if i < 0 or i >= m or j < 0 or j >= n or grid[i][j] == '0':
            return
        # Mark as visited by changing to '0'
        grid[i][j] = '0'
        # Visit all 4 directions
        self.dfs(grid, i + 1, j)
        self.dfs(grid, i - 1, j)
        self.dfs(grid, i, j + 1)
        self.dfs(grid, i, j - 1)

    def numIslands(self, grid: List[List[str]]) -> int:
        count = 0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == '1':
                    count += 1
                    self.dfs(grid, i, j)
        return count


if __name__ == "__main__":
    sol = Solution()
    grid1 = [
        ['1', '1', '0', '0', '0'],
        ['1', '1', '0', '0', '0'],
        ['0', '0', '1', '0', '0'],
        ['0', '0', '0', '1', '1']
    ]
    print(f"Number of Islands: {sol.numIslands(grid1)}")
