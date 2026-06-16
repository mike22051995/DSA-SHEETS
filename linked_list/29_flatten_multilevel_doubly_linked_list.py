from typing import Optional


class Node:
    def __init__(
        self,
        val: int,
        prev: Optional["Node"] = None,
        next: Optional["Node"] = None,
        child: Optional["Node"] = None,
    ):
        self.val = val
        self.prev = prev
        self.next = next
        self.child = child


class Solution:
    def flatten(self, head: Optional[Node]) -> Optional[Node]:
        if not head:
            return head

        pseudo = Node(0, None, head, None)
        self._dfs(pseudo, head)
        pseudo.next.prev = None
        return pseudo.next

    def _dfs(self, prev: Node, curr: Optional[Node]) -> Node:
        if not curr:
            return prev

        curr.prev = prev
        prev.next = curr

        nxt = curr.next
        tail = self._dfs(curr, curr.child)
        curr.child = None
        return self._dfs(tail, nxt)
