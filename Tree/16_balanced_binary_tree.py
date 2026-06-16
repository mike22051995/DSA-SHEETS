"""
PROBLEM: Balanced Binary Tree (LeetCode 110)
DIFFICULTY: Easy
PATTERN: DFS - Height with Balance Check

DESCRIPTION:
Given a binary tree, determine if it is height-balanced.
A height-balanced binary tree is one where the depth of the two subtrees 
of every node never differs by more than 1.

EXAMPLE:
Input: root = [3,9,20,null,null,15,7]
       3
      / \
     9  20
       /  \
      15   7
Output: True

Input: root = [1,2,2,3,3,null,null,4,4]
       1
      / \
     2   2
    / \
   3   3
  / \
 4   4
Output: False

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
    # Approach 1: Optimized O(n) - returns -1 if unbalanced
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        def check_height(node: Optional[TreeNode]) -> int:
            if node is None:
                return 0
            left_height = check_height(node.left)
            if left_height == -1:
                return -1
            right_height = check_height(node.right)
            if right_height == -1:
                return -1
            if abs(left_height - right_height) > 1:
                return -1
            return 1 + max(left_height, right_height)

        return check_height(root) != -1

    # Approach 2: Naive O(n^2) - compute height separately at each node
    def isBalancedNaive(self, root: Optional[TreeNode]) -> bool:
        def height(node: Optional[TreeNode]) -> int:
            if node is None:
                return 0
            return 1 + max(height(node.left), height(node.right))

        if root is None:
            return True
        left_h = height(root.left)
        right_h = height(root.right)
        if abs(left_h - right_h) > 1:
            return False
        return self.isBalancedNaive(root.left) and self.isBalancedNaive(root.right)


def build_balanced() -> TreeNode:
    root = TreeNode(3)
    root.left = TreeNode(9)
    root.right = TreeNode(20)
    root.right.left = TreeNode(15)
    root.right.right = TreeNode(7)
    return root


def build_unbalanced() -> TreeNode:
    root = TreeNode(1)
    root.left = TreeNode(2)
    root.left.left = TreeNode(3)
    root.left.left.left = TreeNode(4)
    root.right = TreeNode(2)
    return root


if __name__ == "__main__":
    sol = Solution()
    balanced = build_balanced()
    print(f"Balanced tree (Optimized): {sol.isBalanced(balanced)}")
    print(f"Balanced tree (Naive): {sol.isBalancedNaive(balanced)}")
    unbalanced = build_unbalanced()
    print(f"Unbalanced tree (Optimized): {sol.isBalanced(unbalanced)}")
    print(f"Unbalanced tree (Naive): {sol.isBalancedNaive(unbalanced)}")
