"""
PROBLEM: Vertical Order Traversal of a Binary Tree (LeetCode 987)
DIFFICULTY: Hard
PATTERN: DFS/BFS with Coordinate Tracking

DESCRIPTION:
Given the root of a binary tree, return the vertical order traversal of its nodes' values.
For each node at position (row, col):
- Its left child is at (row + 1, col - 1)
- Its right child is at (row + 1, col + 1)
Return values from left to right. If multiple nodes at same position, sort by value.

EXAMPLE:
Input: root = [3,9,20,null,null,15,7]
       3(0,0)
      / \
  9(1,-1) 20(1,1)
          /  \
      15(2,0) 7(2,2)

Output: [[9],[3,15],[20],[7]]

TIME COMPLEXITY: O(n log n) due to sorting
SPACE COMPLEXITY: O(n)
"""

from typing import List, Optional
from collections import defaultdict, deque


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    # Approach 1: BFS with (node, row, col) tracking
    def verticalTraversal(self, root: Optional[TreeNode]) -> List[List[int]]:
        if root is None:
            return []

        # col -> list of (row, val)
        col_map: dict = defaultdict(list)
        q: deque = deque([(root, 0, 0)])  # (node, row, col)

        while q:
            node, row, col = q.popleft()
            col_map[col].append((row, node.val))
            if node.left:
                q.append((node.left, row + 1, col - 1))
            if node.right:
                q.append((node.right, row + 1, col + 1))

        result: List[List[int]] = []
        for col in sorted(col_map.keys()):
            # Sort by row, then by value for ties
            result.append([val for _, val in sorted(col_map[col])])
        return result

    # Approach 2: DFS with (row, col) tracking
    def verticalTraversalDFS(self, root: Optional[TreeNode]) -> List[List[int]]:
        col_map: dict = defaultdict(list)

        def dfs(node: Optional[TreeNode], row: int, col: int) -> None:
            if node is None:
                return
            col_map[col].append((row, node.val))
            dfs(node.left, row + 1, col - 1)
            dfs(node.right, row + 1, col + 1)

        dfs(root, 0, 0)
        result: List[List[int]] = []
        for col in sorted(col_map.keys()):
            result.append([val for _, val in sorted(col_map[col])])
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
    root1 = build_tree()
    print(f"Vertical order traversal (BFS): {sol.verticalTraversal(root1)}")
    root2 = build_tree()
    print(f"Vertical order traversal (DFS): {sol.verticalTraversalDFS(root2)}")
