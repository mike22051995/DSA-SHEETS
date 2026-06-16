/*
PROBLEM: Maximal Square (LeetCode 221)
Difficulty: Medium
Company: Google, Meta, Amazon, Microsoft
Pattern: Dynamic Programming on Matrix

DESCRIPTION:
Given an m x n binary matrix filled with 0's and 1's, find the largest square 
containing only 1's and return its area.

MATRIX DIAGRAM:
  Matrix:              DP Values:         Largest Square:
  1  0  1  0  0        1  0  1  0  0      
  1  0  1  1  1  -->   1  0  1  1  1  -->  Area = 4
  1  1  1  1  1        1  1  1  2  2       (2×2 square)
  1  0  0  1  0        1  0  0  1  0
  
  DP[i][j] = side length of largest square with bottom-right at (i,j)
  
  DP Formula:
  If matrix[i][j] = '1':
    dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1
  
  Visual for cell (2,4):
    dp[1][3]=1  dp[1][4]=1
    dp[2][3]=2  dp[2][4]=?
    
    min(1,1,2) + 1 = 2

APPROACH:
1. Create DP table where dp[i][j] represents side length of largest square 
   with bottom-right corner at (i,j)
2. For each cell with '1':
   - Check top, left, and top-left diagonal
   - Take minimum of these three and add 1
3. Track maximum side length seen
4. Return maxSide²

TIME COMPLEXITY: O(M * N)
SPACE COMPLEXITY: O(M * N) or O(N) with optimization
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int maxSide = 0;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1') {
                    if (i == 0 || j == 0) {
                        dp[i][j] = 1;
                    } else {
                        dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
                    }
                    maxSide = max(maxSide, dp[i][j]);
                }
            }
        }
        
        return maxSide * maxSide;
    }
    
    // Space optimized: O(N) space
    int maximalSquareOptimized(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> dp(n + 1, 0);
        int maxSide = 0;
        int prev = 0;
        
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                int temp = dp[j];
                if (matrix[i-1][j-1] == '1') {
                    dp[j] = min({dp[j], dp[j-1], prev}) + 1;
                    maxSide = max(maxSide, dp[j]);
                } else {
                    dp[j] = 0;
                }
                prev = temp;
            }
        }
        
        return maxSide * maxSide;
    }
};

int main() {
    Solution sol;
    
    vector<vector<char>> matrix = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}
    };
    
    cout << "Maximal Square Area: " << sol.maximalSquare(matrix) << endl;
    
    return 0;
}

/*
INPUT:
matrix = [["1","0","1","0","0"],
          ["1","0","1","1","1"],
          ["1","1","1","1","1"],
          ["1","0","0","1","0"]]

OUTPUT:
4

EXPLANATION:
The maximal square is:
Row 1-2, Col 2-3:
[["1","1"],
 ["1","1"]]
Side length = 2
Area = 2 × 2 = 4

DP table:
[1, 0, 1, 0, 0]
[1, 0, 1, 1, 1]
[1, 1, 1, 2, 2] ← Max side = 2
[1, 0, 0, 1, 0]

Another example:
Input: [["0","1"],["1","0"]]
Output: 1
Only single 1's exist, so max square is 1×1 = 1
*/
