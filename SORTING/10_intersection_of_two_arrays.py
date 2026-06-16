"""
PROBLEM: Intersection of Two Arrays (LeetCode 349/350)
===============================================
DESCRIPTION:
Given two integer arrays nums1 and nums2, return an array of their intersection.
Each element in the result must be unique and you may return the result in any order.

PATTERN: Sorting + Two Pointer
DIFFICULTY: Easy
TIME COMPLEXITY: O(n log n + m log m)
SPACE COMPLEXITY: O(1) excluding output array

INPUT:
Two arrays of integers

OUTPUT:
Array containing intersection elements

EXAMPLE:
Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4] or [4,9]
"""

from collections import Counter
from typing import List


class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        """Return unique intersection using sorting + two pointers."""
        nums1_sorted = sorted(nums1)
        nums2_sorted = sorted(nums2)

        i = 0
        j = 0
        result: List[int] = []

        while i < len(nums1_sorted) and j < len(nums2_sorted):
            if nums1_sorted[i] == nums2_sorted[j]:
                if not result or result[-1] != nums1_sorted[i]:
                    result.append(nums1_sorted[i])
                i += 1
                j += 1
            elif nums1_sorted[i] < nums2_sorted[j]:
                i += 1
            else:
                j += 1

        return result

    def intersectionV2(self, nums1: List[int], nums2: List[int]) -> List[int]:
        """Return unique intersection using set operations."""
        return list(set(nums1) & set(nums2))

    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        """Return intersection including duplicates (LeetCode 350)."""
        counts = Counter(nums1)
        result: List[int] = []

        for num in nums2:
            if counts[num] > 0:
                result.append(num)
                counts[num] -= 1

        return result


if __name__ == "__main__":
    sol = Solution()
    nums1 = [1, 2, 2, 1]
    nums2 = [2, 2]

    print("nums1:", nums1)
    print("nums2:", nums2)
    print("Unique intersection (two-pointer):", sol.intersection(nums1, nums2))
    print("Unique intersection (set):", sol.intersectionV2(nums1, nums2))
    print("Intersection with duplicates:", sol.intersect(nums1, nums2))
