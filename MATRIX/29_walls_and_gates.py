"""
PROBLEM: Walls and Gates (LeetCode 286)
Difficulty: Medium
Company: Google, Meta, Amazon, Microsoft
Pattern: Multi-source BFS

DESCRIPTION:
Fill each empty room (INF) in a grid with the distance to its nearest gate (0).
Walls are -1. If unreachable, remain INF.

APPROACH:
Multi-source BFS starting from all gates simultaneously.
Each room is visited only once (minimum distance guaranteed).

TIME COMPLEXITY: O(M * N)
SPACE COMPLEXITY: O(M * N)
"""

from typing import List
from collections import deque


class Solution:
    def wallsAndGates(self, rooms: List[List[int]]) -> None:
        if not rooms or not rooms[0]:
            return

        m, n = len(rooms), len(rooms[0])
        INF = 2147483647
        queue = deque()

        # Add all gates to queue
        for i in range(m):
            for j in range(n):
                if rooms[i][j] == 0:
                    queue.append((i, j))

        dirs = [(-1, 0), (1, 0), (0, -1), (0, 1)]

        while queue:
            row, col = queue.popleft()

            for dr, dc in dirs:
                nr, nc = row + dr, col + dc

                if 0 <= nr < m and 0 <= nc < n and rooms[nr][nc] == INF:
                    rooms[nr][nc] = rooms[row][col] + 1
                    queue.append((nr, nc))


if __name__ == "__main__":
    sol = Solution()

    INF = 2147483647
    rooms = [
        [INF, -1, 0, INF],
        [INF, INF, INF, -1],
        [INF, -1, INF, -1],
        [0, -1, INF, INF]
    ]
    sol.wallsAndGates(rooms)
    print("After fill:")
    for row in rooms:
        print(row)
    # [[3,-1,0,1],[2,2,1,-1],[1,-1,2,-1],[0,-1,3,4]]
