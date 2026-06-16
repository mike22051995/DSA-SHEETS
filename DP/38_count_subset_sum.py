"""
PROBLEM: Count Subset with Given Sum
DIFFICULTY: Medium
PATTERN: 0/1 Knapsack - Counting Variant

DESCRIPTION:
Given an array of non-negative integers and a target sum, count the number 
of subsets whose sum equals the target.

EXAMPLE:
Input: arr[] = {1, 1, 2, 3}, sum = 4
Output: 3
Explanation: {1, 3}, {1, 3}, {1, 1, 2}

Input: arr[] = {1, 2, 3, 3}, sum = 6
Output: 3
Explanation: {1, 2, 3}, {1, 2, 3}, {3, 3}

Input: arr[] = {2, 3, 5, 6, 8, 10}, sum = 10
Output: 3
Explanation: {2, 3, 5}, {2, 8}, {10}

TIME COMPLEXITY: O(n * sum)
SPACE COMPLEXITY: O(sum)
"""

from typing import List, Optional

class Solution:
    def countSubsets(self, arr, targetSum):
        n = len(arr)
        # dp[s] = count of subsets with sum s
        dp = [0] * (targetSum + 1)
        dp[0] = 1
        for i in range(n):
            for s in range(targetSum, arr[i] - 1, -1):
                dp[s] += dp[s - arr[i]]
        return dp[targetSum]

    def countSubsets2D(self, arr, targetSum):
        n = len(arr)
        dp = [[0] * (targetSum + 1) for _ in range(n + 1)]
        for i in range(n + 1):
            dp[i][0] = 1
        for i in range(1, n + 1):
            for s in range(targetSum + 1):
                dp[i][s] = dp[i - 1][s]
                if arr[i - 1] <= s:
                    dp[i][s] += dp[i - 1][s - arr[i - 1]]
        return dp[n][targetSum]

    def countSubsetsMemo(self, arr, targetSum):
        from functools import lru_cache

        n = len(arr)

        @lru_cache(maxsize=None)
        def dfs(i, rem):
            if rem == 0:
                return 1
            if i == n or rem < 0:
                return 0
            return dfs(i + 1, rem) + dfs(i + 1, rem - arr[i])

        return dfs(0, targetSum)

    def getAllSubsets(self, arr, targetSum):
        result = []

        def backtrack(idx, rem, current):
            if rem == 0:
                result.append(current[:])
                return
            for i in range(idx, len(arr)):
                if arr[i] <= rem:
                    current.append(arr[i])
                    backtrack(i + 1, rem - arr[i], current)
                    current.pop()

        backtrack(0, targetSum, [])
        return result


if __name__ == "__main__":
    sol = Solution()
    print(f"Test Case 1:")
    arr1 = [1, 1, 2, 3]
    sum1 = 4
    print(f"Array: {arr1}")
    print(f"Target sum: {sum1}")
    print(f"Count (1D DP): {sol.countSubsets(arr1, sum1)}")
    print(f"Count (2D DP): {sol.countSubsets2D(arr1, sum1)}")
    print(f"Count (Memo): {sol.countSubsetsMemo(arr1, sum1)}")
    print(f"One set of subsets: {sol.getAllSubsets(arr1, sum1)}")
    print(f"\nTest Case 2:")
    arr2 = [1, 2, 3, 3]
    sum2 = 6
    print(f"Array: {arr2}")
    print(f"Target sum: {sum2}")
    print(f"Count: {sol.countSubsets(arr2, sum2)}")
    print(f"\nTest Case 3:")
    arr3 = [2, 3, 5, 6, 8, 10]
    sum3 = 10
    print(f"Array: {arr3}")
    print(f"Target sum: {sum3}")
    print(f"Count: {sol.countSubsets(arr3, sum3)}")
    print(f"\nTest Case 4:")
    arr4 = [1, 1, 1, 1]
    sum4 = 2
    print(f"Array: {arr4}")
    print(f"Target sum: {sum4}")
    print(f"Count: {sol.countSubsets(arr4, sum4)}")
