/*
PROBLEM: Remove Linked List Elements
Difficulty: Easy
Pattern: Dummy head + Single pointer

DESCRIPTION:
Given the head of a linked list and an integer val, remove all the nodes 
of the linked list that has Node.val == val, and return the new head.

EXAMPLE:
Input: head = 1 -> 2 -> 6 -> 3 -> 4 -> 5 -> 6, val = 6
Output: 1 -> 2 -> 3 -> 4 -> 5

Input: head = 7 -> 7 -> 7 -> 7, val = 7
Output: []

TIME COMPLEXITY: O(n) where n is the number of nodes
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
    ListNode* removeElements(ListNode* head, int val) {
        // Create dummy node to handle edge cases (head removal)
        ListNode dummy(0);
        dummy.next = head;
        
        ListNode* current = &dummy;
        
        while (current->next != NULL) {
            if (current->next->val == val) {
                // Remove the node
                ListNode* temp = current->next;
                current->next = current->next->next;
                delete temp;
                // Don't move current, check next node again
            } else {
                // Move to next node
                current = current->next;
            }
        }
        
        return dummy.next;
    }
    
    // Recursive approach
    ListNode* removeElementsRecursive(ListNode* head, int val) {
        if (head == NULL) return NULL;
        
        head->next = removeElementsRecursive(head->next, val);
        
        if (head->val == val) {
            return head->next;
        }
        
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
    cout << " -> NULL" << endl;
}

int main() {
    Solution solution;
    
    // Test Case 1: Remove middle values
    int arr1[] = {1, 2, 6, 3, 4, 5, 6};
    ListNode* head1 = createList(arr1, 7);
    cout << "Original List: ";
    printList(head1);
    cout << "Remove value: 6" << endl;
    head1 = solution.removeElements(head1, 6);
    cout << "After Removal: ";
    printList(head1);
    
    cout << endl;
    
    // Test Case 2: Remove all values
    int arr2[] = {7, 7, 7, 7};
    ListNode* head2 = createList(arr2, 4);
    cout << "Original List: ";
    printList(head2);
    cout << "Remove value: 7" << endl;
    head2 = solution.removeElements(head2, 7);
    cout << "After Removal: ";
    printList(head2);
    
    cout << endl;
    
    // Test Case 3: Remove head
    int arr3[] = {1, 1, 2, 3};
    ListNode* head3 = createList(arr3, 4);
    cout << "Original List: ";
    printList(head3);
    cout << "Remove value: 1" << endl;
    head3 = solution.removeElements(head3, 1);
    cout << "After Removal: ";
    printList(head3);
    
    return 0;
}

/*
EXPLANATION:
Iterative Approach:
1. Create dummy node pointing to head (handles head removal elegantly)
2. Use current pointer starting at dummy
3. Check if next node should be removed:
   - If yes: unlink it, don't move current
   - If no: move current forward
4. Return dummy.next as new head

Recursive Approach:
1. Base case: if head is NULL, return NULL
2. Recursively process rest of list
3. If current head should be removed, return next node
4. Otherwise return current head

WHY DUMMY NODE:
- Simplifies code by avoiding special case for head removal
- No need to check if we're removing head separately
- Current always has a previous node (dummy)

KEY PATTERN: Dummy node for head modification
This is essential when operations might affect the head node!
*/
