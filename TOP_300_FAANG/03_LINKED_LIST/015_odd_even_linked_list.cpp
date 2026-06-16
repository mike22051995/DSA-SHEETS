/*
================================================================================
PROBLEM: Odd Even Linked List (LeetCode #328)
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
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head;
        
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = even;
        
        while (even && even->next) {
            odd->next = even->next;
            odd = odd->next;
            
            even->next = odd->next;
            even = even->next;
        }
        
        odd->next = evenHead;
        
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
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    
    cout << "Original: ";
    printList(head);
    
    head = sol.oddEvenList(head);
    
    cout << "After grouping: ";
    printList(head);
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Split Linked List in Parts (LeetCode #725)
2. Partition List (LeetCode #86)
3. Reverse Linked List II (LeetCode #92)
4. Swap Nodes in Pairs (LeetCode #24)
5. Reverse Nodes in k-Group (LeetCode #25)
6. Remove Nth Node From End (LeetCode #19)
7. Reorder List (LeetCode #143)
8. Linked List Cycle II (LeetCode #142)
9. Flatten Binary Tree to Linked List (LeetCode #114)
10. Sort List (LeetCode #148)
*/
