/*
PROBLEM: Check if Array is Sorted
---------------------------------------------------------------------------
Given an array of integers, check if it is sorted in non-decreasing order 
using recursion.

DIFFICULTY: Easy
PATTERN: Linear Recursion
TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(n) - recursion stack

INPUT/OUTPUT EXAMPLES:
---------------------------------------------------------------------------
Example 1:
Input: arr = [1,2,3,4,5]
Output: true
Explanation: Array is sorted in ascending order

Example 2:
Input: arr = [1,3,2,4]
Output: false
Explanation: 3 > 2, so not sorted
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isSorted(vector<int>& arr) {
        if (arr.size() <= 1) {
            return true;
        }
        return checkSorted(arr, 0);
    }
    
private:
    bool checkSorted(vector<int>& arr, int index) {
        // Base case: reached end
        if (index >= arr.size() - 1) {
            return true;
        }
        
        // Check current pair
        if (arr[index] > arr[index + 1]) {
            return false;
        }
        
        // Recursive case
        return checkSorted(arr, index + 1);
    }
};

int main() {
    Solution sol;
    
    // Test case 1
    vector<int> arr1 = {1, 2, 3, 4, 5};
    cout << "Test 1: Is sorted? " << (sol.isSorted(arr1) ? "true" : "false") << endl;
    
    // Test case 2
    vector<int> arr2 = {1, 3, 2, 4};
    cout << "Test 2: Is sorted? " << (sol.isSorted(arr2) ? "true" : "false") << endl;
    
    return 0;
}
