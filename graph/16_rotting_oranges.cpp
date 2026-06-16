/*
PROBLEM: Rotting Oranges (LeetCode 994)
Difficulty: Medium
Pattern: Multi-Source BFS

DESCRIPTION:
You are given a grid where:
- 0 represents an empty cell
- 1 represents a fresh orange
- 2 represents a rotten orange
Every minute, fresh oranges adjacent (4-directionally) to rotten oranges become rotten.
Return minimum minutes until no fresh oranges remain. If impossible, return -1.

GRID DIAGRAM:
  Minute 0:       Minute 1:       Minute 2:       Minute 3:       Minute 4:
  2 1 1           2 2 1           2 2 2           2 2 2           2 2 2
  1 1 0    -->    2 1 0    -->    2 2 0    -->    2 2 0    -->    2 2 0
  0 1 1           0 1 1           0 2 1           0 2 2           0 2 2

  Total time: 4 minutes (Multi-source BFS from all initial rotten oranges)
  Each level of BFS represents one minute passing

APPROACH:
1. Multi-source BFS starting from all rotten oranges
2. Count fresh oranges initially
3. Process level by level (each level = 1 minute)
4. Track time and fresh oranges rotted
5. If fresh oranges remain, return -1

TIME COMPLEXITY: O(M * N)
SPACE COMPLEXITY: O(M * N) for queue
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
        int freshCount = 0;
        
        // Find all rotten oranges and count fresh ones
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    freshCount++;
                }
            }
        }
        
        // If no fresh oranges, return 0
        if (freshCount == 0) return 0;
        
        int minutes = 0;
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        while (!q.empty()) {
            int size = q.size();
            bool rotted = false;
            
            for (int i = 0; i < size; i++) {
                auto [r, c] = q.front();
                q.pop();
                
                for (auto& dir : dirs) {
                    int nr = r + dir[0];
                    int nc = c + dir[1];
                    
                    if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 1) {
                        grid[nr][nc] = 2;
                        freshCount--;
                        q.push({nr, nc});
                        rotted = true;
                    }
                }
            }
            
            if (rotted) minutes++;
        }
        
        return freshCount == 0 ? minutes : -1;
    }
};

int main() {
    Solution sol;
    
    vector<vector<int>> grid = {
        {2, 1, 1},
        {1, 1, 0},
        {0, 1, 1}
    };
    
    cout << "Minutes until all oranges rot: " << sol.orangesRotting(grid) << endl;
    
    return 0;
}

/*
INPUT:
grid = [[2,1,1],
        [1,1,0],
        [0,1,1]]

OUTPUT:
Minutes until all oranges rot: 4

EXPLANATION:
Minute 0: (0,0) is rotten
Minute 1: (0,1), (1,0) become rotten
Minute 2: (0,2), (1,1) become rotten
Minute 3: (1,2) becomes rotten
Minute 4: (2,2) becomes rotten
*/
