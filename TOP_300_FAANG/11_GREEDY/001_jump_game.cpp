/*
================================================================================
PROBLEM: Jump Game (LeetCode #55)
DIFFICULTY: Medium
PATTERN: Greedy / Dynamic Programming
COMPANIES: Amazon, Microsoft, Google, Apple, Facebook
================================================================================
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Greedy Approach (Optimal)
    bool canJump(vector<int>& nums) {
        int maxReach = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            if (i > maxReach) return false;
            maxReach = max(maxReach, i + nums[i]);
            if (maxReach >= nums.size() - 1) return true;
        }
        
        return true;
    }
    
    // DP Approach
    bool canJumpDP(vector<int>& nums) {
        int n = nums.size();
        vector<bool> dp(n, false);
        dp[0] = true;
        
        for (int i = 0; i < n; i++) {
            if (!dp[i]) continue;
            for (int j = 1; j <= nums[i] && i + j < n; j++) {
                dp[i + j] = true;
            }
        }
        
        return dp[n-1];
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {2,3,1,1,4};
    vector<int> nums2 = {3,2,1,0,4};
    cout << "Can jump (test 1): " << (sol.canJump(nums1) ? "true" : "false") << endl;
    cout << "Can jump (test 2): " << (sol.canJump(nums2) ? "true" : "false") << endl;
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Jump Game II (LeetCode #45) - Minimum jumps
2. Jump Game III (LeetCode #1306) - Can reach value 0
3. Jump Game IV (LeetCode #1345) - With equal values
4. Jump Game V (LeetCode #1340) - With constraints
5. Jump Game VI (LeetCode #1696) - Maximum score
6. Jump Game VII (LeetCode #1871) - Binary string
7. Minimum Jumps to Reach Home (LeetCode #1654)
8. Frog Jump (LeetCode #403)
9. Video Stitching (LeetCode #1024)
10. Minimum Number of Taps (LeetCode #1326)
*/
