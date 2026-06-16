"""
PROBLEM: Bridges in a Graph (Critical Connections)
Difficulty: Hard
Pattern: DFS with Discovery and Low Time

DESCRIPTION:
Find all bridges in an undirected graph.
A bridge is an edge whose removal increases the number of connected components.

APPROACH:
1. Use DFS to assign discovery time and low time to each vertex
2. An edge (u,v) is a bridge if low[v] > disc[u]
3. This means v cannot reach u or any ancestor of u without using edge (u,v)

TIME COMPLEXITY: O(V + E)
SPACE COMPLEXITY: O(V)
"""

from typing import List


class Solution:
    def __init__(self):
        self.timer = 0

    def dfs(self, u: int, parent: int, adj: List[List[int]], disc: List[int],
            low: List[int], visited: List[bool], bridges: List[List[int]]):
        visited[u] = True
        self.timer += 1
        disc[u] = low[u] = self.timer
        for v in adj[u]:
            if v == parent:
                continue
            if visited[v]:
                # Back edge
                low[u] = min(low[u], disc[v])
            else:
                # Tree edge
                self.dfs(v, u, adj, disc, low, visited, bridges)
                low[u] = min(low[u], low[v])
                # Check bridge condition
                if low[v] > disc[u]:
                    bridges.append([u, v])

    def findBridges(self, V: int, adj: List[List[int]]) -> List[List[int]]:
        disc = [-1] * V
        low = [-1] * V
        visited = [False] * V
        bridges = []
        for i in range(V):
            if not visited[i]:
                self.dfs(i, -1, adj, disc, low, visited, bridges)
        return bridges


if __name__ == "__main__":
    V = 5
    adj = [[] for _ in range(V)]
    adj[0].append(1); adj[1].append(0)
    adj[1].append(2); adj[2].append(1)
    adj[2].append(3); adj[3].append(2)
    adj[1].append(3); adj[3].append(1)
    adj[3].append(4); adj[4].append(3)
    sol = Solution()
    bridges = sol.findBridges(V, adj)
    print("Bridges (Critical Connections):")
    if bridges:
        for b in bridges:
            print(f"  {b[0]} -- {b[1]}")
    else:
        print("None")
