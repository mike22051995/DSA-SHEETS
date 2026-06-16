"""
PROBLEM: Number of Provinces (LeetCode 547)
Difficulty: Medium
Pattern: Connected Components using DFS/Union-Find

DESCRIPTION:
Given an n x n matrix isConnected where isConnected[i][j] = 1 if cities i and j are
directly connected, and 0 otherwise. Return the total number of provinces.
A province is a group of directly or indirectly connected cities.

APPROACH:
1. Use DFS to find connected components
2. For each unvisited city, start DFS and mark all connected cities
3. Count represents number of provinces

TIME COMPLEXITY: O(N^2) where N = number of cities
SPACE COMPLEXITY: O(N) for visited array and recursion stack
"""

from typing import List


class Solution:
    def dfs(self, city: int, isConnected: List[List[int]], visited: List[bool]):
        visited[city] = True
        # Visit all connected cities
        for i in range(len(isConnected)):
            if isConnected[city][i] == 1 and not visited[i]:
                self.dfs(i, isConnected, visited)

    def findCircleNum(self, isConnected: List[List[int]]) -> int:
        n = len(isConnected)
        visited = [False] * n
        count = 0
        for i in range(n):
            if not visited[i]:
                self.dfs(i, isConnected, visited)
                count += 1
        return count


if __name__ == "__main__":
    sol = Solution()
    isConnected1 = [[1, 1, 0], [1, 1, 0], [0, 0, 1]]
    print(f"Number of provinces: {sol.findCircleNum(isConnected1)}")
    isConnected2 = [[1, 0, 0], [0, 1, 0], [0, 0, 1]]
    print(f"Number of provinces: {sol.findCircleNum(isConnected2)}")
