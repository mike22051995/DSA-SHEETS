/*
================================================================================
PROBLEM: Reorder List (LeetCode #143)
DIFFICULTY: Medium
PATTERN: Linked List (Fast/Slow Pointer + Reverse + Merge)
COMPANIES: Amazon, Facebook, Microsoft, Google, Apple
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
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;
        
        // Find middle
        ListNode* slow = head;
        ListNode* fast = head;
        
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // Reverse second half
        ListNode* second = reverseList(slow->next);
        slow->next = nullptr;
        
        // Merge two halves
        ListNode* first = head;
        
        while (second) {
            ListNode* temp1 = first->next;
            ListNode* temp2 = second->next;
            
            first->next = second;
            second->next = temp1;
            
            first = temp1;
            second = temp2;
        }
    }
    
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        
        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        return prev;
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
    
    sol.reorderList(head);
    
    cout << "Reordered list: ";
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Reverse Linked List (LeetCode #206)
2. Reverse Linked List II (LeetCode #92)
3. Palindrome Linked List (LeetCode #234)
4. Odd Even Linked List (LeetCode #328)
5. Swap Nodes in Pairs (LeetCode #24)
6. Reverse Nodes in k-Group (LeetCode #25)
7. Rotate List (LeetCode #61)
8. Partition List (LeetCode #86)
9. Sort List (LeetCode #148)
10. Remove Nth Node From End (LeetCode #19)
*/
