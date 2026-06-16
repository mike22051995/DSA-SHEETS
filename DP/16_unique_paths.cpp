/*
PROBLEM: Unique Paths
Difficulty: Medium
Pattern: 2D Grid DP, Path Counting

DESCRIPTION:
A robot is located at the top-left corner of a m x n grid.
The robot can only move either down or right at any point in time.
The robot is trying to reach the bottom-right corner of the grid.
How many possible unique paths are there?

INPUT:
m = 3, n = 7

OUTPUT:
28

TIME COMPLEXITY: O(m * n)
SPACE COMPLEXITY: O(m * n), can be optimized to O(n)
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Method 1: 2D DP
    int uniquePaths(int m, int n) {
        // dp[i][j] = number of ways to reach cell (i, j)
        vector<vector<int>> dp(m, vector<int>(n, 1));
        
        // First row and first column all have 1 way (only right or only down)
        // Already initialized to 1
        
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                // Ways to reach (i,j) = ways from top + ways from left
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        
        return dp[m-1][n-1];
    }
    
    // Method 2: Space Optimized (1D array)
    int uniquePathsOptimized(int m, int n) {
        vector<int> dp(n, 1);
        
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[j] = dp[j] + dp[j-1];
            }
        }
        
        return dp[n-1];
    }
    
    // Method 3: Combinatorics (Most Optimal)
    int uniquePathsMath(int m, int n) {
        // Total moves = (m-1) down + (n-1) right = m+n-2
        // Choose (m-1) positions for down moves = C(m+n-2, m-1)
        long long result = 1;
        
        for (int i = 1; i <= min(m-1, n-1); i++) {
            result = result * (m + n - 1 - i) / i;
        }
        
        return (int)result;
    }
};

int main() {
    Solution sol;
    
    // Test Case 1
    int m1 = 3, n1 = 7;
    cout << "Input: m = " << m1 << ", n = " << n1 << endl;
    cout << "Output: " << sol.uniquePaths(m1, n1) << endl;
    cout << "Output (Optimized): " << sol.uniquePathsOptimized(m1, n1) << endl;
    cout << "Output (Math): " << sol.uniquePathsMath(m1, n1) << endl << endl;
    
    // Test Case 2
    int m2 = 3, n2 = 3;
    cout << "Input: m = " << m2 << ", n = " << n2 << endl;
    cout << "Output: " << sol.uniquePaths(m2, n2) << endl;
    cout << "Output (Optimized): " << sol.uniquePathsOptimized(m2, n2) << endl;
    cout << "Output (Math): " << sol.uniquePathsMath(m2, n2) << endl;
    
    return 0;
}

/*
EXPLANATION:
DP Approach:
1. dp[i][j] = number of unique paths to reach cell (i, j)
2. Can only come from top (i-1, j) or left (i, j-1)
3. dp[i][j] = dp[i-1][j] + dp[i][j-1]
4. Base case: dp[0][j] = dp[i][0] = 1 (only one way along edges)

Space Optimization:
1. Only need previous row to calculate current row
2. Use 1D array, update in-place

Mathematical Approach:
1. Need to make (m-1) down moves and (n-1) right moves
2. Total paths = C(m+n-2, m-1) = (m+n-2)! / ((m-1)! * (n-1)!)

Example: m=3, n=3
1  1  1
1  2  3
1  3  6

KEY LEARNING:
- Grid path counting pattern
- Multiple approaches: DP, Space optimization, Combinatorics
- Build solution from smaller subproblems
- Variants: Unique Paths II (with obstacles), Minimum Path Sum
*/
