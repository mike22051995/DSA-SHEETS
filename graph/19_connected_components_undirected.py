"""
PROBLEM: Number of Connected Components (LeetCode 323)
Difficulty: Medium
Pattern: Union-Find / DFS

DESCRIPTION:
Given n nodes labeled from 0 to n-1 and a list of undirected edges,
find the number of connected components in the graph.

APPROACH (Using Union-Find):
1. Initialize Union-Find with n components
2. For each edge, union the two nodes
3. Return the number of remaining components

TIME COMPLEXITY: O(E * α(N)) where α is inverse Ackermann function
SPACE COMPLEXITY: O(N)
"""

from typing import List


class UnionFind:
    def __init__(self, n: int):
        self.parent = list(range(n))
        self.rank = [0] * n
        self.components = n

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
        self.components -= 1
        return True

    def getComponents(self) -> int:
        return self.components


class Solution:
    def countComponents(self, n: int, edges: List[List[int]]) -> int:
        uf = UnionFind(n)
        for u, v in edges:
            uf.unite(u, v)
        return uf.getComponents()


if __name__ == "__main__":
    sol = Solution()
    print(f"Number of components: {sol.countComponents(5, [[0,1],[1,2],[3,4]])}")
    print(f"Number of components: {sol.countComponents(5, [[0,1],[1,2],[2,3],[3,4]])}")
