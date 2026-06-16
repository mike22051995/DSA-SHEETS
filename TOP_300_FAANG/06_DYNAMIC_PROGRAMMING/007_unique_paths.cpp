/*
================================================================================
PROBLEM: Unique Paths (LeetCode #62)
DIFFICULTY: Medium
PATTERN: 2D Dynamic Programming / Combinatorics
COMPANIES: Amazon, Google, Microsoft, Facebook
================================================================================
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 1));
        
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        
        return dp[m-1][n-1];
    }
    
    // Space Optimized
    int uniquePathsOptimized(int m, int n) {
        vector<int> dp(n, 1);
        
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[j] += dp[j-1];
            }
        }
        
        return dp[n-1];
    }
};

int main() {
    Solution sol;
    cout << "Unique paths (3x7): " << sol.uniquePaths(3, 7) << endl;
    cout << "Unique paths (3x2): " << sol.uniquePaths(3, 2) << endl;
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Unique Paths II (LeetCode #63) - With obstacles
2. Unique Paths III (LeetCode #980) - Visit all squares
3. Minimum Path Sum (LeetCode #64)
4. Dungeon Game (LeetCode #174)
5. Cherry Pickup (LeetCode #741)
6. Cherry Pickup II (LeetCode #1463)
7. Number of Ways to Arrive at Destination (LeetCode #1976)
8. Count Square Submatrices (LeetCode #1277)
9. Maximum Non Negative Product (LeetCode #1594)
10. Paths in Maze That Lead to Same Room (LeetCode #2077)
*/
