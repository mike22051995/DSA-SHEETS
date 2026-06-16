/*
PROBLEM: Set Matrix Zeroes (LeetCode 73)
Difficulty: Medium
Company: Microsoft, Google, Meta, Amazon, Netflix
Pattern: Matrix In-place Modification

DESCRIPTION:
Given an m x n matrix, if an element is 0, set its entire row and column to 0.
Do it in-place with O(1) space.

MATRIX DIAGRAM:
  Input:              Output:
  1  1  1             1  0  1
  1  0  1      -->    0  0  0
  1  1  1             1  0  1
  
  Element at (1,1) is 0:
  - Row 1 becomes all zeros
  - Column 1 becomes all zeros
  
  Use first row and column as markers:
  Initial:       After marking:    After zeroing:
  1  1  1        1  0  1            1  0  1
  1  0  1   -->  0  0  1       -->  0  0  0
  1  1  1        1  0  1            1  0  1

APPROACH:
1. Use first row and column as markers
2. Use separate variables for first row and column themselves
3. Mark zeros in first row/column
4. Use markers to set zeros in rest of matrix
5. Finally handle first row and column

TIME COMPLEXITY: O(M * N)
SPACE COMPLEXITY: O(1)
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if (matrix.empty()) return;
        
        int m = matrix.size();
        int n = matrix[0].size();
        bool firstRowZero = false;
        bool firstColZero = false;
        
        // Check if first row has any zeros
        for (int j = 0; j < n; j++) {
            if (matrix[0][j] == 0) {
                firstRowZero = true;
                break;
            }
        }
        
        // Check if first column has any zeros
        for (int i = 0; i < m; i++) {
            if (matrix[i][0] == 0) {
                firstColZero = true;
                break;
            }
        }
        
        // Use first row and column as markers
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        // Set zeros based on markers
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        
        // Handle first row
        if (firstRowZero) {
            for (int j = 0; j < n; j++) {
                matrix[0][j] = 0;
            }
        }
        
        // Handle first column
        if (firstColZero) {
            for (int i = 0; i < m; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};

int main() {
    Solution sol;
    
    vector<vector<int>> matrix = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}
    };
    
    cout << "Original Matrix:" << endl;
    for (auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    
    sol.setZeroes(matrix);
    
    cout << "\nAfter Setting Zeroes:" << endl;
    for (auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    
    return 0;
}

/*
INPUT:
matrix = [[1,1,1],
          [1,0,1],
          [1,1,1]]

OUTPUT:
[[1,0,1],
 [0,0,0],
 [1,0,1]]

EXPLANATION:
The element at position (1,1) is 0.
This causes:
- Entire row 1 to become zeros: [0,0,0]
- Entire column 1 to become zeros: column with index 1

Multiple zeros example:
Input:  [[0,1,2,0],    Output: [[0,0,0,0],
         [3,4,5,2],             [0,4,5,0],
         [1,3,1,5]]             [0,3,1,0]]
*/
