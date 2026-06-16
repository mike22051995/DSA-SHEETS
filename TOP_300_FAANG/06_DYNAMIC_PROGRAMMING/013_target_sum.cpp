/*
================================================================================
PROBLEM: Target Sum (LeetCode #494)
DIFFICULTY: Medium
PATTERN: Dynamic Programming / Backtracking
COMPANIES: Amazon, Facebook, Google, Microsoft
================================================================================
*/

#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    // DP approach (Subset Sum)
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        
        // Check if valid
        if (abs(target) > sum || (sum + target) % 2 != 0) {
            return 0;
        }
        
        int subsetSum = (sum + target) / 2;
        vector<int> dp(subsetSum + 1, 0);
        dp[0] = 1;
        
        for (int num : nums) {
            for (int j = subsetSum; j >= num; j--) {
                dp[j] += dp[j - num];
            }
        }
        
        return dp[subsetSum];
    }
    
    // Backtracking approach
    int findTargetSumWaysBacktrack(vector<int>& nums, int target) {
        return backtrack(nums, 0, 0, target);
    }
    
    int backtrack(vector<int>& nums, int index, int sum, int target) {
        if (index == nums.size()) {
            return sum == target ? 1 : 0;
        }
        
        int add = backtrack(nums, index + 1, sum + nums[index], target);
        int subtract = backtrack(nums, index + 1, sum - nums[index], target);
        
        return add + subtract;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1,1,1,1,1};
    cout << "Ways to reach target 3: " << sol.findTargetSumWays(nums, 3) << endl;
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Partition Equal Subset Sum (LeetCode #416)
2. Combination Sum IV (LeetCode #377)
3. Expression Add Operators (LeetCode #282)
4. Different Ways to Add Parentheses (LeetCode #241)
5. Ones and Zeroes (LeetCode #474)
6. Last Stone Weight II (LeetCode #1049)
7. Minimize Rounding Error (LeetCode #1058)
8. Number of Dice Rolls (LeetCode #1155)
9. Ways to Make Fair Array (LeetCode #1664)
10. Count Number of Teams (LeetCode #1395)
*/
