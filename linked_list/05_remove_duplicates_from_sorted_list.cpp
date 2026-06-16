/*
PROBLEM: Remove Duplicates from Sorted List
Difficulty: Easy
Pattern: Single pointer traversal

DESCRIPTION:
Given the head of a sorted linked list, delete all duplicates such that 
each element appears only once. Return the linked list sorted as well.

EXAMPLE:
Input: 1 -> 1 -> 2 -> NULL
Output: 1 -> 2 -> NULL

Input: 1 -> 1 -> 2 -> 3 -> 3 -> NULL
Output: 1 -> 2 -> 3 -> NULL

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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL) return NULL;
        // Pointer to traverse the list
        ListNode* current = head;
        
        while (current != NULL && current->next != NULL) {
            if (current->val == current->next->val) {
                // Skip the duplicate node
                ListNode* duplicate = current->next;
                current->next = current->next->next;
                delete duplicate;  // Free memory (good practice)
            } else {
                // Move to next node only if no duplicate found
                current = current->next;
            }
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
    
    // Test Case 1
    int arr1[] = {1, 1, 2};
    ListNode* head1 = createList(arr1, 3);
    cout << "Original: ";
    printList(head1);
    head1 = solution.deleteDuplicates(head1);
    cout << "After removing duplicates: ";
    printList(head1);
    
    cout << endl;
    
    // Test Case 2
    int arr2[] = {1, 1, 2, 3, 3};
    ListNode* head2 = createList(arr2, 5);
    cout << "Original: ";
    printList(head2);
    head2 = solution.deleteDuplicates(head2);
    cout << "After removing duplicates: ";
    printList(head2);
    
    cout << endl;
    
    // Test Case 3: All duplicates
    int arr3[] = {1, 1, 1, 1};
    ListNode* head3 = createList(arr3, 4);
    cout << "Original: ";
    printList(head3);
    head3 = solution.deleteDuplicates(head3);
    cout << "After removing duplicates: ";
    printList(head3);
    
    return 0;
}

/*
EXPLANATION:
1. Start with current pointer at head
2. Compare current node with next node
3. If values are equal:
   - Skip the next node by updating current->next
   - Don't move current (there might be more duplicates)
4. If values are different:
   - Move current to next node
5. Continue until end of list

KEY INSIGHTS:
- List is sorted, so duplicates are adjacent
- We keep the first occurrence and remove subsequent duplicates
- Don't move current when deleting to handle multiple consecutive duplicates

KEY PATTERN: In-place modification with single pointer
Important for understanding linked list manipulation!
*/
