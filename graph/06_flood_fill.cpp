/*
PROBLEM: Flood Fill (LeetCode 733)
Difficulty: Easy
Pattern: DFS/BFS on Grid

DESCRIPTION:
Perform a flood fill on an image starting from pixel (sr, sc).
Replace the color of the starting pixel and all connected pixels of the same color
with a new color.

GRID DIAGRAM:
  Initial Image (sr=1, sc=1, newColor=2):
  1 1 1       After Flood Fill:
  1 1 0  -->  2 2 2  (All connected 1's become 2)
  1 0 1       2 0 1  (The 1 at bottom-right is not connected)

  Starting pixel (1,1) has color 1
  All connected pixels with color 1 are changed to color 2
  The isolated 1 at (2,2) remains unchanged

APPROACH:
1. Store the original color of starting pixel
2. If original color == new color, return (no change needed)
3. Use DFS to visit all connected pixels with same original color
4. Change their color to new color

TIME COMPLEXITY: O(M * N) where M = rows, N = columns
SPACE COMPLEXITY: O(M * N) for recursion stack in worst case
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc, int oldColor, int newColor) {
        int m = image.size();
        int n = image[0].size();
        
        // Base cases
        if (sr < 0 || sr >= m || sc < 0 || sc >= n || image[sr][sc] != oldColor) {
            return;
        }
        
        // Change color
        image[sr][sc] = newColor;
        
        // Fill in all 4 directions
        dfs(image, sr + 1, sc, oldColor, newColor); // down
        dfs(image, sr - 1, sc, oldColor, newColor); // up
        dfs(image, sr, sc + 1, oldColor, newColor); // right
        dfs(image, sr, sc - 1, oldColor, newColor); // left
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int oldColor = image[sr][sc];
        
        // If colors are same, no need to fill
        if (oldColor == newColor) {
            return image;
        }
        
        dfs(image, sr, sc, oldColor, newColor);
        return image;
    }
};

int main() {
    Solution sol;
    
    vector<vector<int>> image = {
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}
    };
    
    int sr = 1, sc = 1, newColor = 2;
    
    cout << "Original Image:" << endl;
    for (auto& row : image) {
        for (int pixel : row) {
            cout << pixel << " ";
        }
        cout << endl;
    }
    
    vector<vector<int>> result = sol.floodFill(image, sr, sc, newColor);
    
    cout << "\nAfter Flood Fill:" << endl;
    for (auto& row : result) {
        for (int pixel : row) {
            cout << pixel << " ";
        }
        cout << endl;
    }
    
    return 0;
}

/*
INPUT:
image = [[1,1,1],
         [1,1,0],
         [1,0,1]]
sr = 1, sc = 1, newColor = 2

OUTPUT:
[[2,2,2],
 [2,2,0],
 [2,0,1]]

EXPLANATION:
Starting from pixel (1,1) with color 1:
- All connected pixels with color 1 are changed to color 2
- The pixel at (1,2) with color 0 is not changed
- The pixel at (2,2) with color 1 is not connected, so not changed
*/
