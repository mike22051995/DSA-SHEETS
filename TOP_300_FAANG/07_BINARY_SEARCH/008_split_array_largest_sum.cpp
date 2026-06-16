/*
================================================================================
PROBLEM: Split Array Largest Sum (LeetCode #410)
DIFFICULTY: Hard
PATTERN: Binary Search / Dynamic Programming
COMPANIES: Amazon, Google, Facebook, Apple
================================================================================

PROBLEM DESCRIPTION:
Given an array of non-negative integers and an integer k, split the array into
k non-empty contiguous subarrays such that the largest subarray sum is minimized.
Return that minimized largest sum.

EXAMPLES:
Example 1:
Input: nums = [7,2,5,10,8], k = 2
Output: 18

Example 2:
Input: nums = [1,2,3,4,5], k = 2
Output: 9

Example 3:
Input: nums = [1,4,4], k = 3
Output: 4

CODE EXPLANATION:
- Binary search the answer between max element and total sum.
- Check if we can split into at most k subarrays with max sum <= mid.
- If possible, tighten the upper bound; otherwise raise the lower bound.
TIME COMPLEXITY: O(n log S), S = sum of nums
SPACE COMPLEXITY: O(1)
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int left = *max_element(nums.begin(), nums.end());
        int right = accumulate(nums.begin(), nums.end(), 0);
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            if (canSplit(nums, mid, k)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        return left;
    }
    
    bool canSplit(vector<int>& nums, int maxSum, int k) {
        int subarrays = 1;
        int currentSum = 0;
        
        for (int num : nums) {
            if (currentSum + num > maxSum) {
                subarrays++;
                currentSum = 0;
            }
            currentSum += num;
        }
        
        return subarrays <= k;
    }
    
    // DP approach - O(n^2 * k)
    int splitArrayDP(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<long long>> dp(k + 1, vector<long long>(n + 1, LLONG_MAX));
        vector<long long> prefixSum(n + 1, 0);
        
        for (int i = 0; i < n; i++) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }
        
        dp[0][0] = 0;
        
        for (int i = 1; i <= k; i++) {
            for (int j = 1; j <= n; j++) {
                for (int p = 0; p < j; p++) {
                    long long maxSum = max(dp[i - 1][p], prefixSum[j] - prefixSum[p]);
                    dp[i][j] = min(dp[i][j], maxSum);
                }
            }
        }
        
        return dp[k][n];
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {7,2,5,10,8};
    vector<int> nums2 = {1,2,3,4,5};
    
    cout << "Min largest sum (k=2): " << sol.splitArray(nums1, 2) << endl;
    cout << "Min largest sum (k=2): " << sol.splitArray(nums2, 2) << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Capacity To Ship Packages (LeetCode #1011)
2. Koko Eating Bananas (LeetCode #875)
3. Divide Chocolate (LeetCode #1231)
4. Painter's Partition Problem (GFG)
5. Book Allocation Problem (GFG)
6. Aggressive Cows (SPOJ)
7. Minimize Max Distance to Gas Station (LeetCode #774)
8. Magnetic Force Between Two Balls (LeetCode #1552)
9. Minimized Maximum of Products (LeetCode #2064)
10. Find K-th Smallest Pair Distance (LeetCode #719)
*/
