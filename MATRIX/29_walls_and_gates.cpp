/*
PROBLEM: Walls and Gates (LeetCode 286)
Difficulty: Medium
Company: Google, Meta, Amazon, Microsoft
Pattern: Multi-source BFS

DESCRIPTION:
You are given an m x n grid rooms initialized with these three possible values:
- -1: A wall or an obstacle
- 0: A gate
- INF: An empty room (use 2147483647 to represent INF)

Fill each empty room with the distance to its nearest gate. If it is impossible 
to reach a gate, it should be filled with INF.

GRID DIAGRAM:
  Initial:               After filling:
  INF -1  0   INF        3  -1  0   1
  INF INF INF -1  -->    2   2  1  -1
  INF -1  INF -1         1  -1  2  -1
  0   -1  INF INF        0  -1  3   4
  
  Multi-source BFS:
  - Start BFS from all gates (0's) simultaneously
  - Each gate expands outward level by level
  - First gate to reach a room determines its distance

APPROACH:
1. Add all gates (cells with value 0) to queue
2. Perform multi-source BFS:
   - For each cell in queue, explore 4 directions
   - If neighbor is INF (empty room), update with distance + 1
   - Add updated neighbor to queue
3. Continue until queue is empty
4. Unreachable rooms remain INF

Why multi-source BFS?
- More efficient than running BFS from each gate separately
- Naturally computes minimum distance to any gate
- Each room visited only once

TIME COMPLEXITY: O(M * N)
SPACE COMPLEXITY: O(M * N) for queue
*/

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        if (rooms.empty() || rooms[0].empty()) return;
        
        int m = rooms.size();
        int n = rooms[0].size();
        const int INF = INT_MAX;
        
        queue<pair<int, int>> q;
        
        // Add all gates to queue
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (rooms[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }
        
        // 4 directions
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        // Multi-source BFS
        while (!q.empty()) {
            auto [row, col] = q.front();
            q.pop();
            
            for (auto& dir : dirs) {
                int nrow = row + dir[0];
                int ncol = col + dir[1];
                
                // Check bounds and if cell is empty room (INF)
                if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n 
                    && rooms[nrow][ncol] == INF) {
                    rooms[nrow][ncol] = rooms[row][col] + 1;
                    q.push({nrow, ncol});
                }
            }
        }
    }
};

int main() {
    Solution sol;
    
    const int INF = INT_MAX;
    vector<vector<int>> rooms = {
        {INF, -1, 0, INF},
        {INF, INF, INF, -1},
        {INF, -1, INF, -1},
        {0, -1, INF, INF}
    };
    
    cout << "Initial grid (INF=2147483647):" << endl;
    for (auto& row : rooms) {
        for (int val : row) {
            if (val == INF) cout << "INF ";
            else if (val == -1) cout << " -1 ";
            else cout << "  " << val << " ";
        }
        cout << endl;
    }
    
    sol.wallsAndGates(rooms);
    
    cout << "\nAfter filling distances:" << endl;
    for (auto& row : rooms) {
        for (int val : row) {
            if (val == INF) cout << "INF ";
            else if (val == -1) cout << " -1 ";
            else cout << "  " << val << " ";
        }
        cout << endl;
    }
    
    return 0;
}

/*
INPUT:
rooms = [[INF,-1,0,INF],
         [INF,INF,INF,-1],
         [INF,-1,INF,-1],
         [0,-1,INF,INF]]

OUTPUT:
[[3,-1,0,1],
 [2,2,1,-1],
 [1,-1,2,-1],
 [0,-1,3,4]]

EXPLANATION:
Two gates at (0,2) and (3,0).

BFS expansion:
Level 0: Gates at (0,2) and (3,0) [distance 0]
Level 1: From (0,2): (0,3)=1, (1,2)=1
         From (3,0): (2,0)=1
Level 2: From (0,3): no new cells
         From (1,2): (1,1)=2, (2,2)=2
         From (2,0): (1,0)=2
Level 3: From (1,1): (0,0)=3
         From (2,2): (3,2)=3
Level 4: From (3,2): (3,3)=4

Cell (0,0): Distance 3 via (3,0)→(2,0)→(1,0)→(0,0)
            or (0,2)→(1,2)→(1,1)→(0,0)
            Both paths = 3, BFS finds shortest naturally

Cell (3,3): Distance 4 via (0,2)→(1,2)→(2,2)→(3,2)→(3,3)

Another example:
INPUT: [[INF,INF,INF],
        [INF,-1,INF],
        [0,INF,INF]]
OUTPUT: [[4,3,4],
         [3,-1,3],
         [0,1,2]]
*/
