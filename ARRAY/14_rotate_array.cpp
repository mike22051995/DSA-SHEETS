/*
PROBLEM: Rotate Array
Difficulty: Medium
Pattern: Array Reversal

DESCRIPTION:
Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.

EXPLANATION:
Three-step reversal approach:
1. Reverse the entire array
2. Reverse the first k elements
3. Reverse the remaining n-k elements
This achieves rotation in-place with O(1) space.

Time Complexity: O(n)
Space Complexity: O(1)

INPUT-OUTPUT EXAMPLES:

Example 1:
Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation: Rotate right by 3 steps

Example 2:
Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
Explanation: Rotate right by 2 steps

Example 3:
Input: nums = [1,2], k = 3
Output: [2,1]
Explanation: k = 3 is equivalent to k = 1 (3 % 2 = 1)
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n; // Handle k > n
        
        if (k == 0) return;
        
        // Reverse entire array
        reverse(nums.begin(), nums.end());
        
        // Reverse first k elements
        reverse(nums.begin(), nums.begin() + k);
        
        // Reverse remaining elements
        reverse(nums.begin() + k, nums.end());
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
    vector<int> nums1 = {1, 2, 3, 4, 5, 6, 7};
    solution.rotate(nums1, 3);
    cout << "Test 1: ";
    printArray(nums1);
    
    // Test Case 2
    vector<int> nums2 = {-1, -100, 3, 99};
    solution.rotate(nums2, 2);
    cout << "Test 2: ";
    printArray(nums2);
    
    // Test Case 3
    vector<int> nums3 = {1, 2};
    solution.rotate(nums3, 3);
    cout << "Test 3: ";
    printArray(nums3);
    
    return 0;
}
