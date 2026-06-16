from typing import List, Optional


class ListNode:
    def __init__(self, val: int = 0, next: Optional["ListNode"] = None):
        self.val = val
        self.next = next


class Solution:
    def splitListToParts(self, head: Optional[ListNode], k: int) -> List[Optional[ListNode]]:
        length = 0
        curr = head
        while curr:
            length += 1
            curr = curr.next

        part_size, extra = divmod(length, k)
        result: List[Optional[ListNode]] = []
        curr = head

        for i in range(k):
            part_head = curr
            size = part_size + (1 if i < extra else 0)

            for _ in range(size - 1):
                if curr:
                    curr = curr.next

            if curr:
                nxt = curr.next
                curr.next = None
                curr = nxt

            result.append(part_head)

        return result
