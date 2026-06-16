/*
================================================================================
PROBLEM: Palindrome Linked List (LeetCode #234)
DIFFICULTY: Easy
PATTERN: Two Pointers / Linked List
COMPANIES: Amazon, Microsoft, Facebook, Google, Apple
================================================================================
*/

#include <iostream>
#include <stack>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    // O(n) time, O(1) space
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
    
    // Using stack - O(n) time, O(n) space
    bool isPalindromeStack(ListNode* head) {
        stack<int> stk;
        ListNode* curr = head;
        
        while (curr) {
            stk.push(curr->val);
            curr = curr->next;
        }
        
        curr = head;
        while (curr) {
            if (curr->val != stk.top()) {
                return false;
            }
            stk.pop();
            curr = curr->next;
        }
        
        return true;
    }
};

int main() {
    Solution sol;
    
    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(2);
    head1->next->next->next = new ListNode(1);
    
    cout << "Is palindrome: " << (sol.isPalindrome(head1) ? "true" : "false") << endl;
    
    ListNode* head2 = new ListNode(1);
    head2->next = new ListNode(2);
    
    cout << "Is palindrome: " << (sol.isPalindrome(head2) ? "true" : "false") << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Valid Palindrome (LeetCode #125)
2. Reverse Linked List (LeetCode #206)
3. Palindrome Number (LeetCode #9)
4. Longest Palindromic Substring (LeetCode #5)
5. Valid Palindrome II (LeetCode #680)
6. Reorder List (LeetCode #143)
7. Maximum Twin Sum of Linked List (LeetCode #2130)
8. Middle of Linked List (LeetCode #876)
9. Delete Middle Node (LeetCode #2095)
10. Linked List Cycle (LeetCode #141)
*/
