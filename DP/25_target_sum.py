"""
PROBLEM: Target Sum (LeetCode 494)
DIFFICULTY: Medium
PATTERN: 0/1 Knapsack Variant - Count Subsets

DESCRIPTION:
You are given an integer array nums and an integer target.
You want to build an expression by adding '+' or '-' before each integer 
and concatenate all integers. Return the number of different expressions that evaluate to target.

EXAMPLE:
Input: nums = [1,1,1,1,1], target = 3
Output: 5
Explanation:
-1 + 1 + 1 + 1 + 1 = 3
+1 - 1 + 1 + 1 + 1 = 3
+1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
+1 + 1 + 1 + 1 - 1 = 3

Input: nums = [1], target = 1
Output: 1

TIME COMPLEXITY: O(n * sum)
SPACE COMPLEXITY: O(n * sum)
"""

from typing import List, Optional

class Solution:
    def findTargetSumWays(self, nums, target):
        total = sum(nums)
        # Edge cases
        if abs(target) > total:
            return 0
        if (total + target) % 2 != 0:
            return 0
        subset_sum = (total + target) // 2
        return self._countSubsets(nums, subset_sum)

    def _countSubsets(self, nums, target_sum):
        dp = [0] * (target_sum + 1)
        dp[0] = 1  # Empty subset
        for num in nums:
            # Traverse right to left (0/1 knapsack pattern)
            for s in range(target_sum, num - 1, -1):
                dp[s] += dp[s - num]
        return dp[target_sum]

    def findTargetSumWaysMemo(self, nums, target):
        from functools import lru_cache
        n = len(nums)
        @lru_cache(maxsize=None)
        def helper(index, current_sum):
            if index == n:
                return 1 if current_sum == target else 0
            return (helper(index + 1, current_sum + nums[index]) +
                    helper(index + 1, current_sum - nums[index]))
        return helper(0, 0)


if __name__ == "__main__":
    sol = Solution()
    print(f"Test Case 1:")
    nums1 = [1, 1, 1, 1, 1]
    target1 = 3
    print(f"nums: {nums1}")
    print(f"target: {target1}")
    print(f"Number of ways (Subset Sum): {sol.findTargetSumWays(nums1, target1)}")
    print(f"Number of ways (Memoization): {sol.findTargetSumWaysMemo(nums1, target1)}")
    print(f"\nTest Case 2:")
    nums2 = [1]
    target2 = 1
    print(f"nums: {nums2}")
    print(f"target: {target2}")
    print(f"Number of ways: {sol.findTargetSumWays(nums2, target2)}")
    print(f"\nTest Case 3:")
    nums3 = [1, 2, 3, 4, 5]
    target3 = 3
    print(f"nums: {nums3}")
    print(f"target: {target3}")
    print(f"Number of ways: {sol.findTargetSumWays(nums3, target3)}")
