"""
PROBLEM: All Nodes Distance K in Binary Tree (LeetCode 863)
DIFFICULTY: Medium/Hard
PATTERN: Tree to Graph Conversion + BFS

DESCRIPTION:
Given the root of a binary tree, a target node, and an integer k,
return an array of the values of all nodes that have a distance k from the target node.

EXAMPLE:
Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2
         3
        / \
       5   1
      / \ / \
     6  2 0  8
       / \
      7   4
Output: [7,4,1]
Nodes at distance 2 from 5: 7, 4, 1

TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(n)
"""

from typing import List, Optional
from collections import deque


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def distanceK(self, root: TreeNode, target: TreeNode, k: int) -> List[int]:
        # Step 1: Build parent map via DFS
        parent: dict = {}

        def build_parents(node: Optional[TreeNode], par: Optional[TreeNode]) -> None:
            if node is None:
                return
            parent[node] = par
            build_parents(node.left, node)
            build_parents(node.right, node)

        build_parents(root, None)

        # Step 2: BFS from target
        visited: set = set()
        q: deque = deque([(target, 0)])
        visited.add(target)
        result: List[int] = []

        while q:
            node, dist = q.popleft()
            if dist == k:
                result.append(node.val)
                continue
            # Visit left, right, and parent
            for neighbor in [node.left, node.right, parent.get(node)]:
                if neighbor and neighbor not in visited:
                    visited.add(neighbor)
                    q.append((neighbor, dist + 1))

        return result


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
    target = root.left  # Node with value 5
    k = 2
    result = sol.distanceK(root, target, k)
    print(f"Nodes at distance {k} from node {target.val}: {sorted(result)}")

