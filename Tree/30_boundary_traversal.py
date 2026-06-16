"""
PROBLEM: Boundary Traversal of Binary Tree
DIFFICULTY: Medium
PATTERN: Three Separate Traversals

DESCRIPTION:
Given a binary tree, return the boundary traversal in anti-clockwise direction.
Boundary includes:
1. Left boundary (excluding leaf)
2. All leaf nodes (left to right)
3. Right boundary in reverse order (excluding leaf)

EXAMPLE:
Input: root = [1,2,3,4,5,6,7,null,null,8,9]
         1
        / \
       2   3
      / \ / \
     4  5 6  7
       / \
      8   9

Output: [1, 2, 4, 8, 9, 6, 7, 3]
Explanation:
- Left boundary: 1, 2, 4
- Leaves: 8, 9, 6, 7
- Right boundary (reverse): 3
Note: 4, 8, 9, 7 are leaves, so not repeated

TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(h)
"""

from typing import List, Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def boundaryTraversal(self, root: Optional[TreeNode]) -> List[int]:
        if root is None:
            return []

        result: List[int] = []

        def is_leaf(node: Optional[TreeNode]) -> bool:
            return node is not None and node.left is None and node.right is None

        def add_left_boundary(node: Optional[TreeNode]) -> None:
            curr = node.left
            while curr:
                if not is_leaf(curr):
                    result.append(curr.val)
                if curr.left:
                    curr = curr.left
                else:
                    curr = curr.right

        def add_leaves(node: Optional[TreeNode]) -> None:
            if node is None:
                return
            if is_leaf(node):
                result.append(node.val)
                return
            add_leaves(node.left)
            add_leaves(node.right)

        def add_right_boundary(node: Optional[TreeNode]) -> None:
            curr = node.right
            temp: List[int] = []
            while curr:
                if not is_leaf(curr):
                    temp.append(curr.val)
                if curr.right:
                    curr = curr.right
                else:
                    curr = curr.left
            result.extend(reversed(temp))

        if is_leaf(root):
            result.append(root.val)
        else:
            result.append(root.val)
            add_left_boundary(root)
            add_leaves(root)
            add_right_boundary(root)

        return result


def build_tree() -> TreeNode:
    root = TreeNode(1)
    root.left = TreeNode(2)
    root.right = TreeNode(3)
    root.left.left = TreeNode(4)
    root.left.right = TreeNode(5)
    root.right.left = TreeNode(6)
    root.right.right = TreeNode(7)
    root.left.right.left = TreeNode(8)
    root.left.right.right = TreeNode(9)
    return root


if __name__ == "__main__":
    sol = Solution()
    root1 = build_tree()
    result1 = sol.boundaryTraversal(root1)
    print(f"Boundary Traversal: {result1}")

