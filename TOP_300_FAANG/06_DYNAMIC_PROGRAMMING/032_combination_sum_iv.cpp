/*
================================================================================
PROBLEM: Combination Sum IV (LeetCode #377)
DIFFICULTY: Medium
PATTERN: Dynamic Programming
COMPANIES: Amazon, Microsoft, Google, Facebook
================================================================================
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned int> dp(target + 1, 0);
        dp[0] = 1;
        
        for (int i = 1; i <= target; i++) {
            for (int num : nums) {
                if (i >= num) {
                    dp[i] += dp[i - num];
                }
            }
        }
        
        return dp[target];
    }
    
    // With memoization
    int combinationSum4Memo(vector<int>& nums, int target) {
        vector<int> memo(target + 1, -1);
        return helper(nums, target, memo);
    }
    
    int helper(vector<int>& nums, int target, vector<int>& memo) {
        if (target == 0) return 1;
        if (target < 0) return 0;
        
        if (memo[target] != -1) {
            return memo[target];
        }
        
        int count = 0;
        for (int num : nums) {
            count += helper(nums, target - num, memo);
        }
        
        memo[target] = count;
        return count;
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {1,2,3};
    vector<int> nums2 = {9};
    
    cout << "Combinations for target 4: " << sol.combinationSum4(nums1, 4) << endl;
    cout << "Combinations for target 3: " << sol.combinationSum4(nums2, 3) << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Combination Sum (LeetCode #39)
2. Combination Sum II (LeetCode #40)
3. Combination Sum III (LeetCode #216)
4. Coin Change (LeetCode #322)
5. Coin Change 2 (LeetCode #518)
6. Perfect Squares (LeetCode #279)
7. Climbing Stairs (LeetCode #70)
8. House Robber (LeetCode #198)
9. Decode Ways (LeetCode #91)
10. Unique Paths (LeetCode #62)
*/
