"""
PROBLEM: Binary Tree Level Order Traversal (LeetCode 102)
DIFFICULTY: Medium (but fundamental)
PATTERN: BFS - Level Order Traversal

DESCRIPTION:
Given the root of a binary tree, return the level order traversal of its nodes' values.
(i.e., from left to right, level by level).

EXAMPLE:
Input: root = [3,9,20,null,null,15,7]
       3
      / \
     9  20
       /  \
      15   7
Output: [[3],[9,20],[15,7]]

Input: root = [1]
Output: [[1]]

TIME COMPLEXITY: O(n) - visit each node once
SPACE COMPLEXITY: O(w) - w is max width of tree (queue size)
"""

from typing import List, Optional
from collections import deque


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        result: List[List[int]] = []
        if root is None:
            return result

        q: deque = deque([root])

        while q:
            level_size = len(q)
            current_level: List[int] = []

            for _ in range(level_size):
                node = q.popleft()
                current_level.append(node.val)

                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)

            result.append(current_level)

        return result


def build_tree() -> TreeNode:
    root = TreeNode(3)
    root.left = TreeNode(9)
    root.right = TreeNode(20)
    root.right.left = TreeNode(15)
    root.right.right = TreeNode(7)
    return root


if __name__ == "__main__":
    sol = Solution()
    root = build_tree()
    result = sol.levelOrder(root)
    print("Level Order Traversal:")
    for i, level in enumerate(result):
        print(f"  Level {i}: {level}")
