"""
PROBLEM: First Missing Positive
Difficulty: Hard
Pattern: Array Marking, Cyclic Sort

DESCRIPTION:
Given an unsorted integer array nums, return the smallest missing positive integer.
You must implement an algorithm that runs in O(n) time and uses constant extra space.

EXPLANATION:
Place each number in its correct position (num at index num-1).
Then scan array to find first position where nums[i] != i+1.
Ignore numbers <= 0 or > n as they can't be the answer.

Time Complexity: O(n)
Space Complexity: O(1)

INPUT-OUTPUT EXAMPLES:

Example 1:
Input: nums = [1,2,0]
Output: 3
Explanation: 1 and 2 are present, 3 is missing

Example 2:
Input: nums = [3,4,-1,1]
Output: 2
Explanation: 1 is present but 2 is missing

Example 3:
Input: nums = [7,8,9,11,12]
Output: 1
Explanation: No positive integers from 1 onwards
"""

from typing import List

class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        n = len(nums)
        # Place each number in its correct position
        for i in range(n):
            while nums[i] > 0 and nums[i] <= n and nums[nums[i] - 1] != nums[i]:
                nums[i], nums[nums[i] - 1] = nums[nums[i] - 1], nums[i]
        # Find first missing positive
        for i in range(n):
            if nums[i] != i + 1:
                return i + 1
        # All positions filled, answer is n+1
        return n + 1


if __name__ == "__main__":
    solution = Solution()
    nums1 = [1, 2, 0]
    print(f"Test 1: {solution.firstMissingPositive(nums1)}")
    nums2 = [3, 4, -1, 1]
    print(f"Test 2: {solution.firstMissingPositive(nums2)}")
    nums3 = [7, 8, 9, 11, 12]
    print(f"Test 3: {solution.firstMissingPositive(nums3)}")
