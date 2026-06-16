"""
PROBLEM: Clone Graph (LeetCode 133)
Difficulty: Medium
Pattern: DFS/BFS with HashMap

DESCRIPTION:
Given a reference of a node in a connected undirected graph, return a deep copy (clone) of the graph.
Each node contains a value and a list of its neighbors.

APPROACH:
1. Use a hashmap to store mapping of original node to cloned node
2. Use DFS to traverse the graph
3. For each node, create a clone and add to hashmap
4. Recursively clone all neighbors

TIME COMPLEXITY: O(V + E)
SPACE COMPLEXITY: O(V) for hashmap and recursion stack
"""

from typing import Optional


class Node:
    def __init__(self, val=0, neighbors=None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []


class Solution:
    def cloneGraph(self, node: Optional[Node]) -> Optional[Node]:
        if not node:
            return None
        visited = {}

        def dfs(n: Node) -> Node:
            if n in visited:
                return visited[n]
            clone = Node(n.val)
            visited[n] = clone
            for neighbor in n.neighbors:
                clone.neighbors.append(dfs(neighbor))
            return clone

        return dfs(node)


if __name__ == "__main__":
    node1 = Node(1)
    node2 = Node(2)
    node3 = Node(3)
    node4 = Node(4)
    node1.neighbors = [node2, node4]
    node2.neighbors = [node1, node3]
    node3.neighbors = [node2, node4]
    node4.neighbors = [node1, node3]
    sol = Solution()
    cloned = sol.cloneGraph(node1)
    print(f"Original node1 val: {node1.val}, Cloned node1 val: {cloned.val}")
    print(f"Same object? {node1 is cloned}")
