"""
PROBLEM: Merge Sorted Array
Difficulty: Easy
Pattern: Two Pointers

DESCRIPTION:
You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two 
integers m and n, representing the number of elements in nums1 and nums2 respectively.
Merge nums1 and nums2 into a single array sorted in non-decreasing order.
The final sorted array should be stored inside the array nums1.

EXPLANATION:
Start merging from the end of both arrays to avoid overwriting elements in nums1.
Compare elements from the end of both arrays and place the larger one at the end of nums1.
This way we use the extra space in nums1 efficiently.

Time Complexity: O(m + n)
Space Complexity: O(1)

INPUT-OUTPUT EXAMPLES:

Example 1:
Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
Explanation: Merge [1,2,3] and [2,5,6]

Example 2:
Input: nums1 = [1], m = 1, nums2 = [], n = 0
Output: [1]
Explanation: Nothing to merge

Example 3:
Input: nums1 = [0], m = 0, nums2 = [1], n = 1
Output: [1]
Explanation: nums1 is empty initially
"""

from typing import List

class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        i = m - 1      # Last element in nums1
        j = n - 1      # Last element in nums2
        k = m + n - 1  # Last position in merged array
        # Merge from the end
        while i >= 0 and j >= 0:
            if nums1[i] > nums2[j]:
                nums1[k] = nums1[i]
                i -= 1
            else:
                nums1[k] = nums2[j]
                j -= 1
            k -= 1
        # Copy remaining elements from nums2 if any
        while j >= 0:
            nums1[k] = nums2[j]
            j -= 1
            k -= 1


if __name__ == "__main__":
    solution = Solution()
    nums1 = [1, 2, 3, 0, 0, 0]
    nums2 = [2, 5, 6]
    solution.merge(nums1, 3, nums2, 3)
    print(f"Test 1: {nums1}")
    nums3 = [1]
    nums4 = []
    solution.merge(nums3, 1, nums4, 0)
    print(f"Test 2: {nums3}")
    nums5 = [0]
    nums6 = [1]
    solution.merge(nums5, 0, nums6, 1)
    print(f"Test 3: {nums5}")
