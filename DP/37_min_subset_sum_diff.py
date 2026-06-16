"""
PROBLEM: Minimum Subset Sum Difference
DIFFICULTY: Medium
PATTERN: 0/1 Knapsack Variant / Partition DP

DESCRIPTION:
Given a set of integers, partition it into two subsets S1 and S2 such that 
the difference of the sum of elements between S1 and S2 is minimized.

Return the minimum possible absolute difference.

EXAMPLE:
Input: arr[] = {1, 6, 11, 5}
Output: 1
Explanation: 
Subset1 = {1, 5, 6}, sum = 12
Subset2 = {11}, sum = 11
Difference = |12-11| = 1

Input: arr[] = {1, 2, 3, 4}
Output: 0
Explanation:
Subset1 = {1, 4}, sum = 5
Subset2 = {2, 3}, sum = 5
Difference = 0

Input: arr[] = {1, 5, 11, 5}
Output: 0
Explanation:
Subset1 = {1, 5, 5}, sum = 11
Subset2 = {11}, sum = 11

TIME COMPLEXITY: O(n * sum)
SPACE COMPLEXITY: O(sum)
"""

from typing import List, Optional

class Solution:
    def minDifference(self, arr):
        n = len(arr)
        total_sum = sum(arr)
        # dp[i] = True if sum i is achievable
        dp = [False] * (total_sum + 1)
        dp[0] = True  # Empty subset
        # Standard subset sum
        for num in arr:
            for s in range(total_sum, num - 1, -1):
                dp[s] = dp[s] or dp[s - num]
        # Find minimum difference
        min_diff = float('inf')
        for i in range(total_sum // 2 + 1):
            if dp[i]:
                diff = total_sum - 2 * i
                min_diff = min(min_diff, diff)
        return min_diff

    def minDifference2D(self, arr):
        n = len(arr)
        total_sum = sum(arr)
        target = total_sum // 2
        dp = [[False] * (total_sum + 1) for _ in range(n + 1)]
        for i in range(n + 1):
            dp[i][0] = True
        for i in range(1, n + 1):
            for j in range(1, total_sum + 1):
                dp[i][j] = dp[i-1][j]
                if arr[i-1] <= j:
                    dp[i][j] = dp[i][j] or dp[i-1][j - arr[i-1]]
        min_diff = float('inf')
        for j in range(target + 1):
            if dp[n][j]:
                min_diff = min(min_diff, total_sum - 2 * j)
        return min_diff

    def getPartitions(self, arr):
        n = len(arr)
        total_sum = sum(arr)
        dp = [[False] * (total_sum + 1) for _ in range(n + 1)]
        for i in range(n + 1):
            dp[i][0] = True
        for i in range(1, n + 1):
            for j in range(1, total_sum + 1):
                dp[i][j] = dp[i-1][j]
                if arr[i-1] <= j:
                    dp[i][j] = dp[i][j] or dp[i-1][j - arr[i-1]]
        # Find best split
        best_j = 0
        for j in range(total_sum // 2 + 1):
            if dp[n][j]:
                best_j = j
        # Backtrack to find items in subset 1
        subset1, subset2 = [], []
        j = best_j
        for i in range(n, 0, -1):
            if not dp[i-1][j]:
                subset1.append(arr[i-1])
                j -= arr[i-1]
            else:
                subset2.append(arr[i-1])
        return subset1, subset2


if __name__ == "__main__":
    sol = Solution()
    print(f"Test Case 1:")
    arr1 = [1, 6, 11, 5]
    print(f"Array: {arr1}")
    print(f"Minimum difference: {sol.minDifference(arr1)}")
    s1_1, s2_1 = sol.getPartitions(arr1)
    print(f"Subset 1: {s1_1} (sum = {sum(s1_1)})")
    print(f"Subset 2: {s2_1} (sum = {sum(s2_1)})")
    print(f"Difference: {abs(sum(s1_1) - sum(s2_1))}")
    print(f"\nTest Case 2:")
    arr2 = [1, 2, 3, 4]
    print(f"Array: {arr2}")
    print(f"Minimum difference: {sol.minDifference(arr2)}")
    print(f"\nTest Case 3:")
    arr3 = [1, 5, 11, 5]
    print(f"Array: {arr3}")
    print(f"Minimum difference (1D): {sol.minDifference(arr3)}")
    print(f"Minimum difference (2D): {sol.minDifference2D(arr3)}")
    print(f"\nTest Case 4:")
    arr4 = [3, 1, 4, 2, 2, 1]
    print(f"Array: {arr4}")
    print(f"Minimum difference: {sol.minDifference(arr4)}")
