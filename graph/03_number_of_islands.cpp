/*
PROBLEM: Number of Islands (LeetCode 200)
Difficulty: Easy-Medium
Pattern: DFS/BFS on Grid

DESCRIPTION:
Given a 2D grid of '1's (land) and '0's (water), count the number of islands.
An island is surrounded by water and formed by connecting adjacent lands horizontally or vertically.

GRID DIAGRAM:
  Initial Grid:
  1 1 0 0 0    Island 1: Connected 1's (top-left)
  1 1 0 0 0    
  0 0 1 0 0    Island 2: Single 1 (middle)
  0 0 0 1 1    Island 3: Connected 1's (bottom-right)

  Number of Islands: 3
  (Each group of connected 1's forms one island)

APPROACH:
1. Iterate through each cell in the grid
2. When we find an unvisited land ('1'), increment island count
3. Use DFS to mark all connected land cells as visited
4. Continue until all cells are processed

TIME COMPLEXITY: O(M * N) where M = rows, N = columns
SPACE COMPLEXITY: O(M * N) for recursion stack in worst case
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<char>>& grid, int i, int j) {
        int m = grid.size();
        int n = grid[0].size();
        
        // Base cases: out of bounds or water or already visited
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == '0') {
            return;
        }
        
        // Mark as visited by changing to '0'
        grid[i][j] = '0';
        
        // Visit all 4 directions
        dfs(grid, i + 1, j); // down
        dfs(grid, i - 1, j); // up
        dfs(grid, i, j + 1); // right
        dfs(grid, i, j - 1); // left
    }
    
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;
        
        int m = grid.size();
        int n = grid[0].size();
        int islands = 0;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    islands++;
                    dfs(grid, i, j);
                }
            }
        }
        
        return islands;
    }
};

int main() {
    Solution sol;
    
    // Example 1
    vector<vector<char>> grid1 = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}
    };
    
    cout << "Number of Islands: " << sol.numIslands(grid1) << endl;
    
    return 0;
}

/*
INPUT:
grid = [
  ['1','1','0','0','0'],
  ['1','1','0','0','0'],
  ['0','0','1','0','0'],
  ['0','0','0','1','1']
]

OUTPUT:
Number of Islands: 3

EXPLANATION:
Island 1: Top-left corner (4 connected 1's)
Island 2: Middle (single 1)
Island 3: Bottom-right corner (2 connected 1's)
*/
