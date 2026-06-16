/*
PROBLEM: Maximal Rectangle (LeetCode 85)
DIFFICULTY: Hard
PATTERN: Stack + Histogram (Extension of Problem 21)

DESCRIPTION:
Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle 
containing only 1's and return its area.

INPUT: matrix = [
  ["1","0","1","0","0"],
  ["1","0","1","1","1"],
  ["1","1","1","1","1"],
  ["1","0","0","1","0"]
]
OUTPUT: 6
Explanation: The maximal rectangle has area 6 (2x3 rectangle)

TIME COMPLEXITY: O(rows * cols) where rows and cols are matrix dimensions
SPACE COMPLEXITY: O(cols) for the height array and stack

EXPLANATION:
Convert the problem to "Largest Rectangle in Histogram" for each row.
Build a heights array where heights[i] = consecutive 1's ending at current row.
For each row, treat it as base of histogram and find largest rectangle.
This combines the histogram problem with dynamic height calculation.
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int largestRectangleArea(vector<int>& heights) {
    stack<int> st;
    int maxArea = 0;
    int n = heights.size();
    
    for (int i = 0; i <= n; i++) {
        int h = (i == n) ? 0 : heights[i];
        
        while (!st.empty() && heights[st.top()] > h) {
            int height = heights[st.top()];
            st.pop();
            int width = st.empty() ? i : i - st.top() - 1;
            maxArea = max(maxArea, height * width);
        }
        st.push(i);
    }
    
    return maxArea;
}

int maximalRectangle(vector<vector<char>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) return 0;
    
    int rows = matrix.size();
    int cols = matrix[0].size();
    vector<int> heights(cols, 0);
    int maxArea = 0;
    
    for (int i = 0; i < rows; i++) {
        // Update heights array
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == '1') {
                heights[j]++;
            } else {
                heights[j] = 0;
            }
        }
        
        // Find largest rectangle for current row
        maxArea = max(maxArea, largestRectangleArea(heights));
    }
    
    return maxArea;
}

void printMatrix(const vector<vector<char>>& matrix) {
    for (const auto& row : matrix) {
        cout << "[";
        for (int i = 0; i < row.size(); i++) {
            cout << "\"" << row[i] << "\"";
            if (i < row.size() - 1) cout << ",";
        }
        cout << "]" << endl;
    }
}

int main() {
    vector<vector<vector<char>>> testCases = {
        {
            {'1', '0', '1', '0', '0'},
            {'1', '0', '1', '1', '1'},
            {'1', '1', '1', '1', '1'},
            {'1', '0', '0', '1', '0'}
        },
        {
            {'0', '1'},
            {'1', '0'}
        },
        {
            {'1', '1', '1', '1'},
            {'1', '1', '1', '1'},
            {'1', '1', '1', '1'}
        },
        {
            {'0'}
        }
    };
    
    for (auto& matrix : testCases) {
        cout << "Matrix:" << endl;
        printMatrix(matrix);
        
        int result = maximalRectangle(matrix);
        cout << "Maximal Rectangle Area: " << result << endl << endl;
    }
    
    return 0;
}
