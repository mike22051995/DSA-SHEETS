/*
PROBLEM: Missing Number
=========================
Given an array containing n distinct numbers from 0 to n, 
find the one that is missing from the array.

APPROACH:
- XOR all numbers from 0 to n
- XOR all numbers in the array
- Missing number = XOR of both results
- Duplicate numbers cancel out, missing one remains

PATTERN: XOR Properties - Finding Missing Element

INPUT/OUTPUT:
Input: nums = [3,0,1]
Output: 2
Explanation: n = 3, range is [0,3], missing number is 2

Input: nums = [0,1]
Output: 2
Explanation: n = 2, range is [0,2], missing number is 2

TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(1)
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int xorAll = 0, xorArray = 0;
        
        // XOR all numbers from 0 to n
        for (int i = 0; i <= n; i++) {
            xorAll ^= i;
        }
        
        // XOR all numbers in array
        for (int num : nums) {
            xorArray ^= num;
        }
        
        // Missing number
        return xorAll ^ xorArray;
    }
    
    // Optimized single pass
    int missingNumberOptimized(vector<int>& nums) {
        int result = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            result ^= i ^ nums[i];
        }
        return result;
    }
};

int main() {
    Solution sol;
    
    // Test Case 1
    vector<int> nums1 = {3, 0, 1};
    cout << "Input: [3,0,1]" << endl;
    cout << "Output: " << sol.missingNumber(nums1) << endl;
    cout << "Explanation: Range [0,3], missing 2" << endl << endl;
    
    // Test Case 2
    vector<int> nums2 = {0, 1};
    cout << "Input: [0,1]" << endl;
    cout << "Output: " << sol.missingNumber(nums2) << endl;
    cout << "Explanation: Range [0,2], missing 2" << endl << endl;
    
    // Test Case 3
    vector<int> nums3 = {9,6,4,2,3,5,7,0,1};
    cout << "Input: [9,6,4,2,3,5,7,0,1]" << endl;
    cout << "Output: " << sol.missingNumber(nums3) << endl;
    cout << "Explanation: Range [0,9], missing 8" << endl;
    
    return 0;
}
