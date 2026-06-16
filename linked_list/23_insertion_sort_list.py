from typing import Optional


class ListNode:
    def __init__(self, val: int = 0, next: Optional["ListNode"] = None):
        self.val = val
        self.next = next


class Solution:
    def insertionSortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        dummy = ListNode(float("-inf"))
        curr = head

        while curr:
            prev = dummy
            while prev.next and prev.next.val < curr.val:
                prev = prev.next

            nxt = curr.next
            curr.next = prev.next
            prev.next = curr
            curr = nxt

        return dummy.next
