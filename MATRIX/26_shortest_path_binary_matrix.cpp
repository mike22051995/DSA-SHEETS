/*
PROBLEM: Shortest Path in Binary Matrix (LeetCode 1091)
Difficulty: Medium
Company: Google, Meta, Amazon, Microsoft
Pattern: BFS - Shortest Path in Grid

DESCRIPTION:
Given an n x n binary matrix grid, return the length of the shortest clear path 
in the matrix. If there is no clear path, return -1.

A clear path is a path from top-left to bottom-right cell such that:
- All visited cells are 0
- All adjacent cells are 8-directionally connected
- Length = number of visited cells

GRID DIAGRAM:
  Grid:                  BFS Distance:
  0  0  0                1  2  3
  1  1  0         -->    X  X  4
  1  1  0                X  X  5
  
  Shortest path: (0,0)→(0,1)→(0,2)→(1,2)→(2,2)
  Length: 5
  
  8 directions:
  (-1,-1) (-1,0) (-1,1)
  (0,-1)   (*)   (0,1)
  (1,-1)  (1,0)  (1,1)

APPROACH:
1. Check if start or end is blocked (value 1) → return -1
2. Use BFS starting from (0,0)
3. For each cell, explore all 8 directions
4. Track visited cells to avoid revisiting
5. When reaching (n-1, n-1), return distance
6. If BFS completes without reaching end → return -1

TIME COMPLEXITY: O(N²)
SPACE COMPLEXITY: O(N²) for queue and visited set
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        
        // Check if start or end is blocked
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1) {
            return -1;
        }
        
        // Special case: single cell
        if (n == 1) return 1;
        
        // 8 directions
        int dirs[8][2] = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
        
        queue<pair<int, int>> q;
        q.push({0, 0});
        grid[0][0] = 1; // Mark as visited (use 1 to store distance)
        
        while (!q.empty()) {
            auto [row, col] = q.front();
            q.pop();
            
            int distance = grid[row][col];
            
            // Check if reached destination
            if (row == n - 1 && col == n - 1) {
                return distance;
            }
            
            // Explore 8 directions
            for (auto& dir : dirs) {
                int nrow = row + dir[0];
                int ncol = col + dir[1];
                
                // Check bounds and if cell is clear and unvisited
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < n 
                    && grid[nrow][ncol] == 0) {
                    grid[nrow][ncol] = distance + 1;
                    q.push({nrow, ncol});
                }
            }
        }
        
        return -1; // No path found
    }
    
    // Alternative: Using separate visited array
    int shortestPathBinaryMatrixWithVisited(vector<vector<int>>& grid) {
        int n = grid.size();
        
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1) {
            return -1;
        }
        
        if (n == 1) return 1;
        
        int dirs[8][2] = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
        
        queue<tuple<int, int, int>> q; // {row, col, distance}
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        
        q.push({0, 0, 1});
        visited[0][0] = true;
        
        while (!q.empty()) {
            auto [row, col, dist] = q.front();
            q.pop();
            
            if (row == n - 1 && col == n - 1) {
                return dist;
            }
            
            for (auto& dir : dirs) {
                int nrow = row + dir[0];
                int ncol = col + dir[1];
                
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < n 
                    && grid[nrow][ncol] == 0 && !visited[nrow][ncol]) {
                    visited[nrow][ncol] = true;
                    q.push({nrow, ncol, dist + 1});
                }
            }
        }
        
        return -1;
    }
};

int main() {
    Solution sol;
    
    vector<vector<int>> grid1 = {
        {0, 1},
        {1, 0}
    };
    
    cout << "Grid 1:" << endl;
    for (auto& row : grid1) {
        for (int val : row) cout << val << " ";
        cout << endl;
    }
    cout << "Shortest path: " << sol.shortestPathBinaryMatrix(grid1) << endl;
    
    vector<vector<int>> grid2 = {
        {0, 0, 0},
        {1, 1, 0},
        {1, 1, 0}
    };
    
    cout << "\nGrid 2:" << endl;
    for (auto& row : grid2) {
        for (int val : row) cout << val << " ";
        cout << endl;
    }
    
    // Need to copy since first solution modifies grid
    auto grid2_copy = grid2;
    cout << "Shortest path: " << sol.shortestPathBinaryMatrixWithVisited(grid2_copy) << endl;
    
    return 0;
}

/*
INPUT:
grid = [[0,1],
        [1,0]]

OUTPUT:
2

EXPLANATION:
Shortest path: (0,0)→(1,1) (diagonal move)
Length: 2

For grid2:
INPUT:
grid = [[0,0,0],
        [1,1,0],
        [1,1,0]]

OUTPUT:
4

EXPLANATION:
Shortest path: (0,0)→(0,1)→(0,2)→(1,2)→(2,2)
Length: 4

BFS exploration:
Level 0: (0,0) [distance=1]
Level 1: (0,1) [distance=2] (can't go diagonally due to obstacles)
Level 2: (0,2) [distance=3]
Level 3: (1,2) [distance=4]
Level 4: (2,2) [distance=5] ← destination reached

For blocked grid:
INPUT: [[1,0,0],[1,1,0],[1,1,0]]
OUTPUT: -1
Start cell is blocked.

INPUT: [[0,1],[0,0]]
OUTPUT: 3
Path: (0,0)→(1,0)→(1,1) or (0,0)→(1,1)
Diagonal: 2, but (1,1) diagonal has obstacle at (0,1), so need to go around: 3
Actually: (0,0)→(1,1) is valid diagonally = 2
*/
