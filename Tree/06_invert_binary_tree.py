"""
PROBLEM: Invert Binary Tree (LeetCode 226)
DIFFICULTY: Easy
PATTERN: DFS - Tree Modification

DESCRIPTION:
Given the root of a binary tree, invert the tree, and return its root.
Inverting means swapping left and right children at every node.

EXAMPLE:
Input: root = [4,2,7,1,3,6,9]
       4
      / \
     2   7
    / \ / \
   1  3 6  9

Output: [4,7,2,9,6,3,1]
       4
      / \
     7   2
    / \ / \
   9  6 3  1

TIME COMPLEXITY: O(n) - visit each node once
SPACE COMPLEXITY: O(h) - recursion stack
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
    def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        if root is None:
            return None
        root.left, root.right = root.right, root.left
        self.invertTree(root.left)
        self.invertTree(root.right)
        return root

    # Approach 2: BFS Iterative
    def invertTreeBFS(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        if root is None:
            return None
        q: deque = deque([root])
        while q:
            node = q.popleft()
            node.left, node.right = node.right, node.left
            if node.left:
                q.append(node.left)
            if node.right:
                q.append(node.right)
        return root


def inorder(root: Optional[TreeNode]) -> None:
    if root is None:
        return
    inorder(root.left)
    print(root.val, end=" ")
    inorder(root.right)


def build_tree() -> TreeNode:
    root = TreeNode(4)
    root.left = TreeNode(2)
    root.right = TreeNode(7)
    root.left.left = TreeNode(1)
    root.left.right = TreeNode(3)
    root.right.left = TreeNode(6)
    root.right.right = TreeNode(9)
    return root


if __name__ == "__main__":
    sol = Solution()
    root = build_tree()
    print("Original tree (inorder): ", end="")
    inorder(root)
    print()
    root = sol.invertTree(root)
    print("Inverted tree (inorder): ", end="")
    inorder(root)
    print()
