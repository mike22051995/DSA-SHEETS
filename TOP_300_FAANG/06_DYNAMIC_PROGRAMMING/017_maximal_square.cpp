/*
================================================================================
PROBLEM: Maximal Square (LeetCode #221)
DIFFICULTY: Medium
PATTERN: 2D Dynamic Programming
COMPANIES: Amazon, Facebook, Google, Microsoft, Apple
================================================================================
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        int maxSide = 0;
        
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (matrix[i-1][j-1] == '1') {
                    dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
                    maxSide = max(maxSide, dp[i][j]);
                }
            }
        }
        
        return maxSide * maxSide;
    }
    
    // Space Optimized
    int maximalSquareOptimized(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        
        int m = matrix.size(), n = matrix[0].size();
        vector<int> dp(n + 1, 0);
        int maxSide = 0, prev = 0;
        
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                int temp = dp[j];
                
                if (matrix[i-1][j-1] == '1') {
                    dp[j] = min({dp[j], dp[j-1], prev}) + 1;
                    maxSide = max(maxSide, dp[j]);
                } else {
                    dp[j] = 0;
                }
                
                prev = temp;
            }
        }
        
        return maxSide * maxSide;
    }
};

int main() {
    Solution sol;
    vector<vector<char>> matrix = {
        {'1','0','1','0','0'},
        {'1','0','1','1','1'},
        {'1','1','1','1','1'},
        {'1','0','0','1','0'}
    };
    
    cout << "Maximal square area: " << sol.maximalSquare(matrix) << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Maximal Rectangle (LeetCode #85)
2. Largest Rectangle in Histogram (LeetCode #84)
3. Count Square Submatrices (LeetCode #1277)
4. Count Submatrices With All Ones (LeetCode #1504)
5. Largest Plus Sign (LeetCode #764)
6. Largest 1-Bordered Square (LeetCode #1139)
7. Minimum Cost Homecoming (LeetCode #2087)
8. Valid Square (LeetCode #593)
9. Perfect Rectangle (LeetCode #391)
10. Number of Submatrices That Sum to Target (LeetCode #1074)
*/
