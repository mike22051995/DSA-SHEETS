"""
PROBLEM: 3Sum Closest
---------------------------------------------------------------------------
Given an integer array nums of length n and an integer target, find three 
integers in nums such that the sum is closest to target. Return the sum 
of the three integers.

PATTERN: Sorting + Two Pointers
TIME COMPLEXITY: O(n²)
SPACE COMPLEXITY: O(1)

INPUT/OUTPUT EXAMPLES:
---------------------------------------------------------------------------
Example 1:
Input: nums = [-1,2,1,-4], target = 1
Output: 2
Explanation: The sum closest to target is 2 (-1 + 2 + 1 = 2).

Example 2:
Input: nums = [0,0,0], target = 1
Output: 0
Explanation: The sum closest to 1 is 0 (0 + 0 + 0 = 0).
"""

from typing import List


class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        nums.sort()
        closestSum = nums[0] + nums[1] + nums[2]
        minDiff = abs(closestSum - target)
        for i in range(len(nums) - 2):
            left = i + 1
            right = len(nums) - 1
            while left < right:
                s = nums[i] + nums[left] + nums[right]
                diff = abs(s - target)
                if diff < minDiff:
                    minDiff = diff
                    closestSum = s
                if s < target:
                    left += 1
                elif s > target:
                    right -= 1
                else:
                    return s  # Exact match
        return closestSum


if __name__ == "__main__":
    sol = Solution()
    nums1 = [-1, 2, 1, -4]
    target1 = 1
    print(f"Test 1: {sol.threeSumClosest(nums1, target1)}")
    nums2 = [0, 0, 0]
    target2 = 1
    print(f"Test 2: {sol.threeSumClosest(nums2, target2)}")
