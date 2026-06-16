/*
================================================================================
PROBLEM: Reverse Linked List II (LeetCode #92)
DIFFICULTY: Medium
PATTERN: Linked List Manipulation
COMPANIES: Amazon, Microsoft, Facebook, Google, Apple
================================================================================
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;
        
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        
        // Move to the node before left
        for (int i = 1; i < left; i++) {
            prev = prev->next;
        }
        
        // Reverse the sublist
        ListNode* curr = prev->next;
        ListNode* next = nullptr;
        
        for (int i = 0; i < right - left; i++) {
            next = curr->next;
            curr->next = next->next;
            next->next = prev->next;
            prev->next = next;
        }
        
        return dummy->next;
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
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    
    cout << "Original: ";
    printList(head);
    
    head = sol.reverseBetween(head, 2, 4);
    
    cout << "After reversing from 2 to 4: ";
    printList(head);
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Reverse Linked List (LeetCode #206)
2. Reverse Nodes in k-Group (LeetCode #25)
3. Swap Nodes in Pairs (LeetCode #24)
4. Rotate List (LeetCode #61)
5. Reorder List (LeetCode #143)
6. Palindrome Linked List (LeetCode #234)
7. Add Two Numbers (LeetCode #2)
8. Remove Nth Node From End (LeetCode #19)
9. Partition List (LeetCode #86)
10. Split Linked List in Parts (LeetCode #725)
*/
