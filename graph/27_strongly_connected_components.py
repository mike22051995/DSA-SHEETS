"""
PROBLEM: Strongly Connected Components - Kosaraju's Algorithm
Difficulty: Hard
Pattern: SCC using Two DFS

DESCRIPTION:
Find all Strongly Connected Components (SCCs) in a directed graph.
A strongly connected component is a maximal set of vertices where every vertex
is reachable from every other vertex in the set.

APPROACH:
1. First DFS: Fill stack with vertices in finishing order
2. Transpose the graph (reverse all edges)
3. Second DFS: Process vertices from stack, each DFS gives one SCC

TIME COMPLEXITY: O(V + E)
SPACE COMPLEXITY: O(V)
"""

from typing import List


class Solution:
    def dfs1(self, node: int, adj: List[List[int]], visited: List[bool], st: list):
        visited[node] = True
        for neighbor in adj[node]:
            if not visited[neighbor]:
                self.dfs1(neighbor, adj, visited, st)
        st.append(node)

    def dfs2(self, node: int, adj_rev: List[List[int]], visited: List[bool], component: list):
        visited[node] = True
        component.append(node)
        for neighbor in adj_rev[node]:
            if not visited[neighbor]:
                self.dfs2(neighbor, adj_rev, visited, component)

    def findSCCs(self, V: int, adj: List[List[int]]) -> List[List[int]]:
        visited = [False] * V
        st = []
        for i in range(V):
            if not visited[i]:
                self.dfs1(i, adj, visited, st)
        # Build reversed graph
        adj_rev = [[] for _ in range(V)]
        for u in range(V):
            for v in adj[u]:
                adj_rev[v].append(u)
        visited = [False] * V
        sccs = []
        while st:
            node = st.pop()
            if not visited[node]:
                component = []
                self.dfs2(node, adj_rev, visited, component)
                sccs.append(component)
        return sccs


if __name__ == "__main__":
    V = 5
    adj = [[] for _ in range(V)]
    adj[0].append(1); adj[1].append(2); adj[2].append(0)
    adj[1].append(3); adj[3].append(4)
    sol = Solution()
    sccs = sol.findSCCs(V, adj)
    print("Strongly Connected Components:")
    for i, scc in enumerate(sccs):
        print(f"SCC {i}: {' '.join(map(str, scc))}")
