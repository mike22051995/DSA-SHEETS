"""
PROBLEM: Minimum Spanning Tree - Prim's Algorithm
Difficulty: Medium-Hard
Pattern: Minimum Spanning Tree (MST)

DESCRIPTION:
Find the Minimum Spanning Tree of a weighted undirected graph.
MST connects all vertices with minimum total edge weight and no cycles.

APPROACH:
1. Start from any vertex
2. Use min-heap to always pick minimum weight edge
3. Add vertex to MST if not already included
4. Add all edges from new vertex to heap
5. Repeat until all vertices are in MST

TIME COMPLEXITY: O(E * log V)
SPACE COMPLEXITY: O(V + E)
"""

from typing import List
import heapq


class Solution:
    def primMST(self, V: int, adj: List[List[List[int]]]) -> int:
        in_mst = [False] * V
        pq = [(0, 0)]  # (weight, vertex)
        mst_weight = 0
        edges_count = 0
        while pq and edges_count < V:
            weight, u = heapq.heappop(pq)
            if in_mst[u]:
                continue
            in_mst[u] = True
            mst_weight += weight
            edges_count += 1
            for v, w in adj[u]:
                if not in_mst[v]:
                    heapq.heappush(pq, (w, v))
        return mst_weight


if __name__ == "__main__":
    V = 5
    adj = [[] for _ in range(V)]
    adj[0].append([1, 2]); adj[1].append([0, 2])
    adj[0].append([3, 6]); adj[3].append([0, 6])
    adj[1].append([2, 3]); adj[2].append([1, 3])
    adj[1].append([3, 8]); adj[3].append([1, 8])
    adj[1].append([4, 5]); adj[4].append([1, 5])
    adj[2].append([4, 7]); adj[4].append([2, 7])
    sol = Solution()
    print(f"MST Weight: {sol.primMST(V, adj)}")
