/*
================================================================================
PROBLEM: Search a 2D Matrix II (LeetCode #240)
DIFFICULTY: Medium
PATTERN: Binary Search / Divide and Conquer
COMPANIES: Amazon, Google, Facebook, Microsoft, Apple
================================================================================

PROBLEM DESCRIPTION:
Given a matrix where each row and each column is sorted in ascending order,
return true if a target value exists in the matrix; otherwise return false.

EXAMPLES:
Example 1:
Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 5
Output: true

Example 2:
Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 20
Output: false

CODE EXPLANATION:
- Start from the top-right corner and eliminate one row or column each step.
- If the current value is too large, move left; if too small, move down.
- The alternative method binary-searches each row.
TIME COMPLEXITY: O(m + n) for the top-right scan
SPACE COMPLEXITY: O(1)
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Start from top-right corner
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty()) return false;
        
        int row = 0;
        int col = matrix[0].size() - 1;
        
        while (row < matrix.size() && col >= 0) {
            if (matrix[row][col] == target) {
                return true;
            } else if (matrix[row][col] > target) {
                col--;
            } else {
                row++;
            }
        }
        
        return false;
    }
    
    // Binary search on each row
    bool searchMatrixBinarySearch(vector<vector<int>>& matrix, int target) {
        for (auto& row : matrix) {
            if (binarySearch(row, target)) {
                return true;
            }
        }
        return false;
    }
    
    bool binarySearch(vector<int>& row, int target) {
        int left = 0, right = row.size() - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (row[mid] == target) {
                return true;
            } else if (row[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return false;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> matrix = {
        {1,4,7,11,15},
        {2,5,8,12,19},
        {3,6,9,16,22},
        {10,13,14,17,24},
        {18,21,23,26,30}
    };
    
    cout << "Search 5: " << (sol.searchMatrix(matrix, 5) ? "true" : "false") << endl;
    cout << "Search 20: " << (sol.searchMatrix(matrix, 20) ? "true" : "false") << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Search a 2D Matrix (LeetCode #74)
2. Kth Smallest Element in Sorted Matrix (LeetCode #378)
3. Count Negative Numbers in Sorted Matrix (LeetCode #1351)
4. Lucky Numbers in Matrix (LeetCode #1380)
5. Find a Peak Element II (LeetCode #1901)
6. Valid Word Square (LeetCode #422)
7. Toeplitz Matrix (LeetCode #766)
8. Spiral Matrix (LeetCode #54)
9. Rotate Image (LeetCode #48)
10. Set Matrix Zeroes (LeetCode #73)
*/
