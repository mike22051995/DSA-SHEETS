"""
PROBLEM: DFS Traversal of Graph
Difficulty: Easy
Pattern: Depth First Search (DFS)

DESCRIPTION:
Given a connected undirected graph, perform Depth First Search traversal starting from vertex 0.
Print all vertices in the order they are visited.

APPROACH:
1. Use recursion or stack to traverse the graph
2. Mark vertices as visited to avoid cycles
3. Visit all adjacent unvisited vertices recursively

TIME COMPLEXITY: O(V + E) where V = vertices, E = edges
SPACE COMPLEXITY: O(V) for visited array and recursion stack
"""

from typing import List


class Solution:
    def dfsHelper(self, node: int, adj: List[List[int]], visited: List[bool], result: List[int]):
        # Base condition: skip already visited nodes
        if visited[node]:
            return
        visited[node] = True
        result.append(node)
        for neighbor in adj[node]:
            if not visited[neighbor]:
                self.dfsHelper(neighbor, adj, visited, result)

    def dfsTraversal(self, V: int, adj: List[List[int]]) -> List[int]:
        visited = [False] * V
        result = []
        # Loop over all vertices to handle disconnected components
        for i in range(V):
            if not visited[i]:
                self.dfsHelper(i, adj, visited, result)
        return result


if __name__ == "__main__":
    V = 5
    adj = [[] for _ in range(V)]
    adj[0].append(1)
    adj[0].append(2)
    adj[1].append(0)
    adj[1].append(3)
    adj[2].append(0)
    adj[2].append(4)
    adj[3].append(1)
    adj[4].append(2)
    sol = Solution()
    result = sol.dfsTraversal(V, adj)
    print("DFS Traversal:", " ".join(map(str, result)))
