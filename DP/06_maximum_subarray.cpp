/*
PROBLEM: Maximum Subarray (Kadane's Algorithm)
Difficulty: Easy
Pattern: 1D DP, Subarray Sum

DESCRIPTION:
Given an integer array nums, find the contiguous subarray (containing at least one number) 
which has the largest sum and return its sum.

INPUT:
nums = [-2, 1, -3, 4, -1, 2, 1, -5, 4]

OUTPUT:
6
Explanation: [4, -1, 2, 1] has the largest sum = 6.

TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(1)
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    // Kadane's Algorithm
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0];
        int currentSum = nums[0];
        
        for (int i = 1; i < nums.size(); i++) {
            // Either extend existing subarray or start new from current element
            currentSum = max(nums[i], currentSum + nums[i]);
            
            // Update maximum sum found so far
            maxSum = max(maxSum, currentSum);
        }
        
        return maxSum;
    }
    
    // DP approach with explicit dp array
    int maxSubArrayDP(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n);
        
        dp[0] = nums[0];
        int maxSum = dp[0];
        
        for (int i = 1; i < n; i++) {
            // dp[i] = max sum ending at index i
            dp[i] = max(nums[i], dp[i-1] + nums[i]);
            maxSum = max(maxSum, dp[i]);
        }
        
        return maxSum;
    }
};

int main() {
    Solution sol;
    
    // Test Case 1
    vector<int> nums1 = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << "Input: nums = [-2, 1, -3, 4, -1, 2, 1, -5, 4]" << endl;
    cout << "Output: " << sol.maxSubArray(nums1) << endl;
    cout << "Output (DP): " << sol.maxSubArrayDP(nums1) << endl << endl;
    
    // Test Case 2
    vector<int> nums2 = {5, 4, -1, 7, 8};
    cout << "Input: nums = [5, 4, -1, 7, 8]" << endl;
    cout << "Output: " << sol.maxSubArray(nums2) << endl;
    cout << "Output (DP): " << sol.maxSubArrayDP(nums2) << endl;
    
    return 0;
}

/*
EXPLANATION:
1. Kadane's Algorithm - Classic DP problem
2. At each position, decide:
   - Start a new subarray from current element
   - Extend the existing subarray
3. currentSum = max(nums[i], currentSum + nums[i])
4. If currentSum becomes negative and next element is positive, start fresh
5. Keep track of maximum sum encountered

KEY LEARNING:
- Famous Kadane's Algorithm
- dp[i] represents maximum sum ending at index i
- Recurrence: dp[i] = max(nums[i], dp[i-1] + nums[i])
- Foundation for many subarray problems
- Can be space optimized to O(1)
*/
