/*
================================================================================
PROBLEM: Middle of the Linked List (LeetCode #876)
DIFFICULTY: Easy
PATTERN: Linked List / Two Pointers (Fast & Slow)
COMPANIES: Amazon, Microsoft, Facebook, Google
================================================================================

PROBLEM DESCRIPTION:
Given the head of a singly linked list, return the middle node of the linked
list. If there are two middle nodes, return the second middle node.

EXAMPLES:

Example 1:
Input: head = [1,2,3,4,5]
Output: [3,4,5]
Explanation: The middle node is 3.

Example 2:
Input: head = [1,2,3,4,5,6]
Output: [4,5,6]
Explanation: Two middle nodes (3 and 4), return the second one.

PATTERN RECOGNITION:
Use this pattern when:
- Need to find middle of linked list in one pass
- Fast and slow pointer technique
- No length calculation needed
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
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
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
    
    // Example 1: [1,2,3,4,5]
    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(3);
    head1->next->next->next = new ListNode(4);
    head1->next->next->next->next = new ListNode(5);
    
    cout << "Original: ";
    printList(head1);
    
    ListNode* mid1 = sol.middleNode(head1);
    cout << "Middle: ";
    printList(mid1);
    
    // Example 2: [1,2,3,4,5,6]
    ListNode* head2 = new ListNode(1);
    head2->next = new ListNode(2);
    head2->next->next = new ListNode(3);
    head2->next->next->next = new ListNode(4);
    head2->next->next->next->next = new ListNode(5);
    head2->next->next->next->next->next = new ListNode(6);
    
    cout << "\nOriginal: ";
    printList(head2);
    
    ListNode* mid2 = sol.middleNode(head2);
    cout << "Middle: ";
    printList(mid2);
    
    return 0;
}

/*
TIME COMPLEXITY: O(n) where n is length of list
SPACE COMPLEXITY: O(1)

SIMILAR PROBLEMS:
1. Linked List Cycle (LeetCode #141)
2. Linked List Cycle II (LeetCode #142)
3. Remove Nth Node From End (LeetCode #19)
4. Reorder List (LeetCode #143)
5. Palindrome Linked List (LeetCode #234)
6. Intersection of Two Linked Lists (LeetCode #160)
7. Delete Middle Node (LeetCode #2095)
8. Split Linked List in Parts (LeetCode #725)
9. Reverse Linked List (LeetCode #206)
10. Odd Even Linked List (LeetCode #328)
*/
