/*
PROBLEM: Diagonal Traverse (LeetCode 498)
Difficulty: Medium
Company: Google, Meta, Amazon
Pattern: Matrix Diagonal Traversal

DESCRIPTION:
Given an m x n matrix, return an array of all elements in diagonal order.

MATRIX DIAGRAM:
  Matrix:              Diagonal Order:
  1  2  3              Direction alternates:
  4  5  6       -->    ↗ 1
  7  8  9              ↙ 2 4
                       ↗ 7 5 3
  Output: [1,2,4,7,5,3,6,8,9]  ↙ 6 8
                       ↗ 9
  Pattern:
  - Diagonals going up-right: d0[1], d1[2,4], d2[7,5,3]
  - Diagonals going down-left: d3[6,8], d4[9]
  - Direction alternates each diagonal
  - Diagonal sum: i + j (determines which diagonal)

APPROACH:
Method 1: Simulation with direction changes
1. Start at (0,0), direction = up-right
2. Move diagonally until boundary
3. When hitting boundary, change direction and adjust position
4. Continue until all elements visited

Method 2: Group by diagonal sum
1. Elements with same i+j are on same diagonal
2. For even sum diagonals: traverse up-right (reverse order)
3. For odd sum diagonals: traverse down-left (normal order)

TIME COMPLEXITY: O(M * N)
SPACE COMPLEXITY: O(1) excluding output array
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        if (mat.empty()) return {};
        
        int m = mat.size();
        int n = mat[0].size();
        vector<int> result;
        
        int row = 0, col = 0;
        bool goingUp = true;
        
        while (result.size() < m * n) {
            result.push_back(mat[row][col]);
            
            if (goingUp) {
                // Going up-right
                if (col == n - 1) {
                    // Hit right boundary, go down
                    row++;
                    goingUp = false;
                } else if (row == 0) {
                    // Hit top boundary, go right
                    col++;
                    goingUp = false;
                } else {
                    // Continue diagonally up-right
                    row--;
                    col++;
                }
            } else {
                // Going down-left
                if (row == m - 1) {
                    // Hit bottom boundary, go right
                    col++;
                    goingUp = true;
                } else if (col == 0) {
                    // Hit left boundary, go down
                    row++;
                    goingUp = true;
                } else {
                    // Continue diagonally down-left
                    row++;
                    col--;
                }
            }
        }
        
        return result;
    }
    
    // Alternative: Group by diagonal sum
    vector<int> findDiagonalOrderGrouping(vector<vector<int>>& mat) {
        if (mat.empty()) return {};
        
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> diagonals(m + n - 1);
        
        // Group elements by diagonal (i + j)
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                diagonals[i + j].push_back(mat[i][j]);
            }
        }
        
        vector<int> result;
        for (int i = 0; i < diagonals.size(); i++) {
            if (i % 2 == 0) {
                // Even diagonal: reverse (going up)
                reverse(diagonals[i].begin(), diagonals[i].end());
            }
            result.insert(result.end(), diagonals[i].begin(), diagonals[i].end());
        }
        
        return result;
    }
};

int main() {
    Solution sol;
    
    vector<vector<int>> mat = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    vector<int> result = sol.findDiagonalOrder(mat);
    
    cout << "Diagonal Order: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}

/*
INPUT:
mat = [[1,2,3],
       [4,5,6],
       [7,8,9]]

OUTPUT:
[1,2,4,7,5,3,6,8,9]

EXPLANATION:
Diagonal traversal with alternating directions:
D0 (↗): 1
D1 (↙): 2, 4
D2 (↗): 7, 5, 3
D3 (↙): 6, 8
D4 (↗): 9

Another example:
Input: [[1,2],[3,4]]
Output: [1,2,3,4]
*/
