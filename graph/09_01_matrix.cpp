/*
PROBLEM: 01 Matrix (LeetCode 542)
Difficulty: Medium
Pattern: Multi-Source BFS

DESCRIPTION:
Given a matrix with 0s and 1s, find the distance of the nearest 0 for each cell.
Distance is calculated as |r1 - r2| + |c1 - c2| (Manhattan distance).

GRID DIAGRAM:
  Input:          Output (distances):
  0 0 0           0 0 0
  0 1 0    -->    0 1 0  (Cell at (1,1) is distance 1 from nearest 0)
  1 1 1           1 2 1  (Cell at (2,1) is distance 2 from nearest 0)

  Multi-source BFS: Start from all 0s simultaneously
  Each 1 gets the minimum distance to any 0

APPROACH:
1. Use multi-source BFS starting from all 0s simultaneously
2. Add all 0 cells to queue initially and set distance to 0
3. For cells with 1, set initial distance to infinity
4. Process BFS level by level, updating distances

TIME COMPLEXITY: O(M * N)
SPACE COMPLEXITY: O(M * N) for queue and distance matrix
*/

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        queue<pair<int, int>> q;
        
        // Add all 0s to queue and set their distance to 0
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        
        // Directions: up, down, left, right
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        // BFS
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            
            for (auto& dir : dirs) {
                int nr = r + dir[0];
                int nc = c + dir[1];
                
                if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                    if (dist[nr][nc] > dist[r][c] + 1) {
                        dist[nr][nc] = dist[r][c] + 1;
                        q.push({nr, nc});
                    }
                }
            }
        }
        
        return dist;
    }
};

int main() {
    Solution sol;
    
    vector<vector<int>> mat = {
        {0, 0, 0},
        {0, 1, 0},
        {1, 1, 1}
    };
    
    cout << "Input Matrix:" << endl;
    for (auto& row : mat) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    
    vector<vector<int>> result = sol.updateMatrix(mat);
    
    cout << "\nDistance Matrix:" << endl;
    for (auto& row : result) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    
    return 0;
}

/*
INPUT:
mat = [[0,0,0],
       [0,1,0],
       [1,1,1]]

OUTPUT:
[[0,0,0],
 [0,1,0],
 [1,2,1]]

EXPLANATION:
- All 0s have distance 0
- Cell (1,1) is distance 1 from nearest 0
- Cells (2,0) and (2,2) are distance 1 from nearest 0
- Cell (2,1) is distance 2 from nearest 0
*/
