"""
PROBLEM: Minimum Score Triangulation of Polygon (LeetCode 1039)
DIFFICULTY: Medium  
PATTERN: Interval/Partition DP

DESCRIPTION:
You have a convex n-sided polygon where each vertex has an integer value.
You are given an integer array values where values[i] is the value of the 
ith vertex (in order).

Triangulate the polygon into n-2 triangles. For each triangle, the value 
of that triangle is the product of the values of its vertices, and the 
total score is the sum of these values over all n-2 triangles.

Return the smallest possible total score that you can achieve with some 
triangulation of the polygon.

EXAMPLE:
Input: values = [1,2,3]
Output: 6
Explanation: Only one triangle: 1*2*3 = 6

Input: values = [3,7,4,5]
Output: 144
Explanation: Triangulation: (3,7,4) + (3,4,5) = 84 + 60 = 144

Input: values = [1,3,1,4,1,5]
Output: 13
Explanation: Minimum score triangulation

TIME COMPLEXITY: O(n³)
SPACE COMPLEXITY: O(n²)
"""

from typing import List, Optional

class Solution:
    def minScoreTriangulation(self, values):
        n = len(values)
        # dp[i][j] = minimum score to triangulate polygon from vertex i to j
        dp = [[0] * n for _ in range(n)]
        # Length of the polygon side
        for length in range(3, n + 1):
            for i in range(0, n - length + 1):
                j = i + length - 1
                dp[i][j] = float('inf')
                # Try all vertices k between i and j as third vertex of triangle
                for k in range(i + 1, j):
                    triangleCost = values[i] * values[k] * values[j]
                    leftCost = dp[i][k]
                    rightCost = dp[k][j]
                    dp[i][j] = min(dp[i][j], triangleCost + leftCost + rightCost)
        return dp[0][n-1]

    def minScoreTriangulationMemo(self, values):
        from functools import lru_cache

        @lru_cache(maxsize=None)
        def solve(i, j):
            if j - i < 2:
                return 0
            best = float('inf')
            for k in range(i + 1, j):
                best = min(best, values[i] * values[k] * values[j] + solve(i, k) + solve(k, j))
            return best

        return solve(0, len(values) - 1)


if __name__ == "__main__":
    sol = Solution()
    print(f"Test Case 1:")
    values1 = [1, 2, 3]
    print(f"Polygon vertices: {values1}")
    print(f"Minimum score: {sol.minScoreTriangulation(values1)}")
    print(f"\nTest Case 2:")
    values2 = [3, 7, 4, 5]
    print(f"Polygon vertices: {values2}")
    print(f"Minimum score (DP): {sol.minScoreTriangulation(values2)}")
    print(f"Minimum score (Memo): {sol.minScoreTriangulationMemo(values2)}")
    print(f"\nTest Case 3:")
    values3 = [1, 3, 1, 4, 1, 5]
    print(f"Polygon vertices: {values3}")
    print(f"Minimum score: {sol.minScoreTriangulation(values3)}")
    print(f"\nTest Case 4:")
    values4 = [2, 4, 1, 3, 5]
    print(f"Polygon vertices: {values4}")
    print(f"Minimum score: {sol.minScoreTriangulation(values4)}")
