from typing import Optional


class ListNode:
    def __init__(self, val: int = 0, next: Optional["ListNode"] = None):
        self.val = val
        self.next = next


class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        if not head or not head.next:
            return

        slow = head
        fast = head
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next

        prev = None
        curr = slow.next
        slow.next = None
        while curr:
            nxt = curr.next
            curr.next = prev
            prev = curr
            curr = nxt

        first = head
        second = prev
        while second:
            n1 = first.next
            n2 = second.next
            first.next = second
            second.next = n1
            first = n1
            second = n2
