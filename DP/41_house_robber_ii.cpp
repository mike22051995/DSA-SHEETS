/*
PROBLEM: House Robber II
Difficulty: Medium
Pattern: 1D DP, Circular Array

DESCRIPTION:
You are a professional robber planning to rob houses along a street. Each house has a certain
amount of money stashed. All houses at this place are arranged in a circle. That means the first
house is the neighbor of the last one. Meanwhile, adjacent houses have security systems connected
and it will automatically contact the police if two adjacent houses were broken into on the same night.
Given an integer array nums representing the amount of money of each house, return the maximum
amount of money you can rob tonight without alerting the police.

INPUT:
nums = [2, 3, 2]

OUTPUT:
3
Explanation: You cannot rob house 1 and house 3 together because they are adjacent in the circle.

TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(1) optimized, O(n) with DP array
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Method 1: Space-optimized linear robber for subarray [start..end]
    int robLinearOptimized(const vector<int>& nums, int start, int end) {
        int prev2 = 0;
        int prev1 = 0;

        for (int i = start; i <= end; i++) {
            int curr = max(prev1, nums[i] + prev2);
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }

    // Main method: split circular case into two linear cases
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        // Case 1: include first house, exclude last -> [0..n-2]
        int case1 = robLinearOptimized(nums, 0, n - 2);

        // Case 2: exclude first house, include possibility of last -> [1..n-1]
        int case2 = robLinearOptimized(nums, 1, n - 1);

        return max(case1, case2);
    }
};

int main() {
    Solution sol;

    // Test Case 1
    vector<int> nums1 = {2, 3, 2};
    cout << "Input: nums = [2, 3, 2]" << endl;
    cout << "Output: " << sol.rob(nums1) << endl << endl;

    // Test Case 2
    vector<int> nums2 = {1, 2, 3, 1};
    cout << "Input: nums = [1, 2, 3, 1]" << endl;
    cout << "Output: " << sol.rob(nums2) << endl << endl;

    // Test Case 3
    vector<int> nums3 = {1, 2, 3};
    cout << "Input: nums = [1, 2, 3]" << endl;
    cout << "Output: " << sol.rob(nums3) << endl;

    return 0;
}

/*
EXPLANATION:
1. In circular arrangement, first and last houses are adjacent.
2. So both cannot be robbed together.
3. Break into two linear subproblems:
   - Rob from index 0 to n-2 (exclude last)
   - Rob from index 1 to n-1 (exclude first)
4. Take maximum of the two answers.

KEY LEARNING:
- Circular dependency is often solved by splitting into multiple linear cases.
- Reuse House Robber I logic as a helper.
- This pattern appears in many "circular array" DP problems.
*/
