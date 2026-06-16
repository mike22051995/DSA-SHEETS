/*
PROBLEM: Reverse a Linked List
Difficulty: Easy
Pattern: In-place reversal using three pointers

DESCRIPTION:
Given the head of a singly linked list, reverse the list and return the reversed list.

EXAMPLE:
Input: 1 -> 2 -> 3 -> 4 -> 5 -> NULL
Output: 5 -> 4 -> 3 -> 2 -> 1 -> NULL

Input: 1 -> 2 -> NULL
Output: 2 -> 1 -> NULL

TIME COMPLEXITY: O(n) where n is the number of nodes
SPACE COMPLEXITY: O(1)
*/

#include <iostream>
using namespace std;

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* current = head;
        ListNode* next = NULL;
        
        while (current != NULL) {
            // Store next node
            next = current->next;
            
            // Reverse current node's pointer
            current->next = prev;
            
            // Move pointers one position ahead
            prev = current;
            current = next;
        }
        
        return prev; // prev is new head
    }
};

// Utility function to create a linked list from array
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

// Utility function to print linked list
void printList(ListNode* head) {
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
    int arr1[] = {1, 2, 3, 4, 5};
    ListNode* head1 = createList(arr1, 5);
    cout << "Original List: ";
    printList(head1);
    head1 = solution.reverseList(head1);
    cout << "Reversed List: ";
    printList(head1);
    
    cout << endl;
    
    // Test Case 2
    int arr2[] = {1, 2};
    ListNode* head2 = createList(arr2, 2);
    cout << "Original List: ";
    printList(head2);
    head2 = solution.reverseList(head2);
    cout << "Reversed List: ";
    printList(head2);
    
    return 0;
}

/*
EXPLANATION:
1. We use three pointers: prev, current, and next
2. Initialize prev as NULL (new tail), current as head
3. In each iteration:
   - Store next node before changing current's next
   - Reverse the link by pointing current->next to prev
   - Move prev and current one step forward
4. When current becomes NULL, prev points to the new head

KEY PATTERN: Three-pointer technique for in-place reversal
This is one of the most fundamental linked list patterns!
*/
