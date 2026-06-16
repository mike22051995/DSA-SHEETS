"""
PROBLEM: Kth Smallest Element in a BST (LeetCode 230)
DIFFICULTY: Medium
PATTERN: BST - Inorder Traversal

DESCRIPTION:
Given the root of a binary search tree, and an integer k,
return the kth smallest value (1-indexed) of all the values in the tree.

EXAMPLE:
Input: root = [3,1,4,null,2], k = 1
       3
      / \
     1   4
      \
       2
Output: 1

Input: root = [5,3,6,2,4,null,null,1], k = 3
       5
      / \
     3   6
    / \
   2   4
  /
 1
Output: 3

TIME COMPLEXITY: O(H + k) where H is height
SPACE COMPLEXITY: O(H) for recursion stack
"""

from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    # Approach 1: Recursive inorder
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        self.count = 0
        self.result = 0

        def inorder(node: Optional[TreeNode]) -> None:
            if node is None:
                return
            inorder(node.left)
            self.count += 1
            if self.count == k:
                self.result = node.val
                return
            inorder(node.right)

        inorder(root)
        return self.result

    # Approach 2: Iterative inorder with stack
    def kthSmallestIterative(self, root: Optional[TreeNode], k: int) -> int:
        stack = []
        count = 0
        curr: Optional[TreeNode] = root

        while curr or stack:
            while curr:
                stack.append(curr)
                curr = curr.left
            curr = stack.pop()
            count += 1
            if count == k:
                return curr.val
            curr = curr.right

        return -1


def build_bst() -> TreeNode:
    root = TreeNode(3)
    root.left = TreeNode(1)
    root.right = TreeNode(4)
    root.left.right = TreeNode(2)
    return root


if __name__ == "__main__":
    sol = Solution()
    root = build_bst()
    print(f"BST inorder: 1 2 3 4")
    print(f"1st smallest (Recursive): {sol.kthSmallest(root, 1)}")
    print(f"3rd smallest (Recursive): {sol.kthSmallest(root, 3)}")
    print(f"4th smallest (Iterative): {sol.kthSmallestIterative(root, 4)}")
