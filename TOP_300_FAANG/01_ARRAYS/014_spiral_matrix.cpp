/*
================================================================================
PROBLEM: Spiral Matrix (LeetCode #54)
DIFFICULTY: Medium
PATTERN: Matrix Traversal / Simulation
COMPANIES: Amazon, Microsoft, Facebook, Google, Apple
================================================================================
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if (matrix.empty()) return result;
        
        int top = 0, bottom = matrix.size() - 1;
        int left = 0, right = matrix[0].size() - 1;
        
        while (top <= bottom && left <= right) {
            // Traverse right
            for (int j = left; j <= right; j++) {
                result.push_back(matrix[top][j]);
            }
            top++;
            
            // Traverse down
            for (int i = top; i <= bottom; i++) {
                result.push_back(matrix[i][right]);
            }
            right--;
            
            // Traverse left (if still valid row)
            if (top <= bottom) {
                for (int j = right; j >= left; j--) {
                    result.push_back(matrix[bottom][j]);
                }
                bottom--;
            }
            
            // Traverse up (if still valid column)
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    result.push_back(matrix[i][left]);
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
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    
    auto result = sol.spiralOrder(matrix);
    
    cout << "Spiral order: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Spiral Matrix II (LeetCode #59)
2. Spiral Matrix III (LeetCode #885)
3. Spiral Matrix IV (LeetCode #2326)
4. Rotate Image (LeetCode #48)
5. Set Matrix Zeroes (LeetCode #73)
6. Diagonal Traverse (LeetCode #498)
7. Print Matrix Diagonally (Multiple Variants)
8. Robot Bounded In Circle (LeetCode #1041)
9. Where Will Ball Fall (LeetCode #1706)
10. Determine Whether Matrix Can Be Obtained By Rotation (LeetCode #1886)
*/
