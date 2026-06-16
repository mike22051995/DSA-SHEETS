/*
================================================================================
PROBLEM: Triangle (LeetCode #120)
DIFFICULTY: Medium
PATTERN: Dynamic Programming
COMPANIES: Amazon, Microsoft, Apple
================================================================================
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> dp = triangle[n-1];
        
        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j <= i; j++) {
                dp[j] = triangle[i][j] + min(dp[j], dp[j+1]);
            }
        }
        
        return dp[0];
    }
    
    // Top-down approach
    int minimumTotalTopDown(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        dp[0][0] = triangle[0][0];
        
        for (int i = 1; i < n; i++) {
            dp[i][0] = dp[i-1][0] + triangle[i][0];
            
            for (int j = 1; j < i; j++) {
                dp[i][j] = triangle[i][j] + min(dp[i-1][j-1], dp[i-1][j]);
            }
            
            dp[i][i] = dp[i-1][i-1] + triangle[i][i];
        }
        
        int result = INT_MAX;
        for (int j = 0; j < n; j++) {
            result = min(result, dp[n-1][j]);
        }
        
        return result;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> triangle = {
        {2},
        {3,4},
        {6,5,7},
        {4,1,8,3}
    };
    
    cout << "Minimum total: " << sol.minimumTotal(triangle) << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Minimum Path Sum (LeetCode #64)
2. Unique Paths (LeetCode #62)
3. Pascal's Triangle (LeetCode #118)
4. Pascal's Triangle II (LeetCode #119)
5. Minimum Falling Path Sum (LeetCode #931)
6. Minimum Falling Path Sum II (LeetCode #1289)
7. Minimum Cost Tree From Leaf Values (LeetCode #1130)
8. Longest Arithmetic Subsequence (LeetCode #1027)
9. Minimum Cost Climbing Stairs (LeetCode #746)
10. Maximum Sum of 3 Non-Overlapping Subarrays (LeetCode #689)
*/
