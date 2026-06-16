/*
================================================================================
PROBLEM: Pascal's Triangle (LeetCode #118)
DIFFICULTY: Easy
PATTERN: Array / DP
COMPANIES: Amazon, Microsoft, Google, Apple
================================================================================
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;
        
        if (numRows <= 0) return triangle;
        
        triangle.push_back({1});
        
        for (int i = 1; i < numRows; i++) {
            vector<int> row;
            row.push_back(1);
            
            for (int j = 1; j < i; j++) {
                row.push_back(triangle[i-1][j-1] + triangle[i-1][j]);
            }
            
            row.push_back(1);
            triangle.push_back(row);
        }
        
        return triangle;
    }
};

int main() {
    Solution sol;
    int numRows = 5;
    
    vector<vector<int>> result = sol.generate(numRows);
    
    cout << "Pascal's Triangle:" << endl;
    for (auto& row : result) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Pascal's Triangle II (LeetCode #119)
2. Triangle (LeetCode #120)
3. Binomial Coefficient
4. Combinations (LeetCode #77)
5. Unique Paths (LeetCode #62)
6. Unique Paths II (LeetCode #63)
7. Minimum Path Sum (LeetCode #64)
8. Dungeon Game (LeetCode #174)
9. K-th Symbol in Grammar (LeetCode #779)
10. Count Square Submatrices (LeetCode #1277)
*/
