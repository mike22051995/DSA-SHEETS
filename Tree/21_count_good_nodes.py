"""
PROBLEM: Count Good Nodes in Binary Tree (LeetCode 1448)
DIFFICULTY: Medium
PATTERN: DFS with Path Tracking

DESCRIPTION:
Given a binary tree root, a node X is named good if in the path from root to X,
there are no nodes with a value greater than X.
Return the number of good nodes in the binary tree.

EXAMPLE:
Input: root = [3,1,4,3,null,1,5]
       3
      / \
     1   4
    /   / \
   3   1   5
Output: 4 (Nodes 3, 4, 3, 5)

Input: root = [3,3,null,4,2]
       3
      /
     3
    / \
   4   2
Output: 3

TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(h)
"""

from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def goodNodes(self, root: Optional[TreeNode]) -> int:
        def dfs(node: Optional[TreeNode], max_so_far: int) -> int:
            if node is None:
                return 0
            count = 1 if node.val >= max_so_far else 0
            new_max = max(max_so_far, node.val)
            count += dfs(node.left, new_max)
            count += dfs(node.right, new_max)
            return count

        return dfs(root, float('-inf'))


def build_tree() -> TreeNode:
    root = TreeNode(3)
    root.left = TreeNode(1)
    root.right = TreeNode(4)
    root.left.left = TreeNode(3)
    root.right.left = TreeNode(1)
    root.right.right = TreeNode(5)
    return root


if __name__ == "__main__":
    sol = Solution()
    root = build_tree()
    print(f"Number of good nodes: {sol.goodNodes(root)}")
