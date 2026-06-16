"""
PROBLEM: Check if Array is Sorted
---------------------------------------------------------------------------
Given an array of integers, check if it is sorted in non-decreasing order 
using recursion.

DIFFICULTY: Easy
PATTERN: Linear Recursion
TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(n) - recursion stack

INPUT/OUTPUT EXAMPLES:
---------------------------------------------------------------------------
Example 1:
Input: arr = [1,2,3,4,5]
Output: True
Explanation: Array is sorted in ascending order

Example 2:
Input: arr = [1,3,2,4]
Output: False
Explanation: 3 > 2, so not sorted
"""

from typing import List


class Solution:
    def isSorted(self, arr: List[int], index: int = 0) -> bool:
        # Base case
        if index >= len(arr) - 1:
            return True
        if arr[index] > arr[index + 1]:
            return False
        return self.isSorted(arr, index + 1)


if __name__ == "__main__":
    sol = Solution()
    arr1 = [1, 2, 3, 4, 5]
    print(f"Test 1: Is sorted? {sol.isSorted(arr1)}")
    arr2 = [1, 3, 2, 4]
    print(f"Test 2: Is sorted? {sol.isSorted(arr2)}")
