"""
PROBLEM: Topological Sort (DFS)
Difficulty: Medium
Pattern: Topological Sort using DFS

DESCRIPTION:
Given a Directed Acyclic Graph (DAG), perform topological sort using DFS.
Use a stack to store the finishing order of vertices.

APPROACH:
1. Use DFS traversal
2. After visiting all neighbors of a vertex, push it to stack
3. The stack will contain vertices in reverse topological order
4. Pop all elements from stack to get topological sort

TIME COMPLEXITY: O(V + E)
SPACE COMPLEXITY: O(V) for visited array and stack
"""

from typing import List


class Solution:
    def dfs(self, node: int, adj: List[List[int]], visited: List[bool], st: list):
        visited[node] = True
        # Visit all neighbors
        for neighbor in adj[node]:
            if not visited[neighbor]:
                self.dfs(neighbor, adj, visited, st)
        # Push to stack after visiting all neighbors
        st.append(node)

    def topoSort(self, V: int, adj: List[List[int]]) -> List[int]:
        visited = [False] * V
        st = []
        for i in range(V):
            if not visited[i]:
                self.dfs(i, adj, visited, st)
        return st[::-1]


if __name__ == "__main__":
    V = 6
    adj = [[] for _ in range(V)]
    adj[5].append(2)
    adj[5].append(0)
    adj[4].append(0)
    adj[4].append(1)
    adj[2].append(3)
    adj[3].append(1)
    sol = Solution()
    result = sol.topoSort(V, adj)
    print("Topological Sort (DFS):", " ".join(map(str, result)))
