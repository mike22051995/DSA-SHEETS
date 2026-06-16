/*
PROBLEM: Insertion Sort List
Difficulty: Medium
Pattern: Build sorted list gradually

DESCRIPTION:
Given the head of a singly linked list, sort the list using insertion sort, 
and return the sorted list's head.

EXAMPLE:
Input: 4 -> 2 -> 1 -> 3
Output: 1 -> 2 -> 3 -> 4

Input: -1 -> 5 -> 3 -> 4 -> 0
Output: -1 -> 0 -> 3 -> 4 -> 5

TIME COMPLEXITY: O(n²) worst case
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
    ListNode* insertionSortList(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        
        ListNode dummy(INT_MIN);  // Dummy with smallest value
        ListNode* current = head;
        
        while (current != NULL) {
            // Save next node
            ListNode* next = current->next;
            
            // Find insertion position
            ListNode* prev = &dummy;
            while (prev->next != NULL && prev->next->val < current->val) {
                prev = prev->next;
            }
            
            // Insert current node
            current->next = prev->next;
            prev->next = current;
            
            // Move to next node
            current = next;
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
    head1 = solution.insertionSortList(head1);
    cout << "Sorted: ";
    printList(head1);
    
    cout << endl;
    
    // Test Case 2
    int arr2[] = {-1, 5, 3, 4, 0};
    ListNode* head2 = createList(arr2, 5);
    cout << "Original: ";
    printList(head2);
    head2 = solution.insertionSortList(head2);
    cout << "Sorted: ";
    printList(head2);
    
    cout << endl;
    
    // Test Case 3: Already sorted
    int arr3[] = {1, 2, 3, 4};
    ListNode* head3 = createList(arr3, 4);
    cout << "Original: ";
    printList(head3);
    head3 = solution.insertionSortList(head3);
    cout << "Sorted: ";
    printList(head3);
    
    cout << endl;
    
    // Test Case 4: Reverse sorted
    int arr4[] = {5, 4, 3, 2, 1};
    ListNode* head4 = createList(arr4, 5);
    cout << "Original: ";
    printList(head4);
    head4 = solution.insertionSortList(head4);
    cout << "Sorted: ";
    printList(head4);
    
    return 0;
}

/*
EXPLANATION:

Insertion Sort Algorithm:
1. Maintain a sorted list (initially empty, using dummy)
2. Take one node at a time from original list
3. Find correct position in sorted list
4. Insert node at that position
5. Repeat until all nodes processed

VISUALIZATION (4->2->1->3):

Initial:
Sorted: dummy
Original: 4 -> 2 -> 1 -> 3

Step 1: Insert 4
Sorted: dummy -> 4
Original: 2 -> 1 -> 3

Step 2: Insert 2
Find position: before 4
Sorted: dummy -> 2 -> 4
Original: 1 -> 3

Step 3: Insert 1
Find position: before 2
Sorted: dummy -> 1 -> 2 -> 4
Original: 3

Step 4: Insert 3
Find position: after 2, before 4
Sorted: dummy -> 1 -> 2 -> 3 -> 4

HOW TO FIND INSERTION POSITION:
- Start from dummy
- Move forward while next node's value < current value
- Insert after this position

WHY DUMMY NODE:
- Simplifies insertion before first node
- No special case for empty sorted list
- Acts as sentinel with smallest possible value

TIME COMPLEXITY:
- Best case: O(n) - already sorted
- Average case: O(n²)
- Worst case: O(n²) - reverse sorted

COMPARISON WITH MERGE SORT:
- Merge Sort: O(n log n), better for large lists
- Insertion Sort: O(n²), but simple and good for small/nearly-sorted lists

KEY PATTERN: Building sorted list with insertion
Classic sorting algorithm adapted for linked lists!
*/
