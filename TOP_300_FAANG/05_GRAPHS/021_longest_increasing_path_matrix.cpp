/*
================================================================================
PROBLEM: Longest Increasing Path in Matrix (LeetCode #329)
DIFFICULTY: Hard
PATTERN: DFS + Memoization / DP
COMPANIES: Amazon, Microsoft, Facebook, Google
================================================================================
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:
    vector<vector<int>> dirs = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty()) return 0;
        
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> memo(m, vector<int>(n, 0));
        
        int maxLen = 0;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                maxLen = max(maxLen, dfs(matrix, i, j, memo));
            }
        }
        
        return maxLen;
    }
    
    int dfs(vector<vector<int>>& matrix, int i, int j, vector<vector<int>>& memo) {
        if (memo[i][j] != 0) {
            return memo[i][j];
        }
        
        int maxPath = 1;
        
        for (auto& dir : dirs) {
            int x = i + dir[0];
            int y = j + dir[1];
            
            if (x >= 0 && x < matrix.size() && y >= 0 && y < matrix[0].size() 
                && matrix[x][y] > matrix[i][j]) {
                maxPath = max(maxPath, 1 + dfs(matrix, x, y, memo));
            }
        }
        
        memo[i][j] = maxPath;
        return maxPath;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> matrix = {
        {9,9,4},
        {6,6,8},
        {2,1,1}
    };
    
    cout << "Longest increasing path: " << sol.longestIncreasingPath(matrix) << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Number of Islands (LeetCode #200)
2. Pacific Atlantic Water Flow (LeetCode #417)
3. Longest Path With Different Adjacent Characters (LeetCode #2246)
4. Minimum Path Sum (LeetCode #64)
5. Unique Paths (LeetCode #62)
6. Dungeon Game (LeetCode #174)
7. Cherry Pickup (LeetCode #741)
8. Out of Boundary Paths (LeetCode #576)
9. Knight Probability in Chessboard (LeetCode #688)
10. Maximal Square (LeetCode #221)
*/
