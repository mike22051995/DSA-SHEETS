/*
================================================================================
PROBLEM: Insertion Sort List (LeetCode #147)
DIFFICULTY: Medium
PATTERN: Linked List / Sorting
COMPANIES: Amazon, Microsoft, Google
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
    ListNode* insertionSortList(ListNode* head) {
        if (!head || !head->next) return head;
        
        ListNode* dummy = new ListNode(0);
        ListNode* curr = head;
        
        while (curr) {
            ListNode* next = curr->next;
            
            // Find insertion position
            ListNode* prev = dummy;
            while (prev->next && prev->next->val < curr->val) {
                prev = prev->next;
            }
            
            // Insert current node
            curr->next = prev->next;
            prev->next = curr;
            
            curr = next;
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
    
    ListNode* head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(3);
    
    cout << "Before sorting: ";
    printList(head);
    
    head = sol.insertionSortList(head);
    
    cout << "After sorting: ";
    printList(head);
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Sort List (LeetCode #148)
2. Merge Two Sorted Lists (LeetCode #21)
3. Merge k Sorted Lists (LeetCode #23)
4. Insertion Sort (Algorithm)
5. Reverse Linked List (LeetCode #206)
6. Sort Colors (LeetCode #75)
7. Reorder List (LeetCode #143)
8. Remove Duplicates from Sorted List (LeetCode #83)
9. Partition List (LeetCode #86)
10. Odd Even Linked List (LeetCode #328)
*/
