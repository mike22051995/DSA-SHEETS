"""
PROBLEM: Reverse Pairs (LeetCode 493)
===============================================
DESCRIPTION:
Given an integer array nums, return the number of reverse pairs in the array.
A reverse pair is a pair (i, j) where:
- 0 <= i < j < nums.length
- nums[i] > 2 * nums[j]

PATTERN: Modified Merge Sort
DIFFICULTY: Hard
TIME COMPLEXITY: O(n log n)
SPACE COMPLEXITY: O(n)

INPUT:
Array of integers

OUTPUT:
Count of reverse pairs

EXAMPLE:
Input: [1,3,2,3,1]
Output: 2
Explanation: (3,1) and (3,1) → 3 > 2*1

Input: [2,4,3,5,1]
Output: 3
Explanation: (2,1), (4,1), (3,1)
"""

from typing import List

class Solution:
    def reversePairs(self, nums: List[int]) -> int:
        def merge_sort(arr):
            if len(arr) <= 1:
                return arr, 0
            
            mid = len(arr) // 2
            left, left_count = merge_sort(arr[:mid])
            right, right_count = merge_sort(arr[mid:])
            
            merged, merge_count = merge(left, right)
            return merged, left_count + right_count + merge_count
        
        def merge(left, right):
            result = []
            count = 0
            j = 0
            
            # Count reverse pairs: i from left, j from right
            for i in range(len(left)):
                while j < len(right) and left[i] <= 2 * right[j]:
                    j += 1
                count += len(right) - j
            
            # Merge arrays
            i = j = 0
            while i < len(left) and j < len(right):
                if left[i] <= right[j]:
                    result.append(left[i])
                    i += 1
                else:
                    result.append(right[j])
                    j += 1
            
            result.extend(left[i:])
            result.extend(right[j:])
            
            return result, count
        
        _, count = merge_sort(nums)
        return count


if __name__ == "__main__":
    sol = Solution()
    
    nums1 = [1, 3, 2, 3, 1]
    print("Input: ")
    for num in nums1:
        print(num, end=" ")
    print()
    print(f"Reverse pairs: {sol.reversePairs(nums1)}")
    
    nums2 = [2, 4, 3, 5, 1]
    print("\nInput: ")
    for num in nums2:
        print(num, end=" ")
    print()
    print(f"Reverse pairs: {sol.reversePairs(nums2)}")
