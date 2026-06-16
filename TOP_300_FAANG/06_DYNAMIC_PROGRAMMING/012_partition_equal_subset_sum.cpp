/*
================================================================================
PROBLEM: Partition Equal Subset Sum (LeetCode #416)
DIFFICULTY: Medium
PATTERN: 0/1 Knapsack (Dynamic Programming)
COMPANIES: Amazon, Facebook, Google, Microsoft
================================================================================
*/

#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        
        // Odd sum cannot be partitioned equally
        if (sum % 2 != 0) return false;
        
        int target = sum / 2;
        vector<bool> dp(target + 1, false);
        dp[0] = true;
        
        for (int num : nums) {
            for (int j = target; j >= num; j--) {
                dp[j] = dp[j] || dp[j - num];
            }
        }
        
        return dp[target];
    }
    
    // 2D DP approach
    bool canPartition2D(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0) return false;
        
        int target = sum / 2;
        int n = nums.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));
        
        for (int i = 0; i <= n; i++) {
            dp[i][0] = true;
        }
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= target; j++) {
                if (j < nums[i-1]) {
                    dp[i][j] = dp[i-1][j];
                } else {
                    dp[i][j] = dp[i-1][j] || dp[i-1][j - nums[i-1]];
                }
            }
        }
        
        return dp[n][target];
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {1,5,11,5};
    vector<int> nums2 = {1,2,3,5};
    
    cout << "Can partition [1,5,11,5]: " << (sol.canPartition(nums1) ? "true" : "false") << endl;
    cout << "Can partition [1,2,3,5]: " << (sol.canPartition(nums2) ? "true" : "false") << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Target Sum (LeetCode #494)
2. Partition to K Equal Sum Subsets (LeetCode #698)
3. Last Stone Weight II (LeetCode #1049)
4. Ones and Zeroes (LeetCode #474)
5. Coin Change (LeetCode #322)
6. Combination Sum IV (LeetCode #377)
7. Perfect Squares (LeetCode #279)
8. Minimum Subset Sum Difference
9. Count of Subset Sum
10. Subset Sum Problem (Classic)
*/
