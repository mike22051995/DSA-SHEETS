/*
PROBLEM: Reorder List
Difficulty: Medium
Pattern: Find middle + Reverse + Merge

DESCRIPTION:
You are given the head of a singly linked-list. Reorder the list to be on 
the following form: L0 → Ln → L1 → Ln-1 → L2 → Ln-2 → ...

You may not modify the values in the list's nodes. Only nodes themselves 
may be changed.

EXAMPLE:
Input: 1 -> 2 -> 3 -> 4
Output: 1 -> 4 -> 2 -> 3

Input: 1 -> 2 -> 3 -> 4 -> 5
Output: 1 -> 5 -> 2 -> 4 -> 3

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
    void reorderList(ListNode* head) {
        if (head == NULL || head->next == NULL) return;
        
        // Step 1: Find middle of list
        ListNode* slow = head;
        ListNode* fast = head;
        
        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // Step 2: Reverse second half
        ListNode* secondHalf = reverseList(slow->next);
        slow->next = NULL;  // Split the list
        
        // Step 3: Merge two halves alternately
        ListNode* first = head;
        ListNode* second = secondHalf;
        
        while (second != NULL) {
            ListNode* temp1 = first->next;
            ListNode* temp2 = second->next;
            
            first->next = second;
            second->next = temp1;
            
            first = temp1;
            second = temp2;
        }
    }
    
private:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* current = head;
        
        while (current != NULL) {
            ListNode* next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        
        return prev;
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
    
    // Test Case 1: Even length
    int arr1[] = {1, 2, 3, 4};
    ListNode* head1 = createList(arr1, 4);
    cout << "Original: ";
    printList(head1);
    solution.reorderList(head1);
    cout << "Reordered: ";
    printList(head1);
    
    cout << endl;
    
    // Test Case 2: Odd length
    int arr2[] = {1, 2, 3, 4, 5};
    ListNode* head2 = createList(arr2, 5);
    cout << "Original: ";
    printList(head2);
    solution.reorderList(head2);
    cout << "Reordered: ";
    printList(head2);
    
    cout << endl;
    
    // Test Case 3: Three elements
    int arr3[] = {1, 2, 3};
    ListNode* head3 = createList(arr3, 3);
    cout << "Original: ";
    printList(head3);
    solution.reorderList(head3);
    cout << "Reordered: ";
    printList(head3);
    
    return 0;
}

/*
EXPLANATION:
Three-step algorithm:

1. FIND MIDDLE:
   - Use slow-fast pointer
   - Slow reaches middle when fast reaches end

2. REVERSE SECOND HALF:
   - Reverse from middle to end
   - Now we have two lists to merge

3. MERGE ALTERNATELY:
   - Take one node from first half
   - Take one node from second half
   - Repeat until second half exhausted

VISUALIZATION (1->2->3->4):
Original: 1 -> 2 -> 3 -> 4

After finding middle:
First half: 1 -> 2
Second half: 3 -> 4

After reversing second half:
First half: 1 -> 2
Second half: 4 -> 3

After merging:
1 -> 4 -> 2 -> 3

WHY SECOND HALF?
- First half might have one extra node (odd length)
- Reversing second ensures correct alternate merging

KEY PATTERN: Combination of three patterns
1. Find middle (slow-fast)
2. Reverse list
3. Merge two lists
This is a composite problem testing multiple skills!
*/
