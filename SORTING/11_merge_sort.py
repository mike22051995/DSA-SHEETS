"""
PROBLEM: Merge Sort Implementation
===============================================
DESCRIPTION:
Implement the merge sort algorithm. Merge sort is a divide-and-conquer algorithm 
that divides the array into two halves, recursively sorts them, and then merges 
the two sorted halves.

PATTERN: Divide and Conquer / Merge Sort
DIFFICULTY: Medium
TIME COMPLEXITY: O(n log n) - all cases
SPACE COMPLEXITY: O(n) for temporary arrays

INPUT:
Array of integers

OUTPUT:
Sorted array

EXAMPLE:
Input: [38, 27, 43, 3, 9, 82, 10]
Output: [3, 9, 10, 27, 38, 43, 82]
"""

from typing import List, Optional

class Solution:
    def merge(self, arr: List[int], left: int, mid: int, right: int):
        # Create temporary arrays
        n1 = mid - left + 1
        n2 = right - mid
        leftArr = arr[left:mid + 1]
        rightArr = arr[mid + 1:right + 1]
        
        # Merge the temporary arrays back
        i = j = 0
        k = left
        
        while i < n1 and j < n2:
            if leftArr[i] <= rightArr[j]:
                arr[k] = leftArr[i]
                i += 1
            else:
                arr[k] = rightArr[j]
                j += 1
            k += 1
        
        # Copy remaining elements
        while i < n1:
            arr[k] = leftArr[i]
            i += 1
            k += 1
        
        while j < n2:
            arr[k] = rightArr[j]
            j += 1
            k += 1
    
    def mergeSort(self, arr: List[int], left: int, right: int):
        if left < right:
            mid = left + (right - left) // 2
            # Sort first and second halves
            self.mergeSort(arr, left, mid)
            self.mergeSort(arr, mid + 1, right)
            # Merge the sorted halves
            self.merge(arr, left, mid, right)
    
    def sort(self, arr: List[int]) -> List[int]:
        self.mergeSort(arr, 0, len(arr) - 1)
        return arr


if __name__ == "__main__":
    sol = Solution()
    arr = [38, 27, 43, 3, 9, 82, 10]
    print("Original array: ")
    for num in arr:
        print(num, end=" ")
    print()
    sol.sort(arr)
    print("Sorted array: ")
    for num in arr:
        print(num, end=" ")
    print()
