/*
================================================================================
PROBLEM: Shortest Bridge (LeetCode #934)
DIFFICULTY: Medium
PATTERN: DFS + BFS / Multi-source BFS
COMPANIES: Amazon, Microsoft, Google, Facebook
================================================================================

PROBLEM DESCRIPTION:
You are given an n x n binary matrix grid where 1 represents land and 0
represents water. An island is a 4-directionally connected group of 1's.
There are exactly two islands in grid. You may change 0's to 1's to connect
the two islands to form one island. Return the smallest number of 0's you
must flip to connect the two islands.

EXAMPLES:

Example 1:
Input: grid = [[0,1],[1,0]]
Output: 1

Example 2:
Input: grid = [[0,1,0],[0,0,0],[0,0,1]]
Output: 2

Example 3:
Input: grid = [[1,1,1,1,1],[1,0,0,0,1],[1,0,1,0,1],[1,0,0,0,1],[1,1,1,1,1]]
Output: 1

PATTERN RECOGNITION:
Use this pattern when:
- Need shortest path between two regions
- Combine DFS (to find region) and BFS (for shortest distance)
- Multi-source expansion from one island
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
private:
    vector<pair<int, int>> dirs = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int, int>> q;
        bool found = false;
        
        // DFS to find first island and mark it
        for (int i = 0; i < n && !found; i++) {
            for (int j = 0; j < n && !found; j++) {
                if (grid[i][j] == 1) {
                    dfs(grid, i, j, q);
                    found = true;
                }
            }
        }
        
        // BFS to expand from first island to second
        int steps = 0;
        
        while (!q.empty()) {
            int size = q.size();
            
            for (int i = 0; i < size; i++) {
                auto [x, y] = q.front();
                q.pop();
                
                for (auto [dx, dy] : dirs) {
                    int nx = x + dx;
                    int ny = y + dy;
                    
                    if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                        if (grid[nx][ny] == 1) {
                            return steps;
                        }
                        if (grid[nx][ny] == 0) {
                            grid[nx][ny] = 2;
                            q.push({nx, ny});
                        }
                    }
                }
            }
            
            steps++;
        }
        
        return -1;
    }
    
    void dfs(vector<vector<int>>& grid, int i, int j, queue<pair<int, int>>& q) {
        int n = grid.size();
        
        if (i < 0 || i >= n || j < 0 || j >= n || grid[i][j] != 1) {
            return;
        }
        
        grid[i][j] = 2;  // Mark as visited
        q.push({i, j});
        
        for (auto [dx, dy] : dirs) {
            dfs(grid, i + dx, j + dy, q);
        }
    }
};

int main() {
    Solution sol;
    
    vector<vector<int>> grid1 = {{0,1},{1,0}};
    cout << "Shortest bridge: " << sol.shortestBridge(grid1) << endl;
    
    vector<vector<int>> grid2 = {{0,1,0},{0,0,0},{0,0,1}};
    cout << "Shortest bridge: " << sol.shortestBridge(grid2) << endl;
    
    return 0;
}

/*
TIME COMPLEXITY: O(n^2) where n is grid size
SPACE COMPLEXITY: O(n^2) for queue and recursion

SIMILAR PROBLEMS:
1. Number of Islands (LeetCode #200)
2. Max Area of Island (LeetCode #695)
3. Number of Closed Islands (LeetCode #1254)
4. Flood Fill (LeetCode #733)
5. Surrounded Regions (LeetCode #130)
6. Rotting Oranges (LeetCode #994)
7. 01 Matrix (LeetCode #542)
8. As Far from Land as Possible (LeetCode #1162)
9. Making A Large Island (LeetCode #827)
10. Number of Distinct Islands (LeetCode #694)
*/
