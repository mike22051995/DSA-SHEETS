/*
================================================================================
PROBLEM: 01 Matrix (LeetCode #542)
DIFFICULTY: Medium
PATTERN: Multi-source BFS / DP
COMPANIES: Amazon, Microsoft, Google, Facebook
================================================================================

PROBLEM DESCRIPTION:
Given an m x n binary matrix mat, return the distance of the nearest 0 for
each cell. The distance between two adjacent cells is 1.

EXAMPLES:

Example 1:
Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
Output: [[0,0,0],[0,1,0],[0,0,0]]

Example 2:
Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
Output: [[0,0,0],[0,1,0],[1,2,1]]

PATTERN RECOGNITION:
Use this pattern when:
- Need distance from multiple sources
- All cells equidistant from nearest source
- Multi-source BFS for level-order distance calculation
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    // Multi-source BFS
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        queue<pair<int, int>> q;
        
        // Add all 0s to queue
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        
        vector<pair<int, int>> dirs = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            
            for (auto [dx, dy] : dirs) {
                int nx = x + dx;
                int ny = y + dy;
                
                if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                    if (dist[nx][ny] > dist[x][y] + 1) {
                        dist[nx][ny] = dist[x][y] + 1;
                        q.push({nx, ny});
                    }
                }
            }
        }
        
        return dist;
    }
    
    // DP approach
    vector<vector<int>> updateMatrixDP(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX - 10000));
        
        // Top and left pass
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    dist[i][j] = 0;
                } else {
                    if (i > 0) dist[i][j] = min(dist[i][j], dist[i-1][j] + 1);
                    if (j > 0) dist[i][j] = min(dist[i][j], dist[i][j-1] + 1);
                }
            }
        }
        
        // Bottom and right pass
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (i < m - 1) dist[i][j] = min(dist[i][j], dist[i+1][j] + 1);
                if (j < n - 1) dist[i][j] = min(dist[i][j], dist[i][j+1] + 1);
            }
        }
        
        return dist;
    }
};

int main() {
    Solution sol;
    
    vector<vector<int>> mat = {{0,0,0},{0,1,0},{1,1,1}};
    auto result = sol.updateMatrix(mat);
    
    for (auto& row : result) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    
    return 0;
}

/*
TIME COMPLEXITY: O(m * n)
SPACE COMPLEXITY: O(m * n) for BFS queue, O(1) for DP approach

SIMILAR PROBLEMS:
1. Rotting Oranges (LeetCode #994)
2. Walls and Gates (LeetCode #286)
3. As Far from Land as Possible (LeetCode #1162)
4. Shortest Path in Binary Matrix (LeetCode #1091)
5. Shortest Bridge (LeetCode #934)
6. Nearest Exit from Entrance in Maze (LeetCode #1926)
7. Detonate the Maximum Bombs (LeetCode #2101)
8. Shortest Path to Get Food (LeetCode #1730)
9. Minimum Operations to Remove Adjacent Ones (LeetCode #2174)
10. Minimum Cost to Make at Least One Valid Path (LeetCode #1368)
*/
