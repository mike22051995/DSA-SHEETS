"""
PROBLEM: Merge Two Sorted Arrays
===============================================
DESCRIPTION:
Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one 
sorted array. The number of elements in nums1 and nums2 are m and n respectively.
Assume nums1 has enough space to hold additional elements from nums2.

PATTERN: Two Pointer + Merge
DIFFICULTY: Easy
TIME COMPLEXITY: O(m + n)
SPACE COMPLEXITY: O(1)

INPUT:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6], n = 3

OUTPUT:
nums1 = [1,2,2,3,5,6]

EXAMPLE:
Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
"""

from typing import List, Optional

class Solution:
    def merge(self, nums1, m, nums2, n):
        # Start from the end to avoid overwriting elements in nums1
        i = m - 1      # Last element in nums1's initial portion
        j = n - 1      # Last element in nums2
        k = m + n - 1  # Last position in nums1
        # Merge from back to front
        while i >= 0 and j >= 0:
            if nums1[i] > nums2[j]:
                nums1[k] = nums1[i]
                i -= 1
            else:
                nums1[k] = nums2[j]
                j -= 1
            k -= 1
        # If any elements left in nums2, copy them
        while j >= 0:
            nums1[k] = nums2[j]
            k -= 1
            j -= 1
        # No need to copy remaining elements from nums1 as they're already in place


if __name__ == "__main__":
    sol = Solution()
    nums1 = [1, 2, 3, 0, 0, 0]
    nums2 = [2, 5, 6]
    m = 3
    n = 3
    print("nums1: ")
    for num in nums1:
        print(num, end=" ")
    print("\nnums2: ")
    for num in nums2:
        print(num, end=" ")
    print()
    sol.merge(nums1, m, nums2, n)
    print("Merged array: ")
    for num in nums1:
        print(num, end=" ")
    print()
