"""
PROBLEM: Union-Find (Disjoint Set Union)
Difficulty: Medium
Pattern: Union-Find Data Structure

DESCRIPTION:
Implement Union-Find data structure with path compression and union by rank.
This is fundamental for many graph problems involving connected components.

OPERATIONS:
1. Find: Find the representative/parent of a set
2. Union: Merge two sets
3. Path Compression: Optimize find operation
4. Union by Rank: Attach smaller tree under larger tree

TIME COMPLEXITY: O(α(N)) for both find and union (nearly constant)
SPACE COMPLEXITY: O(N) for parent and rank arrays
"""


class UnionFind:
    def __init__(self, n: int):
        self.parent = list(range(n))
        self.rank = [0] * n
        self.components = n

    def find(self, x: int) -> int:
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])  # path compression
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

    def isConnected(self, x: int, y: int) -> bool:
        return self.find(x) == self.find(y)

    def getComponents(self) -> int:
        return self.components


if __name__ == "__main__":
    uf = UnionFind(5)
    print(f"Initial components: {uf.getComponents()}")
    uf.unite(0, 1)
    print(f"After union(0,1): {uf.getComponents()}")
    uf.unite(1, 2)
    print(f"After union(1,2): {uf.getComponents()}")
    uf.unite(3, 4)
    print(f"After union(3,4): {uf.getComponents()}")
    print(f"\nAre 0 and 2 connected? {uf.isConnected(0, 2)}")
    print(f"Are 0 and 3 connected? {uf.isConnected(0, 3)}")
    uf.unite(2, 3)
    print(f"\nAfter union(2,3): {uf.getComponents()}")
    print(f"Are 0 and 4 connected? {uf.isConnected(0, 4)}")
