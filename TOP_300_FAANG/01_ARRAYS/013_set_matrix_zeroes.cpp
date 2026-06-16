/*
================================================================================
PROBLEM: Set Matrix Zeroes (LeetCode #73)
DIFFICULTY: Medium
PATTERN: Matrix In-place Modification
COMPANIES: Amazon, Microsoft, Facebook, Google, Apple
================================================================================
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // O(1) space solution
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        bool firstRowZero = false, firstColZero = false;
        
        // Check if first row has zero
        for (int j = 0; j < n; j++) {
            if (matrix[0][j] == 0) {
                firstRowZero = true;
                break;
            }
        }
        
        // Check if first column has zero
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
        
        // Set zeroes based on markers
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
        {1,1,1},
        {1,0,1},
        {1,1,1}
    };
    
    sol.setZeroes(matrix);
    
    cout << "Matrix after setting zeroes:" << endl;
    for (auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Rotate Image (LeetCode #48)
2. Spiral Matrix (LeetCode #54)
3. Game of Life (LeetCode #289)
4. Number of Laser Beams (LeetCode #2125)
5. Cells with Odd Values (LeetCode #1252)
6. Shift 2D Grid (LeetCode #1260)
7. Matrix Diagonal Sum (LeetCode #1572)
8. Lucky Numbers in Matrix (LeetCode #1380)
9. Where Will Ball Fall (LeetCode #1706)
10. Check if Matrix Is X-Matrix (LeetCode #2319)
*/
