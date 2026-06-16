/*
PROBLEM: Transpose Matrix (LeetCode 867)
Difficulty: Easy
Company: Google, Meta, Amazon
Pattern: Matrix Manipulation

DESCRIPTION:
Given a 2D integer array matrix, return the transpose of matrix.
The transpose of a matrix is obtained by flipping the matrix over its main diagonal,
switching rows with columns.

MATRIX DIAGRAM:
  Original Matrix:     Transposed Matrix:
  1  2  3              1  4  7
  4  5  6       -->    2  5  8
  7  8  9              3  6  9
  
  Swap positions: matrix[i][j] ↔ matrix[j][i]
  
  Non-square example:
  1  2  3              1  4
  4  5  6       -->    2  5
                       3  6
  (2×3 becomes 3×2)

APPROACH:
1. Create new matrix with swapped dimensions (n × m)
2. Fill: result[j][i] = matrix[i][j]
3. For square matrices, can do in-place by swapping upper and lower triangles

TIME COMPLEXITY: O(M * N)
SPACE COMPLEXITY: O(M * N) for new matrix
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        // Create transposed matrix with swapped dimensions
        vector<vector<int>> result(n, vector<int>(m));
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                result[j][i] = matrix[i][j];
            }
        }
        
        return result;
    }
    
    // In-place transpose for square matrix
    void transposeInPlace(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if (n == 0 || n != matrix[0].size()) return;  // Only for square matrix
        
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};

int main() {
    Solution sol;
    
    // Example 1: Square matrix
    vector<vector<int>> matrix1 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    cout << "Original Matrix:" << endl;
    for (auto& row : matrix1) {
        for (int val : row) cout << val << " ";
        cout << endl;
    }
    
    vector<vector<int>> transposed1 = sol.transpose(matrix1);
    
    cout << "\nTransposed Matrix:" << endl;
    for (auto& row : transposed1) {
        for (int val : row) cout << val << " ";
        cout << endl;
    }
    
    // Example 2: Non-square matrix
    vector<vector<int>> matrix2 = {
        {1, 2, 3},
        {4, 5, 6}
    };
    
    cout << "\nOriginal Matrix (2×3):" << endl;
    for (auto& row : matrix2) {
        for (int val : row) cout << val << " ";
        cout << endl;
    }
    
    vector<vector<int>> transposed2 = sol.transpose(matrix2);
    
    cout << "\nTransposed Matrix (3×2):" << endl;
    for (auto& row : transposed2) {
        for (int val : row) cout << val << " ";
        cout << endl;
    }
    
    return 0;
}

/*
INPUT:
matrix = [[1,2,3],
          [4,5,6],
          [7,8,9]]

OUTPUT:
[[1,4,7],
 [2,5,8],
 [3,6,9]]

EXPLANATION:
The transpose flips the matrix over its main diagonal:
- Row 0 becomes Column 0: [1,2,3] → [1,4,7]
- Row 1 becomes Column 1: [4,5,6] → [2,5,8]
- Row 2 becomes Column 2: [7,8,9] → [3,6,9]

For non-square matrix:
INPUT: [[1,2,3],[4,5,6]]
OUTPUT: [[1,4],[2,5],[3,6]]
Dimensions change from 2×3 to 3×2
*/
