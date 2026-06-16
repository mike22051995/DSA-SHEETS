/*
PROBLEM: Linked List Cycle Detection
Difficulty: Easy
Pattern: Floyd's Cycle Detection (Slow and Fast Pointer)

DESCRIPTION:
Given head of a linked list, determine if the linked list has a cycle in it.
A cycle exists if there is some node that can be reached again by continuously 
following the next pointer.

EXAMPLE:
Input: 3 -> 2 -> 0 -> -4 (with -4 pointing back to 2)
       ^______________|
Output: true

Input: 1 -> 2 -> NULL
Output: false

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
    bool hasCycle(ListNode *head) {
        if (head == NULL || head->next == NULL) {
            return false;
        }
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;          // Move 1 step
            fast = fast->next->next;    // Move 2 steps
            
            if (slow == fast) {
                return true;  // Cycle detected
            }
        }
        
        return false;  // No cycle
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

// Create cycle at position (0-indexed)
void createCycle(ListNode* head, int pos) {
    if (pos == -1) return;
    ListNode* tail = head;
    ListNode* cycleNode = NULL;
    int index = 0;
    
    while (tail->next != NULL) {
        if (index == pos) {
            cycleNode = tail;
        }
        tail = tail->next;
        index++;
    }
    
    if (cycleNode != NULL) {
        tail->next = cycleNode;
    }
}

int main() {
    Solution solution;
    
    // Test Case 1: List with cycle
    int arr1[] = {3, 2, 0, -4};
    ListNode* head1 = createList(arr1, 4);
    createCycle(head1, 1);  // Create cycle at position 1
    cout << "Test Case 1 (cycle at position 1): " << (solution.hasCycle(head1) ? "true" : "false") << endl;
    
    // Test Case 2: List without cycle
    int arr2[] = {1, 2};
    ListNode* head2 = createList(arr2, 2);
    cout << "Test Case 2 (no cycle): " << (solution.hasCycle(head2) ? "true" : "false") << endl;
    
    // Test Case 3: Single node
    ListNode* head3 = new ListNode(1);
    cout << "Test Case 3 (single node): " << (solution.hasCycle(head3) ? "true" : "false") << endl;
    
    return 0;
}

/*
EXPLANATION:
Floyd's Cycle Detection Algorithm (Tortoise and Hare):
1. Use two pointers: slow (moves 1 step) and fast (moves 2 steps)
2. If there's a cycle, fast pointer will eventually meet slow pointer
3. If there's no cycle, fast pointer will reach NULL

WHY IT WORKS:
- If there's a cycle, both pointers enter the cycle
- Fast pointer gains 1 step per iteration on slow pointer
- Eventually they meet at some point in the cycle

KEY PATTERN: Two-pointer technique (slow/fast)
This is the most efficient approach for cycle detection without extra space!
*/
