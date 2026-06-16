/*
PROBLEM: Middle of the Linked List
Difficulty: Easy
Pattern: Slow and Fast Pointer

DESCRIPTION:
Given the head of a singly linked list, return the middle node.
If there are two middle nodes, return the second middle node.

EXAMPLE:
Input: 1 -> 2 -> 3 -> 4 -> 5 -> NULL
Output: 3 -> 4 -> 5 -> NULL (node with value 3)

Input: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> NULL
Output: 4 -> 5 -> 6 -> NULL (second middle node)

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
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        
        // Fast moves 2x speed of slow
        // When fast reaches end, slow is at middle
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
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
    cout << " -> NULL" << endl;
}

int main() {
    Solution solution;
    
    // Test Case 1: Odd number of nodes
    int arr1[] = {1, 2, 3, 4, 5};
    ListNode* head1 = createList(arr1, 5);
    cout << "Original List: ";
    printList(head1);
    ListNode* middle1 = solution.middleNode(head1);
    cout << "From Middle: ";
    printList(middle1);
    
    cout << endl;
    
    // Test Case 2: Even number of nodes
    int arr2[] = {1, 2, 3, 4, 5, 6};
    ListNode* head2 = createList(arr2, 6);
    cout << "Original List: ";
    printList(head2);
    ListNode* middle2 = solution.middleNode(head2);
    cout << "From Middle: ";
    printList(middle2);
    
    return 0;
}

/*
EXPLANATION:
1. Use two pointers: slow and fast, both starting at head
2. Move slow by 1 step and fast by 2 steps in each iteration
3. When fast reaches the end, slow will be at the middle
4. For even-length lists, slow will be at the second middle node

WHY IT WORKS:
- Fast pointer covers twice the distance of slow pointer
- When fast reaches end, slow is exactly at middle
- For odd length (n): slow moves n/2 steps
- For even length (n): slow moves n/2 steps (second middle)

KEY PATTERN: Two-pointer technique for finding middle
This avoids counting nodes twice - single pass solution!
*/
