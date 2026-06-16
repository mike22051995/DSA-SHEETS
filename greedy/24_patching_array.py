"""
PROBLEM: Patching Array (LeetCode 330)
DIFFICULTY: Hard
PATTERN: Greedy Range Coverage

DESCRIPTION:
Given a sorted integer array nums and an integer n, add/patch elements to the array such 
that any number in the range [1, n] inclusive can be formed by the sum of some elements 
in the array. Return the minimum number of patches required.

INPUT:
- nums: sorted array of positive integers
- n: target range upper bound

OUTPUT:
- Minimum patches needed

APPROACH:
1. Track maximum reachable sum (miss)
2. If current number <= miss, we can extend range to miss + num
3. If current number > miss, we have a gap, add miss as patch
4. Continue until miss > n

WHY GREEDY WORKS:
Always patching with "miss" value maximizes range extension. This is optimal because
it doubles our reachable range.
"""

from typing import List, Optional

class Solution:
    def minPatches(self, nums, n):
        long miss = 1;  # Smallest sum we can't make yet (use long to avoid overflow)
        patches = 0
        i = 0
        while miss <= n:
        if (i < len(nums) and nums[i] <= miss):
        # Use current number to extend range
        miss += nums[i]
        i += 1
        } else 
        # Add "miss" as a patch to double our range
        miss += miss
        patches += 1
        return patches


if __name__ == "__main__":
    sol = Solution()
    nums1 = [1, 3]
    print(f"Test 1 - nums: [1,3], n=6")
    print(f"Output: {sol.minPatches(nums1,}")
    print(f"Expected: 1 (add 2, can form [1,2,3,4,5,6])")
    nums2 = [1, 5, 10]
    print(f"Test 2 - nums: [1,5,10], n=20")
    print(f"Output: {sol.minPatches(nums2,}")
    print(f"Expected: 2 (add 2 and 4)")
    nums3 = [1, 2, 2]
    print(f"Test 3 - nums: [1,2,2], n=5")
    print(f"Output: {sol.minPatches(nums3,}")
    print(f"Expected: 0")
    nums4 = {}
    print(f"Test 4 - nums: [], n=7")
    print(f"Output: {sol.minPatches(nums4,}")
    print(f"Expected: 3 (add 1,2,4)")
