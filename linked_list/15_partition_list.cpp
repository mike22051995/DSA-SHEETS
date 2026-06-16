/*
PROBLEM: Partition List
Difficulty: Medium
Pattern: Two dummy nodes for two sublists

DESCRIPTION:
Given the head of a linked list and a value x, partition it such that all 
nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of nodes in each partition.

EXAMPLE:
Input: head = 1 -> 4 -> 3 -> 2 -> 5 -> 2, x = 3
Output: 1 -> 2 -> 2 -> 4 -> 3 -> 5

Input: head = 2 -> 1, x = 2
Output: 1 -> 2

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
    ListNode* partition(ListNode* head, int x) {
        // Create two dummy nodes for two partitions
        ListNode lessHead(0);    // For nodes < x
        ListNode greaterHead(0); // For nodes >= x
        
        ListNode* less = &lessHead;
        ListNode* greater = &greaterHead;
        
        // Traverse original list and distribute nodes
        ListNode* current = head;
        while (current != NULL) {
            if (current->val < x) {
                less->next = current;
                less = less->next;
            } else {
                greater->next = current;
                greater = greater->next;
            }
            current = current->next;
        }
        
        // Connect two partitions
        greater->next = NULL;  // Important: end the greater list
        less->next = greaterHead.next;
        
        return lessHead.next;
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
    int arr1[] = {1, 4, 3, 2, 5, 2};
    ListNode* head1 = createList(arr1, 6);
    cout << "Original: ";
    printList(head1);
    head1 = solution.partition(head1, 3);
    cout << "Partitioned (x=3): ";
    printList(head1);
    
    cout << endl;
    
    // Test Case 2
    int arr2[] = {2, 1};
    ListNode* head2 = createList(arr2, 2);
    cout << "Original: ";
    printList(head2);
    head2 = solution.partition(head2, 2);
    cout << "Partitioned (x=2): ";
    printList(head2);
    
    cout << endl;
    
    // Test Case 3: All less than x
    int arr3[] = {1, 2, 3};
    ListNode* head3 = createList(arr3, 3);
    cout << "Original: ";
    printList(head3);
    head3 = solution.partition(head3, 5);
    cout << "Partitioned (x=5): ";
    printList(head3);
    
    return 0;
}

/*
EXPLANATION:
Two-Pointer Approach with Dummy Nodes:

1. Create two dummy heads:
   - lessHead: for nodes with val < x
   - greaterHead: for nodes with val >= x

2. Traverse original list:
   - If node->val < x, append to less list
   - Otherwise, append to greater list

3. Connect the two lists:
   - Set greater->next = NULL (terminate list)
   - Connect less list end to greater list start

4. Return lessHead.next

VISUALIZATION (x = 3):
Original: 1 -> 4 -> 3 -> 2 -> 5 -> 2

Less list (<3):    1 -> 2 -> 2
Greater list (≥3): 4 -> 3 -> 5

Final: 1 -> 2 -> 2 -> 4 -> 3 -> 5

WHY TWO DUMMY NODES?
- Simplifies list building (no special case for first node)
- Maintains relative order within each partition
- Clean code without complex conditionals

IMPORTANT DETAIL:
- Must set greater->next = NULL
- Otherwise, may create cycle if greater was originally 
  pointing to a node now in less list

KEY PATTERN: Two dummy nodes for partitioning
Common pattern when splitting list based on condition!
Similar to QuickSort partition but maintaining order.
*/
