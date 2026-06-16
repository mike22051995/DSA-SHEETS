"""
PROBLEM: Find First and Last Position of Element in Sorted Array
Difficulty: Medium
Pattern: Binary Search

DESCRIPTION:
Given an array of integers nums sorted in non-decreasing order, find the starting and 
ending position of a given target value. If target is not found in the array, return [-1, -1].
You must write an algorithm with O(log n) runtime complexity.

EXPLANATION:
Use binary search twice:
1. First binary search to find the leftmost (first) occurrence
2. Second binary search to find the rightmost (last) occurrence
Modify standard binary search to continue searching even after finding the target.

Time Complexity: O(log n)
Space Complexity: O(1)

INPUT-OUTPUT EXAMPLES:

Example 1:
Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Explanation: 8 appears at indices 3 and 4

Example 2:
Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
Explanation: 6 is not in the array

Example 3:
Input: nums = [], target = 0
Output: [-1,-1]
Explanation: Empty array
"""
from typing import List

class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        def findFirst(nums, target):
            left, right = 0, len(nums) - 1
            idx = -1
            while left <= right:
                mid = (left + right) // 2
                if nums[mid] == target:
                    idx = mid
                    right = mid - 1
                elif nums[mid] < target:
                    left = mid + 1
                else:
                    right = mid - 1
            return idx

        def findLast(nums, target):
            left, right = 0, len(nums) - 1
            idx = -1
            while left <= right:
                mid = (left + right) // 2
                if nums[mid] == target:
                    idx = mid
                    left = mid + 1
                elif nums[mid] < target:
                    left = mid + 1
                else:
                    right = mid - 1
            return idx

        return [findFirst(nums, target), findLast(nums, target)]


if __name__ == "__main__":
    solution = Solution()
    nums1 = [5, 7, 7, 8, 8, 10]
    print(f"Test 1: {solution.searchRange(nums1, 8)}")
    nums2 = [5, 7, 7, 8, 8, 10]
    print(f"Test 2: {solution.searchRange(nums2, 6)}")
    nums3 = []
    print(f"Test 3: {solution.searchRange(nums3, 0)}")
