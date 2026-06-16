/*
================================================================================
PROBLEM: Rotate Image (LeetCode #48)
DIFFICULTY: Medium
PATTERN: Matrix Manipulation
COMPANIES: Amazon, Microsoft, Google, Facebook, Apple
================================================================================
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Transpose then reverse each row
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        // Transpose
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        
        // Reverse each row
        for (int i = 0; i < n; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
    
    // Layer by layer rotation
    void rotateLayered(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        for (int layer = 0; layer < n / 2; layer++) {
            int first = layer;
            int last = n - 1 - layer;
            
            for (int i = first; i < last; i++) {
                int offset = i - first;
                
                int top = matrix[first][i];
                
                // left -> top
                matrix[first][i] = matrix[last - offset][first];
                
                // bottom -> left
                matrix[last - offset][first] = matrix[last][last - offset];
                
                // right -> bottom
                matrix[last][last - offset] = matrix[i][last];
                
                // top -> right
                matrix[i][last] = top;
            }
        }
    }
};

int main() {
    Solution sol;
    vector<vector<int>> matrix = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    
    sol.rotate(matrix);
    
    cout << "Rotated matrix:" << endl;
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
1. Rotate Array (LeetCode #189)
2. Spiral Matrix (LeetCode #54)
3. Spiral Matrix II (LeetCode #59)
4. Set Matrix Zeroes (LeetCode #73)
5. Transpose Matrix (LeetCode #867)
6. Reshape the Matrix (LeetCode #566)
7. Flip Image Horizontally (LeetCode #832)
8. Determine Whether Matrix Can Be Obtained By Rotation (LeetCode #1886)
9. Shift 2D Grid (LeetCode #1260)
10. Check if Every Row and Column Contains All Numbers (LeetCode #2133)
*/
