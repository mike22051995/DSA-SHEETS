"""
PROBLEM: Majority Element (Boyer-Moore Voting Algorithm) (LeetCode 169)
DIFFICULTY: Easy
PATTERN: Voting/Cancellation Strategy

DESCRIPTION:
Given an array nums of size n, return the majority element. The majority element is 
the element that appears more than ⌊n/2⌋ times. You may assume that the majority 
element always exists in the array.

INPUT:
- nums: array of integers

OUTPUT:
- The majority element

APPROACH (Boyer-Moore Voting Algorithm):
1. Maintain a candidate and count
2. When count is 0, pick current element as candidate
3. If current element matches candidate, increment count; otherwise decrement
4. Greedy insight: pairs of different elements cancel out

WHY GREEDY WORKS:
Since majority element appears >n/2 times, after all cancellations, 
it will survive as the candidate.
"""

from typing import List, Optional

class Solution:
    def majorityElement(self, nums):
        candidate = 0
        count = 0
        # Phase 1: Find candidate
        for num in nums:
        if count == 0:
        candidate = num;  # New candidate
        # Vote for or against current candidate
        if num == candidate:
        count += 1
        } else 
        count--;  # Cancellation
        # Phase 2: Verify (not needed if majority always exists)
        # Uncomment if verification is required
        /*
        count = 0
        for num in nums:
        if (num == candidate) count += 1
        return (count > len(nums) / 2) ? candidate : -1
        */
        return candidate


if __name__ == "__main__":
    sol = Solution()
    nums1 = [3, 2, 3]
    print(f"Test 1 - Array: [3,2,3]")
    print(f"Output: {sol.majorityElement(nums1)}")
    print(f"Expected: 3")
    nums2 = [2, 2, 1, 1, 1, 2, 2]
    print(f"Test 2 - Array: [2,2,1,1,1,2,2]")
    print(f"Output: {sol.majorityElement(nums2)}")
    print(f"Expected: 2")
    nums3 = [1]
    print(f"Test 3 - Array: [1]")
    print(f"Output: {sol.majorityElement(nums3)}")
    print(f"Expected: 1")
    nums4 = [6, 5, 5]
    print(f"Test 4 - Array: [6,5,5]")
    print(f"Output: {sol.majorityElement(nums4)}")
    print(f"Expected: 5")
