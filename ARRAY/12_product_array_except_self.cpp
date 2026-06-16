/*
PROBLEM: Product of Array Except Self
Difficulty: Medium
Pattern: Prefix and Suffix Product

DESCRIPTION:
Given an integer array nums, return an array answer such that answer[i] is equal to the 
product of all the elements of nums except nums[i]. You must write an algorithm that runs 
in O(n) time and without using the division operation.

EXPLANATION:
Two-pass approach:
1. Calculate prefix products (product of all elements before i)
2. Calculate suffix products (product of all elements after i)
3. Result[i] = prefix[i] * suffix[i]
We can optimize space by calculating suffix on the fly.

Time Complexity: O(n)
Space Complexity: O(1) excluding output array

INPUT-OUTPUT EXAMPLES:

Example 1:
Input: nums = [1,2,3,4]
Output: [24,12,8,6]
Explanation: 24 = 2*3*4, 12 = 1*3*4, 8 = 1*2*4, 6 = 1*2*3

Example 2:
Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]
Explanation: Products involving 0

Example 3:
Input: nums = [2,3,4,5]
Output: [60,40,30,24]
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 1);
        
        // Calculate prefix products
        int prefix = 1;
        for (int i = 0; i < n; i++) {
            result[i] = prefix;
            prefix *= nums[i];
        }
        
        // Calculate suffix products and multiply with prefix
        int suffix = 1;
        for (int i = n - 1; i >= 0; i--) {
            result[i] *= suffix;
            suffix *= nums[i];
        }
        
        return result;
    }
};

void printArray(vector<int>& nums) {
    cout << "[";
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i];
        if (i < nums.size() - 1) cout << ",";
    }
    cout << "]" << endl;
}

int main() {
    Solution solution;
    
    // Test Case 1
    vector<int> nums1 = {1, 2, 3, 4};
    vector<int> result1 = solution.productExceptSelf(nums1);
    cout << "Test 1: ";
    printArray(result1);
    
    // Test Case 2
    vector<int> nums2 = {-1, 1, 0, -3, 3};
    vector<int> result2 = solution.productExceptSelf(nums2);
    cout << "Test 2: ";
    printArray(result2);
    
    // Test Case 3
    vector<int> nums3 = {2, 3, 4, 5};
    vector<int> result3 = solution.productExceptSelf(nums3);
    cout << "Test 3: ";
    printArray(result3);
    
    return 0;
}
