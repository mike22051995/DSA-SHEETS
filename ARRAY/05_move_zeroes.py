"""
PROBLEM: Move Zeroes
Difficulty: Easy
Pattern: Two Pointers

DESCRIPTION:
Given an integer array nums, move all 0's to the end of it while maintaining the relative 
order of the non-zero elements. Note that you must do this in-place without making a copy 
of the array.

EXPLANATION:
We use two pointers: one to track the position where the next non-zero should go,
and another to scan through the array. When we find a non-zero, we swap it with the
position pointed to by the first pointer.

Time Complexity: O(n)
Space Complexity: O(1)

INPUT-OUTPUT EXAMPLES:

Example 1:
Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]
Explanation: Non-zero elements maintain their order

Example 2:
Input: nums = [0]
Output: [0]
Explanation: Single zero element

Example 3:
Input: nums = [1,2,3]
Output: [1,2,3]
Explanation: No zeros to move
"""

from typing import List

class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        nonZeroPos = 0
        # Move all non-zero elements to the front
        for i in range(len(nums)):
            if nums[i] != 0:
                nums[nonZeroPos], nums[i] = nums[i], nums[nonZeroPos]
                nonZeroPos += 1


if __name__ == "__main__":
    solution = Solution()
    nums1 = [0, 1, 0, 3, 12]
    solution.moveZeroes(nums1)
    print(f"Test 1: {nums1}")
    nums2 = [0]
    solution.moveZeroes(nums2)
    print(f"Test 2: {nums2}")
    nums3 = [1, 2, 3]
    solution.moveZeroes(nums3)
    print(f"Test 3: {nums3}")
    print("Test 3: ")
    printArray(nums3)
