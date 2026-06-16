/*
PROBLEM: Rotate Image (LeetCode 48)
Difficulty: Medium
Company: Microsoft, Google, Meta, Amazon
Pattern: Matrix Manipulation

DESCRIPTION:
You are given an n x n 2D matrix representing an image.
Rotate the image by 90 degrees (clockwise) in-place.

MATRIX DIAGRAM:
  Original:          After Rotation 90° clockwise:
  1  2  3            7  4  1
  4  5  6     -->    8  5  2
  7  8  9            9  6  3
  
  Two-Step Process:
  Step 1 - Transpose:  Step 2 - Reverse each row:
  1  4  7              7  4  1
  2  5  8      -->     8  5  2
  3  6  9              9  6  3

APPROACH:
1. Transpose the matrix (swap matrix[i][j] with matrix[j][i])
2. Reverse each row
Alternative: Rotate layer by layer from outside to inside

TIME COMPLEXITY: O(N²)
SPACE COMPLEXITY: O(1) - in-place rotation
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        // Step 1: Transpose the matrix
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        
        // Step 2: Reverse each row
        for (int i = 0; i < n; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
    
    // Alternative: Layer by layer rotation
    void rotateLayers(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        for (int layer = 0; layer < n / 2; layer++) {
            int first = layer;
            int last = n - 1 - layer;
            
            for (int i = first; i < last; i++) {
                int offset = i - first;
                
                // Save top
                int top = matrix[first][i];
                
                // Left -> Top
                matrix[first][i] = matrix[last - offset][first];
                
                // Bottom -> Left
                matrix[last - offset][first] = matrix[last][last - offset];
                
                // Right -> Bottom
                matrix[last][last - offset] = matrix[i][last];
                
                // Top -> Right
                matrix[i][last] = top;
            }
        }
    }
};

int main() {
    Solution sol;
    
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    cout << "Original Matrix:" << endl;
    for (auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    
    sol.rotate(matrix);
    
    cout << "\nRotated Matrix (90° clockwise):" << endl;
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
matrix = [[1,2,3],
          [4,5,6],
          [7,8,9]]

OUTPUT:
[[7,4,1],
 [8,5,2],
 [9,6,3]]

EXPLANATION:
For 90° clockwise rotation:
- Top row becomes right column
- Right column becomes bottom row (reversed)
- Bottom row becomes left column
- Left column becomes top row (reversed)

For other rotations:
- 90° counter-clockwise: Reverse rows first, then transpose
- 180°: Reverse rows, then reverse each row
- 270° clockwise: Same as 90° counter-clockwise
*/
