/*
================================================================================
PROBLEM: Intersection of Two Linked Lists (LeetCode #160)
DIFFICULTY: Easy
PATTERN: Linked List / Two Pointers
COMPANIES: Amazon, Microsoft, Facebook, Google, Apple, Bloomberg
================================================================================

PROBLEM DESCRIPTION:
Given the heads of two singly linked-lists headA and headB, return the node at
which the two lists intersect. If the two linked lists have no intersection,
return null.

EXAMPLES:

Example 1:
Input: listA = [4,1,8,4,5], listB = [5,6,1,8,4,5], intersection at node with value 8
Output: Reference to node with value 8

Example 2:
Input: listA = [1,9,1,2,4], listB = [3,2,4], intersection at node with value 2
Output: Reference to node with value 2

Example 3:
Input: listA = [2,6,4], listB = [1,5]
Output: null

PATTERN RECOGNITION:
Use this pattern when:
- Need to find intersection of two linked lists
- Two pointers with length difference handling
- Space-efficient solution required
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
    // Two pointers approach
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return nullptr;
        
        ListNode* pA = headA;
        ListNode* pB = headB;
        
        // When one pointer reaches end, redirect to other list's head
        while (pA != pB) {
            pA = pA ? pA->next : headB;
            pB = pB ? pB->next : headA;
        }
        
        return pA;
    }
    
    // Length difference approach
    ListNode *getIntersectionNodeLen(ListNode *headA, ListNode *headB) {
        int lenA = getLength(headA);
        int lenB = getLength(headB);
        
        // Align starting points
        while (lenA > lenB) {
            headA = headA->next;
            lenA--;
        }
        
        while (lenB > lenA) {
            headB = headB->next;
            lenB--;
        }
        
        // Find intersection
        while (headA != headB) {
            headA = headA->next;
            headB = headB->next;
        }
        
        return headA;
    }
    
    int getLength(ListNode* head) {
        int len = 0;
        while (head) {
            len++;
            head = head->next;
        }
        return len;
    }
};

int main() {
    Solution sol;
    
    // Create intersection example
    ListNode* common = new ListNode(8);
    common->next = new ListNode(4);
    common->next->next = new ListNode(5);
    
    ListNode* headA = new ListNode(4);
    headA->next = new ListNode(1);
    headA->next->next = common;
    
    ListNode* headB = new ListNode(5);
    headB->next = new ListNode(6);
    headB->next->next = new ListNode(1);
    headB->next->next->next = common;
    
    ListNode* result = sol.getIntersectionNode(headA, headB);
    
    if (result) {
        cout << "Intersection at node with value: " << result->val << endl;
    } else {
        cout << "No intersection" << endl;
    }
    
    return 0;
}

/*
TIME COMPLEXITY: O(m + n) where m, n are lengths of lists
SPACE COMPLEXITY: O(1)

SIMILAR PROBLEMS:
1. Linked List Cycle (LeetCode #141)
2. Linked List Cycle II (LeetCode #142)
3. Merge Two Sorted Lists (LeetCode #21)
4. Add Two Numbers (LeetCode #2)
5. Palindrome Linked List (LeetCode #234)
6. Remove Nth Node From End (LeetCode #19)
7. Middle of Linked List (LeetCode #876)
8. Delete Node in Linked List (LeetCode #237)
9. Reverse Linked List (LeetCode #206)
10. Reorder List (LeetCode #143)
*/
