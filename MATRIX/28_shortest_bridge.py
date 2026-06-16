"""
PROBLEM: Shortest Bridge (LeetCode 934)
Difficulty: Medium
Company: Google, Meta, Amazon
Pattern: DFS + BFS (Multi-source BFS)

DESCRIPTION:
Given an n x n binary matrix with exactly two islands, return the minimum number
of 0's to flip to connect the two islands.

APPROACH:
1. DFS to find and mark all cells of first island, add to BFS queue
2. Multi-source BFS from first island, expanding through water
3. First time BFS hits a 1 from second island → return distance

TIME COMPLEXITY: O(N²)
SPACE COMPLEXITY: O(N²)
"""

from typing import List
from collections import deque


class Solution:
    def shortestBridge(self, grid: List[List[int]]) -> int:
        n = len(grid)
        queue = deque()

        def dfs(i: int, j: int) -> None:
            if i < 0 or i >= n or j < 0 or j >= n or grid[i][j] != 1:
                return
            grid[i][j] = 2  # Mark as visited
            queue.append((i, j))
            dfs(i + 1, j)
            dfs(i - 1, j)
            dfs(i, j + 1)
            dfs(i, j - 1)

        # Find and mark first island
        found = False
        for i in range(n):
            if found:
                break
            for j in range(n):
                if grid[i][j] == 1:
                    dfs(i, j)
                    found = True
                    break

        # BFS from first island to find second island
        dirs = [(-1, 0), (1, 0), (0, -1), (0, 1)]
        distance = 0

        while queue:
            for _ in range(len(queue)):
                i, j = queue.popleft()
                for di, dj in dirs:
                    ni, nj = i + di, j + dj
                    if 0 <= ni < n and 0 <= nj < n:
                        if grid[ni][nj] == 1:
                            return distance
                        if grid[ni][nj] == 0:
                            grid[ni][nj] = 2
                            queue.append((ni, nj))
            distance += 1

        return -1


if __name__ == "__main__":
    import sys
    sys.setrecursionlimit(10000)
    sol = Solution()

    grid1 = [[0, 1], [1, 0]]
    print("Shortest bridge:", sol.shortestBridge(grid1))  # 1

    grid2 = [[0, 1, 0], [0, 0, 0], [0, 0, 1]]
    print("Shortest bridge:", sol.shortestBridge(grid2))  # 2
