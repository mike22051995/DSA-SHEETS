/*
PROBLEM: Add Two Numbers
Difficulty: Medium
Pattern: Digit-by-digit addition with carry

DESCRIPTION:
You are given two non-empty linked lists representing two non-negative integers. 
The digits are stored in reverse order, and each node contains a single digit. 
Add the two numbers and return the sum as a linked list.

EXAMPLE:
Input: l1 = 2 -> 4 -> 3, l2 = 5 -> 6 -> 4
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807

Input: l1 = 9 -> 9 -> 9, l2 = 9 -> 9 -> 9 -> 9
Output: 8 -> 9 -> 9 -> 0 -> 1
Explanation: 999 + 9999 = 10998

TIME COMPLEXITY: O(max(m, n)) where m and n are lengths of two lists
SPACE COMPLEXITY: O(max(m, n)) for the result list
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* tail = &dummy;
        int carry = 0;
        
        while (l1 != NULL || l2 != NULL || carry != 0) {
            int sum = carry;
            
            if (l1 != NULL) {
                sum += l1->val;
                l1 = l1->next;
            }
            
            if (l2 != NULL) {
                sum += l2->val;
                l2 = l2->next;
            }
            
            carry = sum / 10;
            tail->next = new ListNode(sum % 10);
            tail = tail->next;
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
    int arr1[] = {2, 4, 3};
    int arr2[] = {5, 6, 4};
    ListNode* l1 = createList(arr1, 3);
    ListNode* l2 = createList(arr2, 3);
    cout << "L1: ";
    printList(l1);
    cout << "L2: ";
    printList(l2);
    ListNode* result = solution.addTwoNumbers(l1, l2);
    cout << "Sum: ";
    printList(result);
    cout << "(342 + 465 = 807)" << endl << endl;
    
    // Test Case 2: Different lengths
    int arr3[] = {9, 9, 9};
    int arr4[] = {9, 9, 9, 9};
    ListNode* l3 = createList(arr3, 3);
    ListNode* l4 = createList(arr4, 4);
    cout << "L3: ";
    printList(l3);
    cout << "L4: ";
    printList(l4);
    ListNode* result2 = solution.addTwoNumbers(l3, l4);
    cout << "Sum: ";
    printList(result2);
    cout << "(999 + 9999 = 10998)" << endl;
    
    return 0;
}

/*
EXPLANATION:
1. Use dummy node to simplify result list creation
2. Maintain carry variable (0 or 1)
3. Iterate through both lists simultaneously:
   - Add values from both lists (if available) plus carry
   - Create new node with sum % 10
   - Update carry = sum / 10
4. Continue until both lists exhausted AND carry is 0

KEY POINTS:
- Numbers stored in reverse order (easier to add)
- Handle different length lists
- Don't forget final carry (can create extra node)
- Similar to manual addition on paper

EDGE CASES:
- Different lengths: 99 + 9999
- Final carry: 999 + 1 = 1000
- Empty lists (problem states non-empty)

KEY PATTERN: Dummy node + digit-by-digit processing with carry
Common pattern for linked list arithmetic operations!
*/
