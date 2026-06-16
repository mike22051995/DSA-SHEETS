]
/*
PROBLEM: Maximum Subarray (Kadane's Algorithm)
Difficulty: Easy
Pattern: Dynamic Programming, Kadane's Algorithm

DESCRIPTION:
Given an integer array nums, find the contiguous subarray (containing at least one number) 
which has the largest sum and return its sum.

EXPLANATION:
Kadane's Algorithm: We maintain a running sum of the current subarray.
If the running sum becomes negative, we reset it to 0 (start a new subarray).
We keep track of the maximum sum seen so far.

Time Complexity: O(n)
Space Complexity: O(1)

INPUT-OUTPUT EXAMPLES:

Example 1:
Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6

Example 2:
Input: nums = [1]
Output: 1
Explanation: Single element array

Example 3:
Input: nums = [5,4,-1,7,8]
Output: 23
Explanation: [5,4,-1,7,8] has the largest sum = 23
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0];
        int currentSum = nums[0];
        
        for (int i = 1; i < nums.size(); i++) {
            // Either extend the existing subarray or start a new one
            currentSum = max(nums[i], currentSum + nums[i]);
            
            // Update maximum sum
            maxSum = max(maxSum, currentSum);
        }
        
        return maxSum;
    }
};

int main() {
    Solution solution;
    
    // Test Case 1
    vector<int> nums1 = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << "Test 1: " << solution.maxSubArray(nums1) << endl;
    
    // Test Case 2
    vector<int> nums2 = {1};
    cout << "Test 2: " << solution.maxSubArray(nums2) << endl;
    
    // Test Case 3
    vector<int> nums3 = {5, 4, -1, 7, 8};
    cout << "Test 3: " << solution.maxSubArray(nums3) << endl;
    
    return 0;
}
