/*
================================================================================
PROBLEM: Sort List (LeetCode #148)
DIFFICULTY: Medium
PATTERN: Merge Sort
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
    // Merge Sort - Top Down (Recursive)
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;
        
        // Find middle
        ListNode* slow = head;
        ListNode* fast = head->next;
        
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* mid = slow->next;
        slow->next = nullptr;
        
        // Recursively sort both halves
        ListNode* left = sortList(head);
        ListNode* right = sortList(mid);
        
        // Merge
        return merge(left, right);
    }
    
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        
        while (l1 && l2) {
            if (l1->val < l2->val) {
                curr->next = l1;
                l1 = l1->next;
            } else {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }
        
        curr->next = l1 ? l1 : l2;
        
        return dummy->next;
    }
    
    // Bottom-up approach - O(1) space
    ListNode* sortListBottomUp(ListNode* head) {
        if (!head || !head->next) return head;
        
        int length = 0;
        ListNode* curr = head;
        while (curr) {
            length++;
            curr = curr->next;
        }
        
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        for (int size = 1; size < length; size *= 2) {
            ListNode* prev = dummy;
            curr = dummy->next;
            
            while (curr) {
                ListNode* left = curr;
                ListNode* right = split(left, size);
                curr = split(right, size);
                prev = mergeToList(left, right, prev);
            }
        }
        
        return dummy->next;
    }
    
    ListNode* split(ListNode* head, int n) {
        while (--n && head) {
            head = head->next;
        }
        
        ListNode* rest = head ? head->next : nullptr;
        if (head) head->next = nullptr;
        
        return rest;
    }
    
    ListNode* mergeToList(ListNode* l1, ListNode* l2, ListNode* prev) {
        ListNode* curr = prev;
        
        while (l1 && l2) {
            if (l1->val < l2->val) {
                curr->next = l1;
                l1 = l1->next;
            } else {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }
        
        curr->next = l1 ? l1 : l2;
        
        while (curr->next) {
            curr = curr->next;
        }
        
        return curr;
    }
};

int main() {
    Solution sol;
    
    ListNode* head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(3);
    
    head = sol.sortList(head);
    
    cout << "Sorted list: ";
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Merge Two Sorted Lists (LeetCode #21)
2. Merge K Sorted Lists (LeetCode #23)
3. Sort Colors (LeetCode #75)
4. Insertion Sort List (LeetCode #147)
5. Reorder List (LeetCode #143)
6. Reverse Linked List II (LeetCode #92)
7. Partition List (LeetCode #86)
8. Odd Even Linked List (LeetCode #328)
9. Swap Nodes in Pairs (LeetCode #24)
10. Reverse Nodes in k-Group (LeetCode #25)
*/
