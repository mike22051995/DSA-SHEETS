/*
================================================================================
PROBLEM: Merge Two Sorted Lists (LeetCode #21)
DIFFICULTY: Easy
PATTERN: Two Pointers / Linked List Merging
COMPANIES: Amazon, Microsoft, Google, Facebook, Apple
================================================================================

PROBLEM DESCRIPTION:
You are given the heads of two sorted linked lists list1 and list2.
Merge the two lists in a one sorted list. The list should be made by splicing 
together the nodes of the first two lists.

Return the head of the merged linked list.

================================================================================
PATTERN RECOGNITION:
Use this pattern when:
1. Merge two sorted sequences
2. Maintain sorted order
3. Can be done iteratively or recursively
4. Pointer manipulation in linked lists

Key Indicators:
- "Merge" two sorted structures
- Maintain order
- Linked list manipulation
- Compare and link nodes

================================================================================
INPUT/OUTPUT EXAMPLES:

Example 1:
Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]

Example 2:
Input: list1 = [], list2 = []
Output: []

Example 3:
Input: list1 = [], list2 = [0]
Output: [0]

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
    // Iterative Approach
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy(0);
        ListNode* current = &dummy;
        
        while (list1 && list2) {
            if (list1->val <= list2->val) {
                current->next = list1;
                list1 = list1->next;
            } else {
                current->next = list2;
                list2 = list2->next;
            }
            current = current->next;
        }
        
        current->next = list1 ? list1 : list2;
        return dummy.next;
    }
    
    // Recursive Approach
    ListNode* mergeTwoListsRecursive(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        
        if (l1->val <= l2->val) {
            l1->next = mergeTwoListsRecursive(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoListsRecursive(l1, l2->next);
            return l2;
        }
    }
};

int main() {
    Solution sol;
    
    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(4);
    
    ListNode* l2 = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);
    
    ListNode* merged = sol.mergeTwoLists(l1, l2);
    
    cout << "Merged list: ";
    while (merged) {
        cout << merged->val << " ";
        merged = merged->next;
    }
    cout << endl;
    
    return 0;
}

/*
================================================================================
SIMILAR PROBLEMS:
1. Merge K Sorted Lists (LeetCode #23) - Heap or divide-conquer
2. Merge Sorted Array (LeetCode #88) - Array version
3. Sort List (LeetCode #148) - Merge sort on linked list
4. Add Two Numbers (LeetCode #2) - Similar traversal
5. Intersection of Two Linked Lists (LeetCode #160)
6. Merge In Between Linked Lists (LeetCode #1669)
7. Remove Duplicates from Sorted List (LeetCode #83)
8. Partition List (LeetCode #86)
9. Odd Even Linked List (LeetCode #328)
10. Split Linked List in Parts (LeetCode #725)
================================================================================
*/
