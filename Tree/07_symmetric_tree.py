"""
PROBLEM: Symmetric Tree (LeetCode 101)
DIFFICULTY: Easy
PATTERN: DFS - Mirror Comparison

DESCRIPTION:
Given the root of a binary tree, check whether it is a mirror of itself
(i.e., symmetric around its center).

EXAMPLE:
Input: root = [1,2,2,3,4,4,3]
       1
      / \
     2   2
    / \ / \
   3  4 4  3
Output: True

Input: root = [1,2,2,null,3,null,3]
       1
      / \
     2   2
      \   \
       3   3
Output: False

TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(h)
"""

from typing import Optional
from collections import deque


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    # Approach 1: Recursive
    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        def is_mirror(left: Optional[TreeNode], right: Optional[TreeNode]) -> bool:
            if left is None and right is None:
                return True
            if left is None or right is None:
                return False
            return (left.val == right.val
                    and is_mirror(left.left, right.right)
                    and is_mirror(left.right, right.left))

        if root is None:
            return True
        return is_mirror(root.left, root.right)

    # Approach 2: Iterative BFS
    def isSymmetricIterative(self, root: Optional[TreeNode]) -> bool:
        if root is None:
            return True

        q: deque = deque([(root.left, root.right)])
        while q:
            left, right = q.popleft()
            if left is None and right is None:
                continue
            if left is None or right is None:
                return False
            if left.val != right.val:
                return False
            q.append((left.left, right.right))
            q.append((left.right, right.left))

        return True


def build_symmetric() -> TreeNode:
    root = TreeNode(1)
    root.left = TreeNode(2)
    root.right = TreeNode(2)
    root.left.left = TreeNode(3)
    root.left.right = TreeNode(4)
    root.right.left = TreeNode(4)
    root.right.right = TreeNode(3)
    return root


if __name__ == "__main__":
    sol = Solution()
    root = build_symmetric()
    print(f"Is Symmetric (Recursive): {sol.isSymmetric(root)}")
    print(f"Is Symmetric (Iterative): {sol.isSymmetricIterative(root)}")
