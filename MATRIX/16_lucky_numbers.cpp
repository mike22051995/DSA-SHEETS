/*
PROBLEM: Lucky Numbers in a Matrix (LeetCode 1380)
Difficulty: Easy
Company: Amazon, Google
Pattern: Matrix Row/Column Min/Max

DESCRIPTION:
Given an m x n matrix of distinct numbers, return all lucky numbers in the matrix.
A lucky number is an element that is:
- Minimum in its row
- Maximum in its column

MATRIX DIAGRAM:
  Matrix:              Analysis:
  3   7   8            Row mins: [3, 1, 7]
  9   11  13    -->    Col maxs: [9, 11, 15]
  15  16  17           
  
  Check each element:
  - 3: min in row 0? YES, max in col 0? NO (9 > 3)
  - 7: min in row 0? NO
  - 15: min in row 2? NO
  - 11: min in row 1? NO
  - 15: min in row 2? NO, max in col 0? YES → Lucky! ✗
  
  Correct Example:
  1   10  4  2         Row mins: [1, 7, 7]
  9   3   8  7  -->    Col maxs: [9, 10, 8, 7]
  15  16  17  12       
  
  Element 7 (at position (1,3)):
  - Min in row 1? YES (7 = min(9,3,8,7))
  - Wait, 3 < 7, so NO

APPROACH:
1. Find minimum element in each row
2. Find maximum element in each column
3. Element is lucky if it's both row min AND column max
4. Can also check if rowMin[i] == colMax[j] for position (i,j)

TIME COMPLEXITY: O(M * N)
SPACE COMPLEXITY: O(M + N) for storing row mins and column maxs
*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        // Find minimum in each row
        vector<int> rowMins(m);
        for (int i = 0; i < m; i++) {
            int minVal = INT_MAX;
            for (int j = 0; j < n; j++) {
                minVal = min(minVal, matrix[i][j]);
            }
            rowMins[i] = minVal;
        }
        
        // Find maximum in each column
        vector<int> colMaxs(n);
        for (int j = 0; j < n; j++) {
            int maxVal = INT_MIN;
            for (int i = 0; i < m; i++) {
                maxVal = max(maxVal, matrix[i][j]);
            }
            colMaxs[j] = maxVal;
        }
        
        // Find lucky numbers
        vector<int> result;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == rowMins[i] && matrix[i][j] == colMaxs[j]) {
                    result.push_back(matrix[i][j]);
                }
            }
        }
        
        return result;
    }
    
    // Optimized: Find row min positions and check if they're column max
    vector<int> luckyNumbersOptimized(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> result;
        
        for (int i = 0; i < m; i++) {
            // Find minimum in this row and its column index
            int minVal = INT_MAX;
            int minCol = 0;
            
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] < minVal) {
                    minVal = matrix[i][j];
                    minCol = j;
                }
            }
            
            // Check if this element is maximum in its column
            bool isColMax = true;
            for (int k = 0; k < m; k++) {
                if (matrix[k][minCol] > minVal) {
                    isColMax = false;
                    break;
                }
            }
            
            if (isColMax) {
                result.push_back(minVal);
            }
        }
        
        return result;
    }
};

int main() {
    Solution sol;
    
    vector<vector<int>> matrix1 = {
        {3, 7, 8},
        {9, 11, 13},
        {15, 16, 17}
    };
    
    vector<int> result1 = sol.luckyNumbers(matrix1);
    cout << "Lucky numbers: ";
    for (int num : result1) cout << num << " ";
    cout << endl;
    
    vector<vector<int>> matrix2 = {
        {1, 10, 4, 2},
        {9, 3, 8, 7},
        {15, 16, 17, 12}
    };
    
    vector<int> result2 = sol.luckyNumbers(matrix2);
    cout << "Lucky numbers: ";
    for (int num : result2) cout << num << " ";
    cout << endl;
    
    return 0;
}

/*
INPUT:
matrix = [[3,7,8],
          [9,11,13],
          [15,16,17]]

OUTPUT:
[15]

EXPLANATION:
Row minimums: [3, 9, 15]
Column maximums: [15, 16, 17]

Element 15:
- Position: (2, 0)
- Minimum in row 2: YES (15 < 16 < 17)
- Maximum in column 0: YES (15 > 9 > 3)
- Lucky number! ✓

For matrix2:
INPUT: [[1,10,4,2],
        [9,3,8,7],
        [15,16,17,12]]
OUTPUT: [12]

Element 12:
- Position: (2, 3)
- Minimum in row 2: YES
- Maximum in column 3: YES (12 > 7 > 2)
*/
