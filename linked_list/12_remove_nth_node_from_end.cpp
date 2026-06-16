/*
PROBLEM: Remove Nth Node From End of List
Difficulty: Medium
Pattern: Two-pointer with gap

DESCRIPTION:
Given the head of a linked list, remove the nth node from the end of the 
list and return its head.

EXAMPLE:
Input: head = 1 -> 2 -> 3 -> 4 -> 5, n = 2
Output: 1 -> 2 -> 3 -> 5

Input: head = 1, n = 1
Output: []

TIME COMPLEXITY: O(L) where L is the length of list (single pass)
SPACE COMPLEXITY: O(1)
*/

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0);
        dummy.next = head;
        
        ListNode* first = &dummy;
        ListNode* second = &dummy;
        
        // Move first pointer n+1 steps ahead
        for (int i = 0; i <= n; i++) {
            first = first->next;
        }
        
        // Move both pointers until first reaches end
        while (first != NULL) {
            first = first->next;
            second = second->next;
        }
        
        // second now points to node before the one to delete
        ListNode* toDelete = second->next;
        second->next = second->next->next;
        delete toDelete;
        
        return dummy.next;
    }
    
    // Alternative: Two-pass approach
    ListNode* removeNthFromEndTwoPass(ListNode* head, int n) {
        // First pass: count length
        int length = 0;
        ListNode* current = head;
        while (current != NULL) {
            length++;
            current = current->next;
        }
        
        // If removing head
        if (length == n) {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }
        
        // Second pass: go to (length - n - 1)th node
        current = head;
        for (int i = 0; i < length - n - 1; i++) {
            current = current->next;
        }
        
        ListNode* toDelete = current->next;
        current->next = current->next->next;
        delete toDelete;
        
        return head;
    }
};

// Utility functions
ListNode* createList(int arr[], int n) {
    if (n == 0) return NULL;
    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;
    for (int i = 1; i < n; i++) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return head;
}

void printList(ListNode* head) {
    if (head == NULL) {
        cout << "[]" << endl;
        return;
    }
    while (head != NULL) {
        cout << head->val;
        if (head->next != NULL) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Solution solution;
    
    // Test Case 1
    int arr1[] = {1, 2, 3, 4, 5};
    ListNode* head1 = createList(arr1, 5);
    cout << "Original: ";
    printList(head1);
    head1 = solution.removeNthFromEnd(head1, 2);
    cout << "After removing 2nd from end: ";
    printList(head1);
    
    cout << endl;
    
    // Test Case 2: Remove head
    int arr2[] = {1, 2};
    ListNode* head2 = createList(arr2, 2);
    cout << "Original: ";
    printList(head2);
    head2 = solution.removeNthFromEnd(head2, 2);
    cout << "After removing 2nd from end: ";
    printList(head2);
    
    cout << endl;
    
    // Test Case 3: Single node
    ListNode* head3 = new ListNode(1);
    cout << "Original: ";
    printList(head3);
    head3 = solution.removeNthFromEnd(head3, 1);
    cout << "After removing 1st from end: ";
    printList(head3);
    
    return 0;
}

/*
EXPLANATION:
One-Pass Solution (Optimal):
1. Use dummy node to handle edge case (removing head)
2. Use two pointers with gap of n+1 between them
3. Move first pointer n+1 steps ahead
4. Move both pointers together until first reaches end
5. second pointer is now before the node to remove
6. Remove the target node

WHY IT WORKS:
- Gap between pointers = n+1
- When first reaches end, second is at (length - n - 1)
- This is exactly the node before the one to remove

Two-Pass Solution:
1. First pass: count total length
2. Second pass: navigate to (length - n - 1)th node
3. Remove next node

VISUALIZATION (remove 2nd from end):
1 -> 2 -> 3 -> 4 -> 5
     s              f   (after n+1 steps)
          s              f   (move together)
               s              f
                    s         (f is NULL)
Remove node 4

KEY PATTERN: Two-pointer with fixed gap
Essential for "from end" problems in single-pass!
*/
