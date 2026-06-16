/*
================================================================================
PROBLEM: Shortest Path in Binary Matrix (LeetCode #1091)
DIFFICULTY: Medium
PATTERN: BFS / Shortest Path
COMPANIES: Amazon, Microsoft, Google, Facebook
================================================================================

PROBLEM DESCRIPTION:
Given an n x n binary matrix grid, return the length of the shortest clear path
in the matrix. If there is no clear path, return -1. A clear path in a binary
matrix is a path from the top-left cell (i.e., (0, 0)) to the bottom-right cell
(i.e., (n - 1, n - 1)) such that:
- All the visited cells of the path are 0.
- All the adjacent cells are 8-directionally connected.
The length of a clear path is the number of visited cells of this path.

EXAMPLES:

Example 1:
Input: grid = [[0,1],[1,0]]
Output: 2

Example 2:
Input: grid = [[0,0,0],[1,1,0],[1,1,0]]
Output: 4

Example 3:
Input: grid = [[1,0,0],[1,1,0],[1,1,0]]
Output: -1

PATTERN RECOGNITION:
Use this pattern when:
- Shortest path in unweighted grid
- BFS for level-order traversal
- 8-directional movement allowed
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1) {
            return -1;
        }
        
        if (n == 1) return 1;
        
        vector<pair<int, int>> dirs = {{0,1}, {1,0}, {0,-1}, {-1,0}, 
                                       {1,1}, {1,-1}, {-1,1}, {-1,-1}};
        
        queue<pair<int, int>> q;
        q.push({0, 0});
        grid[0][0] = 1;
        int pathLength = 1;
        
        while (!q.empty()) {
            int size = q.size();
            
            for (int i = 0; i < size; i++) {
                auto [x, y] = q.front();
                q.pop();
                
                if (x == n - 1 && y == n - 1) {
                    return pathLength;
                }
                
                for (auto [dx, dy] : dirs) {
                    int nx = x + dx;
                    int ny = y + dy;
                    
                    if (nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] == 0) {
                        grid[nx][ny] = 1;
                        q.push({nx, ny});
                    }
                }
            }
            
            pathLength++;
        }
        
        return -1;
    }
};

int main() {
    Solution sol;
    
    vector<vector<int>> grid1 = {{0,1},{1,0}};
    cout << "Shortest path: " << sol.shortestPathBinaryMatrix(grid1) << endl;
    
    vector<vector<int>> grid2 = {{0,0,0},{1,1,0},{1,1,0}};
    cout << "Shortest path: " << sol.shortestPathBinaryMatrix(grid2) << endl;
    
    vector<vector<int>> grid3 = {{1,0,0},{1,1,0},{1,1,0}};
    cout << "Shortest path: " << sol.shortestPathBinaryMatrix(grid3) << endl;
    
    return 0;
}

/*
TIME COMPLEXITY: O(n^2) where n is grid size
SPACE COMPLEXITY: O(n^2) for queue

SIMILAR PROBLEMS:
1. Shortest Path to Get Food (LeetCode #1730)
2. Minimum Knight Moves (LeetCode #1197)
3. As Far from Land as Possible (LeetCode #1162)
4. 01 Matrix (LeetCode #542)
5. Rotting Oranges (LeetCode #994)
6. Walls and Gates (LeetCode #286)
7. Shortest Bridge (LeetCode #934)
8. Word Ladder (LeetCode #127)
9. Open the Lock (LeetCode #752)
10. Shortest Path with Alternating Colors (LeetCode #1129)
*/
