/*
PROBLEM: Reshape the Matrix (LeetCode 566)
Difficulty: Easy
Company: Microsoft, Amazon, Google
Pattern: Matrix Manipulation

DESCRIPTION:
You are given an m x n matrix and two integers r and c representing 
the number of rows and columns of the wanted reshaped matrix.
Return the reshaped matrix if possible, otherwise return the original matrix.

MATRIX DIAGRAM:
  Original (2×2):      Reshape to (1×4):
  1  2                 1  2  3  4
  3  4          -->    
  
  Original (2×2):      Reshape to (4×1):
  1  2                 1
  3  4          -->    2
                       3
                       4
  
  Impossible reshape (2×2 to 2×3):
  1  2                 Original returned (can't fit 4 elements into 6)
  3  4          -->    

APPROACH:
1. Check if reshape is possible: m * n must equal r * c
2. Flatten original matrix into 1D array
3. Fill new matrix with r rows and c columns
4. Alternative: Use index mapping without extra space

Index mapping:
- Position in original: (i, j) → flat_index = i * n + j
- Position in reshaped: flat_index → new_i = flat_index / c, new_j = flat_index % c

TIME COMPLEXITY: O(M * N)
SPACE COMPLEXITY: O(1) with index mapping, O(M*N) with flattening
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size();
        int n = mat[0].size();
        
        // Check if reshape is possible
        if (m * n != r * c) {
            return mat;
        }
        
        vector<vector<int>> reshaped(r, vector<int>(c));
        
        int row = 0, col = 0;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                reshaped[row][col] = mat[i][j];
                col++;
                if (col == c) {
                    col = 0;
                    row++;
                }
            }
        }
        
        return reshaped;
    }
    
    // Using index mapping
    vector<vector<int>> matrixReshapeMapping(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size();
        int n = mat[0].size();
        
        if (m * n != r * c) {
            return mat;
        }
        
        vector<vector<int>> reshaped(r, vector<int>(c));
        
        for (int i = 0; i < m * n; i++) {
            // Original position
            int origRow = i / n;
            int origCol = i % n;
            
            // New position
            int newRow = i / c;
            int newCol = i % c;
            
            reshaped[newRow][newCol] = mat[origRow][origCol];
        }
        
        return reshaped;
    }
};

int main() {
    Solution sol;
    
    // Example 1: 2×2 to 1×4
    vector<vector<int>> mat1 = {
        {1, 2},
        {3, 4}
    };
    
    cout << "Original Matrix (2×2):" << endl;
    for (auto& row : mat1) {
        for (int val : row) cout << val << " ";
        cout << endl;
    }
    
    vector<vector<int>> reshaped1 = sol.matrixReshape(mat1, 1, 4);
    
    cout << "\nReshaped Matrix (1×4):" << endl;
    for (auto& row : reshaped1) {
        for (int val : row) cout << val << " ";
        cout << endl;
    }
    
    // Example 2: 2×2 to 4×1
    vector<vector<int>> reshaped2 = sol.matrixReshape(mat1, 4, 1);
    
    cout << "\nReshaped Matrix (4×1):" << endl;
    for (auto& row : reshaped2) {
        for (int val : row) cout << val << " ";
        cout << endl;
    }
    
    // Example 3: Impossible reshape
    vector<vector<int>> reshaped3 = sol.matrixReshape(mat1, 2, 3);
    
    cout << "\nImpossible Reshape (2×3) - Returns Original:" << endl;
    for (auto& row : reshaped3) {
        for (int val : row) cout << val << " ";
        cout << endl;
    }
    
    return 0;
}

/*
INPUT:
mat = [[1,2],
       [3,4]]
r = 1, c = 4

OUTPUT:
[[1,2,3,4]]

EXPLANATION:
Original has 2*2 = 4 elements
Reshaped needs 1*4 = 4 elements
Possible! Fill row by row: [1,2,3,4]

For r=4, c=1:
OUTPUT: [[1],[2],[3],[4]]

For r=2, c=3:
Original: 2*2 = 4 elements
Needed: 2*3 = 6 elements
Impossible! Return original matrix

Another example:
INPUT: mat = [[1,2,3,4]], r = 2, c = 2
OUTPUT: [[1,2],[3,4]]
*/
