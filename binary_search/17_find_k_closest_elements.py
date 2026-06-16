"""
PROBLEM: Find K Closest Elements
Difficulty: Medium
Pattern: Binary Search + Two Pointers

DESCRIPTION:
Given a sorted integer array arr, two integers k and x, return the k closest integers to x 
in the array. The result should also be sorted in ascending order.
An integer a is closer to x than an integer b if:
|a - x| < |b - x|, or |a - x| == |b - x| and a < b

EXPLANATION:
Binary search to find the starting position:
- Search for the left boundary of the k-length window
- Window slides based on which end is farther from x
- Return k elements starting from left boundary

Time Complexity: O(log(n - k) + k)
Space Complexity: O(1)

INPUT-OUTPUT EXAMPLES:

Example 1:
Input: arr = [1,2,3,4,5], k = 4, x = 3
Output: [1,2,3,4]

Example 2:
Input: arr = [1,2,3,4,5], k = 4, x = -1
Output: [1,2,3,4]

Example 3:
Input: arr = [1,1,1,10,10,10], k = 1, x = 9
Output: [10]
"""

from typing import List, Optional

class Solution:
    def findClosestElements(self, arr, k, x):
        left = 0
        right = len(arr) - k
        while left < right:
            mid = left + (right - left) // 2
            # Compare distance of left and right boundaries
            if x - arr[mid] > arr[mid + k] - x:
                left = mid + 1
            else:
                right = mid
        return arr[left:left + k]


if __name__ == "__main__":
    solution = Solution()
    arr1 = [1, 2, 3, 4, 5]
    print(f"Test 1: {solution.findClosestElements(arr1, 4, 3)}")
    arr2 = [1, 2, 3, 4, 5]
    print(f"Test 2: {solution.findClosestElements(arr2, 4, -1)}")
    arr3 = [1, 1, 1, 10, 10, 10]
    print(f"Test 3: {solution.findClosestElements(arr3, 1, 9)}")
