"""
PROBLEM: Rotate Array
Difficulty: Medium
Pattern: Array Reversal

DESCRIPTION:
Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.

EXPLANATION:
Three-step reversal approach:
1. Reverse the entire array
2. Reverse the first k elements
3. Reverse the remaining n-k elements
This achieves rotation in-place with O(1) space.

Time Complexity: O(n)
Space Complexity: O(1)

INPUT-OUTPUT EXAMPLES:

Example 1:
Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation: Rotate right by 3 steps

Example 2:
Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
Explanation: Rotate right by 2 steps

Example 3:
Input: nums = [1,2], k = 3
Output: [2,1]
Explanation: k = 3 is equivalent to k = 1 (3 % 2 = 1)
"""

from typing import List

class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        n = len(nums)
        k = k % n  # Handle k > n
        if k == 0:
            return
        # Reverse entire array
        nums.reverse()
        # Reverse first k elements
        nums[:k] = nums[:k][::-1]
        # Reverse remaining elements
        nums[k:] = nums[k:][::-1]


if __name__ == "__main__":
    solution = Solution()
    nums1 = [1, 2, 3, 4, 5, 6, 7]
    solution.rotate(nums1, 3)
    print(f"Test 1: {nums1}")
    nums2 = [-1, -100, 3, 99]
    solution.rotate(nums2, 2)
    print(f"Test 2: {nums2}")
    nums3 = [1, 2]
    solution.rotate(nums3, 3)
    print(f"Test 3: {nums3}")
