/*
PROBLEM: Kth Smallest Element in a Sorted Matrix
Difficulty: Medium
Pattern: Binary Search on Value Range

DESCRIPTION:
Given an n x n matrix where each of the rows and columns is sorted in ascending order, 
return the kth smallest element in the matrix.
Note that it is the kth smallest element in the sorted order, not the kth distinct element.

EXPLANATION:
Binary search on value range:
- Search space: [matrix[0][0], matrix[n-1][n-1]]
- For each mid, count elements <= mid
- If count >= k, answer is <= mid, search left
- Otherwise, search right

Time Complexity: O(n * log(max - min))
Space Complexity: O(1)

INPUT-OUTPUT EXAMPLES:

Example 1:
Input: matrix = [[1,5,9],[10,11,13],[12,13,15]], k = 8
Output: 13
Explanation: Elements are [1,5,9,10,11,12,13,13,15], 8th is 13

Example 2:
Input: matrix = [[-5]], k = 1
Output: -5

Example 3:
Input: matrix = [[1,2],[1,3]], k = 2
Output: 1
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int left = matrix[0][0];
        int right = matrix[n-1][n-1];
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            int count = countLessEqual(matrix, mid);
            
            if (count < k) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        
        return left;
    }
    
private:
    int countLessEqual(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int count = 0;
        int row = n - 1;
        int col = 0;
        
        // Start from bottom-left corner
        while (row >= 0 && col < n) {
            if (matrix[row][col] <= target) {
                count += row + 1;
                col++;
            } else {
                row--;
            }
        }
        
        return count;
    }
};

int main() {
    Solution solution;
    
    // Test Case 1
    vector<vector<int>> matrix1 = {{1,5,9},{10,11,13},{12,13,15}};
    cout << "Test 1: " << solution.kthSmallest(matrix1, 8) << endl;
    
    // Test Case 2
    vector<vector<int>> matrix2 = {{-5}};
    cout << "Test 2: " << solution.kthSmallest(matrix2, 1) << endl;
    
    // Test Case 3
    vector<vector<int>> matrix3 = {{1,2},{1,3}};
    cout << "Test 3: " << solution.kthSmallest(matrix3, 2) << endl;
    
    return 0;
}
