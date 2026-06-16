"""
PROBLEM: Binary Tree Inorder Traversal (LeetCode 94)
DIFFICULTY: Easy
PATTERN: Tree Traversal - DFS

DESCRIPTION:
Given the root of a binary tree, return the inorder traversal of its nodes' values.
Inorder: Left -> Root -> Right

EXAMPLE:
Input: root = [1,null,2,3]
       1
        \
         2
        /
       3
Output: [1,3,2]

Input: root = [1,2,3,4,5]
       1
      / \
     2   3
    / \
   4   5
Output: [4,2,5,1,3]

TIME COMPLEXITY: O(n) - visit each node once
SPACE COMPLEXITY: O(h) - recursion stack, h is height
"""

from typing import List, Optional

class Solution:
    def inorderHelper(self, root, result):
        if root is None:
            return
        self.inorderHelper(root.left, result)  # Left
        result.append(root.val)  # Root
        self.inorderHelper(root.right, result)  # Right


if __name__ == "__main__":
    sol = Solution()
    # TreeNode and createSampleTree need to be properly defined
    # root = createSampleTree()
    # result = sol.inorderTraversal(root)
    # print("Inorder Traversal (Recursive): ", end="")
    # for val in result:
    #     print(val, end=" ")
    # print()
    # result2 = sol.inorderTraversalIterative(root)
    # print("Inorder Traversal (Iterative): ", end="")
    # for val in result2:
    #     print(val, end=" ")
    # print()
    pass
