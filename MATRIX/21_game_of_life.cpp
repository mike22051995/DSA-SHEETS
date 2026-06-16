/*
PROBLEM: Game of Life (LeetCode 289)
Difficulty: Medium
Company: Google, Meta, Amazon, Microsoft, Netflix
Pattern: In-Place Matrix State Update

DESCRIPTION:
Given a board with m x n cells, each cell has an initial state: live (1) or dead (0).
Each cell interacts with its 8 neighbors (horizontal, vertical, diagonal).
Apply the following rules simultaneously to all cells:
1. Live cell with < 2 live neighbors dies (underpopulation)
2. Live cell with 2-3 live neighbors lives
3. Live cell with > 3 live neighbors dies (overpopulation)
4. Dead cell with exactly 3 live neighbors becomes alive (reproduction)

MATRIX DIAGRAM:
  Initial State:         After 1 Generation:
  0  1  0                0  0  0
  0  0  1         -->    1  0  1
  1  1  1                0  1  1
  0  0  0                0  1  0
  
  Cell (1,1): 0 with 3 live neighbors → becomes 1 (reproduction)
  Cell (2,1): 1 with 3 live neighbors → stays 1
  Cell (2,2): 1 with 5 live neighbors → dies (overpopulation)
  
  In-place encoding:
  - Use 2 bits: [new_state][old_state]
  - 0→0: 00 (stays dead)
  - 1→0: 01 (was live, now dead) 
  - 0→1: 10 (was dead, now live)
  - 1→1: 11 (stays live)

APPROACH:
1. Count live neighbors for each cell
2. Apply rules and encode new state in higher bit
3. Update all cells by shifting right (new_state >> 1)

Follow-up: Infinite board → Use hash set to store only live cells

TIME COMPLEXITY: O(M * N)
SPACE COMPLEXITY: O(1) - in-place with bit manipulation
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        if (board.empty()) return;
        
        int m = board.size();
        int n = board[0].size();
        
        // Directions for 8 neighbors
        int dirs[8][2] = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
        
        // First pass: encode new state in second bit
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int liveNeighbors = 0;
                
                // Count live neighbors (check only first bit)
                for (auto& dir : dirs) {
                    int ni = i + dir[0];
                    int nj = j + dir[1];
                    
                    if (ni >= 0 && ni < m && nj >= 0 && nj < n) {
                        liveNeighbors += board[ni][nj] & 1;
                    }
                }
                
                // Apply rules
                if ((board[i][j] & 1) == 1) {
                    // Currently alive
                    if (liveNeighbors == 2 || liveNeighbors == 3) {
                        board[i][j] = 3; // 11: stays alive
                    }
                    // else board[i][j] = 1 (01: dies)
                } else {
                    // Currently dead
                    if (liveNeighbors == 3) {
                        board[i][j] = 2; // 10: becomes alive
                    }
                    // else board[i][j] = 0 (00: stays dead)
                }
            }
        }
        
        // Second pass: update to new state
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                board[i][j] >>= 1;
            }
        }
    }
    
    // Follow-up: Infinite board using hash set
    void gameOfLifeInfinite(vector<vector<int>>& board) {
        // Store only live cells as coordinates
        // For each live cell, increment neighbor counts
        // Apply rules based on counts
    }
};

int main() {
    Solution sol;
    
    vector<vector<int>> board = {
        {0, 1, 0},
        {0, 0, 1},
        {1, 1, 1},
        {0, 0, 0}
    };
    
    cout << "Initial Board:" << endl;
    for (auto& row : board) {
        for (int cell : row) cout << cell << " ";
        cout << endl;
    }
    
    sol.gameOfLife(board);
    
    cout << "\nAfter 1 Generation:" << endl;
    for (auto& row : board) {
        for (int cell : row) cout << cell << " ";
        cout << endl;
    }
    
    return 0;
}

/*
INPUT:
board = [[0,1,0],
         [0,0,1],
         [1,1,1],
         [0,0,0]]

OUTPUT:
[[0,0,0],
 [1,0,1],
 [0,1,1],
 [0,1,0]]

EXPLANATION:
Cell by cell analysis:
(0,0): 0, neighbors=1 → stays 0
(0,1): 1, neighbors=1 → dies (underpopulation)
(0,2): 0, neighbors=2 → stays 0
(1,0): 0, neighbors=3 → becomes 1 (reproduction)
(1,1): 0, neighbors=5 → stays 0
(1,2): 1, neighbors=3 → stays 1
(2,0): 1, neighbors=1 → dies
(2,1): 1, neighbors=3 → stays 1
(2,2): 1, neighbors=2 → stays 1
(3,0): 0, neighbors=2 → stays 0
(3,1): 0, neighbors=3 → becomes 1
(3,2): 0, neighbors=2 → stays 0
*/
