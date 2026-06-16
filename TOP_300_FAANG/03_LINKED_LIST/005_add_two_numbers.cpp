/*
================================================================================
PROBLEM: Add Two Numbers (LeetCode #2)
DIFFICULTY: Medium
PATTERN: Linked List Simulation
COMPANIES: Amazon, Microsoft, Facebook, Google, Apple, Bloomberg
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* current = &dummy;
        int carry = 0;
        
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int sum = carry;
            
            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }
            
            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }
            
            carry = sum / 10;
            current->next = new ListNode(sum % 10);
            current = current->next;
        }
        
        return dummy.next;
    }
};

int main() {
    Solution sol;
    
    // Create l1: 2->4->3 (342)
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);
    
    // Create l2: 5->6->4 (465)
    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);
    
    ListNode* result = sol.addTwoNumbers(l1, l2);
    
    cout << "Sum: ";
    while (result) {
        cout << result->val;
        if (result->next) cout << "->";
        result = result->next;
    }
    cout << " (807)" << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Add Two Numbers II (LeetCode #445) - Most significant first
2. Multiply Strings (LeetCode #43)
3. Add Strings (LeetCode #415)
4. Add Binary (LeetCode #67)
5. Plus One (LeetCode #66)
6. Plus One Linked List (LeetCode #369)
7. Sum of Two Integers (LeetCode #371)
8. Add to Array Form (LeetCode #989)
9. Merge Two Sorted Lists (LeetCode #21)
10. Intersection of Two Linked Lists (LeetCode #160)
*/
