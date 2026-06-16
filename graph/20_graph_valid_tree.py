"""
PROBLEM: Graph Valid Tree (LeetCode 261)
Difficulty: Medium
Pattern: Union-Find / DFS Cycle Detection

DESCRIPTION:
Given n nodes and a list of undirected edges, check if these edges make up a valid tree.
A valid tree must:
1. Be connected (all nodes reachable)
2. Have no cycles
3. Have exactly n-1 edges

APPROACH:
1. A tree with n nodes has exactly n-1 edges
2. Use Union-Find to detect cycles
3. If we can add all edges without forming a cycle, it's a tree

TIME COMPLEXITY: O(E * α(N))
SPACE COMPLEXITY: O(N)
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
    def validTree(self, n: int, edges: List[List[int]]) -> bool:
        # A tree must have exactly n-1 edges
        if len(edges) != n - 1:
            return False
        uf = UnionFind(n)
        # Try to add all edges
        for u, v in edges:
            if not uf.unite(u, v):
                return False  # cycle detected
        return True


if __name__ == "__main__":
    sol = Solution()
    print(f"Is valid tree: {sol.validTree(5, [[0,1],[0,2],[0,3],[1,4]])}")
    print(f"Is valid tree: {sol.validTree(5, [[0,1],[1,2],[2,3],[1,3],[1,4]])}")
