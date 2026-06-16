from typing import Optional


class Node:
    def __init__(self, x: int, next: Optional["Node"] = None, random: Optional["Node"] = None):
        self.val = int(x)
        self.next = next
        self.random = random


class Solution:
    def copyRandomList(self, head: Optional[Node]) -> Optional[Node]:
        if not head:
            return None

        curr = head
        while curr:
            copy = Node(curr.val, curr.next)
            curr.next = copy
            curr = copy.next

        curr = head
        while curr:
            if curr.random:
                curr.next.random = curr.random.next
            curr = curr.next.next

        dummy = Node(0)
        copy_tail = dummy
        curr = head
        while curr:
            copy = curr.next
            curr.next = copy.next
            copy_tail.next = copy
            copy_tail = copy
            curr = curr.next

        return dummy.next
