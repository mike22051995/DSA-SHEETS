/*
PROBLEM: Shortest Bridge (LeetCode 934)
Difficulty: Medium
Company: Google, Meta, Amazon
Pattern: DFS + BFS (Multi-source BFS)

DESCRIPTION:
You are given an n x n binary matrix grid where 1 represents land and 0 represents water.
An island is a 4-directionally connected group of 1's.
There are exactly two islands. Return the smallest number of 0's you must flip 
to connect the two islands.

GRID DIAGRAM:
  Grid:                  Strategy:
  0  1  0                1. Find first island (DFS)
  0  0  0         -->    2. Mark it and add to queue
  0  0  1                3. Expand from island (BFS) until reaching second island
  
  Steps:
  1. DFS from first 1 found → mark entire first island
  2. BFS from all cells of first island → expand level by level
  3. First time we hit a 1 (from second island) → return distance
  
  Distance = minimum flips needed

APPROACH:
1. Find any cell with value 1 (start of first island)
2. Use DFS to find all cells of first island and add to queue
3. Use BFS from all first island cells simultaneously (multi-source BFS)
4. Expand level by level through water (0's)
5. When BFS hits a 1, it's the second island → return level count
6. Level count = number of 0's flipped = shortest bridge

TIME COMPLEXITY: O(N²)
SPACE COMPLEXITY: O(N²) for queue and visited
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>>& grid, queue<pair<int, int>>& q, int i, int j) {
        int n = grid.size();
        
        if (i < 0 || i >= n || j < 0 || j >= n || grid[i][j] != 1) {
            return;
        }
        
        // Mark as visited (use 2 to distinguish from second island)
        grid[i][j] = 2;
        q.push({i, j});
        
        // DFS in 4 directions
        dfs(grid, q, i + 1, j);
        dfs(grid, q, i - 1, j);
        dfs(grid, q, i, j + 1);
        dfs(grid, q, i, j - 1);
    }
    
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int, int>> q;
        bool found = false;
        
        // Step 1: Find first island using DFS
        for (int i = 0; i < n && !found; i++) {
            for (int j = 0; j < n && !found; j++) {
                if (grid[i][j] == 1) {
                    dfs(grid, q, i, j);
                    found = true;
                }
            }
        }
        
        // Step 2: BFS from first island to find second island
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int distance = 0;
        
        while (!q.empty()) {
            int size = q.size();
            
            for (int k = 0; k < size; k++) {
                auto [i, j] = q.front();
                q.pop();
                
                for (auto& dir : dirs) {
                    int ni = i + dir[0];
                    int nj = j + dir[1];
                    
                    if (ni >= 0 && ni < n && nj >= 0 && nj < n) {
                        if (grid[ni][nj] == 1) {
                            // Found second island!
                            return distance;
                        }
                        if (grid[ni][nj] == 0) {
                            grid[ni][nj] = 2; // Mark as visited
                            q.push({ni, nj});
                        }
                    }
                }
            }
            
            distance++;
        }
        
        return -1; // Should never reach here
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
    cout << "Shortest bridge: " << sol.shortestBridge(grid1) << endl;
    
    vector<vector<int>> grid2 = {
        {0, 1, 0},
        {0, 0, 0},
        {0, 0, 1}
    };
    
    cout << "\nGrid 2:" << endl;
    for (auto& row : grid2) {
        for (int val : row) cout << val << " ";
        cout << endl;
    }
    cout << "Shortest bridge: " << sol.shortestBridge(grid2) << endl;
    
    vector<vector<int>> grid3 = {
        {1, 1, 1, 1, 1},
        {1, 0, 0, 0, 1},
        {1, 0, 1, 0, 1},
        {1, 0, 0, 0, 1},
        {1, 1, 1, 1, 1}
    };
    
    cout << "\nGrid 3:" << endl;
    for (auto& row : grid3) {
        for (int val : row) cout << val << " ";
        cout << endl;
    }
    cout << "Shortest bridge: " << sol.shortestBridge(grid3) << endl;
    
    return 0;
}

/*
INPUT:
grid = [[0,1],
        [1,0]]

OUTPUT:
1

EXPLANATION:
Two islands:
- Island 1: (0,1)
- Island 2: (1,0)

Flip (0,0) or (1,1) to connect them.
Distance = 1 flip needed.

For grid2:
INPUT:
grid = [[0,1,0],
        [0,0,0],
        [0,0,1]]

OUTPUT:
2

EXPLANATION:
Island 1: (0,1)
Island 2: (2,2)

BFS expansion from island 1:
Level 0: (0,1) [marked as island 1]
Level 1: (0,0), (1,1), (0,2) [expand through water]
Level 2: (1,0), (2,1), (1,2) [expand further]
Level 2: Hit (2,2) which is island 2!

Shortest path: (0,1)→(1,1)→(2,2) or (0,1)→(0,2)→(1,2)→(2,2)
Minimum flips: 2

For grid3:
INPUT:
grid = [[1,1,1,1,1],
        [1,0,0,0,1],
        [1,0,1,0,1],
        [1,0,0,0,1],
        [1,1,1,1,1]]

OUTPUT:
1

EXPLANATION:
Island 1: Outer ring (border)
Island 2: Center (2,2)

Shortest bridge: From any cell in outer ring to center.
Example: (1,2)→(2,2) or (2,1)→(2,2)
Distance: 1 flip needed
*/
