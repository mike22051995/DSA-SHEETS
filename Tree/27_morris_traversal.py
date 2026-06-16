"""
PROBLEM: Morris Inorder Traversal
DIFFICULTY: Hard
PATTERN: Threading Technique - O(1) Space Traversal

DESCRIPTION:
Implement inorder traversal of a binary tree using O(1) space (no recursion, no stack).
Morris Traversal uses threading to navigate without extra space.

EXAMPLE:
Input: root = [1,2,3,4,5]
       1
      / \
     2   3
    / \
   4   5
Output: [4, 2, 5, 1, 3]

TIME COMPLEXITY: O(n) - each edge traversed at most twice
SPACE COMPLEXITY: O(1) - no recursion or stack
"""

from typing import List, Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    # Morris Inorder Traversal
    def morrisInorder(self, root: Optional[TreeNode]) -> List[int]:
        result: List[int] = []
        curr = root

        while curr:
            if curr.left is None:
                result.append(curr.val)
                curr = curr.right
            else:
                pred = curr.left
                while pred.right and pred.right is not curr:
                    pred = pred.right

                if pred.right is None:
                    pred.right = curr
                    curr = curr.left
                else:
                    pred.right = None
                    result.append(curr.val)
                    curr = curr.right

        return result

    # Morris Preorder Traversal
    def morrisPreorder(self, root: Optional[TreeNode]) -> List[int]:
        result: List[int] = []
        curr = root

        while curr:
            if curr.left is None:
                result.append(curr.val)
                curr = curr.right
            else:
                pred = curr.left
                while pred.right and pred.right is not curr:
                    pred = pred.right

                if pred.right is None:
                    result.append(curr.val)  # visit before threading
                    pred.right = curr
                    curr = curr.left
                else:
                    pred.right = None
                    curr = curr.right

        return result


def build_tree() -> TreeNode:
    root = TreeNode(1)
    root.left = TreeNode(2)
    root.right = TreeNode(3)
    root.left.left = TreeNode(4)
    root.left.right = TreeNode(5)
    return root


if __name__ == "__main__":
    sol = Solution()
    root = build_tree()
    print(f"Morris Inorder:  {sol.morrisInorder(root)}")
    root = build_tree()
    print(f"Morris Preorder: {sol.morrisPreorder(root)}")
