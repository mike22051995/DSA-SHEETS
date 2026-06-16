/*
PROBLEM: Squares of a Sorted Array
---------------------------------------------------------------------------
Given an integer array nums sorted in non-decreasing order, return an array 
of the squares of each number sorted in non-decreasing order.

PATTERN: Opposite Direction Two Pointers
TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(n)

INPUT/OUTPUT EXAMPLES:
---------------------------------------------------------------------------
Example 1:
Input: nums = [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Explanation: Squares are [16,1,0,9,100]. After sorting: [0,1,9,16,100].

Example 2:
Input: nums = [-7,-3,2,3,11]
Output: [4,9,9,49,121]
*/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        
        int left = 0;
        int right = n - 1;
        int pos = n - 1; // Fill from the end
        
        while (left <= right) {
            int leftSquare = nums[left] * nums[left];
            int rightSquare = nums[right] * nums[right];
            
            if (leftSquare > rightSquare) {
                result[pos] = leftSquare;
                left++;
            } else {
                result[pos] = rightSquare;
                right--;
            }
            pos--;
        }
        
        return result;
    }
};

int main() {
    Solution sol;
    
    // Test case 1
    vector<int> nums1 = {-4, -1, 0, 3, 10};
    vector<int> result1 = sol.sortedSquares(nums1);
    cout << "Test 1: [";
    for (int i = 0; i < result1.size(); i++) {
        cout << result1[i] << (i < result1.size() - 1 ? "," : "");
    }
    cout << "]" << endl;
    
    // Test case 2
    vector<int> nums2 = {-7, -3, 2, 3, 11};
    vector<int> result2 = sol.sortedSquares(nums2);
    cout << "Test 2: [";
    for (int i = 0; i < result2.size(); i++) {
        cout << result2[i] << (i < result2.size() - 1 ? "," : "");
    }
    cout << "]" << endl;
    
    return 0;
}
