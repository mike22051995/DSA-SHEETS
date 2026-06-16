"""
PROBLEM: Median of Two Sorted Arrays
Difficulty: Hard
Pattern: Binary Search

DESCRIPTION:
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of 
the two sorted arrays. The overall run time complexity should be O(log (m+n)).

EXPLANATION:
Binary search on partition:
- Partition both arrays such that left half has same number of elements as right
- Ensure max(left1, left2) <= min(right1, right2)
- Median depends on whether total length is odd or even

Time Complexity: O(log(min(m, n)))
Space Complexity: O(1)

INPUT-OUTPUT EXAMPLES:

Example 1:
Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: Merged = [1,2,3], median = 2

Example 2:
Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: Merged = [1,2,3,4], median = (2+3)/2 = 2.5

Example 3:
Input: nums1 = [], nums2 = [1]
Output: 1.00000
"""

from typing import List, Optional

class Solution:
    def findMedianSortedArrays(self, nums1, nums2):
        if len(nums1) > len(nums2):
            return self.findMedianSortedArrays(nums2, nums1)
        m = len(nums1)
        n = len(nums2)
        left = 0
        right = m
        while left <= right:
            partition1 = (left + right) // 2
            partition2 = (m + n + 1) // 2 - partition1
            max_left1 = float('-inf') if partition1 == 0 else nums1[partition1 - 1]
            min_right1 = float('inf') if partition1 == m else nums1[partition1]
            max_left2 = float('-inf') if partition2 == 0 else nums2[partition2 - 1]
            min_right2 = float('inf') if partition2 == n else nums2[partition2]
            if max_left1 <= min_right2 and max_left2 <= min_right1:
                if (m + n) % 2 == 0:
                    return (max(max_left1, max_left2) + min(min_right1, min_right2)) / 2.0
                else:
                    return float(max(max_left1, max_left2))
            elif max_left1 > min_right2:
                right = partition1 - 1
            else:
                left = partition1 + 1
        return 0.0


if __name__ == "__main__":
    solution = Solution()
    nums1 = [1, 3]
    nums2 = [2]
    print(f"Test 1: {solution.findMedianSortedArrays(nums1, nums2)}")
    nums3 = [1, 2]
    nums4 = [3, 4]
    print(f"Test 2: {solution.findMedianSortedArrays(nums3, nums4)}")
    nums5 = []
    nums6 = [1]
    print(f"Test 3: {solution.findMedianSortedArrays(nums5, nums6)}")
