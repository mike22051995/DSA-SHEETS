/*
================================================================================
PROBLEM: Rotate List (LeetCode #61)
DIFFICULTY: Medium
PATTERN: Two Pointers / Linked List
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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;
        
        // Calculate length and find tail
        int length = 1;
        ListNode* tail = head;
        
        while (tail->next) {
            tail = tail->next;
            length++;
        }
        
        // Connect tail to head to make circular
        tail->next = head;
        
        // Find new tail: (length - k % length - 1)th node
        k = k % length;
        int stepsToNewHead = length - k;
        
        ListNode* newTail = head;
        for (int i = 1; i < stepsToNewHead; i++) {
            newTail = newTail->next;
        }
        
        ListNode* newHead = newTail->next;
        newTail->next = nullptr;
        
        return newHead;
    }
};

int main() {
    Solution sol;
    
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    
    head = sol.rotateRight(head, 2);
    
    cout << "After rotation: ";
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Rotate Array (LeetCode #189)
2. Reverse Linked List (LeetCode #206)
3. Reverse Linked List II (LeetCode #92)
4. Reorder List (LeetCode #143)
5. Odd Even Linked List (LeetCode #328)
6. Split Linked List in Parts (LeetCode #725)
7. Partition List (LeetCode #86)
8. Remove Nth Node From End (LeetCode #19)
9. Linked List Cycle II (LeetCode #142)
10. Intersection of Two Linked Lists (LeetCode #160)
*/
