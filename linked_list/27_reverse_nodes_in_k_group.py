from typing import Optional


class ListNode:
    def __init__(self, val: int = 0, next: Optional["ListNode"] = None):
        self.val = val
        self.next = next


class Solution:
    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        dummy = ListNode(0, head)
        group_prev = dummy

        while True:
            kth = group_prev
            for _ in range(k):
                kth = kth.next
                if not kth:
                    return dummy.next

            group_next = kth.next
            prev = group_next
            curr = group_prev.next
            while curr is not group_next:
                nxt = curr.next
                curr.next = prev
                prev = curr
                curr = nxt

            temp = group_prev.next
            group_prev.next = kth
            group_prev = temp
