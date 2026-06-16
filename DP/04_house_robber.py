"""
PROBLEM: House Robber
Difficulty: Easy
Pattern: 1D DP, Non-adjacent Selection

DESCRIPTION:
You are a professional robber planning to rob houses along a street. Each house has a certain 
amount of money stashed. Adjacent houses have security systems connected and will automatically 
contact the police if two adjacent houses were broken into on the same night.
Given an integer array nums representing the amount of money of each house, return the maximum 
amount of money you can rob tonight without alerting the police.

INPUT:
nums = [2, 7, 9, 3, 1]

OUTPUT:
12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
Total amount = 2 + 9 + 1 = 12.

TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(n) for dp array, O(1) optimized
"""

from typing import List, Optional

class Solution:
    def rob(self, nums):
        n = len(nums)
        if n == 0:
            return 0
        if n == 1:
            return nums[0]
        dp = [0] * n
        dp[0] = nums[0]
        dp[1] = max(nums[0], nums[1])
        for i in range(2, n):
            # Either rob current house + max till (i-2)
            # Or skip current house and take max till (i-1)
            dp[i] = max(dp[i-1], nums[i] + dp[i-2])
        return dp[n-1]

    def robOptimized(self, nums):
        n = len(nums)
        if n == 0:
            return 0
        if n == 1:
            return nums[0]
        prev2 = nums[0]
        prev1 = max(nums[0], nums[1])
        for i in range(2, n):
            curr = max(prev1, nums[i] + prev2)
            prev2 = prev1
            prev1 = curr
        return prev1


if __name__ == "__main__":
    sol = Solution()
    nums1 = [2, 7, 9, 3, 1]
    print(f"Input: nums = [2, 7, 9, 3, 1]")
    print(f"Output: {sol.rob(nums1)}")
    print(f"Output (Optimized): {sol.robOptimized(nums1)}")
    nums2 = [1, 2, 3, 1]
    print(f"Input: nums = [1, 2, 3, 1]")
    print(f"Output: {sol.rob(nums2)}")
    print(f"Output (Optimized): {sol.robOptimized(nums2)}")
    print(f"Output: {sol.rob(nums1)}")
    print(f"Output (Optimized): {sol.robOptimized(nums1)}")
    nums2 = [1, 2, 3, 1]
    print(f"Input: nums = [1, 2, 3, 1]")
    print(f"Output: {sol.rob(nums2)}")
    print(f"Output (Optimized): {sol.robOptimized(nums2)}")
