"""
PROBLEM: Binary Tree Maximum Path Sum (LeetCode 124)
DIFFICULTY: Hard
PATTERN: DFS - Path Sum with Global Max

DESCRIPTION:
A path in a binary tree is a sequence of nodes where each pair of adjacent nodes
has an edge. A node can only appear once in the sequence. Path sum is the sum of values.
Return the maximum path sum of any non-empty path.

EXAMPLE:
Input: root = [1,2,3]
       1
      / \
     2   3
Output: 6 (path: 2.1.3)

Input: root = [-10,9,20,null,null,15,7]
       -10
       /  \
      9   20
         /  \
        15   7
Output: 42 (path: 15.20.7)

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
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        self.max_sum = float('-inf')

        def dfs(node: Optional[TreeNode]) -> int:
            if node is None:
                return 0
            # Discard negative contributions
            left_gain = max(dfs(node.left), 0)
            right_gain = max(dfs(node.right), 0)
            # Update global max with path through this node
            self.max_sum = max(self.max_sum, node.val + left_gain + right_gain)
            # Return max path going downward (only one branch)
            return node.val + max(left_gain, right_gain)

        dfs(root)
        return self.max_sum


def build_tree1() -> TreeNode:
    root = TreeNode(1)
    root.left = TreeNode(2)
    root.right = TreeNode(3)
    return root


def build_tree2() -> TreeNode:
    root = TreeNode(-10)
    root.left = TreeNode(9)
    root.right = TreeNode(20)
    root.right.left = TreeNode(15)
    root.right.right = TreeNode(7)
    return root


def build_tree3() -> TreeNode:
    return TreeNode(-3)


if __name__ == "__main__":
    sol = Solution()
    root1 = build_tree1()
    print(f"Tree 1 max path sum: {sol.maxPathSum(root1)}")  # Expected: 6
    root2 = build_tree2()
    print(f"Tree 2 max path sum: {sol.maxPathSum(root2)}")  # Expected: 42
    root3 = build_tree3()
    print(f"Tree 3 max path sum: {sol.maxPathSum(root3)}")  # Expected: -3

