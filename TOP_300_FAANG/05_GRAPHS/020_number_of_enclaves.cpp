/*
================================================================================
PROBLEM: Number of Enclaves (LeetCode #1020)
DIFFICULTY: Medium
PATTERN: DFS / BFS
COMPANIES: Amazon, Google, Microsoft
================================================================================
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        // Mark boundary lands and connected lands
        for (int i = 0; i < m; i++) {
            if (grid[i][0] == 1) dfs(grid, i, 0);
            if (grid[i][n-1] == 1) dfs(grid, i, n-1);
        }
        
        for (int j = 0; j < n; j++) {
            if (grid[0][j] == 1) dfs(grid, 0, j);
            if (grid[m-1][j] == 1) dfs(grid, m-1, j);
        }
        
        // Count remaining 1's
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    count++;
                }
            }
        }
        
        return count;
    }
    
    void dfs(vector<vector<int>>& grid, int i, int j) {
        int m = grid.size();
        int n = grid[0].size();
        
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != 1) {
            return;
        }
        
        grid[i][j] = 0;
        
        dfs(grid, i+1, j);
        dfs(grid, i-1, j);
        dfs(grid, i, j+1);
        dfs(grid, i, j-1);
    }
};

int main() {
    Solution sol;
    vector<vector<int>> grid = {
        {0,0,0,0},
        {1,0,1,0},
        {0,1,1,0},
        {0,0,0,0}
    };
    
    cout << "Number of enclaves: " << sol.numEnclaves(grid) << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Number of Islands (LeetCode #200)
2. Surrounded Regions (LeetCode #130)
3. Number of Closed Islands (LeetCode #1254)
4. Pacific Atlantic Water Flow (LeetCode #417)
5. Max Area of Island (LeetCode #695)
6. Flood Fill (LeetCode #733)
7. Number of Distinct Islands (LeetCode #694)
8. Number of Provinces (LeetCode #547)
9. Keys and Rooms (LeetCode #841)
10. Shortest Bridge (LeetCode #934)
*/
