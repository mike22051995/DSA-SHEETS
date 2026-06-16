"""
PROBLEM: Serialize and Deserialize Binary Tree (LeetCode 297)
DIFFICULTY: Hard
PATTERN: Tree Serialization - DFS/BFS

DESCRIPTION:
Design an algorithm to serialize and deserialize a binary tree.
Serialization is converting a tree to a string.
Deserialization is converting string back to tree.

EXAMPLE:
Input: root = [1,2,3,null,null,4,5]
       1
      / \
     2   3
        / \
       4   5
Output: "1,2,#,#,3,4,#,#,5,#,#"

TIME COMPLEXITY: O(n) for both operations
SPACE COMPLEXITY: O(n)
"""

from typing import Optional
from collections import deque


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Codec:
    """DFS (preorder) based serialization/deserialization."""

    def serialize(self, root: Optional[TreeNode]) -> str:
        parts = []

        def dfs(node: Optional[TreeNode]) -> None:
            if node is None:
                parts.append("#")
                return
            parts.append(str(node.val))
            dfs(node.left)
            dfs(node.right)

        dfs(root)
        return ",".join(parts)

    def deserialize(self, data: str) -> Optional[TreeNode]:
        tokens = iter(data.split(","))

        def dfs() -> Optional[TreeNode]:
            val = next(tokens)
            if val == "#":
                return None
            node = TreeNode(int(val))
            node.left = dfs()
            node.right = dfs()
            return node

        return dfs()


class CodecBFS:
    """BFS (level order) based serialization/deserialization."""

    def serialize(self, root: Optional[TreeNode]) -> str:
        if root is None:
            return "#"
        parts = []
        q: deque = deque([root])
        while q:
            node = q.popleft()
            if node is None:
                parts.append("#")
            else:
                parts.append(str(node.val))
                q.append(node.left)
                q.append(node.right)
        return ",".join(parts)

    def deserialize(self, data: str) -> Optional[TreeNode]:
        tokens = data.split(",")
        if tokens[0] == "#":
            return None
        root = TreeNode(int(tokens[0]))
        q: deque = deque([root])
        i = 1
        while q and i < len(tokens):
            node = q.popleft()
            if tokens[i] != "#":
                node.left = TreeNode(int(tokens[i]))
                q.append(node.left)
            i += 1
            if i < len(tokens) and tokens[i] != "#":
                node.right = TreeNode(int(tokens[i]))
                q.append(node.right)
            i += 1
        return root


def build_tree() -> TreeNode:
    root = TreeNode(1)
    root.left = TreeNode(2)
    root.right = TreeNode(3)
    root.right.left = TreeNode(4)
    root.right.right = TreeNode(5)
    return root


def preorder_print(node: Optional[TreeNode]) -> None:
    if node is None:
        return
    print(node.val, end=" ")
    preorder_print(node.left)
    preorder_print(node.right)


if __name__ == "__main__":
    codec = Codec()
    root = build_tree()
    print("Original tree (preorder): ", end="")
    preorder_print(root)
    print()
    serialized = codec.serialize(root)
    print(f"Serialized (DFS): {serialized}")
    deserialized = codec.deserialize(serialized)
    print("Deserialized tree (preorder): ", end="")
    preorder_print(deserialized)
    print()
    codec_bfs = CodecBFS()
    root2 = build_tree()
    serialized_bfs = codec_bfs.serialize(root2)
    print(f"\nSerialized (BFS): {serialized_bfs}")
    deserialized_bfs = codec_bfs.deserialize(serialized_bfs)
    print("Deserialized tree (preorder): ", end="")
    preorder_print(deserialized_bfs)
    print()

