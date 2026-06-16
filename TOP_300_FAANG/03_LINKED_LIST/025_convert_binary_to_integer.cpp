/*
================================================================================
PROBLEM: Convert Binary Number in Linked List to Integer (LeetCode #1290)
DIFFICULTY: Easy
PATTERN: Linked List / Bit Manipulation
COMPANIES: Amazon, Microsoft
================================================================================

PROBLEM DESCRIPTION:
Given head which is a reference node to a singly-linked list. The value of each
node in the linked list is either 0 or 1. The linked list holds the binary
representation of a number. Return the decimal value of the number in the
linked list.

EXAMPLES:

Example 1:
Input: head = [1,0,1]
Output: 5
Explanation: (101) in base 2 = (5) in base 10

Example 2:
Input: head = [0]
Output: 0

Example 3:
Input: head = [1,0,0,1,0,0,1,1,1,0,0,0,0,0,0]
Output: 18880

PATTERN RECOGNITION:
Use this pattern when:
- Convert binary representation to decimal
- Process linked list values
- Bit shifting or accumulation
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
    int getDecimalValue(ListNode* head) {
        int result = 0;
        
        while (head) {
            result = (result << 1) | head->val;
            head = head->next;
        }
        
        return result;
    }
    
    // Alternative without bit shifting
    int getDecimalValueAlt(ListNode* head) {
        int result = 0;
        
        while (head) {
            result = result * 2 + head->val;
            head = head->next;
        }
        
        return result;
    }
};

int main() {
    Solution sol;
    
    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(0);
    head1->next->next = new ListNode(1);
    
    cout << "[1,0,1]: " << sol.getDecimalValue(head1) << endl;
    
    ListNode* head2 = new ListNode(0);
    cout << "[0]: " << sol.getDecimalValue(head2) << endl;
    
    ListNode* head3 = new ListNode(1);
    head3->next = new ListNode(0);
    head3->next->next = new ListNode(0);
    head3->next->next->next = new ListNode(1);
    head3->next->next->next->next = new ListNode(0);
    head3->next->next->next->next->next = new ListNode(0);
    head3->next->next->next->next->next->next = new ListNode(1);
    head3->next->next->next->next->next->next->next = new ListNode(1);
    
    cout << "[1,0,0,1,0,0,1,1]: " << sol.getDecimalValue(head3) << endl;
    
    return 0;
}

/*
TIME COMPLEXITY: O(n) where n is list length
SPACE COMPLEXITY: O(1)

SIMILAR PROBLEMS:
1. Add Two Numbers (LeetCode #2)
2. Add Two Numbers II (LeetCode #445)
3. Reverse Linked List (LeetCode #206)
4. Binary Number with Alternating Bits (LeetCode #693)
5. Number of 1 Bits (LeetCode #191)
6. Reverse Bits (LeetCode #190)
7. Power of Two (LeetCode #231)
8. Sum of Two Integers (LeetCode #371)
9. Convert to Base -2 (LeetCode #1017)
10. Complement of Base 10 Integer (LeetCode #1009)
*/
