/*
PROBLEM: Move Zeroes
Difficulty: Easy
Pattern: Two Pointers

DESCRIPTION:
Given an integer array nums, move all 0's to the end of it while maintaining the relative 
order of the non-zero elements. Note that you must do this in-place without making a copy 
of the array.

EXPLANATION:
We use two pointers: one to track the position where the next non-zero should go,
and another to scan through the array. When we find a non-zero, we swap it with the
position pointed to by the first pointer.

Time Complexity: O(n)
Space Complexity: O(1)

INPUT-OUTPUT EXAMPLES:

Example 1:
Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]
Explanation: Non-zero elements maintain their order

Example 2:
Input: nums = [0]
Output: [0]
Explanation: Single zero element

Example 3:
Input: nums = [1,2,3]
Output: [1,2,3]
Explanation: No zeros to move
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int nonZeroPos = 0;
        
        // Move all non-zero elements to the front
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                swap(nums[nonZeroPos], nums[i]);
                nonZeroPos++;
            }
        }
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
    vector<int> nums1 = {0, 1, 0, 3, 12};
    solution.moveZeroes(nums1);
    cout << "Test 1: ";
    printArray(nums1);
    
    // Test Case 2
    vector<int> nums2 = {0};
    solution.moveZeroes(nums2);
    cout << "Test 2: ";
    printArray(nums2);
    
    // Test Case 3
    vector<int> nums3 = {1, 2, 3};
    solution.moveZeroes(nums3);
    cout << "Test 3: ";
    printArray(nums3);
    
    return 0;
}
