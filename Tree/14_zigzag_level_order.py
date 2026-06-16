"""
PROBLEM: Binary Tree Zigzag Level Order Traversal (LeetCode 103)
DIFFICULTY: Medium
PATTERN: BFS - Level Order Variant

DESCRIPTION:
Given the root of a binary tree, return the zigzag level order traversal of its nodes' values.
(i.e., from left to right, then right to left for the next level and alternate between).

EXAMPLE:
Input: root = [3,9,20,null,null,15,7]
       3
      / \
     9  20
       /  \
      15   7
Output: [[3],[20,9],[15,7]]

Input: root = [1,2,3,4,null,null,5]
       1
      / \
     2   3
    /     \
   4       5
Output: [[1],[3,2],[4,5]]

TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(w) where w is max width
"""

from typing import List, Optional
from collections import deque


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    # Approach 1: Index manipulation
    def zigzagLevelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        result: List[List[int]] = []
        if root is None:
            return result

        q: deque = deque([root])
        left_to_right = True

        while q:
            level_size = len(q)
            current_level = [0] * level_size
            for i in range(level_size):
                node = q.popleft()
                idx = i if left_to_right else (level_size - 1 - i)
                current_level[idx] = node.val
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
            result.append(current_level)
            left_to_right = not left_to_right

        return result

    # Approach 2: Reverse approach (collect normally, then reverse odd levels)
    def zigzagLevelOrderReverse(self, root: Optional[TreeNode]) -> List[List[int]]:
        result: List[List[int]] = []
        if root is None:
            return result

        q: deque = deque([root])
        left_to_right = True

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
            if not left_to_right:
                current_level.reverse()
            result.append(current_level)
            left_to_right = not left_to_right

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
    print(f"Zigzag Level Order (Index): {sol.zigzagLevelOrder(root)}")
    print(f"Zigzag Level Order (Reverse): {sol.zigzagLevelOrderReverse(root)}")
