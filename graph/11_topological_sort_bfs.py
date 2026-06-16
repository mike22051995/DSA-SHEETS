"""
PROBLEM: Topological Sort (Kahn's Algorithm - BFS)
Difficulty: Medium
Pattern: Topological Sort using BFS

DESCRIPTION:
Given a Directed Acyclic Graph (DAG), perform topological sort.
Topological sort is a linear ordering of vertices such that for every directed edge u.v,
u comes before v in the ordering.

APPROACH:
1. Calculate in-degree for all vertices
2. Add all vertices with in-degree 0 to queue
3. Process vertices from queue, decrement in-degree of neighbors
4. Add vertices with in-degree 0 to queue
5. Repeat until queue is empty

TIME COMPLEXITY: O(V + E)
SPACE COMPLEXITY: O(V) for in-degree array and queue
"""

from typing import List
from collections import deque


class Solution:
    def topoSort(self, V: int, adj: List[List[int]]) -> List[int]:
        indegree = [0] * V
        # Calculate in-degree for all vertices
        for i in range(V):
            for neighbor in adj[i]:
                indegree[neighbor] += 1
        # Add all vertices with in-degree 0
        q = deque()
        for i in range(V):
            if indegree[i] == 0:
                q.append(i)
        topo_order = []
        while q:
            node = q.popleft()
            topo_order.append(node)
            # Reduce in-degree of neighbors
            for neighbor in adj[node]:
                indegree[neighbor] -= 1
                if indegree[neighbor] == 0:
                    q.append(neighbor)
        return topo_order


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
    print("Topological Sort:", " ".join(map(str, result)))
