"""
PROBLEM: BFS Traversal of Graph
Difficulty: Easy
Pattern: Breadth First Search (BFS)

DESCRIPTION:
Given a connected undirected graph, perform Breadth First Search traversal starting from vertex 0.
Print all vertices in the order they are visited level by level.

APPROACH:
1. Use a queue to traverse the graph level by level
2. Mark vertices as visited to avoid cycles
3. Process all vertices at current level before moving to next level

TIME COMPLEXITY: O(V + E) where V = vertices, E = edges
SPACE COMPLEXITY: O(V) for visited array and queue
"""

from typing import List
from collections import deque


class Solution:
    def bfsTraversal(self, V: int, adj: List[List[int]]) -> List[int]:
        visited = [False] * V
        result = []
        # Handle disconnected components
        for i in range(V):
            if not visited[i]:
                q = deque()
                q.append(i)
                visited[i] = True
                while q:
                    node = q.popleft()
                    result.append(node)
                    for neighbor in adj[node]:
                        if not visited[neighbor]:
                            visited[neighbor] = True
                            q.append(neighbor)
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
    result = sol.bfsTraversal(V, adj)
    print("BFS Traversal:", " ".join(map(str, result)))
