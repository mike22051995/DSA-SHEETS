/*
PROBLEM: Longest Increasing Subsequence (LIS)
Difficulty: Medium
Pattern: 1D DP, Subsequence

DESCRIPTION:
Given an integer array nums, return the length of the longest strictly increasing subsequence.

INPUT:
nums = [10, 9, 2, 5, 3, 7, 101, 18]

OUTPUT:
4
Explanation: The longest increasing subsequence is [2, 3, 7, 101], therefore the length is 4.

TIME COMPLEXITY: O(n^2) for DP, O(n log n) for Binary Search approach
SPACE COMPLEXITY: O(n)
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Method 1: DP Approach
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        
        vector<int> dp(n, 1); // dp[i] = length of LIS ending at index i
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
    
    // Method 2: Binary Search (Optimal)
    int lengthOfLISOptimal(vector<int>& nums) {
        vector<int> sub; // Maintains smallest tail for each length
        
        for (int num : nums) {
            auto it = lower_bound(sub.begin(), sub.end(), num);
            
            if (it == sub.end()) {
                sub.push_back(num);
            } else {
                *it = num;
            }
        }
        
        return sub.size();
    }
};

int main() {
    Solution sol;
    
    // Test Case 1
    vector<int> nums1 = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << "Input: nums = [10, 9, 2, 5, 3, 7, 101, 18]" << endl;
    cout << "Output: " << sol.lengthOfLIS(nums1) << endl;
    cout << "Output (Optimal): " << sol.lengthOfLISOptimal(nums1) << endl << endl;
    
    // Test Case 2
    vector<int> nums2 = {0, 1, 0, 3, 2, 3};
    cout << "Input: nums = [0, 1, 0, 3, 2, 3]" << endl;
    cout << "Output: " << sol.lengthOfLIS(nums2) << endl;
    cout << "Output (Optimal): " << sol.lengthOfLISOptimal(nums2) << endl;
    
    return 0;
}

/*
EXPLANATION:
DP Approach:
1. dp[i] = length of longest increasing subsequence ending at index i
2. For each i, check all j < i
3. If nums[j] < nums[i], we can extend LIS ending at j
4. dp[i] = max(dp[i], dp[j] + 1)

Binary Search Approach:
1. Maintain array sub where sub[i] = smallest tail element for LIS of length i+1
2. For each number, find position using binary search
3. Replace or append to maintain smallest possible tails
4. Length of sub is the answer

KEY LEARNING:
- Classic LIS pattern used in many problems
- DP solution is intuitive but O(n^2)
- Binary search optimization reduces to O(n log n)
- Important for stock problems, patience sorting, etc.
*/
