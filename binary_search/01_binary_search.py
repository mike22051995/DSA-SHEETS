"""
PROBLEM: Binary Search
Difficulty: Easy
Pattern: Basic Binary Search

DESCRIPTION:
Given an array of integers nums which is sorted in ascending order, and an integer target, 
write a function to search target in nums. If target exists, then return its index. 
Otherwise, return -1.
You must write an algorithm with O(log n) runtime complexity.

EXPLANATION:
Classic binary search implementation:
1. Maintain left and right pointers
2. Calculate mid = left + (right - left) / 2
3. If nums[mid] == target, return mid
4. If nums[mid] < target, search right half
5. If nums[mid] > target, search left half
6. Return -1 if not found

Time Complexity: O(log n)
Space Complexity: O(1)

INPUT-OUTPUT EXAMPLES:

Example 1:
Input: nums = [-1,0,3,5,9,12], target = 9
Output: 4
Explanation: 9 exists in nums and its index is 4

Example 2:
Input: nums = [-1,0,3,5,9,12], target = 2
Output: -1
Explanation: 2 does not exist in nums

Example 3:
Input: nums = [5], target = 5
Output: 0
"""

from typing import List, Optional

class Solution:
    def search(self, nums, target):
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
        return -1


if __name__ == "__main__":
    solution = Solution()
    nums1 = [-1, 0, 3, 5, 9, 12]
    print(f"Test 1: {solution.search(nums1, 9)}")
    nums2 = [-1, 0, 3, 5, 9, 12]
    print(f"Test 2: {solution.search(nums2, 2)}")
    nums3 = [5]
    print(f"Test 3: {solution.search(nums3, 5)}")
