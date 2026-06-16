"""
PROBLEM: Sort Array by Increasing Frequency (LeetCode 1636)
===============================================
DESCRIPTION:
Given an array of integers nums, sort the array in increasing order based on 
the frequency of the values. If multiple values have the same frequency, sort 
them in decreasing order. Return the sorted array.

PATTERN: Frequency Count + Custom Comparator
DIFFICULTY: Medium
TIME COMPLEXITY: O(n log n)
SPACE COMPLEXITY: O(n)

INPUT:
Array of integers

OUTPUT:
Array sorted by frequency (ascending), then by value (descending)

EXAMPLE:
Input: [1,1,2,2,2,3]
Output: [3,1,1,2,2,2]
Explanation: 3 appears 1 time, 1 appears 2 times, 2 appears 3 times

Input: [2,3,1,3,2]
Output: [1,3,3,2,2]
"""

from typing import List
from functools import cmp_to_key

class Solution:
    def frequencySort(self, nums: List[int]) -> List[int]:
        # Count frequency of each number
        freq = {}
        for num in nums:
            freq[num] = freq.get(num, 0) + 1
        
        # Custom comparator:
        # 1. Sort by frequency (ascending)
        # 2. If frequencies are same, sort by value (descending)
        def compare(a, b):
            if freq[a] != freq[b]:
                return freq[a] - freq[b]  # Increasing frequency
            else:
                return b - a  # Decreasing value
        
        return sorted(nums, key=cmp_to_key(compare))
    
    def frequencySortV2(self, nums: List[int]) -> List[int]:
        freq = {}
        for num in nums:
            freq[num] = freq.get(num, 0) + 1
        
        # Create list of (value, frequency) pairs
        pairs = [(num, freq[num]) for num in freq]
        
        # Sort with custom comparator
        def compare(a, b):
            if a[1] != b[1]:
                return a[1] - b[1]  # By frequency ascending
            else:
                return b[0] - a[0]  # By value descending
        
        pairs.sort(key=cmp_to_key(compare))
        
        # Extract values
        result = []
        for val, freq_val in pairs:
            for _ in range(freq_val):
                result.append(val)
        
        return result


if __name__ == "__main__":
    sol = Solution()
    
    nums1 = [1, 1, 2, 2, 2, 3]
    print("Input: ")
    for num in nums1:
        print(num, end=" ")
    print()
    result1 = sol.frequencySort(nums1)
    print("Output: ")
    for num in result1:
        print(num, end=" ")
    print()
    
    nums2 = [2, 3, 1, 3, 2]
    print("\nInput: ")
    for num in nums2:
        print(num, end=" ")
    print()
    result2 = sol.frequencySort(nums2)
    print("Output: ")
    for num in result2:
        print(num, end=" ")
    print()
    
    nums3 = [-1, 1, -6, 4, 5, -6, 1, 4, 1]
    print("\nInput: ")
    for num in nums3:
        print(num, end=" ")
    print()
    result3 = sol.frequencySort(nums3)
    print("Output: ")
    for num in result3:
        print(num, end=" ")
    print()
