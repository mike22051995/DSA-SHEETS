/*
PROBLEM: Copy List with Random Pointer
Difficulty: Medium
Pattern: Three-pass with interleaving nodes

DESCRIPTION:
A linked list of length n is given such that each node contains an additional 
random pointer, which could point to any node in the list, or null.

Construct a deep copy of the list.

EXAMPLE:
Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]

TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(1) if not counting output, O(n) with hash map approach
*/

#include <iostream>
#include <unordered_map>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    // Approach 1: Interleaving nodes (O(1) space)
    Node* copyRandomList(Node* head) {
        if (head == NULL) return NULL;
        
        // Step 1: Create copy nodes and interleave with original
        Node* current = head;
        while (current != NULL) {
            Node* copy = new Node(current->val);
            copy->next = current->next;
            current->next = copy;
            current = copy->next;
        }
        
        // Step 2: Set random pointers for copied nodes
        current = head;
        while (current != NULL) {
            if (current->random != NULL) {
                current->next->random = current->random->next;
            }
            current = current->next->next;
        }
        
        // Step 3: Separate the two lists
        current = head;
        Node* newHead = head->next;
        Node* copy = newHead;
        
        while (current != NULL) {
            current->next = copy->next;
            current = current->next;
            
            if (current != NULL) {
                copy->next = current->next;
                copy = copy->next;
            }
        }
        
        return newHead;
    }
    
    // Approach 2: Using Hash Map (O(n) space, more intuitive)
    Node* copyRandomListHashMap(Node* head) {
        if (head == NULL) return NULL;
        
        unordered_map<Node*, Node*> nodeMap;
        
        // First pass: create all nodes
        Node* current = head;
        while (current != NULL) {
            nodeMap[current] = new Node(current->val);
            current = current->next;
        }
        
        // Second pass: set next and random pointers
        current = head;
        while (current != NULL) {
            if (current->next != NULL) {
                nodeMap[current]->next = nodeMap[current->next];
            }
            if (current->random != NULL) {
                nodeMap[current]->random = nodeMap[current->random];
            }
            current = current->next;
        }
        
        return nodeMap[head];
    }
};

// Utility functions
void printList(Node* head) {
    Node* current = head;
    cout << "[";
    while (current != NULL) {
        cout << "[" << current->val << ",";
        if (current->random != NULL) {
            // Find index of random node
            Node* temp = head;
            int index = 0;
            while (temp != current->random) {
                temp = temp->next;
                index++;
            }
            cout << index;
        } else {
            cout << "null";
        }
        cout << "]";
        if (current->next != NULL) cout << ",";
        current = current->next;
    }
    cout << "]" << endl;
}

int main() {
    Solution solution;
    
    // Create test list: [[7,null],[13,0],[11,4],[10,2],[1,0]]
    Node* node1 = new Node(7);
    Node* node2 = new Node(13);
    Node* node3 = new Node(11);
    Node* node4 = new Node(10);
    Node* node5 = new Node(1);
    
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    
    node1->random = NULL;
    node2->random = node1;
    node3->random = node5;
    node4->random = node3;
    node5->random = node1;
    
    cout << "Original list: ";
    printList(node1);
    
    Node* copied = solution.copyRandomList(node1);
    cout << "Copied list: ";
    printList(copied);
    
    return 0;
}

/*
EXPLANATION:

Approach 1: Interleaving (Optimal - O(1) space)

STEP 1: Create interleaved list
Original: A -> B -> C
After:    A -> A' -> B -> B' -> C -> C'

STEP 2: Set random pointers
For each original node A:
  A'->random = A->random->next
Why? If A->random points to B, then A'->random should point to B'
And B' is B->next in interleaved list

STEP 3: Separate lists
Restore: A -> B -> C
Extract: A' -> B' -> C'

Approach 2: Hash Map (Intuitive)

STEP 1: Create mapping
For each node, create copy and store in map
map[original] = copy

STEP 2: Set pointers
For each original node:
  map[original]->next = map[original->next]
  map[original]->random = map[original->random]

COMPARISON:
Interleaving:
- Time: O(n)
- Space: O(1) ✓
- More complex logic

Hash Map:
- Time: O(n)
- Space: O(n)
- Clearer logic

KEY PATTERN: Deep copy with extra pointers
Important for cloning complex data structures!
Interleaving technique is clever space optimization.
*/
