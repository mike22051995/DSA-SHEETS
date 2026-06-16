/*
PROBLEM: Unique Paths II (LeetCode 63)
Difficulty: Medium
Company: Google, Meta, Amazon, Microsoft
Pattern: Dynamic Programming with Obstacles

DESCRIPTION:
A robot is located at the top-left corner of a m x n grid.
The robot can only move either down or right at any point in time.
Now consider if some obstacles are added to the grids. 
How many unique paths would there be?
An obstacle is marked as 1 and empty space is marked as 0.

GRID DIAGRAM:
  Grid with obstacles:       Path counts:
  0  0  0                    1  1  1
  0  1  0             -->    1  0  1
  0  0  0                    1  1  2
  
  Obstacle at (1,1) blocks paths!
  Can't pass through obstacles
  
  DP Formula:
  if grid[i][j] == 1:
      dp[i][j] = 0 (obstacle, no paths)
  else:
      dp[i][j] = dp[i-1][j] + dp[i][j-1]
  
  Edge case: If start or end is obstacle → return 0

APPROACH:
1. Check if start or end has obstacle → return 0
2. Create dp array where dp[i][j] = paths to reach (i,j)
3. Initialize first row and column (stop at first obstacle)
4. For each cell:
   - If obstacle: dp[i][j] = 0
   - Else: dp[i][j] = dp[i-1][j] + dp[i][j-1]
5. Return dp[m-1][n-1]

TIME COMPLEXITY: O(M * N)
SPACE COMPLEXITY: O(M * N) or O(N) with optimization
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.empty() || obstacleGrid[0].empty()) return 0;
        
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        // If start or end is obstacle
        if (obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1) {
            return 0;
        }
        
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        // Initialize starting position
        dp[0][0] = 1;
        
        // Fill first column
        for (int i = 1; i < m; i++) {
            if (obstacleGrid[i][0] == 0) {
                dp[i][0] = dp[i-1][0];
            }
            // else dp[i][0] remains 0
        }
        
        // Fill first row
        for (int j = 1; j < n; j++) {
            if (obstacleGrid[0][j] == 0) {
                dp[0][j] = dp[0][j-1];
            }
            // else dp[0][j] remains 0
        }
        
        // Fill rest of the table
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (obstacleGrid[i][j] == 0) {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
                // else dp[i][j] remains 0
            }
        }
        
        return dp[m-1][n-1];
    }
    
    // Space optimized: O(N) space
    int uniquePathsWithObstaclesOptimized(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.empty() || obstacleGrid[0].empty()) return 0;
        
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        if (obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1) {
            return 0;
        }
        
        vector<int> dp(n, 0);
        dp[0] = 1;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (obstacleGrid[i][j] == 1) {
                    dp[j] = 0;
                } else if (j > 0) {
                    dp[j] += dp[j-1];
                }
            }
        }
        
        return dp[n-1];
    }
    
    // In-place: O(1) space (modifies input)
    int uniquePathsWithObstaclesInPlace(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.empty() || obstacleGrid[0].empty()) return 0;
        
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        if (obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1) {
            return 0;
        }
        
        obstacleGrid[0][0] = 1;
        
        // Fill first column
        for (int i = 1; i < m; i++) {
            obstacleGrid[i][0] = (obstacleGrid[i][0] == 0 && obstacleGrid[i-1][0] == 1) ? 1 : 0;
        }
        
        // Fill first row
        for (int j = 1; j < n; j++) {
            obstacleGrid[0][j] = (obstacleGrid[0][j] == 0 && obstacleGrid[0][j-1] == 1) ? 1 : 0;
        }
        
        // Fill rest
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (obstacleGrid[i][j] == 0) {
                    obstacleGrid[i][j] = obstacleGrid[i-1][j] + obstacleGrid[i][j-1];
                } else {
                    obstacleGrid[i][j] = 0;
                }
            }
        }
        
        return obstacleGrid[m-1][n-1];
    }
};

int main() {
    Solution sol;
    
    vector<vector<int>> grid = {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}
    };
    
    cout << "Grid (0=empty, 1=obstacle):" << endl;
    for (auto& row : grid) {
        for (int val : row) cout << val << " ";
        cout << endl;
    }
    
    cout << "\nUnique paths: " << sol.uniquePathsWithObstacles(grid) << endl;
    
    return 0;
}

/*
INPUT:
obstacleGrid = [[0,0,0],
                [0,1,0],
                [0,0,0]]

OUTPUT:
2

EXPLANATION:
DP table:
1  1  1
1  0  1
1  1  2

Path 1: (0,0)→(0,1)→(0,2)→(1,2)→(2,2)
Path 2: (0,0)→(1,0)→(2,0)→(2,1)→(2,2)

Cannot go through (1,1) because it's an obstacle.

Another example:
INPUT: [[0,1],[0,0]]
OUTPUT: 1

DP table:
1  0
1  1

Only one path: (0,0)→(1,0)→(1,1)
Can't go through (0,1) due to obstacle.

Edge case:
INPUT: [[1,0]]
OUTPUT: 0
Start position has obstacle, no paths possible.

INPUT: [[0,0],[0,1]]
OUTPUT: 0
End position has obstacle, no paths possible.
*/
