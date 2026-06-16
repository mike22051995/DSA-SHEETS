/*
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
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& arr, int left, int mid, int right) {
        // Create temporary arrays
        int n1 = mid - left + 1;
        int n2 = right - mid;
        
        vector<int> leftArr(n1);
        vector<int> rightArr(n2);
        
        // Copy data to temporary arrays
        for (int i = 0; i < n1; i++)
            leftArr[i] = arr[left + i];
        for (int i = 0; i < n2; i++)
            rightArr[i] = arr[mid + 1 + i];
        
        // Merge the temporary arrays back
        int i = 0, j = 0, k = left;
        
        while (i < n1 && j < n2) {
            if (leftArr[i] <= rightArr[j]) {
                arr[k++] = leftArr[i++];
            } else {
                arr[k++] = rightArr[j++];
            }
        }
        
        // Copy remaining elements
        while (i < n1) arr[k++] = leftArr[i++];
        while (j < n2) arr[k++] = rightArr[j++];
    }
    
    void mergeSort(vector<int>& arr, int left, int right) {
        if (left < right) {
            int mid = left + (right - left) / 2;
            
            // Sort first and second halves
            mergeSort(arr, left, mid);
            mergeSort(arr, mid + 1, right);
            
            // Merge the sorted halves
            merge(arr, left, mid, right);
        }
    }
    
    void sort(vector<int>& arr) {
        mergeSort(arr, 0, arr.size() - 1);
    }
};

int main() {
    Solution sol;
    vector<int> arr = {38, 27, 43, 3, 9, 82, 10};
    
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
MERGE SORT ALGORITHM:
1. Divide: Split array into two halves
2. Conquer: Recursively sort each half
3. Combine: Merge the two sorted halves

MERGE PROCESS:
1. Create temporary arrays for left and right halves
2. Compare elements from both halves
3. Place smaller element in original array
4. Copy remaining elements

KEY CHARACTERISTICS:
- Stable sort: maintains relative order of equal elements
- Guaranteed O(n log n) time complexity
- Not in-place: requires O(n) extra space
- Predictable performance (no worst case degradation)

RECURSION TREE:
[38,27,43,3,9,82,10]
       /         \
[38,27,43,3]   [9,82,10]
   /    \        /    \
[38,27] [43,3] [9,82] [10]
 /  \    /  \   /  \    |
[38][27][43][3][9][82][10]

WHY THIS PATTERN IS IMPORTANT:
- One of the most efficient general-purpose sorting algorithms
- Foundation for external sorting (sorting data that doesn't fit in memory)
- Used in many standard library implementations
- Demonstrates divide-and-conquer paradigm
- Critical for understanding advanced sorting techniques
- Used in counting inversions, merge k sorted lists, etc.
*/
