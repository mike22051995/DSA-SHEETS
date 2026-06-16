/*
PROBLEM: Longest Increasing Path in Matrix (LeetCode 329)
Difficulty: Hard
Company: Google, Meta, Microsoft, Amazon
Pattern: DFS with Memoization (DP on Matrix)

DESCRIPTION:
Given an m x n matrix, return the length of the longest increasing path.
From each cell, you can move in 4 directions (up, down, left, right).
You cannot move diagonally or outside the boundary.

MATRIX DIAGRAM:
  Matrix:              Longest Paths:
  9  9  4              1  1  2  ← from 4
  6  6  8       -->    2  2  3  ← from 8
  2  1  1              4  3  3  ← from 2
  
  Longest Path: 2 → 6 → 9 (length = 3) or 1 → 2 → 6 → 9 (length = 4)
  Answer: 4
  
  DFS with Memoization:
  For each cell (i,j):
  - Try all 4 directions
  - Only move to cells with larger values
  - Cache results to avoid recomputation

APPROACH:
1. Use DFS from each cell
2. Only explore neighbors with larger values (increasing path)
3. Memoize results to avoid recomputation
4. dp[i][j] = longest path starting from (i,j)
5. Return maximum among all cells

TIME COMPLEXITY: O(M * N) - each cell computed once due to memoization
SPACE COMPLEXITY: O(M * N) for memoization cache
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int dfs(vector<vector<int>>& matrix, vector<vector<int>>& memo, int i, int j) {
        // Return cached result
        if (memo[i][j] != 0) {
            return memo[i][j];
        }
        
        int m = matrix.size();
        int n = matrix[0].size();
        int maxLength = 1;
        
        // Directions: up, down, left, right
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        // Try all 4 directions
        for (auto& dir : dirs) {
            int ni = i + dir[0];
            int nj = j + dir[1];
            
            // Check bounds and increasing condition
            if (ni >= 0 && ni < m && nj >= 0 && nj < n 
                && matrix[ni][nj] > matrix[i][j]) {
                int length = 1 + dfs(matrix, memo, ni, nj);
                maxLength = max(maxLength, length);
            }
        }
        
        // Cache and return
        memo[i][j] = maxLength;
        return maxLength;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty()) return 0;
        
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> memo(m, vector<int>(n, 0));
        
        int result = 0;
        
        // Try starting from each cell
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                result = max(result, dfs(matrix, memo, i, j));
            }
        }
        
        return result;
    }
};

int main() {
    Solution sol;
    
    vector<vector<int>> matrix1 = {
        {9, 9, 4},
        {6, 6, 8},
        {2, 1, 1}
    };
    
    cout << "Longest Increasing Path: " << sol.longestIncreasingPath(matrix1) << endl;
    
    vector<vector<int>> matrix2 = {
        {3, 4, 5},
        {3, 2, 6},
        {2, 2, 1}
    };
    
    cout << "Longest Increasing Path: " << sol.longestIncreasingPath(matrix2) << endl;
    
    return 0;
}

/*
INPUT:
matrix = [[9,9,4],
          [6,6,8],
          [2,1,1]]

OUTPUT:
4

EXPLANATION:
Longest path: 1 → 2 → 6 → 9
Path: (2,1) → (2,0) → (1,0) → (0,0)
Length: 4

Another path: 1 → 2 → 8 → 9 (also length 4)

For matrix2:
INPUT: [[3,4,5],
        [3,2,6],
        [2,2,1]]
OUTPUT: 4
Path: 3 → 4 → 5 → 6
*/
