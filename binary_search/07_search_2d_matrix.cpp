/*
PROBLEM: Search a 2D Matrix
Difficulty: Medium
Pattern: Binary Search on Matrix

DESCRIPTION:
Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix.
This matrix has the following properties:
- Integers in each row are sorted from left to right.
- The first integer of each row is greater than the last integer of the previous row.

EXPLANATION:
Treat 2D matrix as 1D sorted array:
- Total elements = m * n
- For index i: row = i / n, col = i % n
- Apply standard binary search on indices [0, m*n-1]

Time Complexity: O(log(m*n))
Space Complexity: O(1)

INPUT-OUTPUT EXAMPLES:

Example 1:
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true
Explanation: 3 is found in the matrix

Example 2:
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output: false
Explanation: 13 is not in the matrix

Example 3:
Input: matrix = [[1]], target = 1
Output: true
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
        int left = 0;
        int right = m * n - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int row = mid / n;
            int col = mid % n;
            int midValue = matrix[row][col];
            
            if (midValue == target) {
                return true;
            } else if (midValue < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return false;
    }
};

int main() {
    Solution solution;
    
    // Test Case 1
    vector<vector<int>> matrix1 = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    cout << "Test 1: " << (solution.searchMatrix(matrix1, 3) ? "true" : "false") << endl;
    
    // Test Case 2
    vector<vector<int>> matrix2 = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    cout << "Test 2: " << (solution.searchMatrix(matrix2, 13) ? "true" : "false") << endl;
    
    // Test Case 3
    vector<vector<int>> matrix3 = {{1}};
    cout << "Test 3: " << (solution.searchMatrix(matrix3, 1) ? "true" : "false") << endl;
    
    return 0;
}
