"""
PROBLEM: Insertion Sort Implementation
===============================================
DESCRIPTION:
Implement insertion sort algorithm. The array is virtually split into sorted and 
unsorted parts. Values from the unsorted part are picked and placed at the correct 
position in the sorted part.

PATTERN: Basic Sorting Algorithm
DIFFICULTY: Easy
TIME COMPLEXITY: O(n²) - worst case, O(n) - best case
SPACE COMPLEXITY: O(1)

INPUT:
Array of integers

OUTPUT:
Sorted array in ascending order

EXAMPLE:
Input: [12, 11, 13, 5, 6]
Output: [5, 6, 11, 12, 13]
"""

from typing import List, Optional

class Solution:
    def insertionSort(self, arr):
        n = len(arr)
        # Start from second element (first element is considered sorted)
        for i in range(1, n):
            key = arr[i]
            j = i - 1
        # Move elements greater than key one position ahead
            while j >= 0 and arr[j] > key:
                arr[j + 1] = arr[j]
                j -= 1
        # Place key at its correct position
            arr[j + 1] = key
        return arr


if __name__ == "__main__":
    sol = Solution()
    arr = [12, 11, 13, 5, 6]
    print("Original array: ")
    for num in arr:
        print(num, end=" ")
    print()
    sol.insertionSort(arr)
    print("Sorted array: ")
    for num in arr:
        print(num, end=" ")
    print()
