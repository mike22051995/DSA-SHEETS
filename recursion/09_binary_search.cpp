/*
PROBLEM: Binary Search (Recursive)
---------------------------------------------------------------------------
Given a sorted array of integers and a target value, return the index of 
the target if found. If not found, return -1.

DIFFICULTY: Easy-Medium
PATTERN: Divide and Conquer
TIME COMPLEXITY: O(log n)
SPACE COMPLEXITY: O(log n) - recursion stack

INPUT/OUTPUT EXAMPLES:
---------------------------------------------------------------------------
Example 1:
Input: arr = [1,3,5,7,9,11], target = 7
Output: 3
Explanation: 7 is found at index 3

Example 2:
Input: arr = [1,3,5,7,9,11], target = 6
Output: -1
Explanation: 6 is not in the array
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int binarySearch(vector<int>& arr, int target) {
        return search(arr, target, 0, arr.size() - 1);
    }
    
private:
    int search(vector<int>& arr, int target, int left, int right) {
        // Base case: not found
        if (left > right) {
            return -1;
        }
        
        int mid = left + (right - left) / 2;
        
        // Found
        if (arr[mid] == target) {
            return mid;
        }
        
        // Search left half
        if (arr[mid] > target) {
            return search(arr, target, left, mid - 1);
        }
        
        // Search right half
        return search(arr, target, mid + 1, right);
    }
};

int main() {
    Solution sol;
    
    // Test case 1
    vector<int> arr1 = {1, 3, 5, 7, 9, 11};
    int target1 = 7;
    cout << "Test 1: Index of " << target1 << " = " << sol.binarySearch(arr1, target1) << endl;
    
    // Test case 2
    vector<int> arr2 = {1, 3, 5, 7, 9, 11};
    int target2 = 6;
    cout << "Test 2: Index of " << target2 << " = " << sol.binarySearch(arr2, target2) << endl;
    
    return 0;
}
