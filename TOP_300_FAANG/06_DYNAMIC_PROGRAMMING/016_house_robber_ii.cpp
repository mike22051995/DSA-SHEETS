/*
================================================================================
PROBLEM: House Robber II (LeetCode #213)
DIFFICULTY: Medium
PATTERN: Dynamic Programming (Circular Array)
COMPANIES: Amazon, Microsoft, Google, Facebook
================================================================================
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);
        
        // Case 1: Rob houses 0 to n-2
        int case1 = robLinear(nums, 0, n - 2);
        
        // Case 2: Rob houses 1 to n-1
        int case2 = robLinear(nums, 1, n - 1);
        
        return max(case1, case2);
    }
    
    int robLinear(vector<int>& nums, int start, int end) {
        int prev2 = 0, prev1 = 0;
        
        for (int i = start; i <= end; i++) {
            int curr = max(prev1, prev2 + nums[i]);
            prev2 = prev1;
            prev1 = curr;
        }
        
        return prev1;
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {2,3,2};
    vector<int> nums2 = {1,2,3,1};
    
    cout << "Max rob (circular) [2,3,2]: " << sol.rob(nums1) << endl;
    cout << "Max rob (circular) [1,2,3,1]: " << sol.rob(nums2) << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. House Robber (LeetCode #198)
2. House Robber III (LeetCode #337) - Binary tree
3. Delete and Earn (LeetCode #740)
4. Maximum Product Subarray (LeetCode #152)
5. Paint House (LeetCode #256)
6. Paint House II (LeetCode #265)
7. Paint Fence (LeetCode #276)
8. Best Time to Buy Sell Stock (LeetCode #121)
9. Best Time to Buy Sell Stock with Cooldown (LeetCode #309)
10. Wiggle Subsequence (LeetCode #376)
*/
