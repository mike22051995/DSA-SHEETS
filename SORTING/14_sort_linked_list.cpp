/*
PROBLEM: Sort Linked List (LeetCode 148)
===============================================
DESCRIPTION:
Given the head of a linked list, sort it in ascending order using merge sort.
Follow up: Can you sort the linked list in O(n log n) time and O(1) space?

PATTERN: Merge Sort on Linked List
DIFFICULTY: Medium
TIME COMPLEXITY: O(n log n)
SPACE COMPLEXITY: O(log n) for recursion, O(1) for iterative

INPUT:
Head of a linked list

OUTPUT:
Head of sorted linked list

EXAMPLE:
Input: 4 -> 2 -> 1 -> 3
Output: 1 -> 2 -> 3 -> 4
*/

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    // Find middle of linked list using slow-fast pointer
    ListNode* getMid(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }
    
    // Merge two sorted linked lists
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* tail = &dummy;
        
        while (l1 && l2) {
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        
        // Attach remaining nodes
        tail->next = l1 ? l1 : l2;
        
        return dummy.next;
    }
    
    // Recursive merge sort
    ListNode* sortList(ListNode* head) {
        // Base case: empty or single node
        if (!head || !head->next) return head;
        
        // Find middle and split list
        ListNode* mid = getMid(head);
        ListNode* rightHead = mid->next;
        mid->next = nullptr; // Break the link
        
        // Recursively sort both halves
        ListNode* left = sortList(head);
        ListNode* right = sortList(rightHead);
        
        // Merge sorted halves
        return merge(left, right);
    }
};

// Helper functions for testing
ListNode* createList(int arr[], int n) {
    if (n == 0) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* curr = head;
    for (int i = 1; i < n; i++) {
        curr->next = new ListNode(arr[i]);
        curr = curr->next;
    }
    return head;
}

void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Solution sol;
    
    int arr[] = {4, 2, 1, 3};
    ListNode* head = createList(arr, 4);
    
    cout << "Original list: ";
    printList(head);
    
    head = sol.sortList(head);
    
    cout << "Sorted list: ";
    printList(head);
    
    return 0;
}

/*
EXPLANATION:
============
MERGE SORT ON LINKED LIST:
1. Find Middle: Use slow-fast pointer technique
2. Split: Break list into two halves
3. Recursively Sort: Sort both halves
4. Merge: Merge two sorted lists

WHY MERGE SORT FOR LINKED LISTS?
- No random access in linked lists
- Merge sort requires only sequential access
- Quick sort would require O(n) space for recursion
- Merge sort is optimal for linked lists

FINDING MIDDLE:
- Slow pointer moves 1 step
- Fast pointer moves 2 steps
- When fast reaches end, slow is at middle

MERGING TWO SORTED LISTS:
- Use dummy node to simplify edge cases
- Compare nodes from both lists
- Attach smaller node to result
- Handle remaining nodes

ADVANTAGES FOR LINKED LISTS:
- No extra space for temporary arrays
- Efficient pointer manipulation
- Natural for divide-and-conquer

TIME COMPLEXITY ANALYSIS:
- Finding middle: O(n)
- Splitting: O(1)
- Merging: O(n)
- Recursion depth: O(log n)
- Total: O(n log n)

WHY THIS PATTERN IS IMPORTANT:
- Optimal sorting for linked lists
- Demonstrates merge technique on linked structures
- Important for understanding linked list manipulation
- Common in FAANG interviews
- Shows adaptation of array algorithm to linked lists
*/
