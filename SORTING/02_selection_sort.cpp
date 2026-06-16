/*
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
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void selectionSort(vector<int>& arr) {
        int n = arr.size();
        
        // Move boundary of unsorted subarray one by one
        for (int i = 0; i < n - 1; i++) {
            // Find the minimum element in unsorted array
            int minIdx = i;
            for (int j = i + 1; j < n; j++) {
                if (arr[j] < arr[minIdx]) {
                    minIdx = j;
                }
            }
            
            // Swap the found minimum element with the first element
            if (minIdx != i) {
                swap(arr[i], arr[minIdx]);
            }
        }
    }
};

int main() {
    Solution sol;
    vector<int> arr = {64, 25, 12, 22, 11};
    
    cout << "Original array: ";
    for (int num : arr) cout << num << " ";
    cout << endl;
    
    sol.selectionSort(arr);
    
    cout << "Sorted array: ";
    for (int num : arr) cout << num << " ";
    cout << endl;
    
    return 0;
}

/*
EXPLANATION:
============
1. The algorithm divides the array into sorted (left) and unsorted (right) portions
2. In each iteration, find the minimum element from unsorted portion
3. Swap it with the first element of unsorted portion
4. Move the boundary between sorted and unsorted portions one position right
5. Continue until entire array is sorted

KEY POINTS:
- Makes minimum number of swaps: O(n)
- Not stable (relative order of equal elements may change)
- Good when memory write is costly operation
- Performance doesn't depend on initial order of elements

WHY THIS PATTERN IS IMPORTANT:
- Useful when swap operation is expensive
- Minimum number of writes to memory
- Simple and intuitive algorithm
*/
