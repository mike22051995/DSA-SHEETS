"""
PROBLEM: Maximum Subarray (Kadane's Algorithm)
Difficulty: Easy
Pattern: 1D DP, Subarray Sum

DESCRIPTION:
Given an integer array nums, find the contiguous subarray (containing at least one number) 
which has the largest sum and return its sum.

INPUT:
nums = [-2, 1, -3, 4, -1, 2, 1, -5, 4]

OUTPUT:
6
Explanation: [4, -1, 2, 1] has the largest sum = 6.

TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(1)
"""

from typing import List, Optional

class Solution:
    def maxSubArray(self, nums):
        maxSum = nums[0]
        currentSum = nums[0]
        for i in range(1, len(nums)):
            # Either extend existing subarray or start new from current element
            currentSum = max(nums[i], currentSum + nums[i])
            # Update maximum sum found so far
            maxSum = max(maxSum, currentSum)
        return maxSum

    def maxSubArrayDP(self, nums):
        n = len(nums)
        dp = [0] * n
        dp[0] = nums[0]
        maxSum = dp[0]
        for i in range(1, n):
            dp[i] = max(nums[i], dp[i-1] + nums[i])
            maxSum = max(maxSum, dp[i])
        return maxSum


if __name__ == "__main__":
    sol = Solution()
    nums1 = [-2, 1, -3, 4, -1, 2, 1, -5, 4]
    print(f"Input: nums = [-2, 1, -3, 4, -1, 2, 1, -5, 4]")
    print(f"Output: {sol.maxSubArray(nums1)}")
    print(f"Output (DP): {sol.maxSubArrayDP(nums1)}")
    nums2 = [5, 4, -1, 7, 8]
    print(f"Input: nums = [5, 4, -1, 7, 8]")
    print(f"Output: {sol.maxSubArray(nums2)}")
    print(f"Output (DP): {sol.maxSubArrayDP(nums2)}")
