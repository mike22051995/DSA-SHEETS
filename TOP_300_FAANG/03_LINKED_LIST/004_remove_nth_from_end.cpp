/*
================================================================================
PROBLEM: Remove Nth Node From End of List (LeetCode #19)
DIFFICULTY: Medium
PATTERN: Two Pointers (Fast & Slow)
COMPANIES: Amazon, Microsoft, Facebook, Google, Apple
================================================================================
*/

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0);
        dummy.next = head;
        
        ListNode* fast = &dummy;
        ListNode* slow = &dummy;
        
        // Move fast n+1 steps ahead
        for (int i = 0; i <= n; i++) {
            fast = fast->next;
        }
        
        // Move both pointers until fast reaches end
        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
        
        // Remove nth node
        ListNode* temp = slow->next;
        slow->next = slow->next->next;
        delete temp;
        
        return dummy.next;
    }
};

int main() {
    Solution sol;
    
    // Create list: 1->2->3->4->5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    
    head = sol.removeNthFromEnd(head, 2);
    
    cout << "List after removing 2nd from end: ";
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Delete Node in Linked List (LeetCode #237)
2. Remove Linked List Elements (LeetCode #203)
3. Reverse Linked List (LeetCode #206)
4. Middle of Linked List (LeetCode #876)
5. Linked List Cycle (LeetCode #141)
6. Linked List Cycle II (LeetCode #142)
7. Palindrome Linked List (LeetCode #234)
8. Reorder List (LeetCode #143)
9. Rotate List (LeetCode #61)
10. Swap Nodes in Pairs (LeetCode #24)
*/
