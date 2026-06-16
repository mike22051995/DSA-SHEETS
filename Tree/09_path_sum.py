"""
PROBLEM: Path Sum (LeetCode 112)
DIFFICULTY: Easy
PATTERN: DFS - Root to Leaf Path

DESCRIPTION:
Given the root of a binary tree and an integer targetSum, return True if the tree 
has a root-to-leaf path such that adding up all values equals targetSum.
A leaf is a node with no children.

EXAMPLE:
Input: root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
         5
        / \
       4   8
      /   / \
     11  13  4
    /  \      \
   7    2      1
Output: True (5.4.11.2 = 22)

Input: root = [1,2,3], targetSum = 5
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
    # Approach 1: Recursive DFS
    def hasPathSum(self, root: Optional[TreeNode], target_sum: int) -> bool:
        if root is None:
            return False
        # Leaf node: check remaining sum
        if root.left is None and root.right is None:
            return target_sum == root.val
        remaining = target_sum - root.val
        return self.hasPathSum(root.left, remaining) or self.hasPathSum(root.right, remaining)

    # Approach 2: Iterative BFS (stores node + remaining sum)
    def hasPathSumBFS(self, root: Optional[TreeNode], target_sum: int) -> bool:
        if root is None:
            return False
        # Queue of (node, remaining sum)
        q: deque = deque([(root, target_sum)])
        while q:
            node, remaining = q.popleft()
            if node.left is None and node.right is None and remaining == node.val:
                return True
            if node.left:
                q.append((node.left, remaining - node.val))
            if node.right:
                q.append((node.right, remaining - node.val))
        return False


def build_tree() -> TreeNode:
    root = TreeNode(5)
    root.left = TreeNode(4)
    root.right = TreeNode(8)
    root.left.left = TreeNode(11)
    root.left.left.left = TreeNode(7)
    root.left.left.right = TreeNode(2)
    root.right.left = TreeNode(13)
    root.right.right = TreeNode(4)
    root.right.right.right = TreeNode(1)
    return root


if __name__ == "__main__":
    sol = Solution()
    root = build_tree()
    for target in [22, 26, 18]:
        print(f"Has path sum {target} (DFS): {sol.hasPathSum(root, target)}")
        print(f"Has path sum {target} (BFS): {sol.hasPathSumBFS(root, target)}")
