/*
PROBLEM: Spiral Matrix (LeetCode 54)
Difficulty: Medium
Company: Microsoft, Google, Meta, Amazon, Netflix
Pattern: Matrix Traversal

DESCRIPTION:
Given an m x n matrix, return all elements of the matrix in spiral order.

MATRIX DIAGRAM:
  Input Matrix:              Spiral Order:
  1  2  3  4                 1 → 2 → 3 → 4
  5  6  7  8          -->        ↓       ↓
  9  10 11 12                9 → 10→ 11  8
                             ↓           ↑
  Output: [1,2,3,4,8,12,11,10,9,5,6,7]  5 → 6 → 7
  
  Direction: Right → Down → Left → Up (repeat)
  Track boundaries: top, bottom, left, right

APPROACH:
1. Use four pointers: top, bottom, left, right
2. Traverse right: left to right (top row)
3. Traverse down: top to bottom (right column)
4. Traverse left: right to left (bottom row)
5. Traverse up: bottom to top (left column)
6. Shrink boundaries after each traversal

TIME COMPLEXITY: O(M * N)
SPACE COMPLEXITY: O(1) excluding output array
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty()) return {};
        
        vector<int> result;
        int top = 0, bottom = matrix.size() - 1;
        int left = 0, right = matrix[0].size() - 1;
        
        while (top <= bottom && left <= right) {
            // Traverse right
            for (int col = left; col <= right; col++) {
                result.push_back(matrix[top][col]);
            }
            top++;
            
            // Traverse down
            for (int row = top; row <= bottom; row++) {
                result.push_back(matrix[row][right]);
            }
            right--;
            
            // Traverse left (if there's a row remaining)
            if (top <= bottom) {
                for (int col = right; col >= left; col--) {
                    result.push_back(matrix[bottom][col]);
                }
                bottom--;
            }
            
            // Traverse up (if there's a column remaining)
            if (left <= right) {
                for (int row = bottom; row >= top; row--) {
                    result.push_back(matrix[row][left]);
                }
                left++;
            }
        }
        
        return result;
    }
};

int main() {
    Solution sol;
    
    vector<vector<int>> matrix = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    
    vector<int> result = sol.spiralOrder(matrix);
    
    cout << "Spiral Order: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}

/*
INPUT:
matrix = [[1,2,3,4],
          [5,6,7,8],
          [9,10,11,12]]

OUTPUT:
[1,2,3,4,8,12,11,10,9,5,6,7]

EXPLANATION:
Step 1: Traverse right on top row: 1, 2, 3, 4
Step 2: Traverse down on right column: 8, 12
Step 3: Traverse left on bottom row: 11, 10, 9
Step 4: Traverse up on left column: 5
Step 5: Traverse right on remaining: 6, 7
*/
