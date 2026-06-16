"""
PROBLEM: 3Sum
Difficulty: Medium
Pattern: Two Pointers, Sorting

DESCRIPTION:
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that 
i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
Notice that the solution set must not contain duplicate triplets.

EXPLANATION:
1. Sort the array first
2. Fix one element and use two pointers for the remaining two elements
3. Skip duplicates to avoid duplicate triplets
4. If sum is 0, add to result and move both pointers

Time Complexity: O(n²)
Space Complexity: O(1) excluding output array

INPUT-OUTPUT EXAMPLES:

Example 1:
Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation: nums[0] + nums[1] + nums[2] = -1 + 0 + 1 = 0

Example 2:
Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet does not sum to 0

Example 3:
Input: nums = [0,0,0]
Output: [[0,0,0]]
Explanation: The only triplet sums to 0
"""

from typing import List

class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        result = []
        n = len(nums)
        if n < 3:
            return result
        nums.sort()
        for i in range(n - 2):
            # Skip duplicates for first element
            if i > 0 and nums[i] == nums[i - 1]:
                continue
            left = i + 1
            right = n - 1
            target = -nums[i]
            while left < right:
                s = nums[left] + nums[right]
                if s == target:
                    result.append([nums[i], nums[left], nums[right]])
                    # Skip duplicates for second element
                    while left < right and nums[left] == nums[left + 1]:
                        left += 1
                    # Skip duplicates for third element
                    while left < right and nums[right] == nums[right - 1]:
                        right -= 1
                    left += 1
                    right -= 1
                elif s < target:
                    left += 1
                else:
                    right -= 1
        return result


if __name__ == "__main__":
    solution = Solution()
    nums1 = [-1, 0, 1, 2, -1, -4]
    print(f"Test 1: {solution.threeSum(nums1)}")
    nums2 = [0, 1, 1]
    print(f"Test 2: {solution.threeSum(nums2)}")
    nums3 = [0, 0, 0]
    print(f"Test 3: {solution.threeSum(nums3)}")
