/*
================================================================================
PROBLEM: Longest Increasing Subsequence (LeetCode #300)
DIFFICULTY: Medium
PATTERN: Dynamic Programming / Binary Search
COMPANIES: Amazon, Microsoft, Google, Facebook, Apple
================================================================================
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Binary Search - O(n log n)
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp;
        
        for (int num : nums) {
            auto it = lower_bound(dp.begin(), dp.end(), num);
            
            if (it == dp.end()) {
                dp.push_back(num);
            } else {
                *it = num;
            }
        }
        
        return dp.size();
    }
    
    // DP - O(n^2)
    int lengthOfLISDP(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        int maxLen = 1;
        
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            maxLen = max(maxLen, dp[i]);
        }
        
        return maxLen;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {10,9,2,5,3,7,101,18};
    cout << "LIS length: " << sol.lengthOfLIS(nums) << endl;
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Number of Longest Increasing Subsequence (LeetCode #673)
2. Longest Continuous Increasing Subsequence (LeetCode #674)
3. Longest Arithmetic Subsequence (LeetCode #1027)
4. Russian Doll Envelopes (LeetCode #354)
5. Maximum Length of Pair Chain (LeetCode #646)
6. Delete Columns to Make Sorted III (LeetCode #960)
7. Longest Mountain in Array (LeetCode #845)
8. Minimum Number of Removals (LeetCode #1671)
9. Longest Bitonic Subsequence
10. Box Stacking Problem
*/
