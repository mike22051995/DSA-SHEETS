"""
PROBLEM: Find K-th Smallest Pair Distance
Difficulty: Hard
Pattern: Binary Search on Value Range

DESCRIPTION:
The distance of a pair of integers a and b is defined as the absolute difference between a and b.
Given an integer array nums and an integer k, return the kth smallest distance among all the pairs 
nums[i] and nums[j] where 0 <= i < j < nums.length.

EXPLANATION:
Binary search on distance value:
- Sort the array first
- Min distance = 0, Max distance = max - min
- For each mid, count pairs with distance <= mid using sliding window
- Find smallest distance with at least k pairs

Time Complexity: O(n log n + n * log(max - min))
Space Complexity: O(1)

INPUT-OUTPUT EXAMPLES:

Example 1:
Input: nums = [1,3,1], k = 1
Output: 0
Explanation: Pairs: (1,3)=2, (1,1)=0, (3,1)=2. 1st smallest is 0

Example 2:
Input: nums = [1,1,1], k = 2
Output: 0
Explanation: All pairs have distance 0

Example 3:
Input: nums = [1,6,1], k = 3
Output: 5
"""

from typing import List, Optional


def count_pairs(nums, max_dist):
    count = 0
    left = 0
    for right in range(len(nums)):
        while nums[right] - nums[left] > max_dist:
            left += 1
        count += right - left
    return count


class Solution:
    def smallestDistancePair(self, nums, k):
        nums.sort()
        left = 0
        right = nums[-1] - nums[0]
        while left < right:
            mid = left + (right - left) // 2
            if count_pairs(nums, mid) < k:
                left = mid + 1
            else:
                right = mid
        return left


if __name__ == "__main__":
    solution = Solution()
    nums1 = [1, 3, 1]
    print(f"Test 1: {solution.smallestDistancePair(nums1, 1)}")
    nums2 = [1, 1, 1]
    print(f"Test 2: {solution.smallestDistancePair(nums2, 2)}")
    nums3 = [1, 6, 1]
    print(f"Test 3: {solution.smallestDistancePair(nums3, 3)}")
