"""
PROBLEM: Count Complete Tree Nodes (LeetCode 222)
DIFFICULTY: Medium
PATTERN: Binary Search on Tree Height

DESCRIPTION:
Given the root of a complete binary tree, return the number of nodes.
A complete binary tree has all levels fully filled except possibly the last,
which is filled from left to right.

Design an algorithm that runs in less than O(n) time.

EXAMPLE:
Input: root = [1,2,3,4,5,6]
       1
      / \
     2   3
    / \ /
   4  5 6
Output: 6

TIME COMPLEXITY: O(log²n)
SPACE COMPLEXITY: O(log n)
"""

from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    # Approach 1: Recursive with perfect tree detection
    def countNodes(self, root: Optional[TreeNode]) -> int:
        if root is None:
            return 0

        left_height = 0
        right_height = 0
        left = root
        right = root

        while left:
            left_height += 1
            left = left.left

        while right:
            right_height += 1
            right = right.right

        # If left and right heights are equal, it's a perfect tree
        if left_height == right_height:
            return (1 << left_height) - 1

        return 1 + self.countNodes(root.left) + self.countNodes(root.right)

    # Approach 2: Binary search on last level
    def countNodesBS(self, root: Optional[TreeNode]) -> int:
        if root is None:
            return 0

        def get_height(node: Optional[TreeNode]) -> int:
            h = 0
            while node:
                h += 1
                node = node.left
            return h

        def exists(idx: int, height: int, node: Optional[TreeNode]) -> bool:
            left, right = 0, (1 << (height - 1)) - 1
            for _ in range(height - 1):
                mid = (left + right) // 2
                if idx <= mid:
                    node = node.left  # type: ignore
                    right = mid
                else:
                    node = node.right  # type: ignore
                    left = mid + 1
            return node is not None

        height = get_height(root)
        if height == 0:
            return 0

        left_bound = 1
        right_bound = (1 << (height - 1))

        while left_bound < right_bound:
            mid = (left_bound + right_bound + 1) // 2
            if exists(mid, height, root):
                left_bound = mid
            else:
                right_bound = mid - 1

        return (1 << (height - 1)) - 1 + left_bound


def build_complete_tree() -> TreeNode:
    root = TreeNode(1)
    root.left = TreeNode(2)
    root.right = TreeNode(3)
    root.left.left = TreeNode(4)
    root.left.right = TreeNode(5)
    root.right.left = TreeNode(6)
    return root


if __name__ == "__main__":
    sol = Solution()
    root1 = build_complete_tree()
    print(f"Complete tree nodes (recursive): {sol.countNodes(root1)}")
    root2 = build_complete_tree()
    print(f"Complete tree nodes (binary search): {sol.countNodesBS(root2)}")

