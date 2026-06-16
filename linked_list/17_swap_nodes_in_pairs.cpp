/*
PROBLEM: Swap Nodes in Pairs
Difficulty: Medium
Pattern: Pointer manipulation with dummy node

DESCRIPTION:
Given a linked list, swap every two adjacent nodes and return its head. 
You must solve the problem without modifying the values in the list's nodes 
(i.e., only nodes themselves may be changed).

EXAMPLE:
Input: 1 -> 2 -> 3 -> 4
Output: 2 -> 1 -> 4 -> 3

Input: 1
Output: 1

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
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;
        
        while (prev->next != NULL && prev->next->next != NULL) {
            // Identify nodes to swap
            ListNode* first = prev->next;
            ListNode* second = prev->next->next;
            
            // Perform swap
            first->next = second->next;
            second->next = first;
            prev->next = second;
            
            // Move to next pair
            prev = first;
        }
        
        return dummy.next;
    }
    
    // Recursive approach
    ListNode* swapPairsRecursive(ListNode* head) {
        // Base case: no nodes or single node
        if (head == NULL || head->next == NULL) {
            return head;
        }
        
        // Nodes to swap
        ListNode* first = head;
        ListNode* second = head->next;
        
        // Swap
        first->next = swapPairsRecursive(second->next);
        second->next = first;
        
        return second;  // New head of this segment
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
    
    // Test Case 1: Even number of nodes
    int arr1[] = {1, 2, 3, 4};
    ListNode* head1 = createList(arr1, 4);
    cout << "Original: ";
    printList(head1);
    head1 = solution.swapPairs(head1);
    cout << "After swapping pairs: ";
    printList(head1);
    
    cout << endl;
    
    // Test Case 2: Odd number of nodes
    int arr2[] = {1, 2, 3, 4, 5};
    ListNode* head2 = createList(arr2, 5);
    cout << "Original: ";
    printList(head2);
    head2 = solution.swapPairs(head2);
    cout << "After swapping pairs: ";
    printList(head2);
    
    cout << endl;
    
    // Test Case 3: Single node
    ListNode* head3 = new ListNode(1);
    cout << "Original: ";
    printList(head3);
    head3 = solution.swapPairs(head3);
    cout << "After swapping pairs: ";
    printList(head3);
    
    return 0;
}

/*
EXPLANATION:
Iterative Approach:
1. Use dummy node to handle head swap
2. Use prev pointer to track node before current pair
3. For each pair:
   - Identify first and second nodes
   - Swap their connections
   - Move prev to first (now second in order)

VISUALIZATION (swap 1,2):
Before:
dummy -> 1 -> 2 -> 3 -> 4
prev   first second

After swap:
dummy -> 2 -> 1 -> 3 -> 4
        prev

Swapping steps:
1. first->next = second->next    (1 -> 3)
2. second->next = first           (2 -> 1)
3. prev->next = second            (dummy -> 2)

Recursive Approach:
1. Base case: 0 or 1 nodes
2. Swap first two nodes
3. Recursively swap rest of list
4. Connect swapped pair to recursively swapped rest

RECURSIVE VISUALIZATION:
swapPairs(1->2->3->4)
  = 2->1->swapPairs(3->4)
  = 2->1->4->3->swapPairs(NULL)
  = 2->1->4->3->NULL

KEY INSIGHT:
- Swapping requires changing 3 pointers
- Dummy node simplifies handling head swap
- Prev pointer tracks connection point

KEY PATTERN: Multiple pointer manipulation
Essential for complex node rearrangement problems!
*/
