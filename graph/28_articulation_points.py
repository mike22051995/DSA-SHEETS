"""
PROBLEM: Articulation Points (Cut Vertices)
Difficulty: Hard
Pattern: DFS with Discovery and Low Time

DESCRIPTION:
Find all articulation points in an undirected graph.
An articulation point is a vertex whose removal increases the number of connected components.

APPROACH:
1. Use DFS to assign discovery time and low time to each vertex
2. Low time = minimum discovery time reachable from subtree
3. For root: articulation point if it has more than 1 child
4. For non-root: articulation point if low[child] >= disc[node]

TIME COMPLEXITY: O(V + E)
SPACE COMPLEXITY: O(V)
"""

from typing import List


class Solution:
    def __init__(self):
        self.timer = 0

    def dfs(self, u: int, parent: int, adj: List[List[int]], disc: List[int],
            low: List[int], visited: List[bool], ap: set):
        visited[u] = True
        self.timer += 1
        disc[u] = low[u] = self.timer
        children = 0
        for v in adj[u]:
            if v == parent:
                continue
            if visited[v]:
                # Back edge
                low[u] = min(low[u], disc[v])
            else:
                # Tree edge
                children += 1
                self.dfs(v, u, adj, disc, low, visited, ap)
                low[u] = min(low[u], low[v])
                # Check articulation point conditions
                if parent == -1 and children > 1:
                    ap.add(u)
                if parent != -1 and low[v] >= disc[u]:
                    ap.add(u)

    def findArticulationPoints(self, V: int, adj: List[List[int]]) -> List[int]:
        disc = [-1] * V
        low = [-1] * V
        visited = [False] * V
        ap = set()
        for i in range(V):
            if not visited[i]:
                self.dfs(i, -1, adj, disc, low, visited, ap)
        return sorted(ap)


if __name__ == "__main__":
    V = 5
    adj = [[] for _ in range(V)]
    adj[0].append(1); adj[1].append(0)
    adj[1].append(2); adj[2].append(1)
    adj[2].append(3); adj[3].append(2)
    adj[1].append(3); adj[3].append(1)
    adj[3].append(4); adj[4].append(3)
    sol = Solution()
    ap = sol.findArticulationPoints(V, adj)
    print("Articulation Points:", " ".join(map(str, ap)) if ap else "None")
