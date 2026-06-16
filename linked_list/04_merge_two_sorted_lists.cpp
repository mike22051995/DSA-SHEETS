/*
PROBLEM: Merge Two Sorted Lists
Difficulty: Easy
Pattern: Two-pointer merge technique

DESCRIPTION:
Merge two sorted linked lists and return it as a sorted list. 
The list should be made by splicing together the nodes of the first two lists.

EXAMPLE:
Input: list1 = 1 -> 2 -> 4, list2 = 1 -> 3 -> 4
Output: 1 -> 1 -> 2 -> 3 -> 4 -> 4

Input: list1 = [], list2 = []
Output: []

TIME COMPLEXITY: O(m + n) where m and n are lengths of the two lists
SPACE COMPLEXITY: O(1) - only pointer manipulation, no extra space
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Create a dummy node to simplify edge cases
        ListNode dummy(0);
        ListNode* tail = &dummy;
        
        // Merge while both lists have nodes
        while (list1 != NULL && list2 != NULL) {
            if (list1->val <= list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }
        
        // Attach remaining nodes
        if (list1 != NULL) {
            tail->next = list1;
        } else {
            tail->next = list2;
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
    int arr1[] = {1, 2, 4};
    int arr2[] = {1, 3, 4};
    ListNode* list1 = createList(arr1, 3);
    ListNode* list2 = createList(arr2, 3);
    cout << "List 1: ";
    printList(list1);
    cout << "List 2: ";
    printList(list2);
    ListNode* merged = solution.mergeTwoLists(list1, list2);
    cout << "Merged: ";
    printList(merged);
    
    cout << endl;
    
    // Test Case 2: One empty list
    int arr3[] = {5};
    ListNode* list3 = NULL;
    ListNode* list4 = createList(arr3, 1);
    cout << "List 3: ";
    printList(list3);
    cout << "List 4: ";
    printList(list4);
    ListNode* merged2 = solution.mergeTwoLists(list3, list4);
    cout << "Merged: ";
    printList(merged2);
    
    return 0;
}

/*
EXPLANATION:
1. Create a dummy node to avoid handling head separately
2. Use a tail pointer to build the merged list
3. Compare values from both lists and attach smaller one
4. Move the pointer of the list from which node was taken
5. After loop, attach remaining nodes (at most one list has remaining)

DUMMY NODE TRICK:
- Simplifies code by avoiding special case for head
- dummy.next will point to the actual head of merged list

KEY PATTERN: Dummy node + Two-pointer merge
This is a fundamental pattern for merging sorted sequences!
*/
