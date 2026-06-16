/*
PROBLEM: Split Linked List in Parts
Difficulty: Medium
Pattern: Calculate size + Split evenly

DESCRIPTION:
Given the head of a singly linked list and an integer k, split the linked 
list into k consecutive linked list parts.

The length of each part should be as equal as possible: no two parts should 
have a size differing by more than one. Some parts may be null.

EXAMPLE:
Input: head = 1 -> 2 -> 3, k = 5
Output: [[1],[2],[3],[],[]]

Input: head = 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9 -> 10, k = 3
Output: [[1,2,3,4],[5,6,7],[8,9,10]]

TIME COMPLEXITY: O(n + k)
SPACE COMPLEXITY: O(k) for result array
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
        vector<ListNode*> result(k, NULL);
        
        // Step 1: Calculate length
        int length = 0;
        ListNode* current = head;
        while (current != NULL) {
            length++;
            current = current->next;
        }
        
        // Step 2: Calculate base size and extra nodes
        int baseSize = length / k;
        int extra = length % k;
        
        // Step 3: Split the list
        current = head;
        for (int i = 0; i < k && current != NULL; i++) {
            result[i] = current;
            
            // Calculate size of current part
            int currentSize = baseSize + (i < extra ? 1 : 0);
            
            // Move to end of current part
            for (int j = 0; j < currentSize - 1; j++) {
                current = current->next;
            }
            
            // Break the link
            ListNode* next = current->next;
            current->next = NULL;
            current = next;
        }
        
        return result;
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
    cout << "[";
    while (head != NULL) {
        cout << head->val;
        if (head->next != NULL) cout << ",";
        head = head->next;
    }
    cout << "]";
}

void printResult(vector<ListNode*>& parts) {
    cout << "[";
    for (int i = 0; i < parts.size(); i++) {
        printList(parts[i]);
        if (i < parts.size() - 1) cout << ",";
    }
    cout << "]" << endl;
}

int main() {
    Solution solution;
    
    // Test Case 1: More parts than nodes
    int arr1[] = {1, 2, 3};
    ListNode* head1 = createList(arr1, 3);
    cout << "Original: ";
    printList(head1);
    cout << "\nSplit into 5 parts:\n";
    vector<ListNode*> result1 = solution.splitListToParts(head1, 5);
    printResult(result1);
    
    cout << endl;
    
    // Test Case 2: 10 nodes, 3 parts
    int arr2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    ListNode* head2 = createList(arr2, 10);
    cout << "Original: ";
    printList(head2);
    cout << "\nSplit into 3 parts:\n";
    vector<ListNode*> result2 = solution.splitListToParts(head2, 3);
    printResult(result2);
    
    return 0;
}

/*
EXPLANATION:

Algorithm:
1. Calculate total length of list
2. Determine base size for each part: length / k
3. Calculate extra nodes: length % k
4. First 'extra' parts get one additional node
5. Split the list accordingly

MATHEMATICAL BREAKDOWN:
Length = 10, k = 3
- Base size = 10 / 3 = 3
- Extra = 10 % 3 = 1
- First 1 part gets 4 nodes (3 + 1)
- Remaining 2 parts get 3 nodes each
- Result: [4, 3, 3]

Length = 3, k = 5
- Base size = 3 / 5 = 0
- Extra = 3 % 5 = 3
- First 3 parts get 1 node (0 + 1)
- Remaining 2 parts get 0 nodes (NULL)
- Result: [1, 1, 1, 0, 0]

WHY DISTRIBUTE EXTRA THIS WAY?
- Ensures parts differ by at most 1
- Earlier parts get larger size (if needed)
- Simple and fair distribution

STEP-BY-STEP FOR [1,2,3,4,5,6,7,8,9,10], k=3:

Part 0: size = 3 + 1 = 4 → [1,2,3,4]
Part 1: size = 3 + 0 = 3 → [5,6,7]
Part 2: size = 3 + 0 = 3 → [8,9,10]

BREAKING THE LINK:
Important to set current->next = NULL to separate parts!

KEY PATTERN: Fair distribution with arithmetic
Common pattern for splitting sequences evenly!
*/
