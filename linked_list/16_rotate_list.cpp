/*
PROBLEM: Rotate List
Difficulty: Medium
Pattern: Find length + Connect tail to head + Find new tail

DESCRIPTION:
Given the head of a linked list, rotate the list to the right by k places.

EXAMPLE:
Input: head = 1 -> 2 -> 3 -> 4 -> 5, k = 2
Output: 4 -> 5 -> 1 -> 2 -> 3

Input: head = 0 -> 1 -> 2, k = 4
Output: 2 -> 0 -> 1

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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head->next == NULL || k == 0) {
            return head;
        }
        
        // Step 1: Find length and tail
        int length = 1;
        ListNode* tail = head;
        while (tail->next != NULL) {
            tail = tail->next;
            length++;
        }
        
        // Step 2: Optimize k (handle k > length)
        k = k % length;
        if (k == 0) return head;  // No rotation needed
        
        // Step 3: Find new tail at position (length - k - 1)
        ListNode* newTail = head;
        for (int i = 0; i < length - k - 1; i++) {
            newTail = newTail->next;
        }
        
        // Step 4: Perform rotation
        ListNode* newHead = newTail->next;
        newTail->next = NULL;
        tail->next = head;
        
        return newHead;
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
    head1 = solution.rotateRight(head1, 2);
    cout << "Rotated by 2: ";
    printList(head1);
    
    cout << endl;
    
    // Test Case 2: k > length
    int arr2[] = {0, 1, 2};
    ListNode* head2 = createList(arr2, 3);
    cout << "Original: ";
    printList(head2);
    head2 = solution.rotateRight(head2, 4);
    cout << "Rotated by 4: ";
    printList(head2);
    
    cout << endl;
    
    // Test Case 3: k = 0
    int arr3[] = {1, 2, 3};
    ListNode* head3 = createList(arr3, 3);
    cout << "Original: ";
    printList(head3);
    head3 = solution.rotateRight(head3, 0);
    cout << "Rotated by 0: ";
    printList(head3);
    
    return 0;
}

/*
EXPLANATION:
Algorithm Steps:

1. FIND LENGTH AND TAIL:
   - Count nodes and remember tail
   - Needed to optimize k and connect end

2. OPTIMIZE K:
   - k = k % length
   - Rotating by length brings back to original
   - Example: length=5, k=7 → k=2

3. FIND NEW TAIL:
   - New tail is at position (length - k - 1)
   - Example: length=5, k=2 → new tail at position 2
   - This is node with value 3 in example

4. PERFORM ROTATION:
   - New head = newTail->next
   - Break link: newTail->next = NULL
   - Connect old tail to old head: tail->next = head

VISUALIZATION (k=2):
Original: 1 -> 2 -> 3 -> 4 -> 5
                    ↑           ↑
                 newTail     tail

After rotation:
tail connects to head: 5 -> 1 -> 2 -> 3 -> 4 -> 5 (cycle)
Break at newTail: 4 -> 5 -> 1 -> 2 -> 3

KEY INSIGHTS:
- Rotating right by k = moving last k nodes to front
- Same as: new head is at (length - k) position
- Handle k > length by using k % length
- Single pass after finding length

EDGE CASES:
- Empty list or single node
- k = 0 or k = length (no rotation)
- k > length

KEY PATTERN: Circular connection + Break at new position
Useful for rotation and cycle-based problems!
*/
