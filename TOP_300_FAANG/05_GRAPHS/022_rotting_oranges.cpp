/*
================================================================================
PROBLEM: Rotting Oranges (LeetCode #994)
DIFFICULTY: Medium
PATTERN: BFS / Multi-source BFS
COMPANIES: Amazon, Microsoft, Facebook, Google, Bloomberg
================================================================================

PROBLEM DESCRIPTION:
You are given an m x n grid where each cell can have one of three values:
0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten
orange becomes rotten. Return the minimum number of minutes that must elapse
until no cell has a fresh orange. If this is impossible, return -1.

EXAMPLES:

Example 1:
Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
Output: 4

Example 2:
Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
Output: -1

Example 3:
Input: grid = [[0,2]]
Output: 0

PATTERN RECOGNITION:
Use this pattern when:
- Multi-source simultaneous spreading
- Need minimum time/distance
- Grid-based level-order traversal
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        int fresh = 0;
        
        // Count fresh oranges and add rotten ones to queue
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }
        
        if (fresh == 0) return 0;
        
        int minutes = 0;
        vector<pair<int, int>> dirs = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        
        while (!q.empty()) {
            int size = q.size();
            bool rotted = false;
            
            for (int i = 0; i < size; i++) {
                auto [x, y] = q.front();
                q.pop();
                
                for (auto [dx, dy] : dirs) {
                    int nx = x + dx;
                    int ny = y + dy;
                    
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1) {
                        grid[nx][ny] = 2;
                        q.push({nx, ny});
                        fresh--;
                        rotted = true;
                    }
                }
            }
            
            if (rotted) minutes++;
        }
        
        return fresh == 0 ? minutes : -1;
    }
};

int main() {
    Solution sol;
    
    vector<vector<int>> grid1 = {{2,1,1},{1,1,0},{0,1,1}};
    cout << "Minutes: " << sol.orangesRotting(grid1) << endl;
    
    vector<vector<int>> grid2 = {{2,1,1},{0,1,1},{1,0,1}};
    cout << "Minutes: " << sol.orangesRotting(grid2) << endl;
    
    return 0;
}

/*
TIME COMPLEXITY: O(m * n) where m,n are grid dimensions
SPACE COMPLEXITY: O(m * n) for queue

SIMILAR PROBLEMS:
1. Walls and Gates (LeetCode #286)
2. 01 Matrix (LeetCode #542)
3. As Far from Land as Possible (LeetCode #1162)
4. Shortest Path in Binary Matrix (LeetCode #1091)
5. Number of Islands (LeetCode #200)
6. Surrounded Regions (LeetCode #130)
7. Pacific Atlantic Water Flow (LeetCode #417)
8. Number of Enclaves (LeetCode #1020)
9. Minimum Knight Moves (LeetCode #1197)
10. Shortest Bridge (LeetCode #934)
*/
