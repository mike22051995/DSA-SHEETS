"""
PROBLEM: Binary Tree Postorder Traversal (LeetCode 145)
DIFFICULTY: Easy
PATTERN: Tree Traversal - DFS

DESCRIPTION:
Given the root of a binary tree, return the postorder traversal of its nodes' values.
Postorder: Left -> Right -> Root

EXAMPLE:
Input: root = [1,null,2,3]
       1
        \
         2
        /
       3
Output: [3,2,1]

Input: root = [1,2,3,4,5]
       1
      / \
     2   3
    / \
   4   5
Output: [4,5,2,3,1]

TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(h)
"""

from typing import List, Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    # Approach 1: Recursive
    def postorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        result: List[int] = []

        def helper(node: Optional[TreeNode]) -> None:
            if node is None:
                return
            helper(node.left)    # Left
            helper(node.right)   # Right
            result.append(node.val)  # Root

        helper(root)
        return result

    # Approach 2: Iterative (reverse of modified preorder: Root->Right->Left)
    def postorderTraversalIterative(self, root: Optional[TreeNode]) -> List[int]:
        result: List[int] = []
        if root is None:
            return result

        stack = [root]
        while stack:
            node = stack.pop()
            result.append(node.val)
            # Push left first, then right
            if node.left:
                stack.append(node.left)
            if node.right:
                stack.append(node.right)

        # Reverse gives left->right->root order
        result.reverse()
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
    print("Postorder Traversal (Recursive):", sol.postorderTraversal(root))
    print("Postorder Traversal (Iterative):", sol.postorderTraversalIterative(root))
