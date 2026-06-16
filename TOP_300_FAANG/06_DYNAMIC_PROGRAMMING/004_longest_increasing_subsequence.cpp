/*
================================================================================
PROBLEM: Longest Increasing Subsequence (LeetCode #300)
DIFFICULTY: Medium
PATTERN: Dynamic Programming / Binary Search
COMPANIES: Amazon, Microsoft, Google, Facebook, Apple
================================================================================

PROBLEM DESCRIPTION:
Given an integer array nums, return the length of the longest strictly 
increasing subsequence.

A subsequence is derived from an array by deleting some or no elements without 
changing the order of the remaining elements.

================================================================================
PATTERN RECOGNITION:
Use this pattern when:
1. Find longest/shortest subsequence with property
2. Not necessarily contiguous
3. Can use DP or greedy with binary search
4. Subproblem: LIS ending at index i

Key Indicators:
- "Longest increasing subsequence"
- Not contiguous (vs subarray)
- Can skip elements
- Order must be maintained

================================================================================
INPUT/OUTPUT EXAMPLES:

Example 1:
Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: LIS is [2,3,7,101] or [2,3,7,18]

Example 2:
Input: nums = [0,1,0,3,2,3]
Output: 4

Example 3:
Input: nums = [7,7,7,7,7,7,7]
Output: 1

================================================================================
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // DP Approach - O(n^2)
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        
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
    
    // Binary Search - O(n log n)
    int lengthOfLISOptimal(vector<int>& nums) {
        vector<int> tails;
        
        for (int num : nums) {
            auto it = lower_bound(tails.begin(), tails.end(), num);
            
            if (it == tails.end()) {
                tails.push_back(num);
            } else {
                *it = num;
            }
        }
        
        return tails.size();
    }
};

int main() {
    Solution sol;
    
    vector<int> nums1 = {10,9,2,5,3,7,101,18};
    cout << "LIS length: " << sol.lengthOfLIS(nums1) << endl;
    cout << "LIS length (optimal): " << sol.lengthOfLISOptimal(nums1) << endl;
    
    return 0;
}

/*
================================================================================
SIMILAR PROBLEMS:
1. Longest Increasing Subsequence II (LeetCode #2407)
2. Number of LIS (LeetCode #673)
3. Longest Consecutive Sequence (LeetCode #128)
4. Russian Doll Envelopes (LeetCode #354)
5. Maximum Length of Pair Chain (LeetCode #646)
6. Delete and Earn (LeetCode #740)
7. Longest Arithmetic Subsequence (LeetCode #1027)
8. Longest String Chain (LeetCode #1048)
9. Minimum Number of Removals (LeetCode #1671)
10. Make Array Strictly Increasing (LeetCode #1187)
================================================================================
*/
