/*
================================================================================
PROBLEM: Swap Nodes in Pairs (LeetCode #24)
DIFFICULTY: Medium
PATTERN: Linked List Manipulation
COMPANIES: Amazon, Microsoft, Facebook, Google
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
    // Iterative approach
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        
        while (prev->next && prev->next->next) {
            ListNode* first = prev->next;
            ListNode* second = prev->next->next;
            
            // Swap
            first->next = second->next;
            second->next = first;
            prev->next = second;
            
            // Move prev
            prev = first;
        }
        
        return dummy->next;
    }
    
    // Recursive approach
    ListNode* swapPairsRecursive(ListNode* head) {
        if (!head || !head->next) return head;
        
        ListNode* first = head;
        ListNode* second = head->next;
        
        first->next = swapPairsRecursive(second->next);
        second->next = first;
        
        return second;
    }
};

int main() {
    Solution sol;
    
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    
    head = sol.swapPairs(head);
    
    cout << "After swapping pairs: ";
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Reverse Nodes in k-Group (LeetCode #25)
2. Reverse Linked List (LeetCode #206)
3. Reverse Linked List II (LeetCode #92)
4. Reorder List (LeetCode #143)
5. Odd Even Linked List (LeetCode #328)
6. Partition List (LeetCode #86)
7. Rotate List (LeetCode #61)
8. Remove Nth Node From End (LeetCode #19)
9. Palindrome Linked List (LeetCode #234)
10. Sort List (LeetCode #148)
*/
