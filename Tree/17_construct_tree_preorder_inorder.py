"""
PROBLEM: Construct Binary Tree from Preorder and Inorder Traversal (LeetCode 105)
DIFFICULTY: Medium
PATTERN: Tree Construction - Divide and Conquer

DESCRIPTION:
Given two integer arrays preorder and inorder where:
- preorder is the preorder traversal of a binary tree
- inorder is the inorder traversal of the same tree
Construct and return the binary tree.

EXAMPLE:
Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
       3
      / \
     9  20
       /  \
      15   7
Output: [3,9,20,null,null,15,7]

Input: preorder = [-1], inorder = [-1]
Output: [-1]

TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(n)
"""

from typing import List, Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        if not preorder or not inorder:
            return None

        # Build index map for O(1) inorder lookups
        inorder_map = {val: idx for idx, val in enumerate(inorder)}

        def helper(pre_start: int, pre_end: int,
                   in_start: int, in_end: int) -> Optional[TreeNode]:
            if pre_start > pre_end:
                return None
            root_val = preorder[pre_start]
            root = TreeNode(root_val)
            mid = inorder_map[root_val]
            left_size = mid - in_start

            root.left = helper(pre_start + 1, pre_start + left_size,
                                in_start, mid - 1)
            root.right = helper(pre_start + left_size + 1, pre_end,
                                 mid + 1, in_end)
            return root

        return helper(0, len(preorder) - 1, 0, len(inorder) - 1)


if __name__ == "__main__":
    sol = Solution()
    preorder = [3, 9, 20, 15, 7]
    inorder_arr = [9, 3, 15, 20, 7]
    root = sol.buildTree(preorder, inorder_arr)

    def preorder_print(node):
        if node is None:
            return
        print(node.val, end=" ")
        preorder_print(node.left)
        preorder_print(node.right)

    def inorder_print(node):
        if node is None:
            return
        inorder_print(node.left)
        print(node.val, end=" ")
        inorder_print(node.right)

    print("Constructed tree:")
    print("Preorder: ", end="")
    preorder_print(root)
    print()
    print("Inorder:  ", end="")
    inorder_print(root)
    print()

