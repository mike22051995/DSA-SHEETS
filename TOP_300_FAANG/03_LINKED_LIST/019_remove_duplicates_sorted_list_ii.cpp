/*
================================================================================
PROBLEM: Remove Duplicates from Sorted List II (LeetCode #82)
DIFFICULTY: Medium
PATTERN: Linked List / Two Pointers
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        
        while (head) {
            // Skip duplicates
            if (head->next && head->val == head->next->val) {
                while (head->next && head->val == head->next->val) {
                    head = head->next;
                }
                prev->next = head->next;
            } else {
                prev = prev->next;
            }
            
            head = head->next;
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
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next->next = new ListNode(5);
    
    cout << "Original: ";
    printList(head);
    
    head = sol.deleteDuplicates(head);
    
    cout << "After removing duplicates: ";
    printList(head);
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Remove Duplicates from Sorted List (LeetCode #83)
2. Remove Duplicates from Sorted Array (LeetCode #26)
3. Remove Duplicates from Sorted Array II (LeetCode #80)
4. Remove Nth Node From End (LeetCode #19)
5. Delete Node in Linked List (LeetCode #237)
6. Remove Linked List Elements (LeetCode #203)
7. Partition List (LeetCode #86)
8. Odd Even Linked List (LeetCode #328)
9. Split Linked List in Parts (LeetCode #725)
10. Reverse Linked List II (LeetCode #92)
*/
