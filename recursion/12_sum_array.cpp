/*
PROBLEM: Sum of Array Elements
---------------------------------------------------------------------------
Given an array of integers, find the sum of all elements using recursion.

DIFFICULTY: Easy
PATTERN: Linear Recursion
TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(n) - recursion stack

INPUT/OUTPUT EXAMPLES:
---------------------------------------------------------------------------
Example 1:
Input: arr = [1,2,3,4,5]
Output: 15
Explanation: 1 + 2 + 3 + 4 + 5 = 15

Example 2:
Input: arr = [10,20,30]
Output: 60
Explanation: 10 + 20 + 30 = 60
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int arraySum(vector<int>& arr) {
        return sumHelper(arr, 0);
    }
    
    // Using size reduction approach
    int arraySumAlt(vector<int>& arr, int n) {
        // Base case
        if (n <= 0) {
            return 0;
        }
        
        // Recursive case
        return arr[n - 1] + arraySumAlt(arr, n - 1);
    }
    
private:
    int sumHelper(vector<int>& arr, int index) {
        // Base case
        if (index >= arr.size()) {
            return 0;
        }
        
        // Recursive case
        return arr[index] + sumHelper(arr, index + 1);
    }
};

int main() {
    Solution sol;
    
    // Test case 1
    vector<int> arr1 = {1, 2, 3, 4, 5};
    cout << "Test 1: Sum = " << sol.arraySum(arr1) << endl;
    
    // Test case 2
    vector<int> arr2 = {10, 20, 30};
    cout << "Test 2: Sum = " << sol.arraySumAlt(arr2, arr2.size()) << endl;
    
    return 0;
}
