"""
PROBLEM: Rotting Oranges (LeetCode 994)
Difficulty: Medium
Pattern: Multi-Source BFS

DESCRIPTION:
You are given a grid where:
- 0 represents an empty cell
- 1 represents a fresh orange
- 2 represents a rotten orange
Every minute, fresh oranges adjacent (4-directionally) to rotten oranges become rotten.
Return minimum minutes until no fresh oranges remain. If impossible, return -1.

APPROACH:
1. Multi-source BFS starting from all rotten oranges
2. Count fresh oranges initially
3. Process level by level (each level = 1 minute)
4. Track time and fresh oranges rotted
5. If fresh oranges remain, return -1

TIME COMPLEXITY: O(M * N)
SPACE COMPLEXITY: O(M * N) for queue
"""

from typing import List
from collections import deque


class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        q = deque()
        fresh_count = 0
        # Find all rotten oranges and count fresh ones
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 2:
                    q.append((i, j))
                elif grid[i][j] == 1:
                    fresh_count += 1
        # If no fresh oranges, return 0
        if fresh_count == 0:
            return 0
        dirs = [(-1, 0), (1, 0), (0, -1), (0, 1)]
        minutes = 0
        while q:
            size = len(q)
            rotted = False
            for _ in range(size):
                r, c = q.popleft()
                for dr, dc in dirs:
                    nr, nc = r + dr, c + dc
                    if 0 <= nr < m and 0 <= nc < n and grid[nr][nc] == 1:
                        grid[nr][nc] = 2
                        fresh_count -= 1
                        q.append((nr, nc))
                        rotted = True
            if rotted:
                minutes += 1
        return minutes if fresh_count == 0 else -1


if __name__ == "__main__":
    sol = Solution()
    grid = [[2, 1, 1], [1, 1, 0], [0, 1, 1]]
    print(f"Minutes until all oranges rot: {sol.orangesRotting(grid)}")
