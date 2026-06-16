"""
PROBLEM: Heap Sort Implementation
===============================================
DESCRIPTION:
Implement heap sort algorithm. Heap sort uses a binary heap data structure to 
sort elements. It first builds a max heap, then repeatedly extracts the maximum 
element and places it at the end.

PATTERN: Heap-based Sorting
DIFFICULTY: Medium
TIME COMPLEXITY: O(n log n) - all cases
SPACE COMPLEXITY: O(1)

INPUT:
Array of integers

OUTPUT:
Sorted array in ascending order

EXAMPLE:
Input: [12, 11, 13, 5, 6, 7]
Output: [5, 6, 7, 11, 12, 13]
"""

from typing import List, Optional

class Solution:
    def heapify(self, arr: List[int], n: int, i: int):
        largest = i
        left = 2 * i + 1
        right = 2 * i + 2
        
        # If left child is larger than root
        if left < n and arr[left] > arr[largest]:
            largest = left
        
        # If right child is larger than largest so far
        if right < n and arr[right] > arr[largest]:
            largest = right
        
        # If largest is not root
        if largest != i:
            arr[i], arr[largest] = arr[largest], arr[i]
            # Recursively heapify the affected sub-tree
            self.heapify(arr, n, largest)
    
    def heapSort(self, arr: List[int]) -> List[int]:
        n = len(arr)
        
        # Build max heap
        for i in range(n // 2 - 1, -1, -1):
            self.heapify(arr, n, i)
        
        # One by one extract an element from heap
        for i in range(n - 1, 0, -1):
            # Move current root (maximum) to end
            arr[0], arr[i] = arr[i], arr[0]
            # Call heapify on reduced heap
            self.heapify(arr, i, 0)
        
        return arr


if __name__ == "__main__":
    sol = Solution()
    arr = [12, 11, 13, 5, 6, 7]
    print("Original array: ")
    for num in arr:
        print(num, end=" ")
    print()
    sol.heapSort(arr)
    print("Sorted array: ")
    for num in arr:
        print(num, end=" ")
    print()
