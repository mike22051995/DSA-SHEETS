"""
PROBLEM: Maximum Depth of Binary Tree (LeetCode 104)
DIFFICULTY: Easy
PATTERN: DFS - Height Calculation

DESCRIPTION:
Given the root of a binary tree, return its maximum depth.
Maximum depth is the number of nodes along the longest path from root to leaf.

EXAMPLE:
Input: root = [3,9,20,null,null,15,7]
       3
      / \
     9  20
       /  \
      15   7
Output: 3

Input: root = [1,null,2]
       1
        \
         2
Output: 2

TIME COMPLEXITY: O(n) - visit each node once
SPACE COMPLEXITY: O(h) - recursion stack, h is height
"""

from typing import Optional
from collections import deque


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    # Approach 1: Recursive DFS
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        if root is None:
            return 0
        left_depth = self.maxDepth(root.left)
        right_depth = self.maxDepth(root.right)
        return 1 + max(left_depth, right_depth)

    # Approach 2: BFS Level Order
    def maxDepthBFS(self, root: Optional[TreeNode]) -> int:
        if root is None:
            return 0

        q: deque = deque([root])
        depth = 0

        while q:
            level_size = len(q)
            depth += 1
            for _ in range(level_size):
                node = q.popleft()
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)

        return depth


def build_tree() -> TreeNode:
    root = TreeNode(3)
    root.left = TreeNode(9)
    root.right = TreeNode(20)
    root.right.left = TreeNode(15)
    root.right.right = TreeNode(7)
    return root


if __name__ == "__main__":
    sol = Solution()
    root = build_tree()
    print(f"Maximum Depth (DFS): {sol.maxDepth(root)}")
    print(f"Maximum Depth (BFS): {sol.maxDepthBFS(root)}")
