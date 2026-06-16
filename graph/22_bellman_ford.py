"""
PROBLEM: Bellman-Ford Algorithm
Difficulty: Medium-Hard
Pattern: Shortest Path with Negative Weights

DESCRIPTION:
Find shortest paths from source to all vertices, even with negative edge weights.
Can detect negative weight cycles.

APPROACH:
1. Initialize distances to infinity except source (0)
2. Relax all edges V-1 times
3. Check for negative weight cycles in Vth iteration
4. If any distance can still be reduced, negative cycle exists

TIME COMPLEXITY: O(V * E)
SPACE COMPLEXITY: O(V)
"""

from typing import List


class Solution:
    def bellmanFord(self, V: int, edges: List[List[int]], src: int) -> List[int]:
        # edges[i] = [u, v, weight]
        dist = [float('inf')] * V
        dist[src] = 0
        # Relax all edges V-1 times
        for _ in range(V - 1):
            for u, v, weight in edges:
                if dist[u] != float('inf') and dist[u] + weight < dist[v]:
                    dist[v] = dist[u] + weight
        # Check for negative weight cycles
        for u, v, weight in edges:
            if dist[u] != float('inf') and dist[u] + weight < dist[v]:
                print("Graph contains negative weight cycle!")
                return []
        return dist


if __name__ == "__main__":
    sol = Solution()
    V = 5
    edges = [
        [0, 1, -1], [0, 2, 4],
        [1, 2, 3], [1, 3, 2], [1, 4, 2],
        [3, 2, 5], [3, 1, 1], [4, 3, -3]
    ]
    distances = sol.bellmanFord(V, edges, 0)
    if distances:
        print("Shortest distances from vertex 0:")
        for i, d in enumerate(distances):
            if d == float('inf'):
                print(f"Vertex {i}: INF")
            else:
                print(f"Vertex {i}: {d}")
