"""
PROBLEM: 01 Matrix (LeetCode 542)
Difficulty: Medium
Pattern: Multi-Source BFS

DESCRIPTION:
Given a matrix with 0s and 1s, find the distance of the nearest 0 for each cell.
Distance is calculated as |r1 - r2| + |c1 - c2| (Manhattan distance).

APPROACH:
1. Use multi-source BFS starting from all 0s simultaneously
2. Add all 0 cells to queue initially and set distance to 0
3. For cells with 1, set initial distance to infinity
4. Process BFS level by level, updating distances

TIME COMPLEXITY: O(M * N)
SPACE COMPLEXITY: O(M * N) for queue and distance matrix
"""

from typing import List
from collections import deque


class Solution:
    def updateMatrix(self, mat: List[List[int]]) -> List[List[int]]:
        m, n = len(mat), len(mat[0])
        dist = [[float('inf')] * n for _ in range(m)]
        q = deque()
        # Add all 0s to queue and set their distance to 0
        for i in range(m):
            for j in range(n):
                if mat[i][j] == 0:
                    dist[i][j] = 0
                    q.append((i, j))
        # Directions: up, down, left, right
        dirs = [(-1, 0), (1, 0), (0, -1), (0, 1)]
        # BFS
        while q:
            r, c = q.popleft()
            for dr, dc in dirs:
                nr, nc = r + dr, c + dc
                if 0 <= nr < m and 0 <= nc < n:
                    if dist[nr][nc] > dist[r][c] + 1:
                        dist[nr][nc] = dist[r][c] + 1
                        q.append((nr, nc))
        return dist


if __name__ == "__main__":
    sol = Solution()
    mat = [
        [0, 0, 0],
        [0, 1, 0],
        [1, 1, 1]
    ]
    print("Input Matrix:")
    for row in mat:
        print(" ".join(map(str, row)))
    result = sol.updateMatrix(mat)
    print("\nDistance Matrix:")
    for row in result:
        print(" ".join(map(str, row)))
