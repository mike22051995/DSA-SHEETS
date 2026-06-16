"""
PROBLEM: Quick Sort Implementation
===============================================
DESCRIPTION:
Implement the quick sort algorithm. Quick sort picks an element as pivot and 
partitions the array around the pivot, placing smaller elements before it and 
larger elements after it.

PATTERN: Divide and Conquer / Partition
DIFFICULTY: Medium
TIME COMPLEXITY: O(n log n) average, O(n²) worst case
SPACE COMPLEXITY: O(log n) for recursion stack

INPUT:
Array of integers

OUTPUT:
Sorted array

EXAMPLE:
Input: [10, 7, 8, 9, 1, 5]
Output: [1, 5, 7, 8, 9, 10]
"""

from typing import List, Optional

class Solution:
    def partition(self, arr: List[int], low: int, high: int) -> int:
        # Lomuto Partition Scheme
        pivot = arr[high]
        i = low - 1
        
        for j in range(low, high):
            # If current element is smaller than pivot
            if arr[j] < pivot:
                i += 1
                arr[i], arr[j] = arr[j], arr[i]
        
        arr[i + 1], arr[high] = arr[high], arr[i + 1]
        return i + 1
    
    def quickSort(self, arr: List[int], low: int, high: int):
        if low < high:
            # Partitioning index
            pi = self.partition(arr, low, high)
            # Separately sort elements before and after partition
            self.quickSort(arr, low, pi - 1)
            self.quickSort(arr, pi + 1, high)
    
    def sort(self, arr: List[int]) -> List[int]:
        if not arr:
            return arr
        self.quickSort(arr, 0, len(arr) - 1)
        return arr


if __name__ == "__main__":
    sol = Solution()
    arr = [10, 7, 8, 9, 1, 5]
    print("Original array: ")
    for num in arr:
        print(num, end=" ")
    print()
    sol.sort(arr)
    print("Sorted array: ")
    for num in arr:
        print(num, end=" ")
    print()
