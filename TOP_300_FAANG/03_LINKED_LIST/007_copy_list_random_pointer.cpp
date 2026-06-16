/*
================================================================================
PROBLEM: Copy List with Random Pointer (LeetCode #138)
DIFFICULTY: Medium
PATTERN: Hash Map / Linked List Clone
COMPANIES: Amazon, Facebook, Microsoft, Google, Apple, Bloomberg
================================================================================
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
    // Hash Map Approach
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        
        unordered_map<Node*, Node*> nodeMap;
        
        // First pass: create all nodes
        Node* curr = head;
        while (curr) {
            nodeMap[curr] = new Node(curr->val);
            curr = curr->next;
        }
        
        // Second pass: set next and random pointers
        curr = head;
        while (curr) {
            nodeMap[curr]->next = nodeMap[curr->next];
            nodeMap[curr]->random = nodeMap[curr->random];
            curr = curr->next;
        }
        
        return nodeMap[head];
    }
    
    // O(1) Space - Interleaving Nodes
    Node* copyRandomListOptimized(Node* head) {
        if (!head) return nullptr;
        
        // Step 1: Create copy nodes interleaved with original
        Node* curr = head;
        while (curr) {
            Node* copy = new Node(curr->val);
            copy->next = curr->next;
            curr->next = copy;
            curr = copy->next;
        }
        
        // Step 2: Set random pointers for copies
        curr = head;
        while (curr) {
            if (curr->random) {
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }
        
        // Step 3: Separate the two lists
        Node* dummy = new Node(0);
        Node* tail = dummy;
        curr = head;
        
        while (curr) {
            tail->next = curr->next;
            curr->next = curr->next->next;
            tail = tail->next;
            curr = curr->next;
        }
        
        return dummy->next;
    }
};

int main() {
    Solution sol;
    
    Node* head = new Node(7);
    head->next = new Node(13);
    head->next->next = new Node(11);
    head->next->next->next = new Node(10);
    head->next->next->next->next = new Node(1);
    
    head->random = nullptr;
    head->next->random = head;
    head->next->next->random = head->next->next->next->next;
    head->next->next->next->random = head->next->next;
    head->next->next->next->next->random = head;
    
    Node* copied = sol.copyRandomList(head);
    cout << "List copied successfully!" << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Clone Graph (LeetCode #133)
2. Clone N-ary Tree (LeetCode #1490)
3. Clone Binary Tree (LeetCode #1485)
4. Deep Copy of Linked List
5. Flatten a Multilevel Doubly Linked List (LeetCode #430)
6. LRU Cache (LeetCode #146)
7. Design HashMap (LeetCode #706)
8. Design LinkedHashMap
9. Serialize and Deserialize Binary Tree (LeetCode #297)
10. Construct Quad Tree (LeetCode #427)
*/
