/*
================================================================================
PROBLEM: Number of Islands (LeetCode #200)
DIFFICULTY: Medium
PATTERN: Graph DFS/BFS / Union Find
COMPANIES: Amazon, Facebook, Google, Microsoft, Bloomberg, Apple
================================================================================

PROBLEM DESCRIPTION:
Given an m x n 2D binary grid which represents a map of '1's (land) and '0's 
(water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands 
horizontally or vertically. You may assume all four edges of the grid are all 
surrounded by water.

================================================================================
PATTERN RECOGNITION:
Use this pattern when:
1. Finding connected components in grid
2. Need to visit all cells in a region
3. Graph traversal on 2D matrix
4. Counting separate groups/clusters

Key Indicators:
- "Connected components"
- "Number of islands/regions"
- 2D grid traversal
- Can use DFS, BFS, or Union Find

================================================================================
INPUT/OUTPUT EXAMPLES:

Example 1:
Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1
Explanation: One large island

Example 2:
Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3
Explanation: Three separate islands

Example 3:
Input: grid = [
  ["1","0","1","0","1"],
  ["0","1","0","1","0"],
  ["1","0","1","0","1"]
]
Output: 13
Explanation: Each '1' is a separate island

================================================================================
EXPLANATION:

DFS Approach:
1. Iterate through each cell
2. If cell is '1' (unvisited land):
   - Increment island count
   - DFS to mark entire island as visited
3. During DFS:
   - Mark current cell as visited ('0' or use visited array)
   - Recursively visit all 4 adjacent cells

Why DFS?
- Explores entire island before moving to next
- Natural recursion for connected components
- In-place modification possible

BFS Alternative:
- Use queue instead of recursion
- Level by level exploration
- Same time/space complexity

Time Complexity: O(m * n) - visit each cell once
Space Complexity: O(m * n) - recursion stack or queue

================================================================================
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    // Approach 1: DFS (Most Common)
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;
        
        int rows = grid.size();
        int cols = grid[0].size();
        int count = 0;
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == '1') {
                    count++;
                    dfs(grid, i, j);
                }
            }
        }
        
        return count;
    }
    
    void dfs(vector<vector<char>>& grid, int i, int j) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        // Boundary check and water check
        if (i < 0 || i >= rows || j < 0 || j >= cols || grid[i][j] == '0') {
            return;
        }
        
        // Mark as visited
        grid[i][j] = '0';
        
        // Explore all 4 directions
        dfs(grid, i + 1, j);  // Down
        dfs(grid, i - 1, j);  // Up
        dfs(grid, i, j + 1);  // Right
        dfs(grid, i, j - 1);  // Left
    }
    
    // Approach 2: BFS
    int numIslandsBFS(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;
        
        int rows = grid.size();
        int cols = grid[0].size();
        int count = 0;
        
        vector<pair<int, int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == '1') {
                    count++;
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    grid[i][j] = '0';
                    
                    while (!q.empty()) {
                        auto [r, c] = q.front();
                        q.pop();
                        
                        for (auto [dr, dc] : directions) {
                            int nr = r + dr;
                            int nc = c + dc;
                            
                            if (nr >= 0 && nr < rows && nc >= 0 && nc < cols 
                                && grid[nr][nc] == '1') {
                                grid[nr][nc] = '0';
                                q.push({nr, nc});
                            }
                        }
                    }
                }
            }
        }
        
        return count;
    }
    
    // Approach 3: Union Find
    class UnionFind {
    public:
        vector<int> parent;
        vector<int> rank;
        int count;
        
        UnionFind(vector<vector<char>>& grid) {
            int rows = grid.size();
            int cols = grid[0].size();
            count = 0;
            parent.resize(rows * cols);
            rank.resize(rows * cols, 0);
            
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    if (grid[i][j] == '1') {
                        parent[i * cols + j] = i * cols + j;
                        count++;
                    }
                }
            }
        }
        
        int find(int x) {
            if (parent[x] != x) {
                parent[x] = find(parent[x]);  // Path compression
            }
            return parent[x];
        }
        
        void unite(int x, int y) {
            int rootX = find(x);
            int rootY = find(y);
            
            if (rootX != rootY) {
                if (rank[rootX] < rank[rootY]) {
                    parent[rootX] = rootY;
                } else if (rank[rootX] > rank[rootY]) {
                    parent[rootY] = rootX;
                } else {
                    parent[rootY] = rootX;
                    rank[rootX]++;
                }
                count--;
            }
        }
        
        int getCount() {
            return count;
        }
    };
    
    int numIslandsUnionFind(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;
        
        int rows = grid.size();
        int cols = grid[0].size();
        UnionFind uf(grid);
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == '1') {
                    // Check right and down neighbors
                    if (j + 1 < cols && grid[i][j + 1] == '1') {
                        uf.unite(i * cols + j, i * cols + j + 1);
                    }
                    if (i + 1 < rows && grid[i + 1][j] == '1') {
                        uf.unite(i * cols + j, (i + 1) * cols + j);
                    }
                }
            }
        }
        
        return uf.getCount();
    }
};

void runTest(vector<vector<char>> grid, string testName) {
    Solution sol;
    
    // Make copy for each test
    auto grid1 = grid;
    auto grid2 = grid;
    auto grid3 = grid;
    
    int result1 = sol.numIslands(grid1);
    int result2 = sol.numIslandsBFS(grid2);
    int result3 = sol.numIslandsUnionFind(grid3);
    
    cout << testName << ": " << endl;
    cout << "Grid: " << endl;
    for (auto& row : grid) {
        cout << "[";
        for (int i = 0; i < row.size(); i++) {
            cout << "\"" << row[i] << "\"";
            if (i < row.size() - 1) cout << ",";
        }
        cout << "]" << endl;
    }
    cout << "Number of Islands (DFS): " << result1 << endl;
    cout << "Number of Islands (BFS): " << result2 << endl;
    cout << "Number of Islands (UF):  " << result3 << endl;
    cout << "-------------------" << endl;
}

int main() {
    vector<vector<char>> grid1 = {
        {'1','1','1','1','0'},
        {'1','1','0','1','0'},
        {'1','1','0','0','0'},
        {'0','0','0','0','0'}
    };
    runTest(grid1, "Test 1");
    
    vector<vector<char>> grid2 = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };
    runTest(grid2, "Test 2");
    
    return 0;
}

/*
================================================================================
SIMILAR LEETCODE PROBLEMS:
================================================================================
1. Max Area of Island (LeetCode #695) - Medium
   - Find largest island area

2. Number of Closed Islands (LeetCode #1254) - Medium
   - Islands not touching border

3. Number of Distinct Islands (LeetCode #694) - Medium
   - Count unique island shapes

4. Surrounded Regions (LeetCode #130) - Medium
   - Flip regions not connected to border

5. Pacific Atlantic Water Flow (LeetCode #417) - Medium
   - Multi-source BFS/DFS

6. Flood Fill (LeetCode #733) - Easy
   - Color connected region

7. Shortest Bridge (LeetCode #934) - Medium
   - Find shortest path between islands

8. Making A Large Island (LeetCode #827) - Hard
   - Maximum island by flipping one 0

9. Count Sub Islands (LeetCode #1905) - Medium
   - Islands in grid1 contained in grid2

10. Number of Enclaves (LeetCode #1020) - Medium
    - Count land cells not connected to border

================================================================================
KEY PATTERNS & INSIGHTS:
================================================================================

1. DFS vs BFS:
   - DFS: Recursion, simpler code
   - BFS: Queue, level-by-level
   - Same time/space complexity
   - Choose based on problem needs

2. Visiting Strategy:
   - Mark as '0' (modifies input)
   - Use visited array (preserves input)
   - Both work, discuss trade-offs

3. Union Find Benefits:
   - Good for dynamic connectivity
   - Supports queries during construction
   - Path compression optimization

4. Common Variations:
   - Diagonal connections (8-directional)
   - Maximum island size
   - Unique island shapes
   - Border conditions

5. Interview Tips:
   - Clarify connectivity (4 or 8 directions)
   - Ask if can modify input
   - Discuss all three approaches
   - Mention space optimization

================================================================================
*/
