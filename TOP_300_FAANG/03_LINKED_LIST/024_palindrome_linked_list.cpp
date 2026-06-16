/*
================================================================================
PROBLEM: Palindrome Linked List (LeetCode #234)
DIFFICULTY: Easy
PATTERN: Linked List / Two Pointers / Fast & Slow
COMPANIES: Amazon, Microsoft, Facebook, Google, Bloomberg
================================================================================

PROBLEM DESCRIPTION:
Given the head of a singly linked list, return true if it is a palindrome or
false otherwise.

EXAMPLES:

Example 1:
Input: head = [1,2,2,1]
Output: true

Example 2:
Input: head = [1,2]
Output: false

PATTERN RECOGNITION:
Use this pattern when:
- Check palindrome in linked list
- Find middle + reverse second half
- Fast and slow pointer technique
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
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;
        
        // Find middle
        ListNode* slow = head;
        ListNode* fast = head;
        
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // Reverse second half
        ListNode* secondHalf = reverseList(slow->next);
        
        // Compare
        ListNode* p1 = head;
        ListNode* p2 = secondHalf;
        
        while (p2) {
            if (p1->val != p2->val) {
                return false;
            }
            p1 = p1->next;
            p2 = p2->next;
        }
        
        return true;
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
    
    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(2);
    head1->next->next->next = new ListNode(1);
    
    cout << "[1,2,2,1]: " << (sol.isPalindrome(head1) ? "true" : "false") << endl;
    
    ListNode* head2 = new ListNode(1);
    head2->next = new ListNode(2);
    
    cout << "[1,2]: " << (sol.isPalindrome(head2) ? "true" : "false") << endl;
    
    return 0;
}

/*
TIME COMPLEXITY: O(n) where n is list length
SPACE COMPLEXITY: O(1)

SIMILAR PROBLEMS:
1. Reverse Linked List (LeetCode #206)
2. Reverse Linked List II (LeetCode #92)
3. Valid Palindrome (LeetCode #125)
4. Longest Palindromic Substring (LeetCode #5)
5. Palindrome Number (LeetCode #9)
6. Middle of Linked List (LeetCode #876)
7. Reorder List (LeetCode #143)
8. Linked List Cycle (LeetCode #141)
9. Remove Nth Node From End (LeetCode #19)
10. Intersection of Two Linked Lists (LeetCode #160)
*/
