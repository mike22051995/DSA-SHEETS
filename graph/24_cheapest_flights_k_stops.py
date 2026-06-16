"""
PROBLEM: Cheapest Flights Within K Stops (LeetCode 787)
Difficulty: Hard
Pattern: Modified Dijkstra / Bellman-Ford

DESCRIPTION:
Find the cheapest price from src to dst with at most k stops.
If no such route exists, return -1.

APPROACH:
1. Use modified Dijkstra with state (cost, node, stops)
2. Track minimum cost to reach each node with given stops
3. Only explore paths with stops <= k
4. Use priority queue ordered by cost

TIME COMPLEXITY: O(E * K * log(E * K))
SPACE COMPLEXITY: O(V * K)
"""

from typing import List
import heapq
from collections import defaultdict


class Solution:
    def findCheapestPrice(self, n: int, flights: List[List[int]], src: int, dst: int, k: int) -> int:
        # Build adjacency list
        adj = defaultdict(list)
        for u, v, price in flights:
            adj[u].append((v, price))
        # dist[node][stops] = min cost
        dist = [[float('inf')] * (k + 2) for _ in range(n)]
        dist[src][0] = 0
        pq = [(0, src, 0)]  # (cost, node, stops)
        while pq:
            cost, node, stops = heapq.heappop(pq)
            # If we reached destination
            if node == dst:
                return cost
            # If we've used all stops
            if stops > k:
                continue
            # Explore neighbors
            for next_node, price in adj[node]:
                new_cost = cost + price
                if new_cost < dist[next_node][stops + 1]:
                    dist[next_node][stops + 1] = new_cost
                    heapq.heappush(pq, (new_cost, next_node, stops + 1))
        return -1


if __name__ == "__main__":
    sol = Solution()
    print(f"Cheapest price: {sol.findCheapestPrice(4, [[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]], 0, 3, 1)}")
    print(f"Cheapest price: {sol.findCheapestPrice(3, [[0,1,100],[1,2,100],[0,2,500]], 0, 2, 1)}")
