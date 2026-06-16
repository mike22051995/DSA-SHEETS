/*
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
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Heapify a subtree rooted at index i
    // n is size of heap
    void heapify(vector<int>& arr, int n, int i) {
        int largest = i;       // Initialize largest as root
        int left = 2 * i + 1;  // left child
        int right = 2 * i + 2; // right child
        
        // If left child is larger than root
        if (left < n && arr[left] > arr[largest])
            largest = left;
        
        // If right child is larger than largest so far
        if (right < n && arr[right] > arr[largest])
            largest = right;
        
        // If largest is not root
        if (largest != i) {
            swap(arr[i], arr[largest]);
            
            // Recursively heapify the affected sub-tree
            heapify(arr, n, largest);
        }
    }
    
    void heapSort(vector<int>& arr) {
        int n = arr.size();
        
        // Build max heap (rearrange array)
        // Start from last non-leaf node and heapify all nodes
        for (int i = n / 2 - 1; i >= 0; i--)
            heapify(arr, n, i);
        
        // Extract elements from heap one by one
        for (int i = n - 1; i > 0; i--) {
            // Move current root to end
            swap(arr[0], arr[i]);
            
            // Call heapify on the reduced heap
            heapify(arr, i, 0);
        }
    }
};

int main() {
    Solution sol;
    vector<int> arr = {12, 11, 13, 5, 6, 7};
    
    cout << "Original array: ";
    for (int num : arr) cout << num << " ";
    cout << endl;
    
    sol.heapSort(arr);
    
    cout << "Sorted array: ";
    for (int num : arr) cout << num << " ";
    cout << endl;
    
    return 0;
}

/*
EXPLANATION:
============
HEAP SORT PROCESS:
1. Build Max Heap: Convert array into max heap
2. Extract Max: Repeatedly remove max element (root) and place at end
3. Heapify: Restore heap property after each extraction

HEAPIFY PROCESS:
- Compare node with its children
- If a child is larger, swap with it
- Recursively heapify the affected subtree

HEAP REPRESENTATION IN ARRAY:
For node at index i:
- Parent: (i-1)/2
- Left child: 2*i + 1
- Right child: 2*i + 2

BUILDING MAX HEAP:
- Start from last non-leaf node: (n/2 - 1)
- Heapify each node moving upward
- This ensures parent > children property

EXAMPLE HEAP:
        12
       /  \
      11   13
     / \   /
    5   6 7

After heapify becomes:
        13
       /  \
      11   12
     / \   /
    5   6 7

KEY CHARACTERISTICS:
- In-place sorting: O(1) extra space
- Not stable
- Guaranteed O(n log n) time
- Not cache-friendly (random memory access)

WHY THIS PATTERN IS IMPORTANT:
- Foundation for understanding heap data structure
- Used in priority queues
- Important for problems like:
  * Kth largest/smallest element
  * Merge K sorted lists
  * Top K frequent elements
- Guaranteed O(n log n) with O(1) space
- Understanding of complete binary tree
*/
