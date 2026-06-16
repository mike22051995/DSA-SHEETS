"""
PROBLEM: Same Tree (LeetCode 100)
DIFFICULTY: Easy
PATTERN: DFS - Tree Comparison

DESCRIPTION:
Given the roots of two binary trees p and q, write a function to check if they are the same.
Two binary trees are considered the same if they are structurally identical and nodes have same values.

EXAMPLE:
Input: p = [1,2,3], q = [1,2,3]
       1       1
      / \     / \
     2   3   2   3
Output: True

Input: p = [1,2], q = [1,null,2]
       1       1
      /         \
     2           2
Output: False

TIME COMPLEXITY: O(min(n,m)) - n and m are sizes of two trees
SPACE COMPLEXITY: O(min(h1,h2)) - recursion stack
"""

from typing import Optional
from collections import deque


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    # Approach 1: Recursive
    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        if p is None and q is None:
            return True
        if p is None or q is None:
            return False
        return (p.val == q.val
                and self.isSameTree(p.left, q.left)
                and self.isSameTree(p.right, q.right))

    # Approach 2: BFS Iterative
    def isSameTreeBFS(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        queue: deque = deque([(p, q)])
        while queue:
            n1, n2 = queue.popleft()
            if n1 is None and n2 is None:
                continue
            if n1 is None or n2 is None:
                return False
            if n1.val != n2.val:
                return False
            queue.append((n1.left, n2.left))
            queue.append((n1.right, n2.right))
        return True


def build_tree1() -> TreeNode:
    root = TreeNode(1)
    root.left = TreeNode(2)
    root.right = TreeNode(3)
    return root


def build_tree2() -> TreeNode:
    root = TreeNode(1)
    root.left = TreeNode(2)
    root.right = TreeNode(3)
    return root


def build_tree3() -> TreeNode:
    root = TreeNode(1)
    root.left = TreeNode(2)
    return root


if __name__ == "__main__":
    sol = Solution()
    p, q = build_tree1(), build_tree2()
    print(f"Trees [1,2,3] and [1,2,3] same (Recursive): {sol.isSameTree(p, q)}")
    print(f"Trees [1,2,3] and [1,2,3] same (BFS): {sol.isSameTreeBFS(build_tree1(), build_tree2())}")
    print(f"Trees [1,2,3] and [1,2] same (Recursive): {sol.isSameTree(build_tree1(), build_tree3())}")
