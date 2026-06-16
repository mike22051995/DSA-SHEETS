/*
================================================================================
PROBLEM: Reverse Nodes in k-Group (LeetCode #25)
DIFFICULTY: Hard
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;
        
        // Count nodes
        int count = 0;
        ListNode* curr = head;
        while (curr) {
            count++;
            curr = curr->next;
        }
        
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        
        while (count >= k) {
            curr = prev->next;
            ListNode* next = curr->next;
            
            for (int i = 1; i < k; i++) {
                curr->next = next->next;
                next->next = prev->next;
                prev->next = next;
                next = curr->next;
            }
            
            prev = curr;
            count -= k;
        }
        
        return dummy->next;
    }
    
    // Recursive approach
    ListNode* reverseKGroupRecursive(ListNode* head, int k) {
        ListNode* curr = head;
        int count = 0;
        
        while (curr && count < k) {
            curr = curr->next;
            count++;
        }
        
        if (count == k) {
            curr = reverseKGroupRecursive(curr, k);
            
            while (count > 0) {
                ListNode* temp = head->next;
                head->next = curr;
                curr = head;
                head = temp;
                count--;
            }
            
            head = curr;
        }
        
        return head;
    }
};

int main() {
    Solution sol;
    
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    
    head = sol.reverseKGroup(head, 2);
    
    cout << "After reversing in k-groups: ";
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Swap Nodes in Pairs (LeetCode #24)
2. Reverse Linked List (LeetCode #206)
3. Reverse Linked List II (LeetCode #92)
4. Reverse Nodes in Even Length Groups (LeetCode #2074)
5. Reorder List (LeetCode #143)
6. Odd Even Linked List (LeetCode #328)
7. Rotate List (LeetCode #61)
8. Partition List (LeetCode #86)
9. Split Linked List in Parts (LeetCode #725)
10. Palindrome Linked List (LeetCode #234)
*/
