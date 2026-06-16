"""
PROBLEM: Kth Largest Element using QuickSelect (LeetCode 215)
===============================================
DESCRIPTION:
Find the kth largest element in an unsorted array using QuickSelect algorithm.
This is more efficient than sorting the entire array.

PATTERN: QuickSelect / Partition
DIFFICULTY: Medium
TIME COMPLEXITY: O(n) average, O(n²) worst case
SPACE COMPLEXITY: O(1)

INPUT:
Array of integers and k

OUTPUT:
Kth largest element

EXAMPLE:
Input: nums = [3,2,1,5,6,4], k = 2
Output: 5

Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
Output: 4
"""

from typing import List, Optional

class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        # Find kth largest = n - k smallest
        return self.quickSelect(nums, 0, len(nums) - 1, len(nums) - k)
    
    def quickSelect(self, nums: List[int], left: int, right: int, k: int) -> int:
        if left == right:
            return nums[left]
        
        # Partition the array
        pi = self.partition(nums, left, right)
        
        if pi == k:
            return nums[pi]
        elif pi < k:
            return self.quickSelect(nums, pi + 1, right, k)
        else:
            return self.quickSelect(nums, left, pi - 1, k)
    
    def partition(self, nums: List[int], left: int, right: int) -> int:
        pivot = nums[right]
        i = left
        
        for j in range(left, right):
            if nums[j] <= pivot:
                nums[i], nums[j] = nums[j], nums[i]
                i += 1
        
        nums[i], nums[right] = nums[right], nums[i]
        return i


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
