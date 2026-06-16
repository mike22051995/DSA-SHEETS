/*
PROBLEM: Print Array Elements
---------------------------------------------------------------------------
Given an array of integers, print all elements using recursion.

DIFFICULTY: Easy
PATTERN: Linear Recursion
TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(n) - recursion stack

INPUT/OUTPUT EXAMPLES:
---------------------------------------------------------------------------
Example 1:
Input: arr = [1,2,3,4,5]
Output: 1 2 3 4 5

Example 2:
Input: arr = [10,20,30]
Output: 10 20 30
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Print from index to end
    void printArray(vector<int>& arr, int index = 0) {
        // Base case
        if (index >= arr.size()) {
            return;
        }
        
        // Print current element
        cout << arr[index] << " ";
        
        // Recursive case
        printArray(arr, index + 1);
    }
    
    // Print in reverse order
    void printReverse(vector<int>& arr, int index = 0) {
        if (index >= arr.size()) {
            return;
        }
        
        // Recursive call first
        printReverse(arr, index + 1);
        
        // Then print (after returning from recursion)
        cout << arr[index] << " ";
    }
};

int main() {
    Solution sol;
    
    // Test case 1
    vector<int> arr1 = {1, 2, 3, 4, 5};
    cout << "Test 1 (Forward): ";
    sol.printArray(arr1);
    cout << endl;
    
    // Test case 2
    vector<int> arr2 = {10, 20, 30};
    cout << "Test 2 (Reverse): ";
    sol.printReverse(arr2);
    cout << endl;
    
    return 0;
}
