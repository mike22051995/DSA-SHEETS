"""
PROBLEM: Minimum Limit of Balls in a Bag
Difficulty: Hard
Pattern: Binary Search on Answer

DESCRIPTION:
You are given an integer array nums where the ith bag contains nums[i] balls. You are also 
given an integer maxOperations.
You can perform the following operation at most maxOperations times:
- Take any bag of balls and divide it into two new bags with a positive number of balls.
Your goal is to minimize the maximum number of balls in a bag. Return the minimum possible 
penalty after performing the operations.

EXPLANATION:
Binary search on penalty (max balls in bag):
- Min penalty = 1, Max penalty = max(nums)
- For each penalty, calculate operations needed
- Operations for bag with x balls = (x - 1) / penalty
- Find minimum penalty achievable with maxOperations

Time Complexity: O(n * log(max))
Space Complexity: O(1)

INPUT-OUTPUT EXAMPLES:

Example 1:
Input: nums = [9], maxOperations = 2
Output: 3
Explanation: Divide bag: [9] -> [6,3] -> [3,3,3]

Example 2:
Input: nums = [2,4,8,2], maxOperations = 4
Output: 2
Explanation: Divide [8] twice and [4] once

Example 3:
Input: nums = [7,17], maxOperations = 2
Output: 7
"""

from typing import List, Optional


def can_achieve_limit(nums, max_ops, penalty):
    ops = sum((n - 1) // penalty for n in nums)
    return ops <= max_ops


class Solution:
    def minimumSize(self, nums, maxOperations):
        left = 1
        right = max(nums)
        while left < right:
            mid = left + (right - left) // 2
            if can_achieve_limit(nums, maxOperations, mid):
                right = mid
            else:
                left = mid + 1
        return left


if __name__ == "__main__":
    solution = Solution()
    nums1 = [9]
    print(f"Test 1: {solution.minimumSize(nums1, 2)}")
    nums2 = [2, 4, 8, 2]
    print(f"Test 2: {solution.minimumSize(nums2, 4)}")
    nums3 = [7, 17]
    print(f"Test 3: {solution.minimumSize(nums3, 2)}")
