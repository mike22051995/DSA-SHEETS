"""
PROBLEM: Split Array Largest Sum (LeetCode 410)
DIFFICULTY: Hard
PATTERN: Binary Search + Greedy Validation

DESCRIPTION:
Given an array nums which consists of non-negative integers and an integer m, you can split 
the array into m non-empty continuous subarrays. Write an algorithm to minimize the largest 
sum among these m subarrays.

INPUT:
- nums: array of non-negative integers
- m: number of subarrays

OUTPUT:
- Minimized largest sum

APPROACH:
1. Binary search on answer: range [max(nums), sum(nums)]
2. For each mid value, check if we can split into ≤m subarrays with max sum ≤ mid
3. Greedy validation: accumulate sum, create new subarray when exceeds mid
4. Adjust binary search based on validation result

WHY GREEDY WORKS:
For validation, greedily adding elements to current subarray until limit is optimal.
Binary search finds the minimum feasible maximum sum.
"""

from typing import List, Optional

class Solution:
    def splitArray(self, nums, m):
        long left = *max_element(nums.begin(), nums.end());  # Min possible: largest element
        long right = accumulate(nums.begin(), nums.end(), 0L); # Max possible: sum of all
        while left < right:
        long mid = left + (right - left) / 2
        if (canSplit(nums, m, mid)):
        right = mid;  # Can achieve mid, try smaller
        } else 
        left = mid + 1;  # Can't achieve mid, need larger
        return left


if __name__ == "__main__":
    sol = Solution()
    nums1 = [7, 2, 5, 10, 8]
    print(f"Test 1 - nums: [7,2,5,10,8], m=2")
    print(f"Output: {sol.splitArray(nums1,}")
    print(f"Expected: 18 (split: [7,2,5] and [10,8])")
    nums2 = [1, 2, 3, 4, 5]
    print(f"Test 2 - nums: [1,2,3,4,5], m=2")
    print(f"Output: {sol.splitArray(nums2,}")
    print(f"Expected: 9 (split: [1,2,3,4] and [5])")
    nums3 = [1, 4, 4]
    print(f"Test 3 - nums: [1,4,4], m=3")
    print(f"Output: {sol.splitArray(nums3,}")
    print(f"Expected: 4")
