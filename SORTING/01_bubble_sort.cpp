/*
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
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void bubbleSort(vector<int>& arr) {
        int n = arr.size();
        
        // Outer loop for number of passes
        for (int i = 0; i < n - 1; i++) {
            bool swapped = false;
            
            // Inner loop for comparisons in each pass
            // After each pass, the largest element bubbles to the end
            for (int j = 0; j < n - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    swap(arr[j], arr[j + 1]);
                    swapped = true;
                }
            }
            
            // If no swapping happened, array is already sorted
            if (!swapped) break;
        }
    }
};

int main() {
    Solution sol;
    vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
    
    cout << "Original array: ";
    for (int num : arr) cout << num << " ";
    cout << endl;
    
    sol.bubbleSort(arr);
    
    cout << "Sorted array: ";
    for (int num : arr) cout << num << " ";
    cout << endl;
    
    return 0;
}

/*
EXPLANATION:
============
1. Bubble sort works by repeatedly comparing adjacent elements
2. If elements are in wrong order, we swap them
3. After each pass, the largest element "bubbles" to its correct position at the end
4. Optimization: Use a flag to detect if array is already sorted (no swaps in a pass)
5. The outer loop runs n-1 times (number of passes)
6. The inner loop reduces by 1 each time as last elements are already sorted

WHY THIS PATTERN IS IMPORTANT:
- Foundation for understanding sorting
- Good for nearly sorted data
- Stable sorting algorithm
- Simple to implement and understand
*/
