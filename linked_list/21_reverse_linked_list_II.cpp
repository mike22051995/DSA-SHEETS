/*
PROBLEM: Reverse Linked List II
Difficulty: Medium
Pattern: Partial reversal with connection points

DESCRIPTION:
Given the head of a singly linked list and two integers left and right where 
left <= right, reverse the nodes of the list from position left to position 
right, and return the reversed list.

EXAMPLE:
Input: head = 1 -> 2 -> 3 -> 4 -> 5, left = 2, right = 4
Output: 1 -> 4 -> 3 -> 2 -> 5

Input: head = 5, left = 1, right = 1
Output: 5

TIME COMPLEXITY: O(n)
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head == NULL || left == right) return head;
        
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;
        
        // Step 1: Move prev to node before left position
        for (int i = 1; i < left; i++) {
            prev = prev->next;
        }
        
        // Step 2: Reverse the sublist from left to right
        ListNode* current = prev->next;
        ListNode* next = NULL;
        
        for (int i = 0; i < right - left; i++) {
            next = current->next;
            current->next = next->next;
            next->next = prev->next;
            prev->next = next;
        }
        
        return dummy.next;
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
    head1 = solution.reverseBetween(head1, 2, 4);
    cout << "After reversing from position 2 to 4: ";
    printList(head1);
    
    cout << endl;
    
    // Test Case 2: Reverse from head
    int arr2[] = {1, 2, 3, 4, 5};
    ListNode* head2 = createList(arr2, 5);
    cout << "Original: ";
    printList(head2);
    head2 = solution.reverseBetween(head2, 1, 3);
    cout << "After reversing from position 1 to 3: ";
    printList(head2);
    
    cout << endl;
    
    // Test Case 3: Reverse entire list
    int arr3[] = {1, 2, 3};
    ListNode* head3 = createList(arr3, 3);
    cout << "Original: ";
    printList(head3);
    head3 = solution.reverseBetween(head3, 1, 3);
    cout << "After reversing from position 1 to 3: ";
    printList(head3);
    
    return 0;
}

/*
EXPLANATION:

Algorithm:
1. Use dummy node to handle edge case (reversing from head)
2. Move prev to node BEFORE the left position
3. Reverse the sublist by repeatedly moving nodes to front

Detailed Steps for reversing between positions:
Initial state (left=2, right=4):
dummy -> 1 -> 2 -> 3 -> 4 -> 5
        prev  cur  next

Iteration 1:
- next = current->next (next = 3)
- current->next = next->next (2 -> 4)
- next->next = prev->next (3 -> 2)
- prev->next = next (1 -> 3)

Result: 1 -> 3 -> 2 -> 4 -> 5

Iteration 2:
- next = current->next (next = 4)
- current->next = next->next (2 -> 5)
- next->next = prev->next (4 -> 3)
- prev->next = next (1 -> 4)

Result: 1 -> 4 -> 3 -> 2 -> 5

KEY INSIGHT:
- Keep current pointer fixed at original left position
- Repeatedly extract next node and move to front
- This gradually reverses the section
- Number of moves = (right - left)

ALTERNATIVE APPROACH:
Could also:
1. Reverse the entire sublist normally
2. Reconnect with previous and next parts
But current approach is more efficient (single pass)

KEY PATTERN: Partial list reversal with fixed connection point
Important for in-place manipulation of sublists!
*/
