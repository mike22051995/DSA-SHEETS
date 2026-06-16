"""
PROBLEM: Search Insert Position
Difficulty: Easy
Pattern: Binary Search Variant

DESCRIPTION:
Given a sorted array of distinct integers and a target value, return the index if the target 
is found. If not, return the index where it would be if it were inserted in order.
You must write an algorithm with O(log n) runtime complexity.

EXPLANATION:
Modified binary search:
- If target is found, return its index
- If not found, left pointer will be at the position where target should be inserted
- This is because left always moves to positions where element could be >= target

Time Complexity: O(log n)
Space Complexity: O(1)

INPUT-OUTPUT EXAMPLES:

Example 1:
Input: nums = [1,3,5,6], target = 5
Output: 2
Explanation: 5 is found at index 2

Example 2:
Input: nums = [1,3,5,6], target = 2
Output: 1
Explanation: 2 should be inserted at index 1

Example 3:
Input: nums = [1,3,5,6], target = 7
Output: 4
Explanation: 7 should be inserted at the end
"""

from typing import List, Optional

class Solution:
    def searchInsert(self, nums, target):
        left = 0
        right = len(nums) - 1
        while left <= right:
            mid = left + (right - left) // 2
            if nums[mid] == target:
                return mid
            elif nums[mid] < target:
                left = mid + 1
            else:
                right = mid - 1
        return left  # Insert position


if __name__ == "__main__":
    solution = Solution()
    nums1 = [1, 3, 5, 6]
    print(f"Test 1: {solution.searchInsert(nums1, 5)}")
    nums2 = [1, 3, 5, 6]
    print(f"Test 2: {solution.searchInsert(nums2, 2)}")
    nums3 = [1, 3, 5, 6]
    print(f"Test 3: {solution.searchInsert(nums3, 7)}")
