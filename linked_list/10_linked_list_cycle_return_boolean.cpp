/*
PROBLEM: Linked List Cycle (Return Boolean)
Difficulty: Easy
Pattern: Floyd's Cycle Detection Algorithm

DESCRIPTION:
Given head, the head of a linked list, determine if the linked list has a 
cycle in it. Return true if there is a cycle, otherwise return false.

There is a cycle in a linked list if there is some node in the list that 
can be reached again by continuously following the next pointer.

EXAMPLE:
Input: head = 3 -> 2 -> 0 -> -4 (tail connects to node at index 1)
                    ^_________|
Output: true

Input: head = 1 -> 2 -> NULL
Output: false

TIME COMPLEXITY: O(n) where n is the number of nodes
SPACE COMPLEXITY: O(1)
*/

#include <iostream>
#include <unordered_set>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    // Approach 1: Floyd's Cycle Detection (Optimal)
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
    
    // Approach 2: Using Hash Set (Less optimal but intuitive)
    bool hasCycleUsingSet(ListNode *head) {
        unordered_set<ListNode*> visited;
        
        ListNode* current = head;
        while (current != NULL) {
            // If already visited, cycle exists
            if (visited.find(current) != visited.end()) {
                return true;
            }
            
            visited.insert(current);
            current = current->next;
        }
        
        return false;
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
    
    // Test Case 1: Cycle at position 1
    int arr1[] = {3, 2, 0, -4};
    ListNode* head1 = createList(arr1, 4);
    createCycle(head1, 1);
    cout << "Test Case 1 (cycle at position 1):" << endl;
    cout << "Has Cycle: " << (solution.hasCycle(head1) ? "true" : "false") << endl;
    
    cout << endl;
    
    // Test Case 2: No cycle
    int arr2[] = {1, 2, 3};
    ListNode* head2 = createList(arr2, 3);
    cout << "Test Case 2 (no cycle):" << endl;
    cout << "Has Cycle: " << (solution.hasCycle(head2) ? "true" : "false") << endl;
    
    cout << endl;
    
    // Test Case 3: Single node with cycle to itself
    ListNode* head3 = new ListNode(1);
    head3->next = head3;
    cout << "Test Case 3 (single node, cycle to itself):" << endl;
    cout << "Has Cycle: " << (solution.hasCycle(head3) ? "true" : "false") << endl;
    
    cout << endl;
    
    // Test Case 4: Two nodes with cycle
    ListNode* head4 = new ListNode(1);
    head4->next = new ListNode(2);
    head4->next->next = head4;
    cout << "Test Case 4 (two nodes with cycle):" << endl;
    cout << "Has Cycle: " << (solution.hasCycle(head4) ? "true" : "false") << endl;
    
    return 0;
}

/*
EXPLANATION:

Approach 1: Floyd's Cycle Detection (Tortoise and Hare)
1. Use two pointers: slow (1 step) and fast (2 steps)
2. If there's a cycle, fast will eventually catch up to slow
3. If no cycle, fast will reach NULL

Mathematical Proof:
- If cycle length is C and slow is k steps into cycle
- Fast is 2k steps into cycle
- Fast gains 1 step per iteration on slow
- They meet in at most C iterations after both enter cycle

Approach 2: Hash Set
1. Store every visited node in a set
2. If we visit a node already in set, cycle exists
3. If we reach NULL, no cycle

COMPARISON:
Floyd's Algorithm:
- Time: O(n)
- Space: O(1) ✓
- More complex to understand

Hash Set:
- Time: O(n)
- Space: O(n) ✗
- More intuitive

KEY PATTERN: Two-pointer technique (slow/fast)
This is THE standard algorithm for cycle detection in linked lists!
Must know for interviews!
*/
