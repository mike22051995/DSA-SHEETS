"""
PROBLEM: Binary Tree Cameras (LeetCode 968)
DIFFICULTY: Hard
PATTERN: Greedy DFS - State Tracking

DESCRIPTION:
You are given the root of a binary tree. Install cameras on the tree nodes where each
camera can monitor its parent, itself, and its immediate children.
Return the minimum number of cameras needed to monitor all nodes.

EXAMPLE:
Input: root = [0,0,null,0,0]
       0
      /
     0
      \
       0
      /
     0
Output: 1

Input: root = [0,0,null,0,null,0,null,null,0]
Output: 2

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
    # Greedy DFS with 3 states:
    # 0 = needs coverage, 1 = has camera, 2 = covered (by child)
    def minCameraCover(self, root: Optional[TreeNode]) -> int:
        self.cameras = 0

        def dfs(node: Optional[TreeNode]) -> int:
            if node is None:
                return 2  # null is "covered"
            left = dfs(node.left)
            right = dfs(node.right)
            # If any child needs coverage, place camera here
            if left == 0 or right == 0:
                self.cameras += 1
                return 1
            # If any child has a camera, this node is covered
            if left == 1 or right == 1:
                return 2
            # Neither child covers this node
            return 0

        if dfs(root) == 0:
            self.cameras += 1
        return self.cameras


def build_tree1() -> TreeNode:
    root = TreeNode(0)
    root.left = TreeNode(0)
    root.left.right = TreeNode(0)
    root.left.right.left = TreeNode(0)
    return root


def build_tree2() -> TreeNode:
    root = TreeNode(0)
    root.left = TreeNode(0)
    root.left.left = TreeNode(0)
    root.left.left.left = TreeNode(0)
    root.left.left.left.right = TreeNode(0)
    return root


if __name__ == "__main__":
    sol = Solution()
    root1 = build_tree1()
    print(f"Minimum cameras for tree 1: {sol.minCameraCover(root1)}")  # Expected: 1
    root2 = build_tree2()
    print(f"Minimum cameras for tree 2: {sol.minCameraCover(root2)}")  # Expected: 2

