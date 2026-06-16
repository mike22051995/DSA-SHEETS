"""
PROBLEM: Detect Cycle in Undirected Graph
Difficulty: Easy-Medium
Pattern: DFS with Parent Tracking

DESCRIPTION:
Given an undirected graph, detect if it contains any cycle.

APPROACH:
1. Use DFS traversal
2. Keep track of parent node to avoid False cycle detection
3. If we visit an already visited node that is not the parent, cycle exists

TIME COMPLEXITY: O(V + E)
SPACE COMPLEXITY: O(V) for visited array and recursion stack
"""

from typing import List


class Solution:
    def dfsCheckCycle(self, node: int, parent: int, adj: List[List[int]], visited: List[bool]) -> bool:
        visited[node] = True
        for neighbor in adj[node]:
            if not visited[neighbor]:
                if self.dfsCheckCycle(neighbor, node, adj, visited):
                    return True
            elif neighbor != parent:
                return True
        return False

    def isCycle(self, V: int, adj: List[List[int]]) -> bool:
        visited = [False] * V
        for i in range(V):
            if not visited[i]:
                if self.dfsCheckCycle(i, -1, adj, visited):
                    return True
        return False


if __name__ == "__main__":
    sol = Solution()
    V1 = 5
    adj1 = [[] for _ in range(V1)]
    adj1[0].append(1); adj1[1].append(0)
    adj1[1].append(2); adj1[2].append(1)
    adj1[2].append(3); adj1[3].append(2)
    adj1[3].append(4); adj1[4].append(3)
    adj1[4].append(1); adj1[1].append(4)  # creates cycle
    print(f"Graph 1 has cycle: {sol.isCycle(V1, adj1)}")
    V2 = 4
    adj2 = [[] for _ in range(V2)]
    adj2[0].append(1); adj2[1].append(0)
    adj2[1].append(2); adj2[2].append(1)
    adj2[2].append(3); adj2[3].append(2)
    print(f"Graph 2 has cycle: {sol.isCycle(V2, adj2)}")
