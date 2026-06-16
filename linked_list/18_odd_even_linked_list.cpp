/*
PROBLEM: Odd Even Linked List
Difficulty: Medium
Pattern: Two-pointer grouping

DESCRIPTION:
Given the head of a singly linked list, group all the nodes with odd indices 
together followed by the nodes with even indices, and return the reordered list.

The first node is considered odd, and the second node is even, and so on.
Note that the relative order inside both odd and even groups should remain.

EXAMPLE:
Input: 1 -> 2 -> 3 -> 4 -> 5
Output: 1 -> 3 -> 5 -> 2 -> 4

Input: 2 -> 1 -> 3 -> 5 -> 6 -> 4 -> 7
Output: 2 -> 3 -> 6 -> 7 -> 1 -> 5 -> 4

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
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = even;  // Save even list head
        
        // Separate odd and even indexed nodes
        while (even != NULL && even->next != NULL) {
            odd->next = even->next;
            odd = odd->next;
            
            even->next = odd->next;
            even = even->next;
        }
        
        // Connect odd list to even list
        odd->next = evenHead;
        
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
    head1 = solution.oddEvenList(head1);
    cout << "Odd-Even: ";
    printList(head1);
    
    cout << endl;
    
    // Test Case 2
    int arr2[] = {2, 1, 3, 5, 6, 4, 7};
    ListNode* head2 = createList(arr2, 7);
    cout << "Original: ";
    printList(head2);
    head2 = solution.oddEvenList(head2);
    cout << "Odd-Even: ";
    printList(head2);
    
    cout << endl;
    
    // Test Case 3: Even length
    int arr3[] = {1, 2, 3, 4};
    ListNode* head3 = createList(arr3, 4);
    cout << "Original: ";
    printList(head3);
    head3 = solution.oddEvenList(head3);
    cout << "Odd-Even: ";
    printList(head3);
    
    return 0;
}

/*
EXPLANATION:
Two-Pointer Approach:

1. Use two pointers:
   - odd: points to current odd-indexed node
   - even: points to current even-indexed node

2. Remember evenHead to connect later

3. In each iteration:
   - Link current odd to next odd (skip even)
   - Move odd pointer forward
   - Link current even to next even (skip odd)
   - Move even pointer forward

4. Connect end of odd list to evenHead

VISUALIZATION:
Original: 1 -> 2 -> 3 -> 4 -> 5

Iteration 1:
odd: 1 -> 3
even: 2 -> 4
Remaining: 5

Iteration 2:
odd: 1 -> 3 -> 5
even: 2 -> 4 -> NULL

Connect:
1 -> 3 -> 5 -> 2 -> 4 -> NULL

POINTER MOVEMENTS:
Initial: 
odd=1, even=2

After odd->next = even->next:
1 -> 3 (skipped 2)

After odd = odd->next:
odd=3

After even->next = odd->next:
2 -> 4 (skipped 3)

After even = even->next:
even=4

WHY IT WORKS:
- Odd nodes at positions: 1, 3, 5, ... (0-indexed: 0, 2, 4, ...)
- Even nodes at positions: 2, 4, 6, ... (0-indexed: 1, 3, 5, ...)
- By skipping one node each time, we group them correctly

KEY PATTERN: Two-pointer grouping with interleaving
Common pattern for regrouping nodes based on position!
*/
