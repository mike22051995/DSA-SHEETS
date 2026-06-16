"""
PROBLEM: Egg Drop Problem
DIFFICULTY: Hard
PATTERN: Min-Max DP / Binary Search Optimization

DESCRIPTION:
You are given k identical eggs and you have access to a building with n floors.
Each egg is identical in strength. An egg can survive a drop from a certain floor
but will break if dropped from a floor above that.

Find the minimum number of attempts you need in the worst case to find the 
critical floor (highest floor from which the egg will not break).

EXAMPLE:
Input: k = 1, n = 2
Output: 2
Explanation: Drop from floor 1, then floor 2. Total 2 attempts.

Input: k = 2, n = 6
Output: 3
Explanation: Optimal: Drop from floor 3
- Breaks: Check floors 1,2 (worst: 2 more)
- Survives: Drop from floor 5 (worst case continues)

Input: k = 2, n = 10
Output: 4

TIME COMPLEXITY: O(k*n²) naive, O(k*n*log(n)) with binary search
SPACE COMPLEXITY: O(k*n)
"""

from typing import List, Optional

class Solution:
    def eggDropRecursive(self, k, n):
        # Base cases
        if n == 0 or n == 1:
            return n  # 0 or 1 floor
        if k == 1:
            return n  # With 1 egg, must try all floors
        min_attempts = float('inf')
        # Try dropping from each floor
        for floor in range(1, n + 1):
            # Egg breaks: k-1 eggs, floor-1 floors below
            breaks = self.eggDropRecursive(k-1, floor-1)
            # Egg survives: k eggs, n-floor floors above
            survives = self.eggDropRecursive(k, n-floor)
            # Worst case: max of both
            worst_case = 1 + max(breaks, survives)
            # Best of all worst cases
            min_attempts = min(min_attempts, worst_case)
        return min_attempts

    def superEggDrop(self, k, n):
        # DP approach: dp[i][j] = min attempts for i eggs and j floors
        dp = [[0] * (n + 1) for _ in range(k + 1)]
        for j in range(n + 1):
            dp[1][j] = j  # 1 egg: must try all floors
        for i in range(2, k + 1):
            dp[i][0] = 0
            dp[i][1] = 1
        for i in range(2, k + 1):
            for j in range(2, n + 1):
                dp[i][j] = float('inf')
                for floor in range(1, j + 1):
                    worst = 1 + max(dp[i-1][floor-1], dp[i][j-floor])
                    dp[i][j] = min(dp[i][j], worst)
        return dp[k][n]

    def superEggDropOptimized(self, k, n):
        # Binary search optimization: O(k * n * log n)
        from functools import lru_cache
        @lru_cache(maxsize=None)
        def dp(eggs, floors):
            if floors <= 1:
                return floors
            if eggs == 1:
                return floors
            lo, hi = 1, floors
            while lo + 1 < hi:
                mid = (lo + hi) // 2
                breaks = dp(eggs - 1, mid - 1)
                survives = dp(eggs, floors - mid)
                if breaks < survives:
                    lo = mid
                elif breaks > survives:
                    hi = mid
                else:
                    lo = hi = mid
            return 1 + min(max(dp(eggs-1, lo-1), dp(eggs, floors-lo)),
                           max(dp(eggs-1, hi-1), dp(eggs, floors-hi)))
        return dp(k, n)

    def superEggDropReverse(self, k, n):
        # Reverse DP: dp[t][k] = max floors we can check with t tries and k eggs
        t = 0
        dp = [0] * (k + 1)
        while dp[k] < n:
            t += 1
            new_dp = [0] * (k + 1)
            for j in range(1, k + 1):
                new_dp[j] = dp[j-1] + dp[j] + 1
            dp = new_dp
        return t


if __name__ == "__main__":
    sol = Solution()
    print(f"Test Case 1:")
    k1, n1 = 1, 2
    print(f"Eggs: {k1}, Floors: {n1}")
    print(f"Minimum attempts: {sol.superEggDrop(k1, n1)}")
    print(f"\nTest Case 2:")
    k2, n2 = 2, 6
    print(f"Eggs: {k2}, Floors: {n2}")
    print(f"Minimum attempts (DP): {sol.superEggDrop(k2, n2)}")
    print(f"Minimum attempts (Optimized): {sol.superEggDropOptimized(k2, n2)}")
    print(f"Minimum attempts (Reverse): {sol.superEggDropReverse(k2, n2)}")
    print(f"\nTest Case 3:")
    k3, n3 = 2, 10
    print(f"Eggs: {k3}, Floors: {n3}")
    print(f"Minimum attempts: {sol.superEggDrop(k3, n3)}")
    print(f"\nTest Case 4:")
    k4, n4 = 3, 14
    print(f"Eggs: {k4}, Floors: {n4}")
    print(f"Minimum attempts (Optimized): {sol.superEggDropOptimized(k4, n4)}")
    print(f"Minimum attempts (Reverse): {sol.superEggDropReverse(k4, n4)}")
