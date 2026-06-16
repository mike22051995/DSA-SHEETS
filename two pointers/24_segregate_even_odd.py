"""
PROBLEM: Segregate Even and Odd Numbers
---------------------------------------------------------------------------
Given an array arr[], segregate even and odd numbers. All even numbers 
should be present first, followed by odd numbers. The relative order 
doesn't need to be maintained.

PATTERN: Two Pointers (Partition - QuickSort style)
TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(1)

INPUT/OUTPUT EXAMPLES:
---------------------------------------------------------------------------
Example 1:
Input: arr = [12, 34, 45, 9, 8, 90, 3]
Output: [12, 34, 90, 8, 9, 45, 3] (any valid segregation)
Explanation: All even numbers come before odd numbers.

Example 2:
Input: arr = [1, 3, 2, 4, 7, 6, 9, 10]
Output: [10, 6, 2, 4, 7, 3, 9, 1] (any valid segregation)
Explanation: [2,4,6,10,1,3,7,9] is also valid.
"""

from typing import List, Optional

class Solution:
    def segregateEvenOdd(self, arr):
        left = 0
        right = len(arr) - 1
        while left < right:
            # Move left pointer until we find an odd number
            while left < right and arr[left] % 2 == 0:
                left += 1
            # Move right pointer until we find an even number
            while left < right and arr[right] % 2 == 1:
                right -= 1
            # Swap odd at left with even at right
            if left < right:
                arr[left], arr[right] = arr[right], arr[left]
                left += 1
                right -= 1


if __name__ == "__main__":
    sol = Solution()
    arr1 = [12, 34, 45, 9, 8, 90, 3]
    sol.segregateEvenOdd(arr1)
    print("Test 1: [", end="")
    for i in range(len(arr1)):
        print(arr1[i], end="," if i < len(arr1) - 1 else "")
    print("]")
    arr2 = [1, 3, 2, 4, 7, 6, 9, 10]
    sol.segregateEvenOdd(arr2)
    print("Test 2: [", end="")
    for i in range(len(arr2)):
        print(arr2[i], end="," if i < len(arr2) - 1 else "")
    print("]")
