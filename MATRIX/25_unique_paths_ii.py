"""
PROBLEM: Unique Paths II (LeetCode 63)
Difficulty: Medium
Company: Google, Meta, Amazon, Microsoft
Pattern: Dynamic Programming with Obstacles

DESCRIPTION:
Same as Unique Paths but with obstacles (marked as 1).
Find how many unique paths from top-left to bottom-right avoiding obstacles.

APPROACH:
DP where dp[i][j] = paths to (i, j).
If cell is obstacle: dp[i][j] = 0
Else: dp[i][j] = dp[i-1][j] + dp[i][j-1]

TIME COMPLEXITY: O(M * N)
SPACE COMPLEXITY: O(M * N) or O(N) with optimization
"""

from typing import List


class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        if not obstacleGrid or not obstacleGrid[0]:
            return 0

        m, n = len(obstacleGrid), len(obstacleGrid[0])

        if obstacleGrid[0][0] == 1 or obstacleGrid[m-1][n-1] == 1:
            return 0

        dp = [[0] * n for _ in range(m)]
        dp[0][0] = 1

        for i in range(1, m):
            dp[i][0] = dp[i-1][0] if obstacleGrid[i][0] == 0 else 0

        for j in range(1, n):
            dp[0][j] = dp[0][j-1] if obstacleGrid[0][j] == 0 else 0

        for i in range(1, m):
            for j in range(1, n):
                if obstacleGrid[i][j] == 0:
                    dp[i][j] = dp[i-1][j] + dp[i][j-1]

        return dp[m-1][n-1]

    # Space optimized: O(N)
    def uniquePathsWithObstaclesOptimized(self, obstacleGrid: List[List[int]]) -> int:
        m, n = len(obstacleGrid), len(obstacleGrid[0])
        dp = [0] * n
        dp[0] = 1

        for i in range(m):
            if obstacleGrid[i][0] == 1:
                dp[0] = 0
            for j in range(1, n):
                if obstacleGrid[i][j] == 1:
                    dp[j] = 0
                else:
                    dp[j] += dp[j-1]

        return dp[n-1]


if __name__ == "__main__":
    sol = Solution()

    grid1 = [[0, 0, 0], [0, 1, 0], [0, 0, 0]]
    print("Unique paths:", sol.uniquePathsWithObstacles(grid1))  # 2

    grid2 = [[0, 1], [0, 0]]
    print("Unique paths:", sol.uniquePathsWithObstacles(grid2))  # 1
