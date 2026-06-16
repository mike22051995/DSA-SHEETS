"""
PROBLEM: Largest Number (LeetCode 179)
===============================================
DESCRIPTION:
Given a list of non-negative integers, arrange them such that they form the 
largest number and return it as a string.

PATTERN: Custom Comparator Sorting
DIFFICULTY: Medium
TIME COMPLEXITY: O(n log n)
SPACE COMPLEXITY: O(n)

INPUT:
Array of non-negative integers

OUTPUT:
String representing the largest number

EXAMPLE:
Input: [10,2]
Output: "210"

Input: [3,30,34,5,9]
Output: "9534330"
"""

from typing import List
from functools import cmp_to_key

class Solution:
    def largestNumber(self, nums: List[int]) -> str:
        # Convert numbers to strings
        strs = [str(num) for num in nums]
        
        # Custom comparator: compare concatenations
        # For a and b, if ab > ba, then a should come before b
        def compare(a, b):
            if a + b > b + a:
                return -1  # a comes first
            elif a + b < b + a:
                return 1   # b comes first
            else:
                return 0
        
        strs.sort(key=cmp_to_key(compare))
        
        # Handle edge case: all zeros
        if strs[0] == "0":
            return "0"
        
        # Concatenate all strings
        return "".join(strs)


if __name__ == "__main__":
    sol = Solution()
    
    nums1 = [10, 2]
    print("Input: ")
    for num in nums1:
        print(num, end=" ")
    print(f"\nOutput: {sol.largestNumber(nums1)}")
    
    nums2 = [3, 30, 34, 5, 9]
    print("\nInput: ")
    for num in nums2:
        print(num, end=" ")
    print(f"\nOutput: {sol.largestNumber(nums2)}")
    
    nums3 = [0, 0]
    print("\nInput: ")
    for num in nums3:
        print(num, end=" ")
    print(f"\nOutput: {sol.largestNumber(nums3)}")
