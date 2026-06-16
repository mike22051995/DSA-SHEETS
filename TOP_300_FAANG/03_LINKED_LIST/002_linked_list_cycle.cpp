/*
================================================================================
PROBLEM: Linked List Cycle (LeetCode #141)
DIFFICULTY: Easy
PATTERN: Fast & Slow Pointers (Floyd's Cycle Detection)
COMPANIES: Amazon, Microsoft, Facebook, Google, Apple
================================================================================

PROBLEM DESCRIPTION:
Given head, the head of a linked list, determine if the linked list has a cycle.
There is a cycle in a linked list if there is some node that can be reached 
again by continuously following the next pointer.

Return true if there is a cycle, otherwise return false.

================================================================================
PATTERN RECOGNITION:
Use this pattern when:
1. Detect cycle in linked structure
2. Fast and slow pointer technique
3. O(1) space requirement
4. Two pointers moving at different speeds

Key Indicators:
- "Detect cycle"
- Linked list/graph
- Constant space required
- Floyd's algorithm applicable

================================================================================
INPUT/OUTPUT EXAMPLES:

Example 1:
Input: head = [3,2,0,-4], pos = 1
Output: true
Explanation: Cycle at node with value 2

Example 2:
Input: head = [1,2], pos = 0
Output: true

Example 3:
Input: head = [1], pos = -1
Output: false

================================================================================
*/

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head || !head->next) return false;
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            
            if (slow == fast) return true;
        }
        
        return false;
    }
};

int main() {
    Solution sol;
    
    // Create cycle
    ListNode* head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);
    head->next->next->next->next = head->next; // cycle
    
    cout << "Has cycle: " << (sol.hasCycle(head) ? "true" : "false") << endl;
    return 0;
}

/*
================================================================================
SIMILAR PROBLEMS:
1. Linked List Cycle II (LeetCode #142) - Find cycle start
2. Happy Number (LeetCode #202) - Cycle detection in numbers
3. Find the Duplicate Number (LeetCode #287) - Floyd's algorithm
4. Middle of the Linked List (LeetCode #876) - Fast/slow pointers
5. Palindrome Linked List (LeetCode #234) - Fast/slow + reverse
6. Remove Nth Node From End (LeetCode #19) - Two pointers
7. Intersection of Two Linked Lists (LeetCode #160)
8. Delete Middle Node (LeetCode #2095)
9. Reorder List (LeetCode #143)
10. Circular Array Loop (LeetCode #457)
================================================================================
*/
