/*
PROBLEM: Unique Paths (LeetCode 62)
Difficulty: Medium
Company: Google, Meta, Amazon, Microsoft, Netflix
Pattern: Dynamic Programming - Combinatorics

DESCRIPTION:
A robot is located at the top-left corner of a m x n grid.
The robot can only move either down or right at any point in time.
The robot is trying to reach the bottom-right corner.
How many unique paths are there?

GRID DIAGRAM:
  3×7 Grid:                  Path counts to each cell:
  S → → → → → → E            1   1   1   1   1   1   1
  ↓   ↓   ↓   ↓   ↓   ↓      1   2   3   4   5   6   7
  ↓   ↓   ↓   ↓   ↓   ↓      1   3   6  10  15  21  28
  
  Formula: dp[i][j] = dp[i-1][j] + dp[i][j-1]
  (paths from above + paths from left)
  
  Base cases:
  - First row: all 1's (only one way to reach)
  - First column: all 1's (only one way to reach)
  
  Mathematical approach:
  Total moves: (m-1) down + (n-1) right = m+n-2 moves
  Choose (m-1) positions for down: C(m+n-2, m-1)

APPROACH:
Method 1: 2D DP
1. Create dp array where dp[i][j] = paths to reach (i,j)
2. Initialize first row and column to 1
3. Fill table: dp[i][j] = dp[i-1][j] + dp[i][j-1]
4. Return dp[m-1][n-1]

Method 2: 1D DP (Space Optimized)
- Only need previous row

Method 3: Combinatorics
- Answer = C(m+n-2, m-1) = (m+n-2)! / ((m-1)! * (n-1)!)

TIME COMPLEXITY: O(M * N) for DP, O(M + N) for math
SPACE COMPLEXITY: O(M * N) or O(N) or O(1)
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 1));
        
        // First row and column already initialized to 1
        
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        
        return dp[m-1][n-1];
    }
    
    // Space optimized: O(N) space
    int uniquePathsOptimized(int m, int n) {
        vector<int> dp(n, 1);
        
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[j] += dp[j-1];
            }
        }
        
        return dp[n-1];
    }
    
    // Mathematical approach: Combinatorics
    int uniquePathsMath(int m, int n) {
        long long result = 1;
        
        // Calculate C(m+n-2, m-1) = C(m+n-2, n-1)
        // Use the smaller value to minimize calculations
        int k = min(m - 1, n - 1);
        int total = m + n - 2;
        
        // C(n, k) = n! / (k! * (n-k)!)
        // = (n * (n-1) * ... * (n-k+1)) / (k * (k-1) * ... * 1)
        for (int i = 1; i <= k; i++) {
            result = result * (total - k + i) / i;
        }
        
        return result;
    }
};

int main() {
    Solution sol;
    
    int m = 3, n = 7;
    cout << "Grid size: " << m << "×" << n << endl;
    cout << "Unique paths (DP): " << sol.uniquePaths(m, n) << endl;
    cout << "Unique paths (Optimized): " << sol.uniquePathsOptimized(m, n) << endl;
    cout << "Unique paths (Math): " << sol.uniquePathsMath(m, n) << endl;
    
    m = 3; n = 3;
    cout << "\nGrid size: " << m << "×" << n << endl;
    cout << "Unique paths: " << sol.uniquePaths(m, n) << endl;
    
    return 0;
}

/*
INPUT:
m = 3, n = 7

OUTPUT:
28

EXPLANATION:
Robot needs to make (m-1) = 2 down moves and (n-1) = 6 right moves.
Total paths = C(8, 2) = 8!/(2!*6!) = 28

DP table:
1   1   1   1   1   1   1
1   2   3   4   5   6   7
1   3   6  10  15  21  28

Cell (1,1): 1 (from above) + 1 (from left) = 2
Cell (1,2): 2 (from above) + 1 (from left) = 3
Cell (2,2): 3 (from above) + 3 (from left) = 6
...
Cell (2,6): 21 (from above) + 7 (from left) = 28

For m=3, n=3:
INPUT: m = 3, n = 3
OUTPUT: 6

DP table:
1  1  1
1  2  3
1  3  6

Paths: RRDD, RDRD, RDDR, DRRD, DRDR, DDRR
(where R=right, D=down)
*/
