from typing import Optional


class ListNode:
    def __init__(self, x: int):
        self.val = x
        self.next: Optional["ListNode"] = None


class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        slow = head
        fast = head

        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
            if slow is fast:
                return True

        return False