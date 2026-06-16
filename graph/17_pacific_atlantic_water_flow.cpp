/*
PROBLEM: Pacific Atlantic Water Flow (LeetCode 417)
Difficulty: Medium
Pattern: Multi-Source DFS/BFS

DESCRIPTION:
Given an m x n matrix of heights representing an island. Rain water can flow to
neighboring cells if the neighbor's height is less than or equal to current cell.
Water can flow from any cell adjacent to the Pacific (top and left edges) and
Atlantic (bottom and right edges) oceans.
Return cells where water can flow to both oceans.

GRID DIAGRAM:
       PACIFIC OCEAN
         ↓ ↓ ↓ ↓
      →  1 2 2 3  ← ATLANTIC
      →  3 2 3 4  ← OCEAN
      →  2 4 5 3  ← 
      →  1 4 2 4  ← 
         ↑ ↑ ↑ ↑

  Cells marked * can reach both oceans:
  1 2* 2* 3*    Water flows from high to low (or equal)
  3 2* 3* 4*    Top/Left borders touch Pacific
  2 4* 5* 3*    Bottom/Right borders touch Atlantic
  1 4* 2* 4*    Use reverse DFS from each ocean

APPROACH:
1. Start DFS from Pacific borders (top and left)
2. Start DFS from Atlantic borders (bottom and right)
3. Mark cells reachable from each ocean
4. Return cells reachable from both oceans

TIME COMPLEXITY: O(M * N)
SPACE COMPLEXITY: O(M * N) for two boolean matrices
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& reachable, int i, int j) {
        int m = heights.size();
        int n = heights[0].size();
        
        reachable[i][j] = true;
        
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        for (auto& dir : dirs) {
            int ni = i + dir[0];
            int nj = j + dir[1];
            
            // Water flows from high to low, so check if neighbor is >= current
            if (ni >= 0 && ni < m && nj >= 0 && nj < n && 
                !reachable[ni][nj] && heights[ni][nj] >= heights[i][j]) {
                dfs(heights, reachable, ni, nj);
            }
        }
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        if (heights.empty()) return {};
        
        int m = heights.size();
        int n = heights[0].size();
        
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));
        
        // DFS from Pacific borders (top and left)
        for (int i = 0; i < m; i++) {
            dfs(heights, pacific, i, 0);
        }
        for (int j = 0; j < n; j++) {
            dfs(heights, pacific, 0, j);
        }
        
        // DFS from Atlantic borders (bottom and right)
        for (int i = 0; i < m; i++) {
            dfs(heights, atlantic, i, n - 1);
        }
        for (int j = 0; j < n; j++) {
            dfs(heights, atlantic, m - 1, j);
        }
        
        // Find cells reachable from both oceans
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
};

int main() {
    Solution sol;
    
    vector<vector<int>> heights = {
        {1, 2, 2, 3, 5},
        {3, 2, 3, 4, 4},
        {2, 4, 5, 3, 1},
        {6, 7, 1, 4, 5},
        {5, 1, 1, 2, 4}
    };
    
    vector<vector<int>> result = sol.pacificAtlantic(heights);
    
    cout << "Cells that can reach both oceans:" << endl;
    for (auto& cell : result) {
        cout << "[" << cell[0] << "," << cell[1] << "] ";
    }
    cout << endl;
    
    return 0;
}

/*
INPUT:
heights = [[1,2,2,3,5],
           [3,2,3,4,4],
           [2,4,5,3,1],
           [6,7,1,4,5],
           [5,1,1,2,4]]

OUTPUT:
[[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]

EXPLANATION:
Pacific ocean touches top and left edges.
Atlantic ocean touches bottom and right edges.
Water flows from high to low elevation.
Listed cells can reach both oceans.
*/
