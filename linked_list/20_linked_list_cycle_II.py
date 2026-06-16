from typing import Optional


class ListNode:
    def __init__(self, x: int):
        self.val = x
        self.next: Optional["ListNode"] = None


class Solution:
    def detectCycle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        slow = head
        fast = head

        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
            if slow is fast:
                break
        else:
            return None

        ptr = head
        while ptr is not slow:
            ptr = ptr.next
            slow = slow.next

        return ptr