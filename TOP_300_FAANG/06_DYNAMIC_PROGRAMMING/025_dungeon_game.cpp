/*
================================================================================
PROBLEM: Dungeon Game (LeetCode #174)
DIFFICULTY: Hard
PATTERN: Dynamic Programming
COMPANIES: Amazon, Microsoft, Google
================================================================================
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();
        
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        // Start from bottom-right
        dp[m-1][n-1] = max(1, 1 - dungeon[m-1][n-1]);
        
        // Fill last column
        for (int i = m - 2; i >= 0; i--) {
            dp[i][n-1] = max(1, dp[i+1][n-1] - dungeon[i][n-1]);
        }
        
        // Fill last row
        for (int j = n - 2; j >= 0; j--) {
            dp[m-1][j] = max(1, dp[m-1][j+1] - dungeon[m-1][j]);
        }
        
        // Fill rest of the table
        for (int i = m - 2; i >= 0; i--) {
            for (int j = n - 2; j >= 0; j--) {
                int minHP = min(dp[i+1][j], dp[i][j+1]);
                dp[i][j] = max(1, minHP - dungeon[i][j]);
            }
        }
        
        return dp[0][0];
    }
};

int main() {
    Solution sol;
    vector<vector<int>> dungeon = {
        {-2, -3, 3},
        {-5, -10, 1},
        {10, 30, -5}
    };
    
    cout << "Minimum HP required: " << sol.calculateMinimumHP(dungeon) << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Minimum Path Sum (LeetCode #64)
2. Unique Paths (LeetCode #62)
3. Unique Paths II (LeetCode #63)
4. Cherry Pickup (LeetCode #741)
5. Cherry Pickup II (LeetCode #1463)
6. Minimum Falling Path Sum (LeetCode #931)
7. Minimum Cost Homecoming (LeetCode #2087)
8. Paths in Matrix Whose Sum Is Divisible (LeetCode #2435)
9. Maximum Number of Points with Cost (LeetCode #1937)
10. Path with Maximum Gold (LeetCode #1219)
*/
