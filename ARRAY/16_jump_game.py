"""
PROBLEM: Jump Game
Difficulty: Medium
Pattern: Greedy

DESCRIPTION:
You are given an integer array nums. You are initially positioned at the array's first index, 
and each element in the array represents your maximum jump length at that position.
Return True if you can reach the last index, or False otherwise.

EXPLANATION:
Greedy approach: Track the farthest index we can reach.
At each position, update the farthest reachable index.
If at any point current index exceeds farthest reachable, we cannot proceed.

Time Complexity: O(n)
Space Complexity: O(1)

INPUT-OUTPUT EXAMPLES:

Example 1:
Input: nums = [2,3,1,1,4]
Output: True
Explanation: Jump 1 step from index 0 to 1, then 3 steps to last index

Example 2:
Input: nums = [3,2,1,0,4]
Output: False
Explanation: You will always arrive at index 3, max jump = 0

Example 3:
Input: nums = [0]
Output: True
Explanation: Already at last index
"""

from typing import List, Optional

class Solution:
    def canJump(self, nums):
        n = len(nums)
        maxReach = 0
        for i in range(n):
        # If current index is beyond max reachable, cannot proceed
            if i > maxReach:
                return False
            # Update max reachable index
            maxReach = max(maxReach, i + nums[i])
            # If we can reach the last index
            if maxReach >= n - 1:
                return True
        return False


if __name__ == "__main__":
    solution = Solution()
    nums1 = [2, 3, 1, 1, 4]
    print(f"Test 1: {solution.canJump(nums1)}")
    nums2 = [3, 2, 1, 0, 4]
    print(f"Test 2: {solution.canJump(nums2)}")
    nums3 = [0]
    print(f"Test 3: {solution.canJump(nums3)}")
