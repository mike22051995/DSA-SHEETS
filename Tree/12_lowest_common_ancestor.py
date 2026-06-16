"""
PROBLEM: Lowest Common Ancestor of a Binary Tree (LeetCode 236)
DIFFICULTY: Medium
PATTERN: LCA - Recursive Search

DESCRIPTION:
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes.
LCA is the lowest node that has both p and q as descendants (a node can be a descendant of itself).

EXAMPLE:
Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
        3
       / \
      5   1
     / \ / \
    6  2 0  8
      / \
     7   4
Output: 3 (LCA of 5 and 1) 

Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
Output: 5 (LCA of 5 and 4, node can be ancestor of itself)

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
    # Recursive approach
    def lowestCommonAncestor(self, root: Optional[TreeNode],
                             p: TreeNode, q: TreeNode) -> Optional[TreeNode]:
        if root is None:
            return None
        # If root is p or q, it is the LCA
        if root is p or root is q:
            return root

        left = self.lowestCommonAncestor(root.left, p, q)
        right = self.lowestCommonAncestor(root.right, p, q)

        # p and q are in different subtrees
        if left and right:
            return root
        # Both in same subtree
        return left if left else right


def build_tree() -> TreeNode:
    root = TreeNode(3)
    root.left = TreeNode(5)
    root.right = TreeNode(1)
    root.left.left = TreeNode(6)
    root.left.right = TreeNode(2)
    root.right.left = TreeNode(0)
    root.right.right = TreeNode(8)
    root.left.right.left = TreeNode(7)
    root.left.right.right = TreeNode(4)
    return root


if __name__ == "__main__":
    sol = Solution()
    root = build_tree()
    p = root.left          # Node 5
    q = root.right         # Node 1
    lca = sol.lowestCommonAncestor(root, p, q)
    print(f"LCA of {p.val} and {q.val}: {lca.val}")
    p = root.left          # Node 5
    q = root.left.right.right  # Node 4
    lca = sol.lowestCommonAncestor(root, p, q)
    print(f"LCA of {p.val} and {q.val}: {lca.val}")
    p = root.left.left     # Node 6
    q = root.left.right.right  # Node 4
    lca = sol.lowestCommonAncestor(root, p, q)
    print(f"LCA of {p.val} and {q.val}: {lca.val}")
