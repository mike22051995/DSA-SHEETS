/*
PROBLEM: Segregate Even and Odd Numbers
---------------------------------------------------------------------------
Given an array arr[], segregate even and odd numbers. All even numbers 
should be present first, followed by odd numbers. The relative order 
doesn't need to be maintained.

PATTERN: Two Pointers (Partition - QuickSort style)
TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(1)

INPUT/OUTPUT EXAMPLES:
---------------------------------------------------------------------------
Example 1:
Input: arr = [12, 34, 45, 9, 8, 90, 3]
Output: [12, 34, 90, 8, 9, 45, 3] (any valid segregation)
Explanation: All even numbers come before odd numbers.

Example 2:
Input: arr = [1, 3, 2, 4, 7, 6, 9, 10]
Output: [10, 6, 2, 4, 7, 3, 9, 1] (any valid segregation)
Explanation: [2,4,6,10,1,3,7,9] is also valid.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void segregateEvenOdd(vector<int>& arr) {
        int left = 0;
        int right = arr.size() - 1;
        
        while (left < right) {
            // Move left pointer until we find an odd number
            while (left < right && arr[left] % 2 == 0) {
                left++;
            }
            
            // Move right pointer until we find an even number
            while (left < right && arr[right] % 2 == 1) {
                right--;
            }
            
            // Swap odd at left with even at right
            if (left < right) {
                swap(arr[left], arr[right]);
                left++;
                right--;
            }
        }
    }
};

int main() {
    Solution sol;
    
    // Test case 1
    vector<int> arr1 = {12, 34, 45, 9, 8, 90, 3};
    sol.segregateEvenOdd(arr1);
    cout << "Test 1: [";
    for (int i = 0; i < arr1.size(); i++) {
        cout << arr1[i] << (i < arr1.size() - 1 ? "," : "");
    }
    cout << "]" << endl;
    
    // Test case 2
    vector<int> arr2 = {1, 3, 2, 4, 7, 6, 9, 10};
    sol.segregateEvenOdd(arr2);
    cout << "Test 2: [";
    for (int i = 0; i < arr2.size(); i++) {
        cout << arr2[i] << (i < arr2.size() - 1 ? "," : "");
    }
    cout << "]" << endl;
    
    return 0;
}
