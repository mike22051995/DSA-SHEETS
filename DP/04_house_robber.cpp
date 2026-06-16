/*
PROBLEM: House Robber
Difficulty: Easy
Pattern: 1D DP, Non-adjacent Selection

DESCRIPTION:
You are a professional robber planning to rob houses along a street. Each house has a certain 
amount of money stashed. Adjacent houses have security systems connected and will automatically 
contact the police if two adjacent houses were broken into on the same night.
Given an integer array nums representing the amount of money of each house, return the maximum 
amount of money you can rob tonight without alerting the police.

INPUT:
nums = [2, 7, 9, 3, 1]

OUTPUT:
12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
Total amount = 2 + 9 + 1 = 12.

TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(n) for dp array, O(1) optimized
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Method 1: DP Tabulation
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        
        vector<int> dp(n);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        
        for (int i = 2; i < n; i++) {
            // Either rob current house + max till (i-2)
            // Or skip current house and take max till (i-1)
            dp[i] = max(dp[i-1], nums[i] + dp[i-2]);
        }
        
        return dp[n-1];
    }
    
    // Method 2: Space Optimized
    int robOptimized(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        
        int prev2 = nums[0];
        int prev1 = max(nums[0], nums[1]);
        
        for (int i = 2; i < n; i++) {
            int curr = max(prev1, nums[i] + prev2);
            prev2 = prev1;
            prev1 = curr;
        }
        
        return prev1;
    }
};

int main() {
    Solution sol;
    
    // Test Case 1
    vector<int> nums1 = {2, 7, 9, 3, 1};
    cout << "Input: nums = [2, 7, 9, 3, 1]" << endl;
    cout << "Output: " << sol.rob(nums1) << endl;
    cout << "Output (Optimized): " << sol.robOptimized(nums1) << endl << endl;
    
    // Test Case 2
    vector<int> nums2 = {1, 2, 3, 1};
    cout << "Input: nums = [1, 2, 3, 1]" << endl;
    cout << "Output: " << sol.rob(nums2) << endl;
    cout << "Output (Optimized): " << sol.robOptimized(nums2) << endl;
    
    return 0;
}

/*
EXPLANATION:
1. At each house i, we have two choices:
   - Rob it: nums[i] + dp[i-2] (can't rob i-1)
   - Don't rob it: dp[i-1] (take max till previous house)
2. dp[i] = max(rob it, don't rob it)
3. Build solution bottom-up from first house

KEY LEARNING:
- Non-adjacent selection pattern
- Make optimal choice at each step
- Recurrence: dp[i] = max(dp[i-1], nums[i] + dp[i-2])
- Common in problems with constraints on adjacent elements
*/
