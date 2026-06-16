/*
PROBLEM: Delete Node in a Linked List
Difficulty: Easy
Pattern: Value copying trick

DESCRIPTION:
Write a function to delete a node in a singly-linked list. You will NOT be 
given access to the head of the list, instead you will be given access to 
the node to be deleted directly. It is guaranteed that the node is not the 
tail node.

EXAMPLE:
Input: head = 4 -> 5 -> 1 -> 9, node = 5
Output: 4 -> 1 -> 9

Input: head = 4 -> 5 -> 1 -> 9, node = 1
Output: 4 -> 5 -> 9

TIME COMPLEXITY: O(1)
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
    void deleteNode(ListNode* node) {
        // Copy the value from next node
        node->val = node->next->val;
        
        // Delete the next node
        ListNode* temp = node->next;
        node->next = node->next->next;
        
        delete temp;  // Free memory
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

ListNode* getNode(ListNode* head, int value) {
    while (head != NULL) {
        if (head->val == value) return head;
        head = head->next;
    }
    return NULL;
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
    
    // Test Case 1
    int arr1[] = {4, 5, 1, 9};
    ListNode* head1 = createList(arr1, 4);
    cout << "Original List: ";
    printList(head1);
    
    ListNode* nodeToDelete1 = getNode(head1, 5);
    cout << "Deleting node with value: 5" << endl;
    solution.deleteNode(nodeToDelete1);
    
    cout << "After Deletion: ";
    printList(head1);
    
    cout << endl;
    
    // Test Case 2
    int arr2[] = {4, 5, 1, 9};
    ListNode* head2 = createList(arr2, 4);
    cout << "Original List: ";
    printList(head2);
    
    ListNode* nodeToDelete2 = getNode(head2, 1);
    cout << "Deleting node with value: 1" << endl;
    solution.deleteNode(nodeToDelete2);
    
    cout << "After Deletion: ";
    printList(head2);
    
    return 0;
}

/*
EXPLANATION:
Since we don't have access to the previous node, we can't directly unlink 
the current node. Instead, we use a clever trick:

1. Copy the value from the next node to current node
2. Delete the next node instead
3. Update current node's next pointer to skip the deleted node

Example: Delete node 5 from 4 -> 5 -> 1 -> 9
1. Copy 1 to node 5: 4 -> 1 -> 1 -> 9
2. Delete second node 1: 4 -> 1 -> 9

KEY INSIGHT:
- We're actually deleting the NEXT node, not the current node
- But by copying the value, it appears we deleted current node
- This is why it doesn't work for tail node (no next node)

LIMITATIONS:
- Doesn't work if node is tail (no next node to copy from)
- Problem guarantees node is not tail
- If node values had constraints, this might not work

KEY PATTERN: Value swapping for deletion without previous pointer
This is a creative problem-solving pattern in linked lists!
*/
