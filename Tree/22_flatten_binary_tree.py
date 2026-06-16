"""
PROBLEM: Flatten Binary Tree to Linked List (LeetCode 114)
DIFFICULTY: Medium
PATTERN: Tree Modification - Morris Traversal Style

DESCRIPTION:
Given the root of a binary tree, flatten the tree into a "linked list":
- The "linked list" should use TreeNode where right child is next, left is null
- The "linked list" should be in preorder traversal order

EXAMPLE:
Input: root = [1,2,5,3,4,null,6]
       1
      / \
     2   5
    / \   \
   3   4   6

Output: [1,null,2,null,3,null,4,null,5,null,6]
   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6

TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(1) for iterative, O(h) for recursive
"""

from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    # Approach 1: Recursive reverse preorder
    def flatten(self, root: Optional[TreeNode]) -> None:
        self.prev: Optional[TreeNode] = None

        def dfs(node: Optional[TreeNode]) -> None:
            if node is None:
                return
            dfs(node.right)
            dfs(node.left)
            node.right = self.prev
            node.left = None
            self.prev = node

        dfs(root)

    # Approach 2: Iterative O(1) space (Morris-like)
    def flattenIterative(self, root: Optional[TreeNode]) -> None:
        curr = root
        while curr:
            if curr.left:
                # Find rightmost node in left subtree
                rightmost = curr.left
                while rightmost.right:
                    rightmost = rightmost.right
                # Connect right subtree to rightmost of left
                rightmost.right = curr.right
                curr.right = curr.left
                curr.left = None
            curr = curr.right


def build_tree() -> TreeNode:
    root = TreeNode(1)
    root.left = TreeNode(2)
    root.right = TreeNode(5)
    root.left.left = TreeNode(3)
    root.left.right = TreeNode(4)
    root.right.right = TreeNode(6)
    return root


def print_flattened(root: Optional[TreeNode]) -> None:
    curr = root
    while curr:
        print(curr.val, end=" ")
        curr = curr.right
    print()


if __name__ == "__main__":
    sol = Solution()
    root1 = build_tree()
    print("Flattening tree (recursive): ", end="")
    sol.flatten(root1)
    print_flattened(root1)
    root2 = build_tree()
    print("Flattening tree (iterative): ", end="")
    sol.flattenIterative(root2)
    print_flattened(root2)
