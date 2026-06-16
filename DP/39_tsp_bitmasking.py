"""
PROBLEM: Traveling Salesman Problem (TSP) using Bitmasking DP
DIFFICULTY: Hard
PATTERN: Bitmasking DP / State Compression

DESCRIPTION:
Given a set of cities and distance between every pair of cities, find the 
shortest possible route that visits every city exactly once and returns to 
the starting city.

This is NP-hard problem. DP with bitmask gives O(n² * 2^n) solution.

EXAMPLE:
Input: 
dist[][] = 
    {0, 10, 15, 20},
    {10, 0, 35, 25},
    {15, 35, 0, 30},
    {20, 25, 30, 0}
Output: 80
Explanation: 0 → 1 → 3 → 2 → 0 = 10+25+30+15 = 80

TIME COMPLEXITY: O(n² * 2^n)
SPACE COMPLEXITY: O(n * 2^n)
"""

from typing import List, Optional

class Solution:
    def tsp(self, dist):
        n = len(dist)
        # dp[mask][i] = min cost to visit cities in mask, ending at city i
        dp = [[float('inf')] * n for _ in range(1 << n)]
        # Base case: start at city 0
        dp[1][0] = 0
        # Iterate through all masks
        for mask in range(1, (1 << n)):
            for u in range(n):
                if (mask & (1 << u)) and dp[mask][u] != float('inf'):
                    for v in range(n):
                        if not (mask & (1 << v)):
                            new_mask = mask | (1 << v)
                            dp[new_mask][v] = min(dp[new_mask][v], dp[mask][u] + dist[u][v])
        # Find minimum cost to visit all cities and return to start
        allVisited = (1 << n) - 1
        minCost = float('inf')
        for i in range(n):
            if dp[allVisited][i] != float('inf'):
                minCost = min(minCost, dp[allVisited][i] + dist[i][0])
        return minCost

    def tspMemo(self, dist):
        from functools import lru_cache

        n = len(dist)
        all_visited = (1 << n) - 1

        @lru_cache(maxsize=None)
        def dfs(mask, u):
            if mask == all_visited:
                return dist[u][0]
            best = float('inf')
            for v in range(n):
                if not (mask & (1 << v)):
                    best = min(best, dist[u][v] + dfs(mask | (1 << v), v))
            return best

        return dfs(1, 0)

    def getTSPPath(self, dist):
        n = len(dist)
        dp = [[float('inf')] * n for _ in range(1 << n)]
        parent = [[-1] * n for _ in range(1 << n)]
        dp[1][0] = 0

        for mask in range(1, 1 << n):
            for u in range(n):
                if not (mask & (1 << u)) or dp[mask][u] == float('inf'):
                    continue
                for v in range(n):
                    if mask & (1 << v):
                        continue
                    new_mask = mask | (1 << v)
                    new_cost = dp[mask][u] + dist[u][v]
                    if new_cost < dp[new_mask][v]:
                        dp[new_mask][v] = new_cost
                        parent[new_mask][v] = u

        all_visited = (1 << n) - 1
        last = 0
        best = float('inf')
        for i in range(n):
            cost = dp[all_visited][i] + dist[i][0]
            if cost < best:
                best = cost
                last = i

        path = [0]
        order = []
        mask = all_visited
        curr = last
        while curr != -1 and curr != 0:
            order.append(curr)
            prev = parent[mask][curr]
            mask ^= (1 << curr)
            curr = prev
        order.reverse()
        path.extend(order)
        path.append(0)
        return path


if __name__ == "__main__":
    sol = Solution()
    print(f"Test Case 1:")
    dist1 = [
        [0, 10, 15, 20],
        [10, 0, 35, 25],
        [15, 35, 0, 30],
        [20, 25, 30, 0],
    ]
    print(f"Distance matrix:")
    for row in dist1:
        for val in row:
            print(val, end="\t")
        print()
    print(f"Minimum cost (DP): {sol.tsp(dist1)}")
    print(f"Minimum cost (Memo): {sol.tspMemo(dist1)}")
    path1 = sol.getTSPPath(dist1)
    print(f"Optimal path: {path1}")
    print(f"\nTest Case 2:")
    dist2 = [
        [0, 20, 42, 25],
        [20, 0, 30, 34],
        [42, 30, 0, 10],
        [25, 34, 10, 0],
    ]
    print(f"Distance matrix:")
    for row in dist2:
        for val in row:
            print(val, end="\t")
        print()
    print(f"Minimum cost: {sol.tsp(dist2)}")
    path2 = sol.getTSPPath(dist2)
    print(f"Optimal path: {path2}")
    print(f"\nTest Case 3:")
    dist3 = [
        [0, 10, 15],
        [10, 0, 20],
        [15, 20, 0],
    ]
    print(f"Distance matrix:")
    for row in dist3:
        for val in row:
            print(val, end="\t")
        print()
    print(f"Minimum cost: {sol.tsp(dist3)}")
