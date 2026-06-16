/*
================================================================================
PROBLEM: Burst Balloons (LeetCode #312)
DIFFICULTY: Hard
PATTERN: Dynamic Programming (Interval DP)
COMPANIES: Amazon, Microsoft, Google, Facebook
================================================================================
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int> balloons(n + 2);
        balloons[0] = balloons[n + 1] = 1;
        
        for (int i = 0; i < n; i++) {
            balloons[i + 1] = nums[i];
        }
        
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
        
        for (int len = 1; len <= n; len++) {
            for (int left = 1; left <= n - len + 1; left++) {
                int right = left + len - 1;
                
                for (int k = left; k <= right; k++) {
                    int coins = balloons[left - 1] * balloons[k] * balloons[right + 1];
                    dp[left][right] = max(dp[left][right], 
                                         dp[left][k - 1] + coins + dp[k + 1][right]);
                }
            }
        }
        
        return dp[1][n];
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {3,1,5,8};
    vector<int> nums2 = {1,5};
    
    cout << "Max coins: " << sol.maxCoins(nums1) << endl;
    cout << "Max coins: " << sol.maxCoins(nums2) << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Minimum Cost to Merge Stones (LeetCode #1000)
2. Remove Boxes (LeetCode #546)
3. Zuma Game (LeetCode #488)
4. Strange Printer (LeetCode #664)
5. Minimum Cost Tree From Leaf Values (LeetCode #1130)
6. Palindrome Partitioning II (LeetCode #132)
7. Matrix Chain Multiplication
8. Optimal Binary Search Tree
9. Minimum Score Triangulation (LeetCode #1039)
10. Burst Balloons II (variation)
*/
