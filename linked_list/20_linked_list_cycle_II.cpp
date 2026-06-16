/*
PROBLEM: Linked List Cycle II (Find Start of Cycle)
Difficulty: Medium
Pattern: Floyd's Algorithm + Mathematical insight

DESCRIPTION:
Given the head of a linked list, return the node where the cycle begins. 
If there is no cycle, return null.

EXAMPLE:
Input: head = 3 -> 2 -> 0 -> -4 (tail connects to node index 1)
                    ^_________|
Output: Node at index 1 (value 2)

Input: head = 1 -> 2 -> NULL
Output: null

TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(1)
*/

#include <iostream>
#include <unordered_set>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    // Approach 1: Floyd's Algorithm (Optimal)
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL || head->next == NULL) {
            return NULL;
        }
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        // Phase 1: Detect if cycle exists
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            
            if (slow == fast) {
                // Cycle detected, find start
                break;
            }
        }
        
        // No cycle found
        if (fast == NULL || fast->next == NULL) {
            return NULL;
        }
        
        // Phase 2: Find cycle start
        slow = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        
        return slow;  // This is the cycle start
    }
    
    // Approach 2: Using Hash Set
    ListNode *detectCycleHashSet(ListNode *head) {
        unordered_set<ListNode*> visited;
        
        ListNode* current = head;
        while (current != NULL) {
            if (visited.find(current) != visited.end()) {
                return current;  // Found cycle start
            }
            visited.insert(current);
            current = current->next;
        }
        
        return NULL;  // No cycle
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

void createCycle(ListNode* head, int pos) {
    if (pos == -1) return;
    
    ListNode* tail = head;
    ListNode* cycleNode = NULL;
    int index = 0;
    
    while (tail->next != NULL) {
        if (index == pos) {
            cycleNode = tail;
        }
        tail = tail->next;
        index++;
    }
    
    if (cycleNode != NULL) {
        tail->next = cycleNode;
    }
}

int main() {
    Solution solution;
    
    // Test Case 1: Cycle at position 1
    int arr1[] = {3, 2, 0, -4};
    ListNode* head1 = createList(arr1, 4);
    createCycle(head1, 1);
    ListNode* cycleStart1 = solution.detectCycle(head1);
    if (cycleStart1 != NULL) {
        cout << "Test Case 1: Cycle starts at node with value " << cycleStart1->val << endl;
    } else {
        cout << "Test Case 1: No cycle" << endl;
    }
    
    // Test Case 2: No cycle
    int arr2[] = {1, 2, 3};
    ListNode* head2 = createList(arr2, 3);
    ListNode* cycleStart2 = solution.detectCycle(head2);
    if (cycleStart2 != NULL) {
        cout << "Test Case 2: Cycle starts at node with value " << cycleStart2->val << endl;
    } else {
        cout << "Test Case 2: No cycle" << endl;
    }
    
    // Test Case 3: Cycle at head
    int arr3[] = {1, 2};
    ListNode* head3 = createList(arr3, 2);
    createCycle(head3, 0);
    ListNode* cycleStart3 = solution.detectCycle(head3);
    if (cycleStart3 != NULL) {
        cout << "Test Case 3: Cycle starts at node with value " << cycleStart3->val << endl;
    } else {
        cout << "Test Case 3: No cycle" << endl;
    }
    
    return 0;
}

/*
EXPLANATION:

Floyd's Algorithm - Mathematical Proof:

Let's say:
- Distance from head to cycle start = a
- Distance from cycle start to meeting point = b  
- Cycle length = c

When slow and fast meet:
- Slow traveled: a + b
- Fast traveled: a + b + nc (n complete cycles)
- Fast speed = 2 × slow speed

Therefore: 2(a + b) = a + b + nc
           a + b = nc
           a = nc - b
           a = (n-1)c + (c - b)

Key insight: Distance from head to cycle start (a) equals 
distance from meeting point to cycle start (c - b) + some complete cycles.

Algorithm:
1. Move slow and fast until they meet (or fast reaches NULL)
2. If they meet, reset slow to head
3. Move both at same speed
4. They meet at cycle start!

Why? Both need to travel distance 'a' to reach cycle start.

VISUALIZATION:
Head -> [a nodes] -> Cycle Start -> [b nodes] -> Meeting Point
                     ^_____________[c-b nodes]_______________|

After reset:
slow at head, fast at meeting point
Both move same speed
After 'a' steps: both at cycle start!

KEY PATTERN: Floyd's + Mathematical insight
This is an elegant algorithm combining detection and location!
*/
