"""
PROBLEM: Flood Fill (LeetCode 733)
Difficulty: Easy
Pattern: DFS/BFS on Grid

DESCRIPTION:
Perform a flood fill on an image starting from pixel (sr, sc).
Replace the color of the starting pixel and all connected pixels of the same color
with a new color.

APPROACH:
1. Store the original color of starting pixel
2. If original color == new color, return (no change needed)
3. Use DFS to visit all connected pixels with same original color
4. Change their color to new color

TIME COMPLEXITY: O(M * N) where M = rows, N = columns
SPACE COMPLEXITY: O(M * N) for recursion stack in worst case
"""

from typing import List


class Solution:
    def dfs(self, image: List[List[int]], sr: int, sc: int, oldColor: int, newColor: int):
        m, n = len(image), len(image[0])
        # Base cases
        if sr < 0 or sr >= m or sc < 0 or sc >= n or image[sr][sc] != oldColor:
            return
        # Change color
        image[sr][sc] = newColor
        # Fill in all 4 directions
        self.dfs(image, sr + 1, sc, oldColor, newColor)
        self.dfs(image, sr - 1, sc, oldColor, newColor)
        self.dfs(image, sr, sc + 1, oldColor, newColor)
        self.dfs(image, sr, sc - 1, oldColor, newColor)

    def floodFill(self, image: List[List[int]], sr: int, sc: int, color: int) -> List[List[int]]:
        oldColor = image[sr][sc]
        if oldColor != color:
            self.dfs(image, sr, sc, oldColor, color)
        return image


if __name__ == "__main__":
    sol = Solution()
    image = [
        [1, 1, 1],
        [1, 1, 0],
        [1, 0, 1]
    ]
    sr, sc, newColor = 1, 1, 2
    print("Original Image:")
    for row in image:
        print(" ".join(map(str, row)))
    result = sol.floodFill(image, sr, sc, newColor)
    print("\nAfter Flood Fill:")
    for row in result:
        print(" ".join(map(str, row)))
