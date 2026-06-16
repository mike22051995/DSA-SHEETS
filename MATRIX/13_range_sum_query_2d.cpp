/*
PROBLEM: Range Sum Query 2D - Immutable (LeetCode 304)
Difficulty: Medium
Company: Google, Meta, Amazon, Microsoft, Netflix
Pattern: Prefix Sum 2D

DESCRIPTION:
Given a 2D matrix, handle multiple queries of sum of elements inside a rectangle.
Rectangle is defined by (row1, col1) as top-left and (row2, col2) as bottom-right.

MATRIX DIAGRAM:
  Matrix:              Prefix Sum:
  3  0  1  4  2        3  3  4   8  10
  5  6  3  2  1  -->   8  14 18  24 27
  1  2  0  1  5        9  17 21  28 36
  4  1  0  1  7        13 22 26  34 50
  1  0  3  0  5        14 23 30  38 58
  
  Query: sumRegion(2,1,4,3) = sum of shaded region
    2  0  1
    1  0  1
    0  3  0
  Answer: 8
  
  Formula using prefix sums:
  sum = prefixSum[r2+1][c2+1] - prefixSum[r1][c2+1] 
        - prefixSum[r2+1][c1] + prefixSum[r1][c1]

APPROACH:
Preprocessing:
1. Build prefix sum matrix where prefixSum[i][j] represents 
   sum of all elements from (0,0) to (i-1,j-1)
2. prefixSum[i][j] = matrix[i-1][j-1] + prefixSum[i-1][j] 
                     + prefixSum[i][j-1] - prefixSum[i-1][j-1]

Query:
Use inclusion-exclusion principle with prefix sums

TIME COMPLEXITY: 
- Preprocessing: O(M * N)
- Query: O(1)
SPACE COMPLEXITY: O(M * N)
*/

#include <iostream>
#include <vector>
using namespace std;

class NumMatrix {
private:
    vector<vector<int>> prefixSum;
    
public:
    NumMatrix(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return;
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        // Initialize prefix sum matrix (m+1 x n+1)
        prefixSum.resize(m + 1, vector<int>(n + 1, 0));
        
        // Build prefix sum
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                prefixSum[i][j] = matrix[i-1][j-1] 
                                + prefixSum[i-1][j] 
                                + prefixSum[i][j-1] 
                                - prefixSum[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return prefixSum[row2 + 1][col2 + 1] 
             - prefixSum[row1][col2 + 1] 
             - prefixSum[row2 + 1][col1] 
             + prefixSum[row1][col1];
    }
};

int main() {
    vector<vector<int>> matrix = {
        {3, 0, 1, 4, 2},
        {5, 6, 3, 2, 1},
        {1, 2, 0, 1, 5},
        {4, 1, 0, 1, 7},
        {1, 0, 3, 0, 5}
    };
    
    NumMatrix* obj = new NumMatrix(matrix);
    
    cout << "Sum of region (2,1) to (4,3): " << obj->sumRegion(2, 1, 4, 3) << endl;
    cout << "Sum of region (1,1) to (2,2): " << obj->sumRegion(1, 1, 2, 2) << endl;
    cout << "Sum of region (1,2) to (2,4): " << obj->sumRegion(1, 2, 2, 4) << endl;
    
    delete obj;
    return 0;
}

/*
INPUT:
matrix = [[3,0,1,4,2],
          [5,6,3,2,1],
          [1,2,0,1,5],
          [4,1,0,1,7],
          [1,0,3,0,5]]

QUERIES:
sumRegion(2, 1, 4, 3)
sumRegion(1, 1, 2, 2)
sumRegion(1, 2, 2, 4)

OUTPUT:
8
11
12

EXPLANATION:
Query 1: sumRegion(2,1,4,3)
Elements: [2,0,1], [1,0,1], [0,3,0]
Sum: 2+0+1+1+0+1+0+3+0 = 8

Query 2: sumRegion(1,1,2,2)
Elements: [6,3], [2,0]
Sum: 6+3+2+0 = 11

Prefix Sum Formula Visualization:
     (r1,c1)_______(r1,c2+1)
        |            |
        |   Region   |
     (r2+1,c1)____(r2+1,c2+1)
  
  Sum = Total(r2+1,c2+1) - Top(r1,c2+1) - Left(r2+1,c1) + Overlap(r1,c1)
*/
