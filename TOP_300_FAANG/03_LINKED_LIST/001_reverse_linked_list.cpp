/*
================================================================================
PROBLEM: Reverse Linked List (LeetCode #206)
DIFFICULTY: Easy
PATTERN: Linked List / Iterative & Recursive
COMPANIES: Amazon, Microsoft, Facebook, Google, Apple, Bloomberg
================================================================================

PROBLEM DESCRIPTION:
Given the head of a singly linked list, reverse the list, and return the 
reversed list.

================================================================================
PATTERN RECOGNITION:
Use this pattern when:
1. Modifying linked list structure
2. Need to reverse connections
3. Can use iterative (3 pointers) or recursive approach
4. In-place modification required

Key Indicators:
- "Reverse" linked list or part of it
- Modify next pointers
- Can solve both iteratively and recursively
- O(1) space iterative, O(n) space recursive

================================================================================
INPUT/OUTPUT EXAMPLES:

Example 1:
Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]

Example 2:
Input: head = [1,2]
Output: [2,1]

Example 3:
Input: head = []
Output: []

================================================================================
EXPLANATION:

Iterative Approach (3 Pointers):
1. Use three pointers: prev, curr, next
2. For each node:
   - Save next node
   - Reverse current's pointer
   - Move all pointers forward
3. Return prev (new head)

Recursive Approach:
1. Base case: if head or head->next is null
2. Recursively reverse rest of list
3. Make next node point back to current
4. Set current->next to null
5. Return new head

Time: O(n), Space: O(1) iterative, O(n) recursive

================================================================================
*/

#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    // Iterative Solution - Most Common in Interviews
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        
        while (curr != nullptr) {
            ListNode* nextNode = curr->next;  // Save next
            curr->next = prev;                 // Reverse link
            prev = curr;                       // Move prev forward
            curr = nextNode;                   // Move curr forward
        }
        
        return prev;  // New head
    }
    
    // Recursive Solution
    ListNode* reverseListRecursive(ListNode* head) {
        // Base case
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        
        // Recursively reverse the rest
        ListNode* newHead = reverseListRecursive(head->next);
        
        // Reverse the link
        head->next->next = head;
        head->next = nullptr;
        
        return newHead;
    }
    
    // Alternative Recursive (Tail Recursion Style)
    ListNode* reverseListTailRecursive(ListNode* head, ListNode* prev = nullptr) {
        if (head == nullptr) {
            return prev;
        }
        
        ListNode* next = head->next;
        head->next = prev;
        
        return reverseListTailRecursive(next, head);
    }
};

// Helper functions
ListNode* createList(vector<int>& values) {
    if (values.empty()) return nullptr;
    
    ListNode* head = new ListNode(values[0]);
    ListNode* curr = head;
    
    for (int i = 1; i < values.size(); i++) {
        curr->next = new ListNode(values[i]);
        curr = curr->next;
    }
    
    return head;
}

void printList(ListNode* head) {
    cout << "[";
    while (head != nullptr) {
        cout << head->val;
        if (head->next != nullptr) cout << ",";
        head = head->next;
    }
    cout << "]" << endl;
}

void runTest(vector<int> values, string testName) {
    Solution sol;
    ListNode* head = createList(values);
    
    cout << testName << ": " << endl;
    cout << "Input:  ";
    printList(createList(values));  // Print original again
    
    ListNode* reversed = sol.reverseList(head);
    cout << "Output: ";
    printList(reversed);
    
    cout << "-------------------" << endl;
}

int main() {
    vector<int> values1 = {1, 2, 3, 4, 5};
    runTest(values1, "Test 1");
    
    vector<int> values2 = {1, 2};
    runTest(values2, "Test 2");
    
    vector<int> values3 = {};
    runTest(values3, "Test 3");
    
    return 0;
}

/*
================================================================================
SIMILAR LEETCODE PROBLEMS:
================================================================================
1. Reverse Linked List II (LeetCode #92) - Medium
   - Reverse between positions m and n

2. Reverse Nodes in k-Group (LeetCode #25) - Hard
   - Reverse every k nodes

3. Palindrome Linked List (LeetCode #234) - Easy
   - Use reverse to check palindrome

4. Swap Nodes in Pairs (LeetCode #24) - Medium
   - Swap every two adjacent nodes

5. Reorder List (LeetCode #143) - Medium
   - Reverse second half and merge

6. Remove Nth Node From End of List (LeetCode #19) - Medium
   - Two-pointer technique

7. Odd Even Linked List (LeetCode #328) - Medium
   - Reorder based on position

8. Add Two Numbers (LeetCode #2) - Medium
   - Reverse order digit addition

9. Copy List with Random Pointer (LeetCode #138) - Medium
   - Deep copy with modifications

10. Linked List Cycle II (LeetCode #142) - Medium
    - Find cycle start point

================================================================================
KEY PATTERNS & INSIGHTS:
================================================================================

1. Three Pointer Technique (Iterative):
   - prev: tracks reversed portion
   - curr: current node being processed
   - next: saves next node before reversing

2. Recursive Approach:
   - Reverse rest of list first
   - Then fix current node's connections
   - More elegant but uses call stack

3. Common Mistakes:
   - Not saving next pointer before modifying
   - Forgetting to set original head->next to null
   - Incorrect return value

4. Follow-up Questions:
   - Can you do it recursively?
   - Reverse only part of list?
   - Reverse in groups of k?
   - In-place vs creating new list?

5. Interview Tips:
   - Draw the pointer movements
   - Explain iterative first (simpler)
   - Then discuss recursive approach
   - Mention space complexity difference

================================================================================
*/
