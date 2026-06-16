/*
PROBLEM: Toeplitz Matrix (LeetCode 766)
Difficulty: Easy
Company: Google, Meta, Amazon
Pattern: Matrix Diagonal Check

DESCRIPTION:
A matrix is Toeplitz if every diagonal from top-left to bottom-right has the same elements.
Given an m x n matrix, return true if it is Toeplitz, false otherwise.

MATRIX DIAGRAM:
  Toeplitz Matrix:              Not Toeplitz:
  1  2  3  4                    1  2  3
  5  1  2  3           -->      4  1  2
  9  5  1  2                    5  4  1
  
  Diagonals:                    Diagonal check:
  [1,1,1]   ✓                   [1,1,1] ✓ same
  [2,2,2]   ✓                   [2,2] ✓ same
  [3,3]     ✓                   [3] ✓
  [4]       ✓                   [4,4] ✗ not same (4≠5)
  All same → Toeplitz!
  
  Check: matrix[i][j] == matrix[i-1][j-1] for all valid i,j

APPROACH:
Method 1: Compare with Top-Left Neighbor
- For each cell (i,j) where i > 0 and j > 0
- Check if matrix[i][j] == matrix[i-1][j-1]
- If any mismatch, return false

Method 2: Check Each Diagonal
- Start from first row and first column
- For each starting position, check entire diagonal

Follow-up: What if matrix is stored on disk and memory is limited?
- Load one row at a time and compare with previous row

TIME COMPLEXITY: O(M * N)
SPACE COMPLEXITY: O(1)
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        // Check each element with its top-left neighbor
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] != matrix[i-1][j-1]) {
                    return false;
                }
            }
        }
        
        return true;
    }
    
    // Alternative: Check each diagonal
    bool isToeplitzMatrixDiagonal(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        // Check diagonals starting from first row
        for (int col = 0; col < n; col++) {
            if (!checkDiagonal(matrix, 0, col)) {
                return false;
            }
        }
        
        // Check diagonals starting from first column (skip [0][0])
        for (int row = 1; row < m; row++) {
            if (!checkDiagonal(matrix, row, 0)) {
                return false;
            }
        }
        
        return true;
    }
    
    bool checkDiagonal(vector<vector<int>>& matrix, int row, int col) {
        int m = matrix.size();
        int n = matrix[0].size();
        int val = matrix[row][col];
        
        while (row < m && col < n) {
            if (matrix[row][col] != val) {
                return false;
            }
            row++;
            col++;
        }
        
        return true;
    }
};

int main() {
    Solution sol;
    
    // Example 1: Toeplitz matrix
    vector<vector<int>> matrix1 = {
        {1, 2, 3, 4},
        {5, 1, 2, 3},
        {9, 5, 1, 2}
    };
    
    cout << "Matrix 1 is Toeplitz: " 
         << (sol.isToeplitzMatrix(matrix1) ? "Yes" : "No") << endl;
    
    // Example 2: Not Toeplitz
    vector<vector<int>> matrix2 = {
        {1, 2},
        {2, 2}
    };
    
    cout << "Matrix 2 is Toeplitz: " 
         << (sol.isToeplitzMatrix(matrix2) ? "Yes" : "No") << endl;
    
    return 0;
}

/*
INPUT:
matrix = [[1,2,3,4],
          [5,1,2,3],
          [9,5,1,2]]

OUTPUT:
true

EXPLANATION:
Check all diagonals from top-left to bottom-right:
- Diagonal [1,1,1]: All elements are 1 ✓
- Diagonal [2,2,2]: All elements are 2 ✓
- Diagonal [3,3]: All elements are 3 ✓
- Diagonal [4]: Single element ✓
- Diagonal [5,5]: All elements are 5 ✓
- Diagonal [9]: Single element ✓

For matrix2:
INPUT: [[1,2],[2,2]]
OUTPUT: false
EXPLANATION:
Diagonal [1,2] has different elements (1 ≠ 2)

Follow-up for disk storage:
Load matrix[i] and matrix[i-1] into memory
Compare matrix[i][j] with matrix[i-1][j-1]
Only need 2 rows in memory at a time
*/
