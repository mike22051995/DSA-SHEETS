/*
================================================================================
PROBLEM: Pacific Atlantic Water Flow (LeetCode #417)
DIFFICULTY: Medium
PATTERN: DFS/BFS from Edges
COMPANIES: Amazon, Google, Facebook, Microsoft
================================================================================
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        if (heights.empty()) return {};
        
        int m = heights.size(), n = heights[0].size();
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));
        
        // DFS from Pacific edges
        for (int i = 0; i < m; i++) {
            dfs(heights, pacific, i, 0);
            dfs(heights, atlantic, i, n - 1);
        }
        
        for (int j = 0; j < n; j++) {
            dfs(heights, pacific, 0, j);
            dfs(heights, atlantic, m - 1, j);
        }
        
        // Find cells that can reach both oceans
        vector<vector<int>> result;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    result.push_back({i, j});
                }
            }
        }
        
        return result;
    }
    
    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& visited, 
             int i, int j) {
        visited[i][j] = true;
        
        int dirs[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        
        for (auto& dir : dirs) {
            int ni = i + dir[0], nj = j + dir[1];
            
            if (ni >= 0 && ni < heights.size() && nj >= 0 && nj < heights[0].size() &&
                !visited[ni][nj] && heights[ni][nj] >= heights[i][j]) {
                dfs(heights, visited, ni, nj);
            }
        }
    }
};

int main() {
    Solution sol;
    vector<vector<int>> heights = {
        {1,2,2,3,5},
        {3,2,3,4,4},
        {2,4,5,3,1},
        {6,7,1,4,5},
        {5,1,1,2,4}
    };
    
    auto result = sol.pacificAtlantic(heights);
    
    cout << "Cells that can reach both oceans:" << endl;
    for (auto& cell : result) {
        cout << "[" << cell[0] << "," << cell[1] << "]" << endl;
    }
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Number of Islands (LeetCode #200)
2. Surrounded Regions (LeetCode #130)
3. Walls and Gates (LeetCode #286)
4. Number of Enclaves (LeetCode #1020)
5. Number of Closed Islands (LeetCode #1254)
6. Max Area of Island (LeetCode #695)
7. Island Perimeter (LeetCode #463)
8. Shortest Bridge (LeetCode #934)
9. Rotting Oranges (LeetCode #994)
10. As Far from Land as Possible (LeetCode #1162)
*/
