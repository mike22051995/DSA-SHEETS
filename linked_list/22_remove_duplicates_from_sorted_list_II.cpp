/*
PROBLEM: Remove Duplicates from Sorted List II
Difficulty: Medium
Pattern: Dummy node + Skip duplicates

DESCRIPTION:
Given the head of a sorted linked list, delete all nodes that have duplicate 
numbers, leaving only distinct numbers from the original list. Return the 
linked list sorted as well.

EXAMPLE:
Input: 1 -> 2 -> 3 -> 3 -> 4 -> 4 -> 5
Output: 1 -> 2 -> 5

Input: 1 -> 1 -> 1 -> 2 -> 3
Output: 2 -> 3

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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;
        
        while (head != NULL) {
            // Check if current node has duplicates
            if (head->next != NULL && head->val == head->next->val) {
                // Skip all nodes with same value
                while (head->next != NULL && head->val == head->next->val) {
                    ListNode* temp = head;
                    head = head->next;
                    delete temp;
                }
                // Delete the last duplicate
                ListNode* temp = head;
                head = head->next;
                delete temp;
                
                prev->next = head;
            } else {
                // No duplicate, move both pointers
                prev = head;
                head = head->next;
            }
        }
        
        return dummy.next;
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
    
    // Test Case 1
    int arr1[] = {1, 2, 3, 3, 4, 4, 5};
    ListNode* head1 = createList(arr1, 7);
    cout << "Original: ";
    printList(head1);
    head1 = solution.deleteDuplicates(head1);
    cout << "After removing duplicates: ";
    printList(head1);
    
    cout << endl;
    
    // Test Case 2: Duplicates at start
    int arr2[] = {1, 1, 1, 2, 3};
    ListNode* head2 = createList(arr2, 5);
    cout << "Original: ";
    printList(head2);
    head2 = solution.deleteDuplicates(head2);
    cout << "After removing duplicates: ";
    printList(head2);
    
    cout << endl;
    
    // Test Case 3: All duplicates
    int arr3[] = {1, 1, 2, 2};
    ListNode* head3 = createList(arr3, 4);
    cout << "Original: ";
    printList(head3);
    head3 = solution.deleteDuplicates(head3);
    cout << "After removing duplicates: ";
    printList(head3);
    
    cout << endl;
    
    // Test Case 4: No duplicates
    int arr4[] = {1, 2, 3};
    ListNode* head4 = createList(arr4, 3);
    cout << "Original: ";
    printList(head4);
    head4 = solution.deleteDuplicates(head4);
    cout << "After removing duplicates: ";
    printList(head4);
    
    return 0;
}

/*
EXPLANATION:

Key Difference from "Remove Duplicates I":
- In version I: Keep ONE occurrence of each value
- In version II: Remove ALL occurrences of duplicated values

Algorithm:
1. Use dummy node (head might be removed)
2. Use prev pointer to track last valid node
3. Use head pointer to scan through list
4. When duplicate detected:
   - Skip ALL nodes with that value
   - Connect prev to node after duplicates
5. When no duplicate:
   - Move both prev and head forward

VISUALIZATION (1->2->3->3->4->4->5):

Initial:
dummy -> 1 -> 2 -> 3 -> 3 -> 4 -> 4 -> 5
prev    head

No duplicate at 1:
dummy -> 1 -> 2 -> 3 -> 3 -> 4 -> 4 -> 5
        prev head

No duplicate at 2:
dummy -> 1 -> 2 -> 3 -> 3 -> 4 -> 4 -> 5
             prev head

Duplicate at 3:
Skip both 3s
dummy -> 1 -> 2 -> 4 -> 4 -> 5
             prev head

Duplicate at 4:
Skip both 4s
dummy -> 1 -> 2 -> 5
             prev head

No duplicate at 5:
dummy -> 1 -> 2 -> 5
                  prev head

KEY POINTS:
- Must skip ALL nodes with duplicate value
- Use prev to maintain connection to last valid node
- Dummy node handles case where head is duplicate

KEY PATTERN: Skip all occurrences pattern
Important variation of duplicate removal!
*/
