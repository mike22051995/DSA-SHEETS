/*
PROBLEM: Count Square Submatrices with All Ones (LeetCode 1277)
Difficulty: Medium
Company: Google, Meta, Amazon
Pattern: Dynamic Programming on Matrix

DESCRIPTION:
Given an m x n binary matrix, return the number of square submatrices 
that have all ones.

MATRIX DIAGRAM:
  Matrix:              DP (square count ending here):
  0  1  1  1           0  1  1  1
  1  1  1  1    -->    1  1  2  2
  0  1  1  1           0  1  2  3
  
  Squares at (2,3):
  - 1×1: [1]
  - 2×2: [[1,1],[1,1]]
  - 3×3: [[1,1,1],[1,1,1],[1,1,1]]
  
  Total squares: 0+1+1+1+1+1+2+2+0+1+2+3 = 15

APPROACH:
1. dp[i][j] = number of squares with bottom-right corner at (i,j)
2. This equals the side length of largest square ending at (i,j)
3. Formula: dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1
4. Sum all dp values for total count

TIME COMPLEXITY: O(M * N)
SPACE COMPLEXITY: O(M * N) or O(N) with optimization
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        if (matrix.empty()) return 0;
        
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int totalCount = 0;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 1) {
                    if (i == 0 || j == 0) {
                        dp[i][j] = 1;
                    } else {
                        dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
                    }
                    totalCount += dp[i][j];
                }
            }
        }
        
        return totalCount;
    }
    
    // Space optimized version
    int countSquaresOptimized(vector<vector<int>>& matrix) {
        if (matrix.empty()) return 0;
        
        int m = matrix.size();
        int n = matrix[0].size();
        int totalCount = 0;
        
        // Use matrix itself for DP (in-place)
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 1 && i > 0 && j > 0) {
                    matrix[i][j] = min({matrix[i-1][j], matrix[i][j-1], matrix[i-1][j-1]}) + 1;
                }
                totalCount += matrix[i][j];
            }
        }
        
        return totalCount;
    }
};

int main() {
    Solution sol;
    
    vector<vector<int>> matrix = {
        {0, 1, 1, 1},
        {1, 1, 1, 1},
        {0, 1, 1, 1}
    };
    
    cout << "Count of square submatrices: " << sol.countSquares(matrix) << endl;
    
    return 0;
}

/*
INPUT:
matrix = [[0,1,1,1],
          [1,1,1,1],
          [0,1,1,1]]

OUTPUT:
15

EXPLANATION:
1×1 squares: 10 squares (count of all 1's)
2×2 squares: 4 squares at positions (1,1), (1,2), (1,3), (2,2)
3×3 squares: 1 square at position (2,3)
Total: 10 + 4 + 1 = 15

DP table breakdown:
[0, 1, 1, 1]  → contributes 0+1+1+1 = 3
[1, 1, 2, 2]  → contributes 1+1+2+2 = 6
[0, 1, 2, 3]  → contributes 0+1+2+3 = 6
Total: 15

Another example:
Input: [[1,0,1],[1,1,0],[1,1,0]]
Output: 7 (six 1×1 and one 2×2)
*/
