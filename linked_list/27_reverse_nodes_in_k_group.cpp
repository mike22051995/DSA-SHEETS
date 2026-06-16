/*
PROBLEM: Reverse Nodes in k-Group
Difficulty: Hard
Pattern: Recursive reversal with measurement

DESCRIPTION:
Given the head of a linked list, reverse the nodes of the list k at a time, 
and return the modified list. k is a positive integer and is less than or 
equal to the length of the linked list.

If the number of nodes is not a multiple of k then left-out nodes, in the end, 
should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves.

EXAMPLE:
Input: head = 1 -> 2 -> 3 -> 4 -> 5, k = 2
Output: 2 -> 1 -> 4 -> 3 -> 5

Input: head = 1 -> 2 -> 3 -> 4 -> 5, k = 3
Output: 3 -> 2 -> 1 -> 4 -> 5

TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(n/k) for recursion stack
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL || k == 1) return head;
        
        // Check if there are k nodes ahead
        ListNode* current = head;
        int count = 0;
        while (current != NULL && count < k) {
            current = current->next;
            count++;
        }
        
        // If less than k nodes, return as is
        if (count < k) return head;
        
        // Reverse first k nodes
        ListNode* prev = NULL;
        current = head;
        ListNode* next = NULL;
        
        for (int i = 0; i < k; i++) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        
        // prev is now new head of reversed group
        // head is now tail of reversed group
        // current points to start of next group
        
        // Recursively reverse next groups
        if (next != NULL) {
            head->next = reverseKGroup(next, k);
        }
        
        return prev;  // New head
    }
    
    // Iterative approach
    ListNode* reverseKGroupIterative(ListNode* head, int k) {
        if (head == NULL || k == 1) return head;
        
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prevGroupEnd = &dummy;
        
        while (true) {
            // Check if k nodes exist
            ListNode* kthNode = getKthNode(prevGroupEnd, k);
            if (kthNode == NULL) break;
            
            ListNode* nextGroupStart = kthNode->next;
            
            // Reverse current group
            ListNode* prev = nextGroupStart;
            ListNode* current = prevGroupEnd->next;
            
            while (current != nextGroupStart) {
                ListNode* next = current->next;
                current->next = prev;
                prev = current;
                current = next;
            }
            
            // Connect with previous group
            ListNode* groupStart = prevGroupEnd->next;
            prevGroupEnd->next = kthNode;
            prevGroupEnd = groupStart;
        }
        
        return dummy.next;
    }
    
private:
    ListNode* getKthNode(ListNode* start, int k) {
        ListNode* current = start;
        while (current != NULL && k > 0) {
            current = current->next;
            k--;
        }
        return current;
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
    
    // Test Case 1: k = 2
    int arr1[] = {1, 2, 3, 4, 5};
    ListNode* head1 = createList(arr1, 5);
    cout << "Original: ";
    printList(head1);
    head1 = solution.reverseKGroup(head1, 2);
    cout << "Reversed in groups of 2: ";
    printList(head1);
    
    cout << endl;
    
    // Test Case 2: k = 3
    int arr2[] = {1, 2, 3, 4, 5};
    ListNode* head2 = createList(arr2, 5);
    cout << "Original: ";
    printList(head2);
    head2 = solution.reverseKGroup(head2, 3);
    cout << "Reversed in groups of 3: ";
    printList(head2);
    
    cout << endl;
    
    // Test Case 3: k = 1
    int arr3[] = {1, 2, 3};
    ListNode* head3 = createList(arr3, 3);
    cout << "Original: ";
    printList(head3);
    head3 = solution.reverseKGroup(head3, 1);
    cout << "Reversed in groups of 1: ";
    printList(head3);
    
    return 0;
}

/*
EXPLANATION:

Recursive Approach:

STEP 1: Check if k nodes available
- Count k nodes from current position
- If less than k, return as is

STEP 2: Reverse first k nodes
- Use standard reversal technique
- prev becomes new head of this group
- original head becomes tail

STEP 3: Recursively process rest
- Call reverseKGroup on remaining list
- Connect tail of current group to result

VISUALIZATION (k=2, list=1->2->3->4->5):

Initial: 1 -> 2 -> 3 -> 4 -> 5

Step 1: Reverse first 2
2 -> 1 -> [3 -> 4 -> 5]
     tail  remaining

Step 2: Recursively reverse remaining
2 -> 1 -> [4 -> 3 -> 5]
     tail        

Final: 2 -> 1 -> 4 -> 3 -> 5

DETAILED REVERSAL OF GROUP:
Before: 1 -> 2 -> 3
prev=NULL, current=1

i=0: next=2, 1->NULL, prev=1, current=2
i=1: next=3, 2->1, prev=2, current=3

Result: 2 -> 1, current=3 (next group)

Iterative Approach:
1. Use dummy node
2. Track previous group's end
3. For each group:
   - Check if k nodes exist
   - Reverse the group
   - Connect with previous group
4. Move to next group

WHY THIS IS HARD:
- Multiple edge cases (k=1, k=n, k>n)
- Complex pointer manipulation
- Need to track multiple positions
- Recursive thinking required

KEY INSIGHTS:
- Don't reverse if less than k nodes remain
- Original head becomes tail after reversal
- Need to connect groups properly
- Recursion simplifies the logic

KEY PATTERN: Recursive reversal with measurement
Combines reversal with careful counting and connection!
*/
