/*
================================================================================
PROBLEM: Partition List (LeetCode #86)
DIFFICULTY: Medium
PATTERN: Two Pointers / Linked List
COMPANIES: Amazon, Microsoft, Facebook
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
    ListNode* partition(ListNode* head, int x) {
        ListNode* lessHead = new ListNode(0);
        ListNode* greaterHead = new ListNode(0);
        
        ListNode* less = lessHead;
        ListNode* greater = greaterHead;
        
        while (head) {
            if (head->val < x) {
                less->next = head;
                less = less->next;
            } else {
                greater->next = head;
                greater = greater->next;
            }
            head = head->next;
        }
        
        greater->next = nullptr;
        less->next = greaterHead->next;
        
        return lessHead->next;
    }
};

int main() {
    Solution sol;
    
    ListNode* head = new ListNode(1);
    head->next = new ListNode(4);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(2);
    
    head = sol.partition(head, 3);
    
    cout << "After partition: ";
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Sort Colors (LeetCode #75)
2. Sort List (LeetCode #148)
3. Odd Even Linked List (LeetCode #328)
4. Partition Array (LeetCode #2161)
5. Partition Equal Subset Sum (LeetCode #416)
6. Partition Labels (LeetCode #763)
7. Remove Duplicates from Sorted List (LeetCode #83)
8. Remove Duplicates from Sorted List II (LeetCode #82)
9. Merge Two Sorted Lists (LeetCode #21)
10. Reorder List (LeetCode #143)
*/
