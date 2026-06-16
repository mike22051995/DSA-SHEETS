"""
PROBLEM: Kth Largest Element in Array (Simple Approach)
===============================================
DESCRIPTION:
Find the kth largest element in an unsorted array. Note that it is the kth 
largest element in sorted order, not the kth distinct element.

PATTERN: Sorting Approach
DIFFICULTY: Easy
TIME COMPLEXITY: O(n log n)
SPACE COMPLEXITY: O(1)

INPUT:
nums = [3,2,1,5,6,4], k = 2

OUTPUT:
5

EXAMPLE:
Input: nums = [3,2,1,5,6,4], k = 2
Output: 5 (largest is 6, 2nd largest is 5)

Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
Output: 4
"""

from typing import List, Optional

class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        # Sort in descending order
        nums.sort(reverse=True)
        return nums[k - 1]


if __name__ == "__main__":
    sol = Solution()
    nums1 = [3, 2, 1, 5, 6, 4]
    k1 = 2
    print("Array: ")
    for num in nums1:
        print(num, end=" ")
    print(f"\nK = {k1}")
    print(f"Kth largest: {sol.findKthLargest(nums1, k1)}")
    
    nums2 = [3, 2, 3, 1, 2, 4, 5, 5, 6]
    k2 = 4
    print("\nArray: ")
    for num in nums2:
        print(num, end=" ")
    print(f"\nK = {k2}")
    print(f"Kth largest: {sol.findKthLargest(nums2, k2)}")
