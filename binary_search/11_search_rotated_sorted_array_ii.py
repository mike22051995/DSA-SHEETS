"""
PROBLEM: Search in Rotated Sorted Array II
Difficulty: Medium
Pattern: Modified Binary Search with Duplicates

DESCRIPTION:
There is an integer array nums sorted in non-decreasing order (not necessarily with distinct values).
Given the array nums after rotation and an integer target, return True if target is in nums, 
or False if it is not in nums. You must decrease the overall operation steps as much as possible.

EXPLANATION:
Modified binary search handling duplicates:
- When nums[left] == nums[mid] == nums[right], can't determine which half is sorted
- In this case, increment left and decrement right
- Otherwise, same logic as Search in Rotated Sorted Array

Time Complexity: O(log n) average, O(n) worst case
Space Complexity: O(1)

INPUT-OUTPUT EXAMPLES: 

Example 1:
Input: nums = [2,5,6,0,0,1,2], target = 0
Output: True

Example 2:
Input: nums = [2,5,6,0,0,1,2], target = 3
Output: False

Example 3:
Input: nums = [1,0,1,1,1], target = 0
Output: True
"""

from typing import List, Optional

class Solution:
    def search(self, nums, target):
        left = 0
        right = len(nums) - 1
        while left <= right:
            mid = left + (right - left) // 2
            if nums[mid] == target:
                return True
            # Handle duplicates
            if nums[left] == nums[mid] == nums[right]:
                left += 1
                right -= 1
            elif nums[left] <= nums[mid]:
                # Left half is sorted
                if nums[left] <= target < nums[mid]:
                    right = mid - 1
                else:
                    left = mid + 1
            else:
                # Right half is sorted
                if nums[mid] < target <= nums[right]:
                    left = mid + 1
                else:
                    right = mid - 1
        return False


if __name__ == "__main__":
    solution = Solution()
    nums1 = [2, 5, 6, 0, 0, 1, 2]
    print(f"Test 1: {solution.search(nums1, 0)}")
    nums2 = [2, 5, 6, 0, 0, 1, 2]
    print(f"Test 2: {solution.search(nums2, 3)}")
    nums3 = [1, 0, 1, 1, 1]
    print(f"Test 3: {solution.search(nums3, 0)}")
