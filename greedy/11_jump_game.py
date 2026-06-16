"""
PROBLEM: Jump Game (LeetCode 55)
DIFFICULTY: Medium
PATTERN: Greedy Reachability / Farthest Position Tracking

DESCRIPTION:
You are given an integer array nums. You are initially positioned at the array's first index, 
and each element in the array represents your maximum jump length at that position.
Return True if you can reach the last index, or False otherwise.

INPUT:
- nums: array where nums[i] is max jump length from position i

OUTPUT:
- True if last index is reachable, False otherwise

APPROACH:
1. Track the farthest position reachable so far
2. At each position, update farthest reachable
3. If current position > farthest, we're stuck
4. If farthest >= last index, return True

WHY GREEDY WORKS:
We don't need to find the actual path, just verify reachability.
Tracking maximum reach is sufficient and optimal.
"""

from typing import List, Optional

class Solution:
    def canJump(self, nums):
        farthest = 0
        n = len(nums)
        for i in range(n):
        # If current position is beyond our reach, can't proceed
        if i > farthest:
        return False
        # Update farthest position we can reach
        farthest = max(farthest, i + nums[i])
        # Early exit: if we can reach the end
        if farthest >= n - 1:
        return True
        return True


if __name__ == "__main__":
    sol = Solution()
    nums1 = [2, 3, 1, 1, 4]
    print(f"Test 1 - Array: [2,3,1,1,4]")
    print(f"Output: {(sol.canJump(nums1)}")
    print(f"Expected: True (jump 1 to index 1, then 3 to last)")
    nums2 = [3, 2, 1, 0, 4]
    print(f"Test 2 - Array: [3,2,1,0,4]")
    print(f"Output: {(sol.canJump(nums2)}")
    print(f"Expected: False (stuck at index 3)")
    nums3 = [0]
    print(f"Test 3 - Array: [0]")
    print(f"Output: {(sol.canJump(nums3)}")
    print(f"Expected: True (already at end)")
    nums4 = [2, 0, 0]
    print(f"Test 4 - Array: [2,0,0]")
    print(f"Output: {(sol.canJump(nums4)}")
    print(f"Expected: True")
