"""
PROBLEM: Binary Tree Maximum Width (LeetCode 662)
DIFFICULTY: Medium
PATTERN: BFS with Position Tracking

DESCRIPTION:
Given the root of a binary tree, return the maximum width of the given tree.
Width of one level = distance between leftmost and rightmost non-null nodes,
where null nodes in between are counted.

EXAMPLE:
Input: root = [1,3,2,5,3,null,9]
       1
      / \
     3   2
    / \   \
   5   3   9
Output: 4 (level with [5,3,null,9])

Input: root = [1,3,null,5,3]
       1
      /
     3
    / \
   5   3
Output: 2

TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(w) where w is max width
"""

from typing import Optional
from collections import deque


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def widthOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        if root is None:
            return 0

        max_width = 0
        q: deque = deque([(root, 0)])

        while q:
            level_size = len(q)
            _, leftmost = q[0]
            rightmost = leftmost

            for _ in range(level_size):
                node, pos = q.popleft()
                pos -= leftmost  # normalize to prevent overflow
                rightmost = pos
                if node.left:
                    q.append((node.left, 2 * pos))
                if node.right:
                    q.append((node.right, 2 * pos + 1))

            max_width = max(max_width, rightmost + 1)

        return max_width


def build_tree1() -> TreeNode:
    root = TreeNode(1)
    root.left = TreeNode(3)
    root.right = TreeNode(2)
    root.left.left = TreeNode(5)
    root.left.right = TreeNode(3)
    root.right.right = TreeNode(9)
    return root


def build_tree2() -> TreeNode:
    root = TreeNode(1)
    root.left = TreeNode(3)
    root.left.left = TreeNode(5)
    root.left.right = TreeNode(3)
    return root


if __name__ == "__main__":
    sol = Solution()
    root1 = build_tree1()
    print(f"Maximum width of tree 1: {sol.widthOfBinaryTree(root1)}")  # Expected: 4
    root2 = build_tree2()
    print(f"Maximum width of tree 2: {sol.widthOfBinaryTree(root2)}")  # Expected: 2

