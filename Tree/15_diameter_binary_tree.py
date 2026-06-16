"""
PROBLEM: Diameter of Binary Tree (LeetCode 543)
DIFFICULTY: Easy/Medium
PATTERN: DFS - Height with Global Variable

DESCRIPTION:
Given the root of a binary tree, return the length of the diameter of the tree.
The diameter is the length of the longest path between any two nodes in a tree.
The path may or may not pass through the root.
The length is measured in number of edges.

EXAMPLE:
Input: root = [1,2,3,4,5]
       1
      / \
     2   3
    / \
   4   5
Output: 3 (path: [4,2,1,3] or [5,2,1,3])

Input: root = [1,2]
       1
      /
     2
Output: 1

TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(h)
"""



from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        self.diameter = 0

        def dfs(node: Optional[TreeNode]) -> int:
            if node is None:
                return 0
            left_height = dfs(node.left)
            right_height = dfs(node.right)
            # Update diameter if path through this node is longer
            self.diameter = max(self.diameter, left_height + right_height)
            return 1 + max(left_height, right_height)

        dfs(root)
        return self.diameter


def build_tree() -> TreeNode:
    root = TreeNode(1)
    root.left = TreeNode(2)
    root.right = TreeNode(3)
    root.left.left = TreeNode(4)
    root.left.right = TreeNode(5)
    return root


def build_skewed() -> TreeNode:
    root = TreeNode(1)
    root.left = TreeNode(2)
    root.left.left = TreeNode(3)
    root.left.left.left = TreeNode(4)
    return root


if __name__ == "__main__":
    sol = Solution()
    root1 = build_tree()
    print(f"Diameter of tree 1: {sol.diameterOfBinaryTree(root1)}")
    root2 = build_skewed()
    print(f"Diameter of tree 2: {sol.diameterOfBinaryTree(root2)}")

