"""
PROBLEM: Sort Linked List (LeetCode 148)
===============================================
DESCRIPTION:
Given the head of a linked list, sort it in ascending order using merge sort.
Follow up: Can you sort the linked list in O(n log n) time and O(1) space?

PATTERN: Merge Sort on Linked List
DIFFICULTY: Medium
TIME COMPLEXITY: O(n log n)
SPACE COMPLEXITY: O(log n) for recursion, O(1) for iterative

INPUT:
Head of a linked list

OUTPUT:
Head of sorted linked list

EXAMPLE:
Input: 4 -> 2 -> 1 -> 3
Output: 1 -> 2 -> 3 -> 4
"""

from typing import Optional

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def sortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head or not head.next:
            return head
        
        # Find middle of list using slow and fast pointers
        slow = head
        fast = head
        prev = None
        
        while fast and fast.next:
            prev = slow
            slow = slow.next
            fast = fast.next.next
        
        # Split into two halves
        if prev:
            prev.next = None
        
        # Recursively sort both halves
        left = self.sortList(head)
        right = self.sortList(slow)
        
        # Merge sorted halves
        return self.merge(left, right)
    
    def merge(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        dummy = ListNode(0)
        current = dummy
        
        while l1 and l2:
            if l1.val <= l2.val:
                current.next = l1
                l1 = l1.next
            else:
                current.next = l2
                l2 = l2.next
            current = current.next
        
        # Attach remaining elements
        if l1:
            current.next = l1
        else:
            current.next = l2
        
        return dummy.next


def create_linked_list(arr):
    if not arr:
        return None
    head = ListNode(arr[0])
    current = head
    for val in arr[1:]:
        current.next = ListNode(val)
        current = current.next
    return head


def print_linked_list(head):
    current = head
    result = []
    while current:
        result.append(str(current.val))
        current = current.next
    print(" -> ".join(result) if result else "Empty")


if __name__ == "__main__":
    sol = Solution()
    
    # Test case 1
    arr1 = [4, 2, 1, 3]
    head1 = create_linked_list(arr1)
    print("Original list: ")
    print_linked_list(head1)
    
    head1 = sol.sortList(head1)
    print("Sorted list: ")
    print_linked_list(head1)
    
    # Test case 2
    arr2 = [5, 1, 1, 9, 9, 9]
    head2 = create_linked_list(arr2)
    print("\nOriginal list: ")
    print_linked_list(head2)
    
    head2 = sol.sortList(head2)
    print("Sorted list: ")
    print_linked_list(head2)
