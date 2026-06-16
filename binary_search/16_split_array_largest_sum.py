"""
PROBLEM: Split Array Largest Sum
Difficulty: Hard
Pattern: Binary Search on Answer

DESCRIPTION:
Given an array nums which consists of non-negative integers and an integer m, you can split 
the array into m non-empty continuous subarrays. Write an algorithm to minimize the largest 
sum among these m subarrays.

EXPLANATION:
Binary search on the largest sum:
- Min sum = max(nums) (each subarray has at least one element)
- Max sum = sum(nums) (all in one subarray)
- For each mid, check if can split into m subarrays with max sum <= mid
- Find minimum such sum

Time Complexity: O(n * log(sum))
Space Complexity: O(1)

INPUT-OUTPUT EXAMPLES:

Example 1:
Input: nums = [7,2,5,10,8], m = 2
Output: 18
Explanation: Split into [7,2,5] and [10,8], max is 18

Example 2:
Input: nums = [1,2,3,4,5], m = 2
Output: 9
Explanation: Split into [1,2,3,4] and [5], max is 9

Example 3:
Input: nums = [1,4,4], m = 3
Output: 4
"""

from typing import List, Optional


def can_split(nums, m, max_sum):
    parts = 1
    current_sum = 0
    for n in nums:
        if current_sum + n > max_sum:
            parts += 1
            current_sum = 0
        current_sum += n
    return parts <= m


class Solution:
    def splitArray(self, nums, m):
        left = max(nums)
        right = sum(nums)
        while left < right:
            mid = left + (right - left) // 2
            if can_split(nums, m, mid):
                right = mid
            else:
                left = mid + 1
        return left


if __name__ == "__main__":
    solution = Solution()
    nums1 = [7, 2, 5, 10, 8]
    print(f"Test 1: {solution.splitArray(nums1, 2)}")
    nums2 = [1, 2, 3, 4, 5]
    print(f"Test 2: {solution.splitArray(nums2, 2)}")
    nums3 = [1, 4, 4]
    print(f"Test 3: {solution.splitArray(nums3, 3)}")
