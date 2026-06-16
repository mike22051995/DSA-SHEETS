"""
PROBLEM: Binary Tree Right Side View (LeetCode 199)
DIFFICULTY: Medium
PATTERN: BFS/DFS - Level Order Variant

DESCRIPTION:
Given the root of a binary tree, imagine yourself standing on the right side of it,
return the values of the nodes you can see ordered from top to bottom.

EXAMPLE:
Input: root = [1,2,3,null,5,null,4]
       1
      / \
     2   3
      \   \
       5   4
Output: [1,3,4]

Input: root = [1,null,3]
       1
        \
         3
Output: [1,3]

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
    # Approach 1: BFS - last node of each level
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        result: List[int] = []
        if root is None:
            return result

        q: deque = deque([root])
        while q:
            level_size = len(q)
            for i in range(level_size):
                node = q.popleft()
                if i == level_size - 1:
                    result.append(node.val)
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)

        return result

    # Approach 2: DFS - track rightmost node at each depth
    def rightSideViewDFS(self, root: Optional[TreeNode]) -> List[int]:
        result: List[int] = []

        def dfs(node: Optional[TreeNode], depth: int) -> None:
            if node is None:
                return
            if depth == len(result):
                result.append(node.val)
            else:
                result[depth] = node.val
            dfs(node.left, depth + 1)
            dfs(node.right, depth + 1)

        dfs(root, 0)
        return result


def build_tree() -> TreeNode:
    root = TreeNode(1)
    root.left = TreeNode(2)
    root.right = TreeNode(3)
    root.left.right = TreeNode(5)
    root.right.right = TreeNode(4)
    return root


if __name__ == "__main__":
    sol = Solution()
    root = build_tree()
    print(f"Right Side View (BFS): {sol.rightSideView(root)}")
    print(f"Right Side View (DFS): {sol.rightSideViewDFS(root)}")
