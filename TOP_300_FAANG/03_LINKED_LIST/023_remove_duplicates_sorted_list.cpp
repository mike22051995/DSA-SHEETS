/*
================================================================================
PROBLEM: Remove Duplicates from Sorted List (LeetCode #83)
DIFFICULTY: Easy
PATTERN: Linked List
COMPANIES: Amazon, Microsoft, Facebook
================================================================================

PROBLEM DESCRIPTION:
Given the head of a sorted linked list, delete all duplicates such that each
element appears only once. Return the linked list sorted as well.

EXAMPLES:

Example 1:
Input: head = [1,1,2]
Output: [1,2]

Example 2:
Input: head = [1,1,2,3,3]
Output: [1,2,3]

PATTERN RECOGNITION:
Use this pattern when:
- Remove duplicates from sorted linked list
- Preserve first occurrence
- In-place modification
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
        if (!head) return nullptr;
        
        ListNode* curr = head;
        
        while (curr && curr->next) {
            if (curr->val == curr->next->val) {
                ListNode* temp = curr->next;
                curr->next = curr->next->next;
                delete temp;
            } else {
                curr = curr->next;
            }
        }
        
        return head;
    }
    
    // Recursive approach
    ListNode* deleteDuplicatesRecursive(ListNode* head) {
        if (!head || !head->next) return head;
        
        head->next = deleteDuplicatesRecursive(head->next);
        
        if (head->val == head->next->val) {
            return head->next;
        }
        
        return head;
    }
};

void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Solution sol;
    
    ListNode* head = new ListNode(1);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(3);
    
    cout << "Original: ";
    printList(head);
    
    head = sol.deleteDuplicates(head);
    
    cout << "After removing duplicates: ";
    printList(head);
    
    return 0;
}

/*
TIME COMPLEXITY: O(n) where n is list length
SPACE COMPLEXITY: O(1) for iterative, O(n) for recursive (call stack)

SIMILAR PROBLEMS:
1. Remove Duplicates from Sorted List II (LeetCode #82)
2. Remove Duplicates from Sorted Array (LeetCode #26)
3. Remove Duplicates from Sorted Array II (LeetCode #80)
4. Remove Element (LeetCode #27)
5. Remove Linked List Elements (LeetCode #203)
6. Delete Node in Linked List (LeetCode #237)
7. Remove Nth Node From End (LeetCode #19)
8. Partition List (LeetCode #86)
9. Odd Even Linked List (LeetCode #328)
10. Remove Zero Sum Consecutive Nodes (LeetCode #1171)
*/
