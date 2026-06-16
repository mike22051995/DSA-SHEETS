"""
PROBLEM: Binary Tree Preorder Traversal (LeetCode 144)
DIFFICULTY: Easy
PATTERN: Tree Traversal - DFS

DESCRIPTION:
Given the root of a binary tree, return the preorder traversal of its nodes' values.
Preorder: Root -> Left -> Right

EXAMPLE:
Input: root = [1,null,2,3]
       1
        \
         2
        /
       3
Output: [1,2,3]

Input: root = [1,2,3,4,5]
       1
      / \
     2   3
    / \
   4   5
Output: [1,2,4,5,3]

TIME COMPLEXITY: O(n) - visit each node once
SPACE COMPLEXITY: O(h) - recursion stack, h is height
"""

from typing import List, Optional
from collections import deque


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    # Approach 1: Recursive
    def preorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        result: List[int] = []

        def helper(node: Optional[TreeNode]) -> None:
            if node is None:
                return
            result.append(node.val)     # Root
            helper(node.left)           # Left
            helper(node.right)          # Right

        helper(root)
        return result

    # Approach 2: Iterative using stack
    def preorderTraversalIterative(self, root: Optional[TreeNode]) -> List[int]:
        result: List[int] = []
        if root is None:
            return result

        stack = [root]
        while stack:
            node = stack.pop()
            result.append(node.val)
            # Push right first so left is processed first
            if node.right:
                stack.append(node.right)
            if node.left:
                stack.append(node.left)

        return result


def build_tree() -> TreeNode:
    root = TreeNode(1)
    root.left = TreeNode(2)
    root.right = TreeNode(3)
    root.left.left = TreeNode(4)
    root.left.right = TreeNode(5)
    return root


if __name__ == "__main__":
    sol = Solution()
    root = build_tree()
    print("Preorder Traversal (Recursive):", sol.preorderTraversal(root))
    print("Preorder Traversal (Iterative):", sol.preorderTraversalIterative(root))
