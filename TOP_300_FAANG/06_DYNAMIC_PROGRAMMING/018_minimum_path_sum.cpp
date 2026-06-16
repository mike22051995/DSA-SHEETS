/*
================================================================================
PROBLEM: Minimum Path Sum (LeetCode #64)
DIFFICULTY: Medium
PATTERN: 2D Dynamic Programming
COMPANIES: Amazon, Microsoft, Google, Facebook, Apple
================================================================================
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = grid[0][0];
        
        // Initialize first row
        for (int j = 1; j < n; j++) {
            dp[0][j] = dp[0][j-1] + grid[0][j];
        }
        
        // Initialize first column
        for (int i = 1; i < m; i++) {
            dp[i][0] = dp[i-1][0] + grid[i][0];
        }
        
        // Fill the rest
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1]);
            }
        }
        
        return dp[m-1][n-1];
    }
    
    // Space optimized
    int minPathSumOptimized(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<int> dp(n, 0);
        dp[0] = grid[0][0];
        
        for (int j = 1; j < n; j++) {
            dp[j] = dp[j-1] + grid[0][j];
        }
        
        for (int i = 1; i < m; i++) {
            dp[0] += grid[i][0];
            
            for (int j = 1; j < n; j++) {
                dp[j] = grid[i][j] + min(dp[j], dp[j-1]);
            }
        }
        
        return dp[n-1];
    }
};

int main() {
    Solution sol;
    vector<vector<int>> grid = {
        {1,3,1},
        {1,5,1},
        {4,2,1}
    };
    
    cout << "Minimum path sum: " << sol.minPathSum(grid) << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Unique Paths (LeetCode #62)
2. Unique Paths II (LeetCode #63)
3. Minimum Path Sum in Triangle (LeetCode #120)
4. Dungeon Game (LeetCode #174)
5. Cherry Pickup (LeetCode #741)
6. Cherry Pickup II (LeetCode #1463)
7. Minimum Falling Path Sum (LeetCode #931)
8. Minimum Falling Path Sum II (LeetCode #1289)
9. Get Maximum in Generated Array (LeetCode #1646)
10. Maximal Square (LeetCode #221)
*/
