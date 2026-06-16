"""
PROBLEM: Pacific Atlantic Water Flow (LeetCode 417)
Difficulty: Medium
Pattern: Multi-Source DFS/BFS

DESCRIPTION:
Given an m x n matrix of heights representing an island. Rain water can flow to
neighboring cells if the neighbor's height is less than or equal to current cell.
Water can flow from any cell adjacent to the Pacific (top and left edges) and
Atlantic (bottom and right edges) oceans.
Return cells where water can flow to both oceans.

APPROACH:
1. Start DFS from Pacific borders (top and left)
2. Start DFS from Atlantic borders (bottom and right)
3. Mark cells reachable from each ocean
4. Return cells reachable from both oceans

TIME COMPLEXITY: O(M * N)
SPACE COMPLEXITY: O(M * N) for two boolean matrices
"""

from typing import List


class Solution:
    def dfs(self, heights: List[List[int]], reachable: List[List[bool]], i: int, j: int):
        m, n = len(heights), len(heights[0])
        reachable[i][j] = True
        dirs = [(-1, 0), (1, 0), (0, -1), (0, 1)]
        for dr, dc in dirs:
            ni, nj = i + dr, j + dc
            # Water flows from high to low, so check if neighbor is >= current
            if 0 <= ni < m and 0 <= nj < n and not reachable[ni][nj] and heights[ni][nj] >= heights[i][j]:
                self.dfs(heights, reachable, ni, nj)

    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        m, n = len(heights), len(heights[0])
        pacific = [[False] * n for _ in range(m)]
        atlantic = [[False] * n for _ in range(m)]
        for i in range(m):
            self.dfs(heights, pacific, i, 0)
            self.dfs(heights, atlantic, i, n - 1)
        for j in range(n):
            self.dfs(heights, pacific, 0, j)
            self.dfs(heights, atlantic, m - 1, j)
        result = []
        for i in range(m):
            for j in range(n):
                if pacific[i][j] and atlantic[i][j]:
                    result.append([i, j])
        return result


if __name__ == "__main__":
    sol = Solution()
    heights = [
        [1, 2, 2, 3, 5],
        [3, 2, 3, 4, 4],
        [2, 4, 5, 3, 1],
        [6, 7, 1, 4, 5],
        [5, 1, 1, 2, 4]
    ]
    result = sol.pacificAtlantic(heights)
    print("Cells that can reach both oceans:", result)
