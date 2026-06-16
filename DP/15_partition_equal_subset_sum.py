"""
PROBLEM: Partition Equal Subset Sum
Difficulty: Medium
Pattern: 0/1 Knapsack, Subset Sum

DESCRIPTION:
Given a non-empty array nums containing only positive integers, find if the array can be 
partitioned into two subsets such that the sum of elements in both subsets is equal.

INPUT:
nums = [1, 5, 11, 5]

OUTPUT:
True
Explanation: The array can be partitioned as [1, 5, 5] and [11].

TIME COMPLEXITY: O(n * sum) where sum = total sum / 2
SPACE COMPLEXITY: O(sum), can use 1D array
"""

from typing import List, Optional

class Solution:
    def canPartition(self, nums):
        totalSum = sum(nums)
        # If total sum is odd, cannot partition into equal subsets
        if totalSum % 2 != 0:
            return False
        target = totalSum // 2
        # dp[i] = True if sum i can be formed using subset of nums
        dp = [False] * (target + 1)
        dp[0] = True  # Sum 0 can always be formed (empty subset)
        for num in nums:
            # Traverse backwards to avoid using same element twice
            for j in range(target, num - 1, -1):
                dp[j] = dp[j] or dp[j - num]
        return dp[target]

    def canPartition2D(self, nums):
        totalSum = sum(nums)
        if totalSum % 2 != 0:
            return False
        target = totalSum // 2
        n = len(nums)
        dp = [[False] * (target + 1) for _ in range(n + 1)]
        for i in range(n + 1):
            dp[i][0] = True
        for i in range(1, n + 1):
            for j in range(1, target + 1):
                dp[i][j] = dp[i-1][j]
                if nums[i-1] <= j:
                    dp[i][j] = dp[i][j] or dp[i-1][j - nums[i-1]]
        return dp[n][target]


if __name__ == "__main__":
    sol = Solution()
    nums1 = [1, 5, 11, 5]
    print(f"Input: nums = [1, 5, 11, 5]")
    print(f"Output: {sol.canPartition(nums1)}")
    print(f"Output (2D): {sol.canPartition2D(nums1)}")
    nums2 = [1, 2, 3, 5]
    print(f"Input: nums = [1, 2, 3, 5]")
    print(f"Output: {sol.canPartition(nums2)}")
    print(f"Output (2D): {sol.canPartition2D(nums2)}")
