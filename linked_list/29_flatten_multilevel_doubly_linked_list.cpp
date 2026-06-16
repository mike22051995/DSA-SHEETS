/*
PROBLEM: Flatten a Multilevel Doubly Linked List
Difficulty: Hard (Medium-Hard)
Pattern: DFS with stack or recursion

DESCRIPTION:
You are given a doubly linked list, which contains nodes that have a next 
pointer, a previous pointer, and an additional child pointer. This child 
pointer may point to a separate doubly linked list, also containing these 
special nodes. These child lists may have one or more children of their own, 
and so on.

Flatten the list so that all the nodes appear in a single-level, doubly 
linked list.

EXAMPLE:
Input: 
1 - 2 - 3 - 4 - 5 - 6
    |
    7 - 8 - 9 - 10
        |
        11 - 12

Output: 1 - 2 - 7 - 8 - 11 - 12 - 9 - 10 - 3 - 4 - 5 - 6

TIME COMPLEXITY: O(n) where n is total number of nodes
SPACE COMPLEXITY: O(n) for recursion stack in worst case
*/

#include <iostream>
#include <stack>
using namespace std;

class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
    
    Node(int _val) : val(_val), prev(NULL), next(NULL), child(NULL) {}
};

class Solution {
public:
    // Approach 1: Recursive (Clean and intuitive)
    Node* flatten(Node* head) {
        if (head == NULL) return NULL;
        
        Node* current = head;
        
        while (current != NULL) {
            // If no child, move to next
            if (current->child == NULL) {
                current = current->next;
                continue;
            }
            
            // Has child - need to flatten
            Node* child = current->child;
            Node* next = current->next;
            
            // Connect current to child
            current->next = child;
            child->prev = current;
            current->child = NULL;
            
            // Find tail of child list
            Node* tail = child;
            while (tail->next != NULL) {
                tail = tail->next;
            }
            
            // Connect tail to original next
            if (next != NULL) {
                tail->next = next;
                next->prev = tail;
            }
            
            // Continue from child
            current = child;
        }
        
        return head;
    }
    
    // Approach 2: Using Stack (Iterative DFS)
    Node* flattenStack(Node* head) {
        if (head == NULL) return NULL;
        
        stack<Node*> st;
        Node* current = head;
        Node* prev = NULL;
        
        while (current != NULL || !st.empty()) {
            // Set prev pointer
            if (prev != NULL) {
                prev->next = current;
                current->prev = prev;
            }
            
            // If current has child, push next to stack
            if (current->child != NULL) {
                if (current->next != NULL) {
                    st.push(current->next);
                }
                current->next = current->child;
                current->child->prev = current;
                current->child = NULL;
            }
            
            prev = current;
            current = current->next;
            
            // If reached end and stack not empty
            if (current == NULL && !st.empty()) {
                current = st.top();
                st.pop();
            }
        }
        
        return head;
    }
    
    // Approach 3: Pure Recursion
    Node* flattenRecursive(Node* head) {
        flattenHelper(head);
        return head;
    }
    
private:
    Node* flattenHelper(Node* head) {
        if (head == NULL) return NULL;
        
        Node* current = head;
        Node* tail = head;
        
        while (current != NULL) {
            Node* next = current->next;
            
            if (current->child != NULL) {
                Node* childTail = flattenHelper(current->child);
                
                // Insert child list
                current->next = current->child;
                current->child->prev = current;
                current->child = NULL;
                
                // Connect child tail to next
                if (next != NULL) {
                    childTail->next = next;
                    next->prev = childTail;
                }
                
                tail = childTail;
            } else {
                tail = current;
            }
            
            current = next;
        }
        
        return tail;
    }
};

// Utility functions
void printList(Node* head) {
    while (head != NULL) {
        cout << head->val;
        if (head->next != NULL) cout << " - ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Solution solution;
    
    // Create multilevel list:
    // 1 - 2 - 3 - 4
    //     |
    //     5 - 6
    
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);
    Node* node5 = new Node(5);
    Node* node6 = new Node(6);
    
    node1->next = node2;
    node2->prev = node1;
    node2->next = node3;
    node3->prev = node2;
    node3->next = node4;
    node4->prev = node3;
    
    node2->child = node5;
    node5->next = node6;
    node6->prev = node5;
    
    cout << "Original list (main level): ";
    printList(node1);
    cout << "Child at node 2: ";
    printList(node5);
    
    Node* flattened = solution.flatten(node1);
    cout << "\nFlattened list: ";
    printList(flattened);
    
    return 0;
}

/*
EXPLANATION:

The problem is essentially a DFS traversal on a tree-like structure.

Approach 1: Iterative with inline processing

ALGORITHM:
1. Traverse the list
2. When encountering a node with child:
   - Save the next pointer
   - Connect current to child
   - Find tail of child list
   - Connect tail to saved next
   - Remove child pointer
3. Continue traversal

VISUALIZATION:
Original:
1 - 2 - 3 - 4
    |
    5 - 6

Process node 2 (has child):
1. Save next = 3
2. Connect: 2 -> 5 -> 6
3. Find tail: 6
4. Connect: 6 -> 3

Result: 1 - 2 - 5 - 6 - 3 - 4

Approach 2: Stack-based DFS

ALGORITHM:
1. Use stack to save "next" pointers when going into child
2. Process child first (DFS)
3. When child exhausted, pop from stack
4. Continue with popped node

Like DFS on a tree, but building linked list as we traverse.

Approach 3: Pure Recursion

ALGORITHM:
1. For each node, recursively flatten child
2. Insert flattened child between current and next
3. Return tail of current segment
4. Parent uses tail to connect to its next

WHY THIS IS HARD:
- Multiple pointer types (prev, next, child)
- Need to maintain doubly linked list invariants
- DFS traversal while building flat structure
- Edge cases: NULL pointers, end of lists

KEY INSIGHTS:
- Child takes priority over next (DFS)
- Must find tail of child to connect to next
- Must clear child pointers after flattening
- Doubly linked list requires updating both directions

KEY PATTERN: DFS on linked list with multiple next pointers
Tests understanding of DFS + pointer manipulation!
*/
