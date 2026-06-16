"""
PROBLEM: Validate Binary Search Tree (LeetCode 98)
DIFFICULTY: Medium
PATTERN: BST Validation - Range Checking

DESCRIPTION:
Given the root of a binary tree, determine if it is a valid binary search tree (BST).
A valid BST is defined as follows:
- The left subtree of a node contains only nodes with keys less than the node's key.
- The right subtree contains only nodes with keys greater than the node's key.
- Both left and right subtrees must also be binary search trees.

EXAMPLE:
Input: root = [2,1,3]
    2
   / \
  1   3
Output: True

Input: root = [5,1,4,null,null,3,6]
    5
   / \
  1   4
     / \
    3   6
Output: False (3 < 5 but it's in right subtree)

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
    # Approach 1: Range checking (recursive)
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        def helper(node: Optional[TreeNode], min_val: float, max_val: float) -> bool:
            if node is None:
                return True
            if node.val <= min_val or node.val >= max_val:
                return False
            return (helper(node.left, min_val, node.val)
                    and helper(node.right, node.val, max_val))

        return helper(root, float('-inf'), float('inf'))

    # Approach 2: Inorder traversal (must be strictly increasing)
    def isValidBSTInorder(self, root: Optional[TreeNode]) -> bool:
        self.prev: Optional[int] = None

        def inorder(node: Optional[TreeNode]) -> bool:
            if node is None:
                return True
            if not inorder(node.left):
                return False
            if self.prev is not None and node.val <= self.prev:
                return False
            self.prev = node.val
            return inorder(node.right)

        return inorder(root)


def build_valid_bst() -> TreeNode:
    root = TreeNode(2)
    root.left = TreeNode(1)
    root.right = TreeNode(3)
    return root


def build_invalid_bst() -> TreeNode:
    root = TreeNode(5)
    root.left = TreeNode(1)
    root.right = TreeNode(4)
    root.right.left = TreeNode(3)
    root.right.right = TreeNode(6)
    return root


if __name__ == "__main__":
    sol = Solution()
    valid_bst = build_valid_bst()
    print(f"Valid BST (Range): {sol.isValidBST(valid_bst)}")
    print(f"Valid BST (Inorder): {sol.isValidBSTInorder(valid_bst)}")
    invalid_bst = build_invalid_bst()
    print(f"Invalid BST (Range): {sol.isValidBST(invalid_bst)}")
    print(f"Invalid BST (Inorder): {sol.isValidBSTInorder(invalid_bst)}")
