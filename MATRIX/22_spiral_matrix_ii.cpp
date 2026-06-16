/*
PROBLEM: Spiral Matrix II (LeetCode 59)
Difficulty: Medium
Company: Microsoft, Google, Meta, Amazon
Pattern: Matrix Generation - Spiral Pattern

DESCRIPTION:
Given a positive integer n, generate an n x n matrix filled with elements 
from 1 to n² in spiral order.

MATRIX DIAGRAM:
  n = 3:                 n = 4:
  1  2  3                1   2   3   4
  8  9  4         -->    12  13  14  5
  7  6  5                11  16  15  6
                         10  9   8   7
  
  Fill pattern:
  Right → Down → Left → Up → (repeat, shrink boundaries)
  
  Boundaries:
  top=0, bottom=n-1, left=0, right=n-1
  Shrink after each direction

APPROACH:
1. Initialize matrix n×n with zeros
2. Use four boundaries: top, bottom, left, right
3. Fill in spiral order:
   - Right: left to right on top row
   - Down: top to bottom on right column
   - Left: right to left on bottom row
   - Up: bottom to top on left column
4. Shrink boundaries after each direction
5. Continue until all cells filled

TIME COMPLEXITY: O(N²)
SPACE COMPLEXITY: O(N²) for output matrix (O(1) excluding output)
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n));
        
        int top = 0, bottom = n - 1;
        int left = 0, right = n - 1;
        int num = 1;
        
        while (top <= bottom && left <= right) {
            // Fill top row (left to right)
            for (int col = left; col <= right; col++) {
                matrix[top][col] = num++;
            }
            top++;
            
            // Fill right column (top to bottom)
            for (int row = top; row <= bottom; row++) {
                matrix[row][right] = num++;
            }
            right--;
            
            // Fill bottom row (right to left)
            if (top <= bottom) {
                for (int col = right; col >= left; col--) {
                    matrix[bottom][col] = num++;
                }
                bottom--;
            }
            
            // Fill left column (bottom to top)
            if (left <= right) {
                for (int row = bottom; row >= top; row--) {
                    matrix[row][left] = num++;
                }
                left++;
            }
        }
        
        return matrix;
    }
    
    // Alternative: Direction-based approach
    vector<vector<int>> generateMatrixDirection(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        
        int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // right, down, left, up
        int dir = 0;
        int row = 0, col = 0;
        
        for (int num = 1; num <= n * n; num++) {
            matrix[row][col] = num;
            
            // Try to continue in current direction
            int nrow = row + dirs[dir][0];
            int ncol = col + dirs[dir][1];
            
            // If hit boundary or filled cell, change direction
            if (nrow < 0 || nrow >= n || ncol < 0 || ncol >= n || matrix[nrow][ncol] != 0) {
                dir = (dir + 1) % 4; // Turn right
                nrow = row + dirs[dir][0];
                ncol = col + dirs[dir][1];
            }
            
            row = nrow;
            col = ncol;
        }
        
        return matrix;
    }
};

int main() {
    Solution sol;
    
    int n = 3;
    vector<vector<int>> matrix = sol.generateMatrix(n);
    
    cout << "Spiral Matrix (" << n << "×" << n << "):" << endl;
    for (auto& row : matrix) {
        for (int val : row) {
            cout << val << "\t";
        }
        cout << endl;
    }
    
    cout << "\n";
    n = 4;
    matrix = sol.generateMatrix(n);
    
    cout << "Spiral Matrix (" << n << "×" << n << "):" << endl;
    for (auto& row : matrix) {
        for (int val : row) {
            cout << val << "\t";
        }
        cout << endl;
    }
    
    return 0;
}

/*
INPUT:
n = 3

OUTPUT:
[[1,2,3],
 [8,9,4],
 [7,6,5]]

EXPLANATION:
Step-by-step filling:
1. Fill top row: 1, 2, 3
2. Fill right column: 4, 5
3. Fill bottom row: 6, 7
4. Fill left column: 8
5. Fill center: 9

For n = 4:
OUTPUT:
[[1,2,3,4],
 [12,13,14,5],
 [11,16,15,6],
 [10,9,8,7]]

Outer spiral: 1→2→3→4→5→6→7→8→9→10→11→12
Inner spiral: 13→14→15→16

For n = 1:
OUTPUT: [[1]]
*/
