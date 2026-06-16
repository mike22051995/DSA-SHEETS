"""
PROBLEM: Count of Range Sum (LeetCode 327)
===============================================
DESCRIPTION:
Given an integer array nums and two integers lower and upper, return the number 
of range sums that lie in [lower, upper] inclusive.
Range sum S(i, j) is defined as the sum of elements in nums between indices i 
and j inclusive, where i <= j.

PATTERN: Modified Merge Sort with Prefix Sums
DIFFICULTY: Hard
TIME COMPLEXITY: O(n log n)
SPACE COMPLEXITY: O(n)

INPUT:
nums = [-2,5,-1], lower = -2, upper = 2

OUTPUT:
3
Explanation: Ranges [0,0], [2,2], [0,2] have sums in [-2,2]

EXAMPLE:
Input: nums = [-2,5,-1], lower = -2, upper = 2
Output: 3

Input: nums = [0], lower = 0, upper = 0
Output: 1
"""

from typing import List

class Solution:
    def countRangeSum(self, nums: List[int], lower: int, upper: int) -> int:
        # Calculate prefix sums
        prefix_sum = [0]
        for num in nums:
            prefix_sum.append(prefix_sum[-1] + num)
        
        # Use modified merge sort to count valid ranges
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
            j = k = 0
            
            # Count ranges with sum in [lower, upper]
            for i in range(len(left)):
                while j < len(right) and right[j] < left[i] - upper:
                    j += 1
                while k < len(right) and right[k] <= left[i] - lower:
                    k += 1
                count += k - j
            
            # Merge
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
        
        _, count = merge_sort(prefix_sum)
        return count


if __name__ == "__main__":
    sol = Solution()
    
    nums1 = [-2, 5, -1]
    lower1 = -2
    upper1 = 2
    print("Input: ")
    for num in nums1:
        print(num, end=" ")
    print(f"\nRange: [{lower1}, {upper1}]")
    print(f"Count: {sol.countRangeSum(nums1, lower1, upper1)}")
    
    nums2 = [0]
    lower2 = 0
    upper2 = 0
    print("\nInput: ")
    for num in nums2:
        print(num, end=" ")
    print(f"\nRange: [{lower2}, {upper2}]")
    print(f"Count: {sol.countRangeSum(nums2, lower2, upper2)}")
