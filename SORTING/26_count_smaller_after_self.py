"""
PROBLEM: Count of Smaller Numbers After Self (LeetCode 315)
===============================================
DESCRIPTION:
Given an integer array nums, return an integer array counts where counts[i] is 
the number of smaller elements to the right of nums[i].

PATTERN: Merge Sort with Index Tracking / Binary Indexed Tree
DIFFICULTY: Hard
TIME COMPLEXITY: O(n log n)
SPACE COMPLEXITY: O(n)

INPUT:
Array of integers

OUTPUT:
Array where each element = count of smaller elements to its right

EXAMPLE:
Input: [5,2,6,1]
Output: [2,1,1,0]
Explanation:
- To the right of 5: [2,1] are smaller → 2
- To the right of 2: [1] is smaller → 1
- To the right of 6: [1] is smaller → 1
- To the right of 1: [] → 0
"""

from typing import List

class Solution:
    def countSmaller(self, nums: List[int]) -> List[int]:
        result = [0] * len(nums)
        # Create list of (value, original_index)
        indexed_nums = [(num, i) for i, num in enumerate(nums)]
        
        def merge_sort(arr):
            if len(arr) <= 1:
                return arr
            
            mid = len(arr) // 2
            left = merge_sort(arr[:mid])
            right = merge_sort(arr[mid:])
            
            return merge(left, right)
        
        def merge(left, right):
            result_arr = []
            i = j = 0
            
            while i < len(left) and j < len(right):
                if left[i][0] <= right[j][0]:
                    result_arr.append(left[i])
                    i += 1
                else:
                    # All remaining elements in left are greater than right[j]
                    result[right[j][1]] += i
                    result_arr.append(right[j])
                    j += 1
            
            result_arr.extend(left[i:])
            result_arr.extend(right[j:])
            return result_arr
        
        merge_sort(indexed_nums)
        return result


if __name__ == "__main__":
    sol = Solution()
    
    nums1 = [5, 2, 6, 1]
    print("Input: ")
    for num in nums1:
        print(num, end=" ")
    print()
    result1 = sol.countSmaller(nums1)
    print("Output: ")
    for num in result1:
        print(num, end=" ")
    print()
    
    nums2 = [-1, -1]
    print("\nInput: ")
    for num in nums2:
        print(num, end=" ")
    print()
    result2 = sol.countSmaller(nums2)
    print("Output: ")
    for num in result2:
        print(num, end=" ")
    print()
