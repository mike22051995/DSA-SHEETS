/*
PROBLEM: Maximal Rectangle (LeetCode 85)
Difficulty: Hard
Company: Google, Meta, Amazon, Microsoft
Pattern: Histogram + DP

DESCRIPTION:
Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle 
containing only 1's and return its area.

MATRIX DIAGRAM:
  Matrix:              Heights:          Largest Rectangle:
  1  0  1  0  0        1  0  1  0  0     
  1  0  1  1  1  -->   2  0  2  1  1  -->  Area = 6
  1  1  1  1  1        3  1  3  2  2       (2 rows × 3 cols)
  1  0  0  1  0        4  0  0  3  0
  
  Convert to histogram problem:
  Row 0: [1,0,1,0,0] → max area = 1
  Row 1: [2,0,2,1,1] → max area = 3
  Row 2: [3,1,3,2,2] → max area = 6 ✓
  Row 3: [4,0,0,3,0] → max area = 4
  
  For each row, treat as histogram base and find largest rectangle

APPROACH:
Method 1: Convert to Largest Rectangle in Histogram
1. Build height array for each row (cumulative 1's)
2. For each row, solve largest rectangle in histogram
3. Track maximum area across all rows

Method 2: Dynamic Programming
- Track: left[], right[], height[] arrays
- left[j] = leftmost column where height >= current height
- right[j] = rightmost column where height >= current height
- area = height[j] * (right[j] - left[j])

TIME COMPLEXITY: O(M * N)
SPACE COMPLEXITY: O(N) for height array
*/

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    int largestRectangleHistogram(vector<int>& heights) {
        stack<int> st;
        int maxArea = 0;
        int n = heights.size();
        
        for (int i = 0; i <= n; i++) {
            int h = (i == n) ? 0 : heights[i];
            
            while (!st.empty() && h < heights[st.top()]) {
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
        
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> heights(n, 0);
        int maxArea = 0;
        
        for (int i = 0; i < m; i++) {
            // Update heights array
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1') {
                    heights[j]++;
                } else {
                    heights[j] = 0;
                }
            }
            
            // Find max rectangle in current histogram
            maxArea = max(maxArea, largestRectangleHistogram(heights));
        }
        
        return maxArea;
    }
    
    // Alternative: DP approach
    int maximalRectangleDP(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> left(n, 0);
        vector<int> right(n, n);
        vector<int> height(n, 0);
        int maxArea = 0;
        
        for (int i = 0; i < m; i++) {
            int curLeft = 0, curRight = n;
            
            // Update height
            for (int j = 0; j < n; j++) {
                height[j] = (matrix[i][j] == '1') ? height[j] + 1 : 0;
            }
            
            // Update left
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1') {
                    left[j] = max(left[j], curLeft);
                } else {
                    left[j] = 0;
                    curLeft = j + 1;
                }
            }
            
            // Update right
            for (int j = n - 1; j >= 0; j--) {
                if (matrix[i][j] == '1') {
                    right[j] = min(right[j], curRight);
                } else {
                    right[j] = n;
                    curRight = j;
                }
            }
            
            // Calculate area
            for (int j = 0; j < n; j++) {
                maxArea = max(maxArea, (right[j] - left[j]) * height[j]);
            }
        }
        
        return maxArea;
    }
};

int main() {
    Solution sol;
    
    vector<vector<char>> matrix = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}
    };
    
    cout << "Maximal Rectangle Area: " << sol.maximalRectangle(matrix) << endl;
    
    return 0;
}

/*
INPUT:
matrix = [["1","0","1","0","0"],
          ["1","0","1","1","1"],
          ["1","1","1","1","1"],
          ["1","0","0","1","0"]]

OUTPUT:
6

EXPLANATION:
The maximal rectangle is:
Row 1-2, Col 2-4:
[["1","1","1"],
 ["1","1","1"]]
Area = 2 rows × 3 columns = 6

Heights after each row:
Row 0: [1,0,1,0,0]
Row 1: [2,0,2,1,1]
Row 2: [3,1,3,2,2] ← Max histogram area = 6
Row 3: [4,0,0,3,0]
*/
