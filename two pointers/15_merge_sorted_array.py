"""
PROBLEM: Merge Sorted Array
---------------------------------------------------------------------------
You are given two integer arrays nums1 and nums2, sorted in non-decreasing 
order, and two integers m and n, representing the number of elements in 
nums1 and nums2 respectively. Merge nums2 into nums1 as one sorted array.

PATTERN: Opposite Direction Two Pointers (Backward)
TIME COMPLEXITY: O(m + n)
SPACE COMPLEXITY: O(1)

INPUT/OUTPUT EXAMPLES:
---------------------------------------------------------------------------
Example 1:
Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
Explanation: Merge [1,2,3] and [2,5,6] into nums1.

Example 2:
Input: nums1 = [1], m = 1, nums2 = [], n = 0
Output: [1]
Explanation: Arrays [1] and [] merge into [1].
"""

from typing import List


class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        i = m - 1      # Last element in nums1
        j = n - 1      # Last element in nums2
        k = m + n - 1  # Last position in merged array
        # Merge from the end to avoid overwriting
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
    sol = Solution()
    nums1_1 = [1, 2, 3, 0, 0, 0]
    nums2_1 = [2, 5, 6]
    sol.merge(nums1_1, 3, nums2_1, 3)
    print(f"Test 1: {nums1_1}")
    nums1_2 = [1]
    nums2_2 = []
    sol.merge(nums1_2, 1, nums2_2, 0)
    print(f"Test 2: {nums1_2}")
