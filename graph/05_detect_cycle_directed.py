"""
PROBLEM: Detect Cycle in Directed Graph
Difficulty: Medium
Pattern: DFS with Recursion Stack

DESCRIPTION:
Given a directed graph, detect if it contains any cycle.

APPROACH:
1. Use DFS with two arrays: visited and recursion stack
2. visited tracks all visited nodes
3. recursionStack tracks nodes in current DFS path
4. If we reach a node that's in recursion stack, cycle exists

TIME COMPLEXITY: O(V + E)
SPACE COMPLEXITY: O(V) for visited and recursion stack arrays
"""

from typing import List


class Solution:
    def dfsCheckCycle(self, node: int, adj: List[List[int]], visited: List[bool], recStack: List[bool]) -> bool:
        visited[node] = True
        recStack[node] = True
        for neighbor in adj[node]:
            if not visited[neighbor]:
                if self.dfsCheckCycle(neighbor, adj, visited, recStack):
                    return True
            elif recStack[neighbor]:
                return True
        # Remove from recursion stack before returning
        recStack[node] = False
        return False

    def isCyclic(self, V: int, adj: List[List[int]]) -> bool:
        visited = [False] * V
        recStack = [False] * V
        for i in range(V):
            if not visited[i]:
                if self.dfsCheckCycle(i, adj, visited, recStack):
                    return True
        return False


if __name__ == "__main__":
    sol = Solution()
    V1 = 4
    adj1 = [[] for _ in range(V1)]
    adj1[0].append(1)
    adj1[1].append(2)
    adj1[2].append(3)
    adj1[3].append(1)  # cycle: 1->2->3->1
    print(f"Graph 1 has cycle: {sol.isCyclic(V1, adj1)}")
    V2 = 4
    adj2 = [[] for _ in range(V2)]
    adj2[0].append(1)
    adj2[1].append(2)
    adj2[2].append(3)
    print(f"Graph 2 has cycle: {sol.isCyclic(V2, adj2)}")
