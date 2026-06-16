/*
PROBLEM: Matrix Diagonal Sum (LeetCode 1572)
Difficulty: Easy
Company: Amazon, Google
Pattern: Matrix Diagonal Traversal

DESCRIPTION:
Given a square matrix, return the sum of its diagonals.
Include only the primary diagonal and secondary diagonal, and do not count
the center element twice if the matrix size is odd.

MATRIX DIAGRAM:
  Matrix (3×3):              Matrix (4×4):
  1  2  3                    1  2  3  4
  4  5  6           -->      5  6  7  8
  7  8  9                    9  10 11 12
                             13 14 15 16
  Primary: 1+5+9 = 15        Primary: 1+6+11+16 = 34
  Secondary: 3+5+7 = 15      Secondary: 4+7+10+13 = 34
  Center: 5 (counted once)   No center (even size)
  Total: 15+15-5 = 25        Total: 34+34 = 68
  
  Primary diagonal: i==j (top-left to bottom-right)
  Secondary diagonal: i+j==n-1 (top-right to bottom-left)

APPROACH:
1. Traverse primary diagonal: i from 0 to n-1, sum matrix[i][i]
2. Traverse secondary diagonal: i from 0 to n-1, sum matrix[i][n-1-i]
3. If n is odd, subtract center element matrix[n/2][n/2] (counted twice)

TIME COMPLEXITY: O(N)
SPACE COMPLEXITY: O(1)
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int sum = 0;
        
        for (int i = 0; i < n; i++) {
            // Primary diagonal
            sum += mat[i][i];
            
            // Secondary diagonal
            sum += mat[i][n - 1 - i];
        }
        
        // If odd size, subtract center (counted twice)
        if (n % 2 == 1) {
            sum -= mat[n / 2][n / 2];
        }
        
        return sum;
    }
    
    // Alternative: Check for each element
    int diagonalSumAlternative(vector<vector<int>>& mat) {
        int n = mat.size();
        int sum = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // Primary diagonal or secondary diagonal
                if (i == j || i + j == n - 1) {
                    sum += mat[i][j];
                }
            }
        }
        
        return sum;
    }
};

int main() {
    Solution sol;
    
    // Example 1: 3×3 matrix (odd)
    vector<vector<int>> mat1 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    cout << "Diagonal sum (3×3): " << sol.diagonalSum(mat1) << endl;
    
    // Example 2: 4×4 matrix (even)
    vector<vector<int>> mat2 = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    
    cout << "Diagonal sum (4×4): " << sol.diagonalSum(mat2) << endl;
    
    // Example 3: 1×1 matrix
    vector<vector<int>> mat3 = {{5}};
    cout << "Diagonal sum (1×1): " << sol.diagonalSum(mat3) << endl;
    
    return 0;
}

/*
INPUT:
mat = [[1,2,3],
       [4,5,6],
       [7,8,9]]

OUTPUT:
25

EXPLANATION:
Primary diagonal (↘): 1 + 5 + 9 = 15
Secondary diagonal (↙): 3 + 5 + 7 = 15
Center element 5 is counted in both
Total: 15 + 15 - 5 = 25

For 4×4 matrix:
INPUT: [[1,2,3,4],
        [5,6,7,8],
        [9,10,11,12],
        [13,14,15,16]]
OUTPUT: 68

Primary diagonal: 1 + 6 + 11 + 16 = 34
Secondary diagonal: 4 + 7 + 10 + 13 = 34
No overlap (even size)
Total: 34 + 34 = 68

For 1×1 matrix:
INPUT: [[5]]
OUTPUT: 5
Single element is both diagonals
*/
