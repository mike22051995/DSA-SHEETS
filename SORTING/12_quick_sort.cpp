/*
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
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Lomuto Partition Scheme
    int partition(vector<int>& arr, int low, int high) {
        int pivot = arr[high]; // Choose last element as pivot
        int i = low - 1; // Index of smaller element
        
        for (int j = low; j < high; j++) {
            // If current element is smaller than pivot
            if (arr[j] < pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        return i + 1;
    }
    
    // Hoare Partition Scheme (more efficient)
    int partitionHoare(vector<int>& arr, int low, int high) {
        int pivot = arr[low];
        int i = low - 1;
        int j = high + 1;
        
        while (true) {
            // Find element >= pivot from left
            do {
                i++;
            } while (arr[i] < pivot);
            
            // Find element <= pivot from right
            do {
                j--;
            } while (arr[j] > pivot);
            
            if (i >= j) return j;
            
            swap(arr[i], arr[j]);
        }
    }
    
    void quickSort(vector<int>& arr, int low, int high) {
        if (low < high) {
            // Partitioning index
            int pi = partition(arr, low, high);
            
            // Separately sort elements before and after partition
            quickSort(arr, low, pi - 1);
            quickSort(arr, pi + 1, high);
        }
    }
    
    void sort(vector<int>& arr) {
        if (arr.empty()) return;
        quickSort(arr, 0, arr.size() - 1);
    }
};

int main() {
    Solution sol;
    vector<int> arr = {10, 7, 8, 9, 1, 5};
    
    cout << "Original array: ";
    for (int num : arr) cout << num << " ";
    cout << endl;
    
    sol.sort(arr);
    
    cout << "Sorted array: ";
    for (int num : arr) cout << num << " ";
    cout << endl;
    
    return 0;
}

/*
EXPLANATION:
============
QUICK SORT ALGORITHM:
1. Choose a pivot element
2. Partition: rearrange array so elements < pivot are before it, > pivot are after
3. Recursively apply above steps to sub-arrays

LOMUTO PARTITION:
- Choose last element as pivot
- Maintain index i for smaller elements
- Swap elements smaller than pivot to left side
- Finally place pivot at correct position

HOARE PARTITION:
- More efficient (fewer swaps)
- Two pointers move from both ends
- Swap when left finds large element and right finds small element

PIVOT SELECTION STRATEGIES:
1. Last element (implemented above)
2. First element
3. Random element
4. Median-of-three (first, middle, last)

KEY CHARACTERISTICS:
- In-place sorting (O(log n) space for recursion)
- Not stable (can change relative order of equal elements)
- Cache-friendly
- Average case O(n log n), worst case O(n²)

WORST CASE: Already sorted array with poor pivot selection

WHY THIS PATTERN IS IMPORTANT:
- Most commonly used sorting algorithm in practice
- Foundation for QuickSelect algorithm
- Demonstrates partitioning technique
- Understanding pivot selection and optimization
- Used in many interview problems
- Forms basis of many divide-and-conquer solutions
*/
