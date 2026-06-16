"""
PROBLEM: Two Sum Less Than K
---------------------------------------------------------------------------
Given an array nums of integers and integer k, return the maximum sum such 
that there exists i < j with nums[i] + nums[j] = sum and sum < k. 
If no i, j exist satisfying this equation, return -1.

PATTERN: Sorting + Opposite Direction Two Pointers
TIME COMPLEXITY: O(n log n)
SPACE COMPLEXITY: O(1)

INPUT/OUTPUT EXAMPLES:
---------------------------------------------------------------------------
Example 1:
Input: nums = [34,23,1,24,75,33,54,8], k = 60
Output: 58
Explanation: We can use 34 and 24 to sum 58 which is less than 60.

Example 2:
Input: nums = [10,20,30], k = 15
Output: -1
Explanation: No two elements sum to a value less than 15.
"""

from typing import List


class Solution:
    def twoSumLessThanK(self, nums: List[int], k: int) -> int:
        nums.sort()
        left = 0
        right = len(nums) - 1
        maxSum = -1
        while left < right:
            s = nums[left] + nums[right]
            if s < k:
                maxSum = max(maxSum, s)
                left += 1
            else:
                right -= 1
        return maxSum


if __name__ == "__main__":
    sol = Solution()
    nums1 = [34, 23, 1, 24, 75, 33, 54, 8]
    k1 = 60
    print(f"Test 1: {sol.twoSumLessThanK(nums1, k1)}")
    nums2 = [10, 20, 30]
    k2 = 15
    print(f"Test 2: {sol.twoSumLessThanK(nums2, k2)}")
