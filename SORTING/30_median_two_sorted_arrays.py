"""
PROBLEM: Median of Two Sorted Arrays (LeetCode 4)
===============================================
DESCRIPTION:
Given two sorted arrays nums1 and nums2 of size m and n respectively, return 
the median of the two sorted arrays. The overall run time complexity should be 
O(log(min(m,n))).

PATTERN: Binary Search on Sorted Arrays
DIFFICULTY: Hard
TIME COMPLEXITY: O(log(min(m,n)))
SPACE COMPLEXITY: O(1)

INPUT:
Two sorted arrays

OUTPUT:
Median of combined sorted array

EXAMPLE:
Input: nums1 = [1,3], nums2 = [2]
Output: 2.0
Explanation: merged [1,2,3], median = 2

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.5
Explanation: merged [1,2,3,4], median = (2+3)/2 = 2.5
"""

from typing import List

class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        # Ensure nums1 is smaller for efficiency
        if len(nums1) > len(nums2):
            return self.findMedianSortedArrays(nums2, nums1)
        
        m = len(nums1)
        n = len(nums2)
        left = 0
        right = m
        
        # Binary search on smaller array
        while left <= right:
            # Partition nums1 at i, nums2 at j
            i = (left + right) // 2
            j = (m + n + 1) // 2 - i
            
            # Handle edge cases
            maxLeft1 = float('-inf') if i == 0 else nums1[i - 1]
            minRight1 = float('inf') if i == m else nums1[i]
            maxLeft2 = float('-inf') if j == 0 else nums2[j - 1]
            minRight2 = float('inf') if j == n else nums2[j]
            
            # Check if partition is correct
            if maxLeft1 <= minRight2 and maxLeft2 <= minRight1:
                # Found correct partition
                if (m + n) % 2 == 0:
                    # Even total length
                    return (max(maxLeft1, maxLeft2) + min(minRight1, minRight2)) / 2.0
                else:
                    # Odd total length
                    return max(maxLeft1, maxLeft2)
            elif maxLeft1 > minRight2:
                # Too far right in nums1, move left
                right = i - 1
            else:
                # Too far left in nums1, move right
                left = i + 1
        
        return 0.0


if __name__ == "__main__":
    sol = Solution()
    
    nums1 = [1, 3]
    nums2 = [2]
    print("nums1: ")
    for num in nums1:
        print(num, end=" ")
    print("\nnums2: ")
    for num in nums2:
        print(num, end=" ")
    print(f"\nMedian: {sol.findMedianSortedArrays(nums1, nums2)}")
    
    nums3 = [1, 2]
    nums4 = [3, 4]
    print("\nnums1: ")
    for num in nums3:
        print(num, end=" ")
    print("\nnums2: ")
    for num in nums4:
        print(num, end=" ")
    print(f"\nMedian: {sol.findMedianSortedArrays(nums3, nums4)}")
