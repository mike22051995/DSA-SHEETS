/*
PROBLEM: Spiral Matrix
Difficulty: Medium
Pattern: Matrix Traversal, Simulation

DESCRIPTION:
Given an m x n matrix, return all elements of the matrix in spiral order.

EXPLANATION:
Use four boundaries: top, bottom, left, right
Traverse in spiral order: right -> down -> left -> up
After each direction, shrink the corresponding boundary
Continue until all elements are visited

Time Complexity: O(m * n)
Space Complexity: O(1) excluding output array

INPUT-OUTPUT EXAMPLES:

Example 1:
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]
Explanation: Spiral order traversal

Example 2:
Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
Explanation: Rectangle matrix spiral

Example 3:
Input: matrix = [[1]]
Output: [1]
Explanation: Single element
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        
        if (matrix.empty() || matrix[0].empty()) return result;
        
        int top = 0;
        int bottom = matrix.size() - 1;
        int left = 0;
        int right = matrix[0].size() - 1;
        
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
            
            // Traverse left (if there's still a row)
            if (top <= bottom) {
                for (int col = right; col >= left; col--) {
                    result.push_back(matrix[bottom][col]);
                }
                bottom--;
            }
            
            // Traverse up (if there's still a column)
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

void printArray(vector<int>& nums) {
    cout << "[";
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i];
        if (i < nums.size() - 1) cout << ",";
    }
    cout << "]" << endl;
}

int main() {
    Solution solution;
    
    // Test Case 1
    vector<vector<int>> matrix1 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<int> result1 = solution.spiralOrder(matrix1);
    cout << "Test 1: ";
    printArray(result1);
    
    // Test Case 2
    vector<vector<int>> matrix2 = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    vector<int> result2 = solution.spiralOrder(matrix2);
    cout << "Test 2: ";
    printArray(result2);
    
    // Test Case 3
    vector<vector<int>> matrix3 = {{1}};
    vector<int> result3 = solution.spiralOrder(matrix3);
    cout << "Test 3: ";
    printArray(result3);
    
    return 0;
}
