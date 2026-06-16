/*
================================================================================
PROBLEM: As Far from Land as Possible (LeetCode #1162)
DIFFICULTY: Medium
PATTERN: Multi-source BFS
COMPANIES: Amazon, Google, Facebook
================================================================================

PROBLEM DESCRIPTION:
Given an n x n grid containing only values 0 and 1, where 0 represents water
and 1 represents land, find a water cell such that its distance to the nearest
land cell is maximized, and return the distance. If no land or water exists in
the grid, return -1.

EXAMPLES:

Example 1:
Input: grid = [[1,0,1],[0,0,0],[1,0,1]]
Output: 2
Explanation: The cell (1, 1) is as far as possible from all land cells with distance 2.

Example 2:
Input: grid = [[1,0,0],[0,0,0],[0,0,0]]
Output: 4

PATTERN RECOGNITION:
Use this pattern when:
- Find maximum distance from multiple sources
- Multi-source BFS from all land cells
- Level-order traversal to track distance
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int, int>> q;
        
        // Add all land cells to queue
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                }
            }
        }
        
        // If all land or all water, return -1
        if (q.empty() || q.size() == n * n) {
            return -1;
        }
        
        vector<pair<int, int>> dirs = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        int distance = -1;
        
        while (!q.empty()) {
            int size = q.size();
            distance++;
            
            for (int i = 0; i < size; i++) {
                auto [x, y] = q.front();
                q.pop();
                
                for (auto [dx, dy] : dirs) {
                    int nx = x + dx;
                    int ny = y + dy;
                    
                    if (nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] == 0) {
                        grid[nx][ny] = 1;
                        q.push({nx, ny});
                    }
                }
            }
        }
        
        return distance;
    }
};

int main() {
    Solution sol;
    
    vector<vector<int>> grid1 = {{1,0,1},{0,0,0},{1,0,1}};
    cout << "Max distance: " << sol.maxDistance(grid1) << endl;
    
    vector<vector<int>> grid2 = {{1,0,0},{0,0,0},{0,0,0}};
    cout << "Max distance: " << sol.maxDistance(grid2) << endl;
    
    return 0;
}

/*
TIME COMPLEXITY: O(n^2) where n is grid size
SPACE COMPLEXITY: O(n^2) for queue

SIMILAR PROBLEMS:
1. 01 Matrix (LeetCode #542)
2. Rotting Oranges (LeetCode #994)
3. Walls and Gates (LeetCode #286)
4. Shortest Path in Binary Matrix (LeetCode #1091)
5. Shortest Bridge (LeetCode #934)
6. Number of Islands (LeetCode #200)
7. Pacific Atlantic Water Flow (LeetCode #417)
8. Surrounded Regions (LeetCode #130)
9. Flood Fill (LeetCode #733)
10. Number of Enclaves (LeetCode #1020)
*/
