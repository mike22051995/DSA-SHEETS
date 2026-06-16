/*
PROBLEM: Single Number III (Two Non-Repeating Elements)
=========================================================
Given an array where every element appears twice except two elements,
find those two elements.

APPROACH:
- XOR all elements to get XOR of two unique numbers
- Find rightmost set bit in XOR result (differentiating bit)
- Partition numbers into two groups based on this bit
- XOR each group separately to get the two unique numbers

PATTERN: XOR with Partitioning - Multiple Unique Elements

INPUT/OUTPUT:
Input: nums = [1,2,1,3,2,5]
Output: [3,5]
Explanation: 1 and 2 appear twice, 3 and 5 appear once

Input: nums = [-1,0]
Output: [-1,0]

TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(1)
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        // Step 1: XOR all elements to get XOR of two unique numbers
        int xorResult = 0;
        for (int num : nums) {
            xorResult ^= num;
        }
        
        // Step 2: Find rightmost set bit (any set bit works)
        int rightmostBit = xorResult & (-xorResult);
        
        // Step 3: Partition numbers based on rightmost bit
        int num1 = 0, num2 = 0;
        for (int num : nums) {
            if (num & rightmostBit) {
                num1 ^= num; // Group 1: bit is set
            } else {
                num2 ^= num; // Group 2: bit is not set
            }
        }
        
        return {num1, num2};
    }
};

int main() {
    Solution sol;
    
    // Test Case 1
    vector<int> nums1 = {1, 2, 1, 3, 2, 5};
    cout << "Input: [1,2,1,3,2,5]" << endl;
    vector<int> result1 = sol.singleNumber(nums1);
    cout << "Output: [" << result1[0] << "," << result1[1] << "]" << endl;
    cout << "Explanation: 1,2 appear twice; 3,5 once" << endl << endl;
    
    // Test Case 2
    vector<int> nums2 = {-1, 0};
    cout << "Input: [-1,0]" << endl;
    vector<int> result2 = sol.singleNumber(nums2);
    cout << "Output: [" << result2[0] << "," << result2[1] << "]" << endl;
    cout << "Explanation: Only two elements" << endl << endl;
    
    // Test Case 3
    vector<int> nums3 = {1, 1, 2, 2, 3, 4};
    cout << "Input: [1,1,2,2,3,4]" << endl;
    vector<int> result3 = sol.singleNumber(nums3);
    cout << "Output: [" << result3[0] << "," << result3[1] << "]" << endl;
    cout << "Explanation: 1,2 appear twice; 3,4 once" << endl;
    
    return 0;
}
