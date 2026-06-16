"""
PROBLEM: Selection Sort Implementation
===============================================
DESCRIPTION:
Implement the selection sort algorithm. The algorithm divides the input list into 
two parts: sorted and unsorted. It repeatedly selects the smallest element from 
the unsorted portion and moves it to the end of the sorted portion.

PATTERN: Basic Sorting Algorithm
DIFFICULTY: Easy
TIME COMPLEXITY: O(n²)
SPACE COMPLEXITY: O(1)

INPUT:
Array of integers

OUTPUT:
Sorted array in ascending order

EXAMPLE:
Input: [64, 25, 12, 22, 11]
Output: [11, 12, 22, 25, 64]
"""

from typing import List, Optional

class Solution:
    def selectionSort(self, arr):
        n = len(arr)
        # Move boundary of unsorted subarray one by one
        for i in range(n - 1):
        # Find the minimum element in unsorted array
            minIdx = i
            for j in range(i + 1, n):
                if arr[j] < arr[minIdx]:
                    minIdx = j
        # Swap the found minimum element with the first element
            if minIdx != i:
                arr[i], arr[minIdx] = arr[minIdx], arr[i]
        return arr


if __name__ == "__main__":
    sol = Solution()
    arr = [64, 25, 12, 22, 11]
    print("Original array: ")
    for num in arr:
        print(num, end=" ")
    print()
    sol.selectionSort(arr)
    print("Sorted array: ")
    for num in arr:
        print(num, end=" ")
    print()
