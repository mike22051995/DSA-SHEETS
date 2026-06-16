"""
PROBLEM: Binary Search (Recursive)
---------------------------------------------------------------------------
Given a sorted array of integers and a target value, return the index of 
the target if found. If not found, return -1.

DIFFICULTY: Easy-Medium
PATTERN: Divide and Conquer
TIME COMPLEXITY: O(log n)
SPACE COMPLEXITY: O(log n) - recursion stack

INPUT/OUTPUT EXAMPLES:
---------------------------------------------------------------------------
Example 1:
Input: arr = [1,3,5,7,9,11], target = 7
Output: 3
Explanation: 7 is found at index 3

Example 2:
Input: arr = [1,3,5,7,9,11], target = 6
Output: -1
Explanation: 6 is not in the array
"""

from typing import List


class Solution:
    def binarySearch(self, arr: List[int], target: int) -> int:
        def search(left: int, right: int) -> int:
            if left > right:
                return -1
            mid = (left + right) // 2
            if arr[mid] == target:
                return mid
            elif arr[mid] < target:
                return search(mid + 1, right)
            else:
                return search(left, mid - 1)

        return search(0, len(arr) - 1)


if __name__ == "__main__":
    sol = Solution()
    arr1 = [1, 3, 5, 7, 9, 11]
    target1 = 7
    print(f"Test 1: Index of {target1} = {sol.binarySearch(arr1, target1)}")
    arr2 = [1, 3, 5, 7, 9, 11]
    target2 = 6
    print(f"Test 2: Index of {target2} = {sol.binarySearch(arr2, target2)}")
