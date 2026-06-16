"""
PROBLEM: Minimum Spanning Tree - Kruskal's Algorithm
Difficulty: Medium-Hard
Pattern: MST using Union-Find

DESCRIPTION:
Find the Minimum Spanning Tree using Kruskal's algorithm.
Sort edges by weight and use Union-Find to avoid cycles.

APPROACH:
1. Sort all edges by weight
2. Use Union-Find to track connected components
3. For each edge, if it connects different components, add to MST
4. Stop when we have V-1 edges

TIME COMPLEXITY: O(E * log E) for sorting
SPACE COMPLEXITY: O(V)
"""

from typing import List


class UnionFind:
    def __init__(self, n: int):
        self.parent = list(range(n))
        self.rank = [0] * n

    def find(self, x: int) -> int:
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]

    def unite(self, x: int, y: int) -> bool:
        px, py = self.find(x), self.find(y)
        if px == py:
            return False
        if self.rank[px] < self.rank[py]:
            px, py = py, px
        self.parent[py] = px
        if self.rank[px] == self.rank[py]:
            self.rank[px] += 1
        return True


class Solution:
    def kruskalMST(self, V: int, edges: List[List[int]]) -> int:
        # edges[i] = [u, v, weight]
        # Sort edges by weight
        edges.sort(key=lambda e: e[2])
        uf = UnionFind(V)
        mst_weight = 0
        edges_added = 0
        mst_edges = []
        for u, v, weight in edges:
            # If adding edge doesn't create cycle
            if uf.unite(u, v):
                mst_weight += weight
                mst_edges.append((u, v))
                edges_added += 1
                # MST complete
                if edges_added == V - 1:
                    break
        print("MST Edges:")
        for u, v in mst_edges:
            print(f"  {u} -- {v}")
        return mst_weight


if __name__ == "__main__":
    V = 5
    edges = [[0,1,2],[0,3,6],[1,2,3],[1,3,8],[1,4,5],[2,4,7]]
    sol = Solution()
    print(f"\nMST Weight: {sol.kruskalMST(V, edges)}")
