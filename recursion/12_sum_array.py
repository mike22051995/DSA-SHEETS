"""
PROBLEM: Sum of Array Elements
---------------------------------------------------------------------------
Given an array of integers, find the sum of all elements using recursion.

DIFFICULTY: Easy
PATTERN: Linear Recursion
TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(n) - recursion stack

INPUT/OUTPUT EXAMPLES:
---------------------------------------------------------------------------
Example 1:
Input: arr = [1,2,3,4,5]
Output: 15
Explanation: 1 + 2 + 3 + 4 + 5 = 15

Example 2:
Input: arr = [10,20,30]
Output: 60
Explanation: 10 + 20 + 30 = 60
"""

from typing import List


class Solution:
    def arraySum(self, arr: List[int], index: int = 0) -> int:
        # Base case
        if index >= len(arr):
            return 0
        # Recursive case
        return arr[index] + self.arraySum(arr, index + 1)


if __name__ == "__main__":
    sol = Solution()
    arr1 = [1, 2, 3, 4, 5]
    print(f"Test 1: Sum = {sol.arraySum(arr1)}")
    arr2 = [10, 20, 30]
    print(f"Test 2: Sum = {sol.arraySum(arr2)}")
