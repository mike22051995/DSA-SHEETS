/*
PROBLEM: First Missing Positive
Difficulty: Hard
Pattern: Array Marking, Cyclic Sort

DESCRIPTION:
Given an unsorted integer array nums, return the smallest missing positive integer.
You must implement an algorithm that runs in O(n) time and uses constant extra space.

EXPLANATION:
Place each number in its correct position (num at index num-1).
Then scan array to find first position where nums[i] != i+1.
Ignore numbers <= 0 or > n as they can't be the answer.

Time Complexity: O(n)
Space Complexity: O(1)

INPUT-OUTPUT EXAMPLES:

Example 1:
Input: nums = [1,2,0]
Output: 3
Explanation: 1 and 2 are present, 3 is missing

Example 2:
Input: nums = [3,4,-1,1]
Output: 2
Explanation: 1 is present but 2 is missing

Example 3:
Input: nums = [7,8,9,11,12]
Output: 1
Explanation: No positive integers from 1 onwards
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        
        // Place each number in its correct position
        for (int i = 0; i < n; i++) {
            while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        
        // Find first missing positive
        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }
        
        // All positions filled, answer is n+1
        return n + 1;
    }
};

int main() {
    Solution solution;
    
    // Test Case 1
    vector<int> nums1 = {1, 2, 0};
    cout << "Test 1: " << solution.firstMissingPositive(nums1) << endl;
    
    // Test Case 2
    vector<int> nums2 = {3, 4, -1, 1};
    cout << "Test 2: " << solution.firstMissingPositive(nums2) << endl;
    
    // Test Case 3
    vector<int> nums3 = {7, 8, 9, 11, 12};
    cout << "Test 3: " << solution.firstMissingPositive(nums3) << endl;
    
    return 0;
}
