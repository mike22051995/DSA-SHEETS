"""
PROBLEM: Shortest Path in Binary Matrix (LeetCode 1091)
Difficulty: Medium
Company: Google, Meta, Amazon, Microsoft
Pattern: BFS - Shortest Path in Grid

DESCRIPTION:
Given an n x n binary matrix grid, return the length of the shortest clear path
from top-left to bottom-right (8-directionally connected 0-cells).
Return -1 if no clear path exists.

APPROACH:
BFS from (0,0) through all 8 directions.
Mark visited cells to avoid revisiting.

TIME COMPLEXITY: O(N²)
SPACE COMPLEXITY: O(N²) for queue
"""

from typing import List
from collections import deque


class Solution:
    def shortestPathBinaryMatrix(self, grid: List[List[int]]) -> int:
        n = len(grid)

        if grid[0][0] == 1 or grid[n-1][n-1] == 1:
            return -1

        if n == 1:
            return 1

        dirs = [(-1, -1), (-1, 0), (-1, 1), (0, -1), (0, 1), (1, -1), (1, 0), (1, 1)]
        queue = deque([(0, 0)])
        grid[0][0] = 1  # Mark visited with distance

        while queue:
            row, col = queue.popleft()
            distance = grid[row][col]

            for dr, dc in dirs:
                nr, nc = row + dr, col + dc

                if 0 <= nr < n and 0 <= nc < n and grid[nr][nc] == 0:
                    if nr == n - 1 and nc == n - 1:
                        return distance + 1
                    grid[nr][nc] = distance + 1
                    queue.append((nr, nc))

        return -1


if __name__ == "__main__":
    sol = Solution()

    grid1 = [[0, 1], [1, 0]]
    print("Shortest path:", sol.shortestPathBinaryMatrix(grid1))  # 2

    grid2 = [[0, 0, 0], [1, 1, 0], [1, 1, 0]]
    print("Shortest path:", sol.shortestPathBinaryMatrix(grid2))  # 4
