"""
PROBLEM: Print Array Elements
---------------------------------------------------------------------------
Given an array of integers, print all elements using recursion.

DIFFICULTY: Easy
PATTERN: Linear Recursion
TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(n) - recursion stack

INPUT/OUTPUT EXAMPLES:
---------------------------------------------------------------------------
Example 1:
Input: arr = [1,2,3,4,5]
Output: 1 2 3 4 5

Example 2:
Input: arr = [10,20,30]
Output: 10 20 30
"""

from typing import List


class Solution:
    def printArray(self, arr: List[int], index: int = 0) -> None:
        # Base case
        if index >= len(arr):
            return
        # Print current element
        print(arr[index], end=" ")
        # Recursive case
        self.printArray(arr, index + 1)

    def printReverse(self, arr: List[int], index: int = 0) -> None:
        # Base case
        if index >= len(arr):
            return
        # Recurse first, then print (reverse order)
        self.printReverse(arr, index + 1)
        print(arr[index], end=" ")


if __name__ == "__main__":
    sol = Solution()
    arr1 = [1, 2, 3, 4, 5]
    print("Test 1 (Forward): ", end="")
    sol.printArray(arr1)
    print()
    arr2 = [10, 20, 30]
    print("Test 2 (Reverse): ", end="")
    sol.printReverse(arr2)
    print()
