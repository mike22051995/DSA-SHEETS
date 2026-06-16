/*
PROBLEM: Intersection of Two Linked Lists
Difficulty: Easy
Pattern: Two-pointer technique with length adjustment

DESCRIPTION:
Given the heads of two singly linked-lists headA and headB, return the node 
at which the two lists intersect. If the two linked lists have no intersection, 
return null.

EXAMPLE:
Input: 
listA = 4 -> 1 -> 8 -> 4 -> 5
listB = 5 -> 6 -> 1 -> 8 -> 4 -> 5
               (intersection at node with value 8)
Output: Node with value 8

Input: 
listA = 1 -> 2 -> 3
listB = 4 -> 5
Output: null

TIME COMPLEXITY: O(m + n) where m and n are lengths of the two lists
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == NULL || headB == NULL) return NULL;
        
        ListNode* ptrA = headA;
        ListNode* ptrB = headB;
        
        // Traverse both lists. When one pointer reaches end,
        // redirect it to the other list's head.
        // They will meet at intersection or both become NULL
        while (ptrA != ptrB) {
            ptrA = (ptrA == NULL) ? headB : ptrA->next;
            ptrB = (ptrB == NULL) ? headA : ptrB->next;
        }
        
        return ptrA;  // Either intersection node or NULL
    }
    
    // Alternative approach: Calculate lengths first
    ListNode *getIntersectionNodeAlt(ListNode *headA, ListNode *headB) {
        int lenA = getLength(headA);
        int lenB = getLength(headB);
        
        // Align the starting points
        while (lenA > lenB) {
            headA = headA->next;
            lenA--;
        }
        
        while (lenB > lenA) {
            headB = headB->next;
            lenB--;
        }
        
        // Now traverse together
        while (headA != NULL && headB != NULL) {
            if (headA == headB) return headA;
            headA = headA->next;
            headB = headB->next;
        }
        
        return NULL;
    }
    
private:
    int getLength(ListNode* head) {
        int length = 0;
        while (head != NULL) {
            length++;
            head = head->next;
        }
        return length;
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
    cout << endl;
}

int main() {
    Solution solution;
    
    // Test Case 1: Lists with intersection
    // Create intersection: 8 -> 4 -> 5
    ListNode* intersection = createList(new int[3]{8, 4, 5}, 3);
    
    // List A: 4 -> 1 -> intersection
    ListNode* headA = new ListNode(4);
    headA->next = new ListNode(1);
    headA->next->next = intersection;
    
    // List B: 5 -> 6 -> 1 -> intersection
    ListNode* headB = new ListNode(5);
    headB->next = new ListNode(6);
    headB->next->next = new ListNode(1);
    headB->next->next->next = intersection;
    
    cout << "List A: ";
    printList(headA);
    cout << "List B: ";
    printList(headB);
    
    ListNode* result = solution.getIntersectionNode(headA, headB);
    if (result != NULL) {
        cout << "Intersection at node with value: " << result->val << endl;
    } else {
        cout << "No intersection" << endl;
    }
    
    cout << endl;
    
    // Test Case 2: No intersection
    int arr1[] = {1, 2, 3};
    int arr2[] = {4, 5};
    ListNode* headC = createList(arr1, 3);
    ListNode* headD = createList(arr2, 2);
    
    cout << "List C: ";
    printList(headC);
    cout << "List D: ";
    printList(headD);
    
    result = solution.getIntersectionNode(headC, headD);
    if (result != NULL) {
        cout << "Intersection at node with value: " << result->val << endl;
    } else {
        cout << "No intersection" << endl;
    }
    
    return 0;
}

/*
EXPLANATION:
Approach 1 (Elegant):
1. Use two pointers starting at headA and headB
2. When a pointer reaches end, redirect it to the other list's head
3. Both pointers will travel the same total distance: lenA + lenB
4. They meet at intersection or both become NULL (no intersection)

WHY IT WORKS:
- If lists intersect at node X:
  * ptrA travels: lenA + (lenB - commonLength)
  * ptrB travels: lenB + (lenA - commonLength)
  * Both reach X at the same time!
- If no intersection: both become NULL after same distance

Approach 2 (Intuitive):
1. Calculate lengths of both lists
2. Align starting points by advancing longer list
3. Move both pointers together until they meet

KEY PATTERN: Two-pointer with path switching
This problem teaches an elegant way to handle different lengths!
*/
