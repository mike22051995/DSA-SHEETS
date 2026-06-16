/*
PROBLEM: Longest Line of Consecutive One in Matrix (LeetCode 562)
Difficulty: Medium
Company: Google, Meta
Pattern: Dynamic Programming - Multiple Directions

DESCRIPTION:
Given an m x n binary matrix mat, return the length of the longest line of 
consecutive ones in the matrix.
The line could be horizontal, vertical, diagonal, or anti-diagonal.

MATRIX DIAGRAM:
  Matrix:                Lines to check:
  0  1  1  0             Horizontal: →
  0  1  1  0      -->    Vertical: ↓
  0  0  0  1             Diagonal: ↘
                         Anti-diagonal: ↙
  
  Longest consecutive 1's:
  Horizontal: 2 (row 0: 1,1 or row 1: 1,1)
  Vertical: 2 (col 1: 1,1 or col 2: 1,1)
  Diagonal: 1 (no diagonal line of 2+)
  Anti-diagonal: 1
  
  Answer: 2
  
  DP Approach:
  dp[i][j][d] = length of consecutive 1's ending at (i,j) in direction d
  d = 0: horizontal, 1: vertical, 2: diagonal, 3: anti-diagonal

APPROACH:
Method 1: DP with 4 directions
1. Create 3D DP array: dp[i][j][4]
2. For each cell with value 1:
   - Horizontal: dp[i][j][0] = dp[i][j-1][0] + 1
   - Vertical: dp[i][j][1] = dp[i-1][j][1] + 1
   - Diagonal: dp[i][j][2] = dp[i-1][j-1][2] + 1
   - Anti-diagonal: dp[i][j][3] = dp[i-1][j+1][3] + 1
3. Track maximum value seen

Method 2: Four separate passes
- One pass for each direction

TIME COMPLEXITY: O(M * N)
SPACE COMPLEXITY: O(M * N) with DP, can optimize to O(N)
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestLine(vector<vector<int>>& mat) {
        if (mat.empty() || mat[0].empty()) return 0;
        
        int m = mat.size();
        int n = mat[0].size();
        
        // dp[i][j][d]: length ending at (i,j) in direction d
        // d=0: horizontal, d=1: vertical, d=2: diagonal, d=3: anti-diagonal
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(4, 0)));
        
        int maxLen = 0;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1) {
                    // Horizontal
                    dp[i][j][0] = (j > 0) ? dp[i][j-1][0] + 1 : 1;
                    
                    // Vertical
                    dp[i][j][1] = (i > 0) ? dp[i-1][j][1] + 1 : 1;
                    
                    // Diagonal
                    dp[i][j][2] = (i > 0 && j > 0) ? dp[i-1][j-1][2] + 1 : 1;
                    
                    // Anti-diagonal
                    dp[i][j][3] = (i > 0 && j < n - 1) ? dp[i-1][j+1][3] + 1 : 1;
                    
                    // Update max
                    maxLen = max(maxLen, max({dp[i][j][0], dp[i][j][1], 
                                             dp[i][j][2], dp[i][j][3]}));
                }
            }
        }
        
        return maxLen;
    }
    
    // Space optimized: O(N) space
    int longestLineOptimized(vector<vector<int>>& mat) {
        if (mat.empty() || mat[0].empty()) return 0;
        
        int m = mat.size();
        int n = mat[0].size();
        
        // Only need previous row for vertical and diagonals
        vector<vector<int>> prev(n, vector<int>(4, 0));
        vector<vector<int>> curr(n, vector<int>(4, 0));
        
        int maxLen = 0;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1) {
                    // Horizontal
                    curr[j][0] = (j > 0) ? curr[j-1][0] + 1 : 1;
                    
                    // Vertical
                    curr[j][1] = prev[j][1] + 1;
                    
                    // Diagonal
                    curr[j][2] = (j > 0) ? prev[j-1][2] + 1 : 1;
                    
                    // Anti-diagonal
                    curr[j][3] = (j < n - 1) ? prev[j+1][3] + 1 : 1;
                    
                    maxLen = max(maxLen, max({curr[j][0], curr[j][1], 
                                             curr[j][2], curr[j][3]}));
                } else {
                    curr[j] = {0, 0, 0, 0};
                }
            }
            prev = curr;
        }
        
        return maxLen;
    }
};

int main() {
    Solution sol;
    
    vector<vector<int>> mat1 = {
        {0, 1, 1, 0},
        {0, 1, 1, 0},
        {0, 0, 0, 1}
    };
    
    cout << "Matrix 1:" << endl;
    for (auto& row : mat1) {
        for (int val : row) cout << val << " ";
        cout << endl;
    }
    cout << "Longest line: " << sol.longestLine(mat1) << endl;
    
    vector<vector<int>> mat2 = {
        {1, 1, 1, 1},
        {0, 1, 1, 0},
        {0, 0, 0, 1}
    };
    
    cout << "\nMatrix 2:" << endl;
    for (auto& row : mat2) {
        for (int val : row) cout << val << " ";
        cout << endl;
    }
    cout << "Longest line: " << sol.longestLine(mat2) << endl;
    
    return 0;
}

/*
INPUT:
mat = [[0,1,1,0],
       [0,1,1,0],
       [0,0,0,1]]

OUTPUT:
2

EXPLANATION:
Check all four directions:

Horizontal lines:
Row 0: 1,1 (length 2) ✓
Row 1: 1,1 (length 2) ✓
Row 2: 1 (length 1)

Vertical lines:
Col 1: 1,1 (length 2) ✓
Col 2: 1,1 (length 2) ✓
Col 3: 1 (length 1)

Diagonal lines (↘):
(0,1)→(1,2) = 1,1 (length 2) ✓
All others: length 1

Anti-diagonal lines (↙):
All: length 1

Maximum: 2

For mat2:
INPUT:
mat = [[1,1,1,1],
       [0,1,1,0],
       [0,0,0,1]]

OUTPUT:
4

EXPLANATION:
Horizontal line in row 0: 1,1,1,1 (length 4) ✓

DP table for horizontal direction:
1  2  3  4
0  1  2  0
0  0  0  1

Maximum across all directions: 4
*/
