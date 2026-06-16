"""
PROBLEM: Is Graph Bipartite? (LeetCode 785)
Difficulty: Medium
Pattern: BFS/DFS with Coloring

DESCRIPTION:
A graph is bipartite if we can divide its vertices into two independent sets such that
every edge connects a vertex from one set to the other.
Check if the given graph is bipartite.

APPROACH:
1. Try to color the graph using 2 colors (0 and 1)
2. Use BFS/DFS to traverse and color nodes
3. If any adjacent nodes have the same color, it's not bipartite
4. Check all components for disconnected graphs

TIME COMPLEXITY: O(V + E)
SPACE COMPLEXITY: O(V) for color array and queue
"""

from typing import List
from collections import deque


class Solution:
    def bfsCheck(self, start: int, graph: List[List[int]], color: List[int]) -> bool:
        q = deque()
        q.append(start)
        color[start] = 0
        while q:
            node = q.popleft()
            for neighbor in graph[node]:
                # If not colored, color with opposite color
                if color[neighbor] == -1:
                    color[neighbor] = 1 - color[node]
                    q.append(neighbor)
                # If same color as current node, not bipartite
                elif color[neighbor] == color[node]:
                    return False
        return True

    def isBipartite(self, graph: List[List[int]]) -> bool:
        n = len(graph)
        color = [-1] * n
        for i in range(n):
            if color[i] == -1:
                if not self.bfsCheck(i, graph, color):
                    return False
        return True


if __name__ == "__main__":
    sol = Solution()
    graph1 = [[1, 3], [0, 2], [1, 3], [0, 2]]
    print(f"Graph 1 is bipartite: {sol.isBipartite(graph1)}")
    graph2 = [[1, 2, 3], [0, 2], [0, 1, 3], [0, 2]]
    print(f"Graph 2 is bipartite: {sol.isBipartite(graph2)}")
