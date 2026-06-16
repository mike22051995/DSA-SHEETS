/*
PROBLEM: Move Zeroes
---------------------------------------------------------------------------
Given an integer array nums, move all 0's to the end of it while maintaining 
the relative order of the non-zero elements. Must do this in-place without 
making a copy of the array.

PATTERN: Fast-Slow Two Pointers
TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(1)

INPUT/OUTPUT EXAMPLES:
---------------------------------------------------------------------------
Example 1:
Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]

Example 2:
Input: nums = [0,0,1]
Output: [1,0,0]
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int slow = 0; // Position to place next non-zero element
        
        // Move all non-zero elements to the front
        for (int fast = 0; fast < nums.size(); fast++) {
            if (nums[fast] != 0) {
                nums[slow] = nums[fast];
                slow++;
            }
        }
        
        // Fill remaining positions with zeros
        for (int i = slow; i < nums.size(); i++) {
            nums[i] = 0;
        }
    }
};

int main() {
    Solution sol;
    
    // Test case 1
    vector<int> nums1 = {0, 1, 0, 3, 12};
    sol.moveZeroes(nums1);
    cout << "Test 1: [";
    for (int i = 0; i < nums1.size(); i++) {
        cout << nums1[i] << (i < nums1.size() - 1 ? "," : "");
    }
    cout << "]" << endl;
    
    // Test case 2
    vector<int> nums2 = {0, 0, 1};
    sol.moveZeroes(nums2);
    cout << "Test 2: [";
    for (int i = 0; i < nums2.size(); i++) {
        cout << nums2[i] << (i < nums2.size() - 1 ? "," : "");
    }
    cout << "]" << endl;
    
    return 0;
}
