/*
PROBLEM: Partition Equal Subset Sum
Difficulty: Medium
Pattern: 0/1 Knapsack, Subset Sum

DESCRIPTION:
Given a non-empty array nums containing only positive integers, find if the array can be 
partitioned into two subsets such that the sum of elements in both subsets is equal.

INPUT:
nums = [1, 5, 11, 5]

OUTPUT:
true
Explanation: The array can be partitioned as [1, 5, 5] and [11].

TIME COMPLEXITY: O(n * sum) where sum = total sum / 2
SPACE COMPLEXITY: O(sum), can use 1D array
*/

#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        
        // If total sum is odd, cannot partition into equal subsets
        if (totalSum % 2 != 0) return false;
        
        int target = totalSum / 2;
        int n = nums.size();
        
        // dp[i] = true if sum i can be formed using subset of nums
        vector<bool> dp(target + 1, false);
        dp[0] = true; // Sum 0 can always be formed (empty subset)
        
        for (int num : nums) {
            // Traverse backwards to avoid using same element twice
            for (int j = target; j >= num; j--) {
                dp[j] = dp[j] || dp[j - num];
            }
        }
        
        return dp[target];
    }
    
    // Alternative: 2D DP for better understanding
    bool canPartition2D(vector<int>& nums) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        if (totalSum % 2 != 0) return false;
        
        int target = totalSum / 2;
        int n = nums.size();
        
        // dp[i][j] = can we make sum j using first i elements
        vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));
        
        // Base case: sum 0 is always possible
        for (int i = 0; i <= n; i++) {
            dp[i][0] = true;
        }
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= target; j++) {
                // Don't include current element
                dp[i][j] = dp[i-1][j];
                
                // Include current element if possible
                if (j >= nums[i-1]) {
                    dp[i][j] = dp[i][j] || dp[i-1][j - nums[i-1]];
                }
            }
        }
        
        return dp[n][target];
    }
};

int main() {
    Solution sol;
    
    // Test Case 1
    vector<int> nums1 = {1, 5, 11, 5};
    cout << "Input: nums = [1, 5, 11, 5]" << endl;
    cout << "Output: " << (sol.canPartition(nums1) ? "true" : "false") << endl;
    cout << "Output (2D): " << (sol.canPartition2D(nums1) ? "true" : "false") << endl << endl;
    
    // Test Case 2
    vector<int> nums2 = {1, 2, 3, 5};
    cout << "Input: nums = [1, 2, 3, 5]" << endl;
    cout << "Output: " << (sol.canPartition(nums2) ? "true" : "false") << endl;
    cout << "Output (2D): " << (sol.canPartition2D(nums2) ? "true" : "false") << endl;
    
    return 0;
}

/*
EXPLANATION:
1. If total sum is odd, impossible to partition equally
2. If even, check if we can form subset with sum = totalSum/2
3. This becomes a subset sum problem
4. dp[j] = can we achieve sum j using some subset
5. For each number, update dp array backwards to avoid using element twice

1D DP Transition:
- For each num in nums:
  - For each sum j from target down to num:
    - dp[j] = dp[j] OR dp[j-num]

2D DP Transition:
- dp[i][j] = dp[i-1][j] (don't take) OR dp[i-1][j-nums[i-1]] (take)

KEY LEARNING:
- Classic 0/1 Knapsack variant
- Subset sum is NP-complete but DP gives pseudo-polynomial solution
- Space optimization: 2D -> 1D by processing backwards
- Similar problems: Target Sum, Last Stone Weight II
*/
