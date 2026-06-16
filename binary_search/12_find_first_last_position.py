"""
PROBLEM: Find First and Last Position of Element in Sorted Array
Difficulty: Medium
Pattern: Binary Search Variants

DESCRIPTION:
Given an array of integers nums sorted in non-decreasing order, find the starting and ending 
position of a given target value. If target is not found in the array, return [-1, -1].
You must write an algorithm with O(log n) runtime complexity.

EXPLANATION:
Use two binary searches:
1. First search: Find leftmost occurrence
2. Second search: Find rightmost occurrence
Modify standard binary search to continue searching even after finding target

Time Complexity: O(log n)
Space Complexity: O(1)

INPUT-OUTPUT EXAMPLES:

Example 1:
Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]

Example 2:
Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]

Example 3:
Input: nums = [], target = 0
Output: [-1,-1]
"""

from typing import List


class Solution:
    def searchRange(self, nums, target):
        def find_left(nums, target):
            left, right = 0, len(nums) - 1
            result = -1
            while left <= right:
                mid = left + (right - left) // 2
                if nums[mid] == target:
                    result = mid
                    right = mid - 1
                elif nums[mid] < target:
                    left = mid + 1
                else:
                    right = mid - 1
            return result

        def find_right(nums, target):
            left, right = 0, len(nums) - 1
            result = -1
            while left <= right:
                mid = left + (right - left) // 2
                if nums[mid] == target:
                    result = mid
                    left = mid + 1
                elif nums[mid] < target:
                    left = mid + 1
                else:
                    right = mid - 1
            return result

        return [find_left(nums, target), find_right(nums, target)]


if __name__ == "__main__":
    solution = Solution()
    nums1 = [5, 7, 7, 8, 8, 10]
    print(f"Test 1: {solution.searchRange(nums1, 8)}")
    nums2 = [5, 7, 7, 8, 8, 10]
    print(f"Test 2: {solution.searchRange(nums2, 6)}")
    nums3 = []
    print(f"Test 3: {solution.searchRange(nums3, 0)}")
