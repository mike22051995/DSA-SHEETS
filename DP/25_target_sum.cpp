/*
PROBLEM: Target Sum (LeetCode 494)
DIFFICULTY: Medium
PATTERN: 0/1 Knapsack Variant - Count Subsets

DESCRIPTION:
You are given an integer array nums and an integer target.
You want to build an expression by adding '+' or '-' before each integer 
and concatenate all integers. Return the number of different expressions that evaluate to target.

EXAMPLE:
Input: nums = [1,1,1,1,1], target = 3
Output: 5
Explanation:
-1 + 1 + 1 + 1 + 1 = 3
+1 - 1 + 1 + 1 + 1 = 3
+1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
+1 + 1 + 1 + 1 - 1 = 3

Input: nums = [1], target = 1
Output: 1

TIME COMPLEXITY: O(n * sum)
SPACE COMPLEXITY: O(n * sum)
*/

#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    // Approach 1: Recursion with memoization
    int countHelper(vector<int>& nums, int target, int index, int sum, 
                    vector<vector<int>>& dp, int offset) {
        if (index == nums.size()) {
            return sum == target ? 1 : 0;
        }
        
        // Use offset to handle negative indices
        if (dp[index][sum + offset] != -1) {
            return dp[index][sum + offset];
        }
        
        // Add current number
        int add = countHelper(nums, target, index + 1, sum + nums[index], dp, offset);
        
        // Subtract current number
        int subtract = countHelper(nums, target, index + 1, sum - nums[index], dp, offset);
        
        return dp[index][sum + offset] = add + subtract;
    }
    
    int findTargetSumWaysMemo(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int offset = sum;  // To handle negative indices
        vector<vector<int>> dp(nums.size(), vector<int>(2 * sum + 1, -1));
        return countHelper(nums, target, 0, 0, dp, offset);
    }
    
    // Approach 2: Convert to Subset Sum Problem (BRILLIANT!)
    /*
    Let S1 = sum of numbers with + sign
    Let S2 = sum of numbers with - sign
    
    S1 + S2 = total_sum  ... (1)
    S1 - S2 = target     ... (2)
    
    Adding (1) and (2):
    2*S1 = total_sum + target
    S1 = (total_sum + target) / 2
    
    So problem becomes: Count subsets with sum = (total_sum + target) / 2
    */
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        
        // Edge cases
        if (abs(target) > sum) return 0;
        if ((sum + target) % 2 != 0) return 0;
        
        int subsetSum = (sum + target) / 2;
        
        // Count subsets with sum = subsetSum
        return countSubsets(nums, subsetSum);
    }
    
    // Count number of subsets with given sum
    int countSubsets(vector<int>& nums, int targetSum) {
        vector<int> dp(targetSum + 1, 0);
        dp[0] = 1;  // Empty subset
        
        for (int num : nums) {
            // Traverse right to left (0/1 knapsack pattern)
            for (int sum = targetSum; sum >= num; sum--) {
                dp[sum] += dp[sum - num];
            }
        }
        
        return dp[targetSum];
    }
    
    // Approach 3: 2D DP for subset count
    int countSubsets2D(vector<int>& nums, int targetSum) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(targetSum+1, 0));
        
        // Base case: empty subset has sum 0
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }
        
        for (int i = 1; i <= n; i++) {
            for (int sum = 0; sum <= targetSum; sum++) {
                // Don't include current number
                dp[i][sum] = dp[i-1][sum];
                
                // Include current number
                if (nums[i-1] <= sum) {
                    dp[i][sum] += dp[i-1][sum - nums[i-1]];
                }
            }
        }
        
        return dp[n][targetSum];
    }
};

int main() {
    Solution sol;
    
    // Test case 1
    cout << "Test Case 1:" << endl;
    vector<int> nums1 = {1, 1, 1, 1, 1};
    int target1 = 3;
    
    cout << "nums: "; for(int n : nums1) cout << n << " "; cout << endl;
    cout << "target: " << target1 << endl;
    cout << "Number of ways (Subset Sum): " << sol.findTargetSumWays(nums1, target1) << endl;
    cout << "Number of ways (Memoization): " << sol.findTargetSumWaysMemo(nums1, target1) << endl;
    
    // Test case 2
    cout << "\nTest Case 2:" << endl;
    vector<int> nums2 = {1};
    int target2 = 1;
    
    cout << "nums: "; for(int n : nums2) cout << n << " "; cout << endl;
    cout << "target: " << target2 << endl;
    cout << "Number of ways: " << sol.findTargetSumWays(nums2, target2) << endl;
    
    // Test case 3
    cout << "\nTest Case 3:" << endl;
    vector<int> nums3 = {1, 2, 3, 4, 5};
    int target3 = 3;
    cout << "nums: "; for(int n : nums3) cout << n << " "; cout << endl;
    cout << "target: " << target3 << endl;
    cout << "Number of ways: " << sol.findTargetSumWays(nums3, target3) << endl;
    
    return 0;
}

/*
EXPLANATION:

TARGET SUM - Beautiful conversion to Subset Sum!

NAIVE APPROACH:
Try all 2^n combinations of + and - signs.
Time: O(2^n) - too slow!

BRILLIANT INSIGHT:
Convert to subset sum problem!

Let S1 = sum of positive numbers
Let S2 = sum of negative numbers

We know:
S1 + S2 = total_sum
S1 - S2 = target

Solving these equations:
2*S1 = total_sum + target
S1 = (total_sum + target) / 2

So instead of trying +/- signs, we can:
"Find number of subsets with sum = (total_sum + target) / 2"

This is a standard subset sum counting problem!

EDGE CASES:
1. If target > total_sum: Impossible → return 0
2. If (total_sum + target) is odd: Can't divide by 2 → return 0

EXAMPLE:
nums = [1, 1, 1, 1, 1], target = 3
total_sum = 5
S1 = (5 + 3) / 2 = 4

Count subsets with sum 4:
{1, 1, 1, 1} - 5 ways to choose 4 numbers from 5 ones
Actually need to count: C(5, 4) = 5 ways

Each way corresponds to:
+1+1+1+1-1 = 3
+1+1+1-1+1 = 3
... (5 combinations)

SUBSET SUM COUNTING:
dp[sum] = number of subsets with this sum

For each number:
    for sum from targetSum to num:
        dp[sum] += dp[sum - num]

Why right to left? To avoid counting same subset twice!

PATTERN RECOGNITION:
- Assign +/- to get target → Partition into two subsets
- Count ways → DP counting
- Can use/not use each element → 0/1 Knapsack

OUTPUT:
Test Case 1:
nums: 1 1 1 1 1
target: 3
Number of ways (Subset Sum): 5
Number of ways (Memoization): 5

Test Case 2:
nums: 1
target: 1
Number of ways: 1

Test Case 3:
nums: 1 2 3 4 5
target: 3
Number of ways: 5
*/
