"""
PROBLEM: Network Delay Time (LeetCode 743)
Difficulty: Medium-Hard
Pattern: Dijkstra's Algorithm Application

DESCRIPTION:
Given a network of n nodes labeled 1 to n, and a list of travel times as directed edges
times[i] = (ui, vi, wi), where ui is source, vi is target, and wi is the time for a
signal to travel. Send a signal from node k. Return the minimum time for all nodes to
receive the signal. If impossible, return -1.

APPROACH:
1. Build adjacency list from edges
2. Use Dijkstra's algorithm from source k
3. Find maximum distance among all nodes
4. If any node is unreachable, return -1

TIME COMPLEXITY: O((V + E) * log V)
SPACE COMPLEXITY: O(V + E)
"""

from typing import List
import heapq
from collections import defaultdict


class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        # Build adjacency list
        adj = defaultdict(list)
        for u, v, w in times:
            adj[u].append((v, w))
        # Dijkstra's algorithm
        dist = [float('inf')] * (n + 1)
        dist[k] = 0
        pq = [(0, k)]
        while pq:
            d, u = heapq.heappop(pq)
            if d > dist[u]:
                continue
            for v, w in adj[u]:
                if dist[u] + w < dist[v]:
                    dist[v] = dist[u] + w
                    heapq.heappush(pq, (dist[v], v))
        # Find maximum distance among all nodes
        max_time = max(dist[1:])
        return max_time if max_time != float('inf') else -1


if __name__ == "__main__":
    sol = Solution()
    print(f"Network delay time: {sol.networkDelayTime([[2,1,1],[2,3,1],[3,4,1]], 4, 2)}")
    print(f"Network delay time: {sol.networkDelayTime([[1,2,1]], 2, 1)}")
    print(f"Network delay time: {sol.networkDelayTime([[1,2,1]], 2, 2)}")
