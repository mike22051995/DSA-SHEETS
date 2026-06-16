/*
PROBLEM: Palindrome Linked List
Difficulty: Easy
Pattern: Slow-Fast Pointer + Reverse + Compare

DESCRIPTION:
Given the head of a singly linked list, return true if it is a palindrome.

EXAMPLE:
Input: 1 -> 2 -> 2 -> 1 -> NULL
Output: true

Input: 1 -> 2 -> NULL
Output: false

TIME COMPLEXITY: O(n) where n is the number of nodes
SPACE COMPLEXITY: O(1)
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
        if (head == NULL || head->next == NULL) return true;
        
        // Step 1: Find the middle using slow-fast pointer
        ListNode* slow = head;
        ListNode* fast = head;
        
        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // Step 2: Reverse the second half
        ListNode* secondHalf = reverseList(slow->next);
        
        // Step 3: Compare first half and reversed second half
        ListNode* firstHalf = head;
        ListNode* secondHalfCopy = secondHalf;  // Keep a copy to restore later
        bool result = true;
        
        while (secondHalf != NULL) {
            if (firstHalf->val != secondHalf->val) {
                result = false;
                break;
            }
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }
        
        // Step 4: (Optional) Restore the list
        slow->next = reverseList(secondHalfCopy);
        
        return result;
    }
    
private:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* current = head;
        
        while (current != NULL) {
            ListNode* next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        
        return prev;
    }
};

// Utility functions
ListNode* createList(int arr[], int n) {
    if (n == 0) return NULL;
    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;
    for (int i = 1; i < n; i++) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return head;
}

void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val;
        if (head->next != NULL) cout << " -> ";
        head = head->next;
    }
    cout << " -> NULL" << endl;
}

int main() {
    Solution solution;
    
    // Test Case 1: Palindrome (even length)
    int arr1[] = {1, 2, 2, 1};
    ListNode* head1 = createList(arr1, 4);
    cout << "List: ";
    printList(head1);
    cout << "Is Palindrome: " << (solution.isPalindrome(head1) ? "true" : "false") << endl;
    
    cout << endl;
    
    // Test Case 2: Not palindrome
    int arr2[] = {1, 2};
    ListNode* head2 = createList(arr2, 2);
    cout << "List: ";
    printList(head2);
    cout << "Is Palindrome: " << (solution.isPalindrome(head2) ? "true" : "false") << endl;
    
    cout << endl;
    
    // Test Case 3: Palindrome (odd length)
    int arr3[] = {1, 2, 3, 2, 1};
    ListNode* head3 = createList(arr3, 5);
    cout << "List: ";
    printList(head3);
    cout << "Is Palindrome: " << (solution.isPalindrome(head3) ? "true" : "false") << endl;
    
    return 0;
}

/*
EXPLANATION:
1. Find middle of list using slow-fast pointer technique
2. Reverse the second half of the list
3. Compare first half with reversed second half node by node
4. If all nodes match, it's a palindrome
5. (Optional) Restore the original list structure

WHY THIS WORKS:
- For palindrome: first half == reverse of second half
- Example: 1->2->2->1 => compare (1,2) with reverse of (2,1) = (1,2)
- We only need O(1) space by modifying list in-place

ALTERNATIVE APPROACH:
- Could use stack to store first half (O(n) space)
- Current approach is optimal with O(1) space

KEY PATTERN: Combination of multiple patterns
1. Slow-Fast pointer (find middle)
2. Reverse linked list
3. Two-pointer comparison
*/
