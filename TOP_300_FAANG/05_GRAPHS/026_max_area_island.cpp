/*
================================================================================
PROBLEM: Max Area of Island (LeetCode #695)
DIFFICULTY: Medium
PATTERN: DFS / BFS
COMPANIES: Amazon, Microsoft, Facebook, Google
================================================================================

PROBLEM DESCRIPTION:
You are given an m x n binary matrix grid. An island is a group of 1's
(representing land) connected 4-directionally (horizontal or vertical). You may
assume all four edges of the grid are surrounded by water. The area of an
island is the number of cells with a value 1 in the island. Return the maximum
area of an island in grid. If there is no island, return 0.

EXAMPLES:

Example 1:
Input: grid = [
  [0,0,1,0,0,0,0,1,0,0,0,0,0],
  [0,0,0,0,0,0,0,1,1,1,0,0,0],
  [0,1,1,0,1,0,0,0,0,0,0,0,0],
  [0,1,0,0,1,1,0,0,1,0,1,0,0],
  [0,1,0,0,1,1,0,0,1,1,1,0,0],
  [0,0,0,0,0,0,0,0,0,0,1,0,0],
  [0,0,0,0,0,0,0,1,1,1,0,0,0],
  [0,0,0,0,0,0,0,1,1,0,0,0,0]
]
Output: 6

Example 2:
Input: grid = [[0,0,0,0,0,0,0,0]]
Output: 0

PATTERN RECOGNITION:
Use this pattern when:
- Count connected components with sizes
- DFS/BFS to explore islands
- Track visited cells and accumulate area
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    vector<pair<int, int>> dirs = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int maxArea = 0;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    maxArea = max(maxArea, dfs(grid, i, j));
                }
            }
        }
        
        return maxArea;
    }
    
    int dfs(vector<vector<int>>& grid, int i, int j) {
        int m = grid.size();
        int n = grid[0].size();
        
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != 1) {
            return 0;
        }
        
        grid[i][j] = 0;  // Mark as visited
        int area = 1;
        
        for (auto [dx, dy] : dirs) {
            area += dfs(grid, i + dx, j + dy);
        }
        
        return area;
    }
};

int main() {
    Solution sol;
    
    vector<vector<int>> grid = {
        {0,0,1,0,0,0,0,1,0,0,0,0,0},
        {0,0,0,0,0,0,0,1,1,1,0,0,0},
        {0,1,1,0,1,0,0,0,0,0,0,0,0},
        {0,1,0,0,1,1,0,0,1,0,1,0,0},
        {0,1,0,0,1,1,0,0,1,1,1,0,0},
        {0,0,0,0,0,0,0,0,0,0,1,0,0},
        {0,0,0,0,0,0,0,1,1,1,0,0,0},
        {0,0,0,0,0,0,0,1,1,0,0,0,0}
    };
    
    cout << "Max area of island: " << sol.maxAreaOfIsland(grid) << endl;
    
    return 0;
}

/*
TIME COMPLEXITY: O(m * n) where m,n are grid dimensions
SPACE COMPLEXITY: O(m * n) for recursion stack in worst case

SIMILAR PROBLEMS:
1. Number of Islands (LeetCode #200)
2. Number of Closed Islands (LeetCode #1254)
3. Number of Enclaves (LeetCode #1020)
4. Number of Distinct Islands (LeetCode #694)
5. Island Perimeter (LeetCode #463)
6. Surrounded Regions (LeetCode #130)
7. Flood Fill (LeetCode #733)
8. Pacific Atlantic Water Flow (LeetCode #417)
9. Making A Large Island (LeetCode #827)
10. Count Sub Islands (LeetCode #1905)
*/
