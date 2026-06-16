from typing import Optional


class ListNode:
    def __init__(self, val: int = 0, next: Optional["ListNode"] = None):
        self.val = val
        self.next = next


class Solution:
    def partition(self, head: Optional[ListNode], x: int) -> Optional[ListNode]:
        before_dummy = ListNode()
        after_dummy = ListNode()
        before = before_dummy
        after = after_dummy

        curr = head
        while curr:
            if curr.val < x:
                before.next = curr
                before = before.next
            else:
                after.next = curr
                after = after.next
            curr = curr.next

        after.next = None
        before.next = after_dummy.next
        return before_dummy.next
