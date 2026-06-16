"""
PROBLEM: Bubble Sort Implementation
===============================================
DESCRIPTION:
Implement the bubble sort algorithm to sort an array in ascending order.
Bubble sort repeatedly steps through the list, compares adjacent elements and 
swaps them if they are in the wrong order.

PATTERN: Basic Sorting Algorithm
DIFFICULTY: Easy
TIME COMPLEXITY: O(n²) - worst and average case, O(n) - best case (optimized)
SPACE COMPLEXITY: O(1)

INPUT:
Array of integers

OUTPUT:
Sorted array in ascending order

EXAMPLE:
Input: [64, 34, 25, 12, 22, 11, 90]
Output: [11, 12, 22, 25, 34, 64, 90]
"""

from typing import List, Optional

class Solution:
    def bubbleSort(self, arr):
        n = len(arr)
        # Outer loop for number of passes
        for i in range(n - 1):
            swapped = False
            # Inner loop for comparisons in each pass
            # After each pass, the largest element bubbles to the end
            for j in range(n - i - 1):
                if arr[j] > arr[j + 1]:
                    arr[j], arr[j + 1] = arr[j + 1], arr[j]
                    swapped = True
        # If no swapping happened, array is already sorted
            if not swapped:
                break
        return arr


if __name__ == "__main__":
    sol = Solution()
    arr = [64, 34, 25, 12, 22, 11, 90]
    print("Original array: ")
    for num in arr:
        print(num, end=" ")
    print()
    sol.bubbleSort(arr)
    print("Sorted array: ")
    for num in arr:
        print(num, end=" ")
    print()
