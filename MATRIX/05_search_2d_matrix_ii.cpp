/*
PROBLEM: Search a 2D Matrix II (LeetCode 240)
Difficulty: Medium
Company: Google, Meta, Amazon, Microsoft
Pattern: Matrix Search with Elimination

DESCRIPTION:
Write an efficient algorithm that searches for a value in an m x n matrix.
Properties:
- Integers in each row are sorted in ascending from left to right
- Integers in each column are sorted in ascending from top to bottom

MATRIX DIAGRAM:
  Matrix:                Target = 5
  1   4   7   11  15     Start from top-right (or bottom-left)
  2   5   8   12  19     
  3   6   9   16  22     Current = 15 > 5, move left
  10  13  14  17  24     Current = 11 > 5, move left
  18  21  23  26  30     Current = 7 > 5, move left
                         Current = 4 < 5, move down
  Top-Right Strategy:    Current = 5 = 5 ✓ Found!
  - If current > target: Move left (eliminate column)
  - If current < target: Move down (eliminate row)
  - If current = target: Found!

APPROACH:
Start from top-right corner (or bottom-left):
1. If current element equals target, return true
2. If current element > target, move left (smaller values)
3. If current element < target, move down (larger values)
4. This eliminates one row or column in each step

TIME COMPLEXITY: O(M + N)
SPACE COMPLEXITY: O(1)
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        // Start from top-right corner
        int row = 0;
        int col = n - 1;
        
        while (row < m && col >= 0) {
            if (matrix[row][col] == target) {
                return true;
            } else if (matrix[row][col] > target) {
                col--; // Move left
            } else {
                row++; // Move down
            }
        }
        
        return false;
    }
    
    // Alternative: Start from bottom-left
    bool searchMatrixBottomLeft(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        // Start from bottom-left corner
        int row = m - 1;
        int col = 0;
        
        while (row >= 0 && col < n) {
            if (matrix[row][col] == target) {
                return true;
            } else if (matrix[row][col] > target) {
                row--; // Move up
            } else {
                col++; // Move right
            }
        }
        
        return false;
    }
};

int main() {
    Solution sol;
    
    vector<vector<int>> matrix = {
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };
    
    int target = 5;
    cout << "Searching for " << target << ": " 
         << (sol.searchMatrix(matrix, target) ? "Found" : "Not Found") << endl;
    
    target = 20;
    cout << "Searching for " << target << ": " 
         << (sol.searchMatrix(matrix, target) ? "Found" : "Not Found") << endl;
    
    return 0;
}

/*
INPUT:
matrix = [[1,4,7,11,15],
          [2,5,8,12,19],
          [3,6,9,16,22],
          [10,13,14,17,24],
          [18,21,23,26,30]]
target = 5

OUTPUT:
true

EXPLANATION:
Starting from top-right (15):
15 > 5 → move left to 11
11 > 5 → move left to 7
7 > 5 → move left to 4
4 < 5 → move down to 5
5 = 5 → Found!

Path: (0,4) → (0,3) → (0,2) → (0,1) → (1,1)

For target = 20:
OUTPUT: false
20 is not in the matrix
*/
