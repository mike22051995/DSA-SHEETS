/*
PROBLEM: Minimum Path Sum (LeetCode 64)
Difficulty: Medium
Company: Google, Meta, Amazon, Microsoft, Netflix
Pattern: Dynamic Programming - Grid Path

DESCRIPTION:
Given a m x n grid filled with non-negative numbers, find a path from 
top-left to bottom-right that minimizes the sum of all numbers along the path.
You can only move either down or right at any point.

MATRIX DIAGRAM:
  Grid:                  DP (min path sum to reach each cell):
  1  3  1                1  4  5
  1  5  1         -->    2  7  6
  4  2  1                6  8  7
  
  Min path: 1→3→1→1→1 = 7
  Path: (0,0)→(0,1)→(0,2)→(1,2)→(2,2)
  
  DP Formula:
  dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1])
  
  Base cases:
  dp[0][0] = grid[0][0]
  dp[i][0] = dp[i-1][0] + grid[i][0] (can only come from above)
  dp[0][j] = dp[0][j-1] + grid[0][j] (can only come from left)

APPROACH:
Method 1: 2D DP
1. Create dp array where dp[i][j] = min path sum to reach (i,j)
2. Fill first row and first column
3. For other cells: dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1])
4. Return dp[m-1][n-1]

Method 2: Space Optimized (1D DP)
- Only need previous row to compute current row
- Use single array and update in-place

Method 3: In-place (modify input)
- Directly modify grid array as dp array

TIME COMPLEXITY: O(M * N)
SPACE COMPLEXITY: O(M * N) or O(N) or O(1)
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n));
        
        // Base case
        dp[0][0] = grid[0][0];
        
        // Fill first row
        for (int j = 1; j < n; j++) {
            dp[0][j] = dp[0][j-1] + grid[0][j];
        }
        
        // Fill first column
        for (int i = 1; i < m; i++) {
            dp[i][0] = dp[i-1][0] + grid[i][0];
        }
        
        // Fill rest of the table
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1]);
            }
        }
        
        return dp[m-1][n-1];
    }
    
    // Space optimized: O(N) space
    int minPathSumOptimized(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        
        int m = grid.size();
        int n = grid[0].size();
        vector<int> dp(n);
        
        dp[0] = grid[0][0];
        
        // Fill first row
        for (int j = 1; j < n; j++) {
            dp[j] = dp[j-1] + grid[0][j];
        }
        
        // Process remaining rows
        for (int i = 1; i < m; i++) {
            dp[0] += grid[i][0]; // First column
            
            for (int j = 1; j < n; j++) {
                dp[j] = grid[i][j] + min(dp[j], dp[j-1]);
            }
        }
        
        return dp[n-1];
    }
    
    // In-place: O(1) space
    int minPathSumInPlace(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        
        int m = grid.size();
        int n = grid[0].size();
        
        // Fill first row
        for (int j = 1; j < n; j++) {
            grid[0][j] += grid[0][j-1];
        }
        
        // Fill first column
        for (int i = 1; i < m; i++) {
            grid[i][0] += grid[i-1][0];
        }
        
        // Fill rest
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                grid[i][j] += min(grid[i-1][j], grid[i][j-1]);
            }
        }
        
        return grid[m-1][n-1];
    }
};

int main() {
    Solution sol;
    
    vector<vector<int>> grid = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}
    };
    
    cout << "Grid:" << endl;
    for (auto& row : grid) {
        for (int val : row) cout << val << " ";
        cout << endl;
    }
    
    cout << "\nMinimum Path Sum: " << sol.minPathSum(grid) << endl;
    
    return 0;
}

/*
INPUT:
grid = [[1,3,1],
        [1,5,1],
        [4,2,1]]

OUTPUT:
7

EXPLANATION:
Minimum path: 1→3→1→1→1 = 7
Path visualization:
[*1] [*3] [*1]
[ 1] [ 5] [*1]
[ 4] [ 2] [*1]

DP table construction:
Step 1 (base):    Step 2 (fill):
1  4  5           1  4  5
2  ?  ?           2  7  6
6  ?  ?           6  8  7

Cell (1,1): min(4,2) + 5 = 7
Cell (1,2): min(5,7) + 1 = 6
Cell (2,1): min(2,6) + 2 = 8
Cell (2,2): min(6,8) + 1 = 7

Another example:
INPUT: [[1,2,3],[4,5,6]]
OUTPUT: 12
Path: 1→2→3→6 (can't go down earlier)
*/
