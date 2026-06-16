"""
PROBLEM: Find Peak Element
Difficulty: Medium/Hard
Pattern: Binary Search

DESCRIPTION:
A peak element is an element that is strictly greater than its neighbors. Given an integer 
array nums, find a peak element, and return its index. If the array contains multiple peaks, 
return the index to any of the peaks.
You must write an algorithm that runs in O(log n) time.

EXPLANATION:
Binary Search approach:
- If mid element is greater than next element, peak is on the left (including mid)
- Otherwise, peak is on the right
- Array boundaries are treated as negative infinity
- This guarantees finding a peak

Time Complexity: O(log n)
Space Complexity: O(1)

INPUT-OUTPUT EXAMPLES:

Example 1:
Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element at index 2

Example 2:
Input: nums = [1,2,1,3,5,6,4]
Output: 5
Explanation: 6 is a peak element at index 5 (or index 1 with value 2)

Example 3:
Input: nums = [1]
Output: 0
Explanation: Single element is a peak
"""

from typing import List

class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        left = 0
        right = len(nums) - 1
        while left < right:
            mid = left + (right - left) // 2
            # If mid is greater than next element, peak is on left side
            if nums[mid] > nums[mid + 1]:
                right = mid
            else:
                # Peak is on right side
                left = mid + 1
        return left


if __name__ == "__main__":
    solution = Solution()
    nums1 = [1, 2, 3, 1]
    print(f"Test 1: {solution.findPeakElement(nums1)}")
    nums2 = [1, 2, 1, 3, 5, 6, 4]
    print(f"Test 2: {solution.findPeakElement(nums2)}")
    nums3 = [1]
    print(f"Test 3: {solution.findPeakElement(nums3)}")
