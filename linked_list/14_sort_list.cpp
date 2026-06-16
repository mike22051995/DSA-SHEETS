/*
PROBLEM: Sort List
Difficulty: Medium
Pattern: Merge Sort on Linked List

DESCRIPTION:
Given the head of a linked list, return the list after sorting it in 
ascending order.

Follow up: Can you sort the list in O(n log n) time and O(1) space?

EXAMPLE:
Input: 4 -> 2 -> 1 -> 3
Output: 1 -> 2 -> 3 -> 4

Input: -1 -> 5 -> 3 -> 4 -> 0
Output: -1 -> 0 -> 3 -> 4 -> 5

TIME COMPLEXITY: O(n log n)
SPACE COMPLEXITY: O(log n) due to recursion stack (O(1) extra space for pointers)
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
    ListNode* sortList(ListNode* head) {
        // Base case
        if (head == NULL || head->next == NULL) {
            return head;
        }
        
        // Step 1: Split list into two halves
        ListNode* mid = getMid(head);
        ListNode* left = head;
        ListNode* right = mid->next;
        mid->next = NULL;  // Split the list
        
        // Step 2: Recursively sort both halves
        left = sortList(left);
        right = sortList(right);
        
        // Step 3: Merge sorted halves
        return merge(left, right);
    }
    
private:
    // Find middle node (for splitting)
    ListNode* getMid(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;  // fast starts at next for proper split
        
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }
    
    // Merge two sorted lists
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* tail = &dummy;
        
        while (l1 != NULL && l2 != NULL) {
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        
        tail->next = (l1 != NULL) ? l1 : l2;
        
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
    int arr1[] = {4, 2, 1, 3};
    ListNode* head1 = createList(arr1, 4);
    cout << "Original: ";
    printList(head1);
    head1 = solution.sortList(head1);
    cout << "Sorted: ";
    printList(head1);
    
    cout << endl;
    
    // Test Case 2
    int arr2[] = {-1, 5, 3, 4, 0};
    ListNode* head2 = createList(arr2, 5);
    cout << "Original: ";
    printList(head2);
    head2 = solution.sortList(head2);
    cout << "Sorted: ";
    printList(head2);
    
    cout << endl;
    
    // Test Case 3: Already sorted
    int arr3[] = {1, 2, 3, 4, 5};
    ListNode* head3 = createList(arr3, 5);
    cout << "Original: ";
    printList(head3);
    head3 = solution.sortList(head3);
    cout << "Sorted: ";
    printList(head3);
    
    return 0;
}

/*
EXPLANATION:
Merge Sort Algorithm for Linked List:

1. BASE CASE: If 0 or 1 nodes, already sorted

2. DIVIDE:
   - Find middle using slow-fast pointer
   - Split list into two halves at middle

3. CONQUER:
   - Recursively sort left half
   - Recursively sort right half

4. COMBINE:
   - Merge two sorted halves

WHY MERGE SORT FOR LINKED LIST?
- Doesn't need random access (unlike QuickSort)
- Works well with linked list's sequential access
- Stable sort
- O(n log n) time complexity

TIME COMPLEXITY ANALYSIS:
- Dividing: O(log n) levels
- Merging at each level: O(n)
- Total: O(n log n)

SPACE COMPLEXITY:
- Recursion stack: O(log n)
- No extra space for arrays (in-place rearrangement)

KEY PATTERN: Merge sort adapted for linked list
Classic divide-and-conquer on linked list structure!
This is THE standard sorting algorithm for linked lists!
*/
