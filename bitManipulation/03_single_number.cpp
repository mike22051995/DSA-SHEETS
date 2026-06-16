/*
PROBLEM: Single Number (Find the Unique Element)
==================================================
Given a non-empty array where every element appears twice except one, 
find that single element.

APPROACH:
- XOR of two same numbers is 0
- XOR of a number with 0 is the number itself
- XOR all elements: duplicates cancel out, single element remains

PATTERN: XOR Properties - Finding Unique Element

INPUT/OUTPUT:
Input: nums = [2,2,1]
Output: 1

Input: nums = [4,1,2,1,2]
Output: 4

Input: nums = [1]
Output: 1

TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(1)
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        // XOR all elements
        // a ^ a = 0, a ^ 0 = a
        for (int num : nums) {
            result ^= num;
        }
        return result;
    }
};

int main() {
    Solution sol;
    
    // Test Case 1
    vector<int> nums1 = {2, 2, 1};
    cout << "Input: [2,2,1]" << endl;
    cout << "Output: " << sol.singleNumber(nums1) << endl;
    cout << "Explanation: 2 appears twice, 1 is unique" << endl << endl;
    
    // Test Case 2
    vector<int> nums2 = {4, 1, 2, 1, 2};
    cout << "Input: [4,1,2,1,2]" << endl;
    cout << "Output: " << sol.singleNumber(nums2) << endl;
    cout << "Explanation: 1 and 2 appear twice, 4 is unique" << endl << endl;
    
    // Test Case 3
    vector<int> nums3 = {1};
    cout << "Input: [1]" << endl;
    cout << "Output: " << sol.singleNumber(nums3) << endl;
    cout << "Explanation: Only one element" << endl;
    
    return 0;
}
