"""
PROBLEM: Minimum Depth of Binary Tree (LeetCode 111)
DIFFICULTY: Easy
PATTERN: BFS/DFS - Depth Calculation

DESCRIPTION:
Given a binary tree, find its minimum depth.
The minimum depth is the number of nodes along the shortest path 
from the root node down to the nearest leaf node.
Note: A leaf is a node with no children.

EXAMPLE:
Input: root = [3,9,20,null,null,15,7]
       3
      / \
     9  20
       /  \
      15   7
Output: 2 (path: 3.9)

Input: root = [2,null,3,null,4,null,5,null,6]
       2
        \
         3
          \
           4
            \
             5
              \
               6
Output: 5

TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(w) for BFS, O(h) for DFS
"""

from typing import Optional
from collections import deque


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    # Approach 1: BFS (optimal - finds first leaf immediately)
    def minDepth(self, root: Optional[TreeNode]) -> int:
        if root is None:
            return 0

        q: deque = deque([root])
        depth = 1

        while q:
            level_size = len(q)
            for _ in range(level_size):
                node = q.popleft()
                # First leaf found - minimum depth
                if node.left is None and node.right is None:
                    return depth
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
            depth += 1

        return depth

    # Approach 2: Recursive DFS
    def minDepthDFS(self, root: Optional[TreeNode]) -> int:
        if root is None:
            return 0
        # Only right child exists
        if root.left is None:
            return 1 + self.minDepthDFS(root.right)
        # Only left child exists
        if root.right is None:
            return 1 + self.minDepthDFS(root.left)
        return 1 + min(self.minDepthDFS(root.left), self.minDepthDFS(root.right))


def build_tree() -> TreeNode:
    root = TreeNode(3)
    root.left = TreeNode(9)
    root.right = TreeNode(20)
    root.right.left = TreeNode(15)
    root.right.right = TreeNode(7)
    return root


def build_skewed() -> TreeNode:
    root = TreeNode(2)
    root.right = TreeNode(3)
    root.right.right = TreeNode(4)
    root.right.right.right = TreeNode(5)
    root.right.right.right.right = TreeNode(6)
    return root


if __name__ == "__main__":
    sol = Solution()
    root1 = build_tree()
    print(f"Minimum Depth (BFS): {sol.minDepth(root1)}")
    print(f"Minimum Depth (DFS): {sol.minDepthDFS(root1)}")
    root2 = build_skewed()
    print(f"Skewed tree - Minimum Depth (BFS): {sol.minDepth(root2)}")
    print(f"Skewed tree - Minimum Depth (DFS): {sol.minDepthDFS(root2)}")
