"""
PROBLEM: Recover Binary Search Tree (LeetCode 99)
DIFFICULTY: Medium/Hard
PATTERN: BST - Inorder with Anomaly Detection

DESCRIPTION:
You are given the root of a binary search tree (BST) where the values of exactly
two nodes have been swapped by mistake. Recover the tree without changing its structure.

EXAMPLE:
Input: root = [1,3,null,null,2]
   1
  /
 3
  \
   2
Output: [3,1,null,null,2]
   3
  /
 1
  \
   2

Input: root = [3,1,4,null,null,2]
   3
  / \
 1   4
    /
   2
Output: [2,1,4,null,null,3]

TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(h) for recursion, O(1) with Morris traversal
"""

from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def recoverTree(self, root: Optional[TreeNode]) -> None:
        self.first: Optional[TreeNode] = None
        self.second: Optional[TreeNode] = None
        self.prev: Optional[TreeNode] = None

        def inorder(node: Optional[TreeNode]) -> None:
            if node is None:
                return
            inorder(node.left)
            if self.prev and self.prev.val > node.val:
                if self.first is None:
                    self.first = self.prev
                self.second = node
            self.prev = node
            inorder(node.right)

        inorder(root)
        if self.first and self.second:
            self.first.val, self.second.val = self.second.val, self.first.val


def build_tree1() -> TreeNode:
    root = TreeNode(1)
    root.left = TreeNode(3)
    root.left.right = TreeNode(2)
    return root


def build_tree2() -> TreeNode:
    root = TreeNode(3)
    root.left = TreeNode(1)
    root.right = TreeNode(4)
    root.right.left = TreeNode(2)
    return root


def print_inorder(root: Optional[TreeNode]) -> None:
    if root is None:
        return
    print_inorder(root.left)
    print(root.val, end=" ")
    print_inorder(root.right)


if __name__ == "__main__":
    sol = Solution()
    root1 = build_tree1()
    print("Before recovery: ", end="")
    print_inorder(root1)
    print()
    sol.recoverTree(root1)
    print("After recovery:  ", end="")
    print_inorder(root1)
    print()
    root2 = build_tree2()
    print("Before recovery: ", end="")
    print_inorder(root2)
    print()
    sol.recoverTree(root2)
    print("After recovery:  ", end="")
    print_inorder(root2)
    print()
