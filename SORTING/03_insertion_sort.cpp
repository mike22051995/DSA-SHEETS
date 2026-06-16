/*
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
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void insertionSort(vector<int>& arr) {
        int n = arr.size();
        
        // Start from second element (first element is considered sorted)
        for (int i = 1; i < n; i++) {
            int key = arr[i];
            int j = i - 1;
            
            // Move elements greater than key one position ahead
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            }
            
            // Place key at its correct position
            arr[j + 1] = key;
        }
    }
};

int main() {
    Solution sol;
    vector<int> arr = {12, 11, 13, 5, 6};
    
    cout << "Original array: ";
    for (int num : arr) cout << num << " ";
    cout << endl;
    
    sol.insertionSort(arr);
    
    cout << "Sorted array: ";
    for (int num : arr) cout << num << " ";
    cout << endl;
    
    return 0;
}

/*
EXPLANATION:
============
1. Start with the second element (consider first element as sorted)
2. Pick current element as 'key'
3. Compare key with elements in sorted portion (left side)
4. Shift all elements greater than key one position to the right
5. Insert key at its correct position
6. Repeat for all elements

KEY POINTS:
- Efficient for small data sets
- Efficient for nearly sorted data: O(n) in best case
- Stable sorting algorithm (maintains relative order)
- Online algorithm: can sort data as it receives
- Works well with linked lists

WHY THIS PATTERN IS IMPORTANT:
- Used in hybrid sorting algorithms (Timsort uses insertion sort)
- Best for small arrays or nearly sorted data
- Adaptive algorithm - performance improves with partially sorted input
- Used in practice for small subarrays in quicksort/mergesort
*/
