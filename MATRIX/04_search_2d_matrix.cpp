/*
PROBLEM: Search a 2D Matrix (LeetCode 74)
Difficulty: Medium
Company: Microsoft, Google, Meta, Amazon
Pattern: Binary Search on Matrix

DESCRIPTION:
Write an efficient algorithm that searches for a value in an m x n matrix.
Properties:
- Integers in each row are sorted from left to right
- First integer of each row is greater than last integer of previous row

MATRIX DIAGRAM:
  Matrix:                Target = 3
  1   3   5   7          Row 0: [1, 3, 5, 7]  ← Target found here!
  10  11  16  20         Row 1: [10,11,16,20]
  23  30  34  60         Row 2: [23,30,34,60]
  
  Treat as sorted 1D array:
  [1, 3, 5, 7, 10, 11, 16, 20, 23, 30, 34, 60]
   0  1  2  3   4   5   6   7   8   9  10  11 (indices)
  
  Binary search: mid = 1, value = 3 ✓
  Convert: row = mid / n, col = mid % n

APPROACH:
Method 1: Treat as 1D array and binary search
  - Convert matrix[i][j] to index: i * n + j
  - Convert index to coordinates: row = idx / n, col = idx % n

Method 2: Two binary searches
  - First find the row (binary search on first column)
  - Then find in that row (binary search)

TIME COMPLEXITY: O(log(M * N))
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
        
        int left = 0;
        int right = m * n - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int midValue = matrix[mid / n][mid % n];
            
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
    
    // Alternative: Two binary searches
    bool searchMatrixTwoBS(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        // Binary search for the row
        int top = 0, bottom = m - 1;
        int targetRow = -1;
        
        while (top <= bottom) {
            int mid = top + (bottom - top) / 2;
            if (matrix[mid][0] <= target && target <= matrix[mid][n - 1]) {
                targetRow = mid;
                break;
            } else if (matrix[mid][0] > target) {
                bottom = mid - 1;
            } else {
                top = mid + 1;
            }
        }
        
        if (targetRow == -1) return false;
        
        // Binary search in the row
        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (matrix[targetRow][mid] == target) {
                return true;
            } else if (matrix[targetRow][mid] < target) {
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
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };
    
    int target = 3;
    cout << "Searching for " << target << ": " 
         << (sol.searchMatrix(matrix, target) ? "Found" : "Not Found") << endl;
    
    target = 13;
    cout << "Searching for " << target << ": " 
         << (sol.searchMatrix(matrix, target) ? "Found" : "Not Found") << endl;
    
    return 0;
}

/*
INPUT:
matrix = [[1,3,5,7],
          [10,11,16,20],
          [23,30,34,60]]
target = 3

OUTPUT:
true

EXPLANATION:
The matrix can be viewed as a sorted array:
[1,3,5,7,10,11,16,20,23,30,34,60]
Binary search finds 3 at position 1
Which corresponds to matrix[0][1]

For target = 13:
OUTPUT: false
13 is not in the matrix
*/
