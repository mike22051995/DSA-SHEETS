/*
================================================================================
PROBLEM: Split Linked List in Parts (LeetCode #725)
DIFFICULTY: Medium
PATTERN: Linked List
COMPANIES: Amazon, Microsoft, Google
================================================================================

PROBLEM DESCRIPTION:
Given the head of a singly linked list and an integer k, split the linked list
into k consecutive linked list parts. The length of each part should be as
equal as possible: no two parts should have a size differing by more than one.
Return an array of the k parts.

EXAMPLES:

Example 1:
Input: head = [1,2,3], k = 5
Output: [[1],[2],[3],[],[]]

Example 2:
Input: head = [1,2,3,4,5,6,7,8,9,10], k = 3
Output: [[1,2,3,4],[5,6,7],[8,9,10]]

PATTERN RECOGNITION:
Use this pattern when:
- Need to divide linked list into equal parts
- Calculate part sizes with remainder distribution
- Preserve relative order
*/

#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        // Calculate length
        int length = 0;
        ListNode* curr = head;
        while (curr) {
            length++;
            curr = curr->next;
        }
        
        // Calculate size of each part
        int partSize = length / k;
        int extra = length % k;  // First 'extra' parts get one more node
        
        vector<ListNode*> result(k, nullptr);
        curr = head;
        
        for (int i = 0; i < k && curr; i++) {
            result[i] = curr;
            int currentPartSize = partSize + (i < extra ? 1 : 0);
            
            // Move to end of current part
            for (int j = 0; j < currentPartSize - 1; j++) {
                curr = curr->next;
            }
            
            // Break the link
            ListNode* next = curr->next;
            curr->next = nullptr;
            curr = next;
        }
        
        return result;
    }
};

void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Solution sol;
    
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);
    head->next->next->next->next->next->next = new ListNode(7);
    head->next->next->next->next->next->next->next = new ListNode(8);
    head->next->next->next->next->next->next->next->next = new ListNode(9);
    head->next->next->next->next->next->next->next->next->next = new ListNode(10);
    
    auto result = sol.splitListToParts(head, 3);
    
    cout << "Split into 3 parts:" << endl;
    for (int i = 0; i < result.size(); i++) {
        cout << "Part " << i + 1 << ": ";
        printList(result[i]);
    }
    
    return 0;
}

/*
TIME COMPLEXITY: O(n + k) where n is list length
SPACE COMPLEXITY: O(k) for result array

SIMILAR PROBLEMS:
1. Rotate List (LeetCode #61)
2. Partition List (LeetCode #86)
3. Odd Even Linked List (LeetCode #328)
4. Reverse Linked List II (LeetCode #92)
5. Reverse Nodes in k-Group (LeetCode #25)
6. Remove Nth Node From End (LeetCode #19)
7. Reorder List (LeetCode #143)
8. Design Linked List (LeetCode #707)
9. Flatten Multilevel Doubly Linked List (LeetCode #430)
10. Merge In Between Linked Lists (LeetCode #1669)
*/
