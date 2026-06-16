"""
PROBLEM: Dijkstra's Shortest Path Algorithm
Difficulty: Medium-Hard
Pattern: Shortest Path - Single Source

DESCRIPTION:
Find the shortest path from a source vertex to all other vertices in a weighted graph
with non-negative edge weights.

APPROACH:
1. Use a min-heap (priority queue) to always process the nearest unvisited vertex
2. Maintain a distance array initialized to infinity
3. Update distances of neighbors if a shorter path is found
4. Repeat until all vertices are processed

TIME COMPLEXITY: O((V + E) * log V) with binary heap
SPACE COMPLEXITY: O(V + E)
"""

from typing import List
import heapq


class Solution:
    def dijkstra(self, V: int, adj: List[List[List[int]]], src: int) -> List[int]:
        dist = [float('inf')] * V
        dist[src] = 0
        pq = [(0, src)]  # (distance, node)
        while pq:
            d, u = heapq.heappop(pq)
            if d > dist[u]:
                continue
            for v, weight in adj[u]:
                if dist[u] + weight < dist[v]:
                    dist[v] = dist[u] + weight
                    heapq.heappush(pq, (dist[v], v))
        return dist


if __name__ == "__main__":
    V = 5
    adj = [[] for _ in range(V)]
    adj[0].append([1, 2]); adj[0].append([2, 4])
    adj[1].append([2, 1]); adj[1].append([3, 7])
    adj[2].append([4, 3])
    adj[3].append([4, 1])
    adj[4].append([3, 2])
    sol = Solution()
    distances = sol.dijkstra(V, adj, 0)
    print("Shortest distances from vertex 0:")
    for i, d in enumerate(distances):
        if d == float('inf'):
            print(f"Vertex {i}: INF")
        else:
            print(f"Vertex {i}: {d}")
