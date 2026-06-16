/*
================================================================================
PROBLEM: Populating Next Right Pointers in Each Node (LeetCode #116)
DIFFICULTY: Medium
PATTERN: BFS / Tree Traversal
COMPANIES: Amazon, Microsoft, Facebook, Google
================================================================================
*/

#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;
    
    Node() : val(0), left(NULL), right(NULL), next(NULL) {}
    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    // O(1) space solution
    Node* connect(Node* root) {
        if (!root) return nullptr;
        
        Node* leftmost = root;
        
        while (leftmost->left) {
            Node* head = leftmost;
            
            while (head) {
                head->left->next = head->right;
                
                if (head->next) {
                    head->right->next = head->next->left;
                }
                
                head = head->next;
            }
            
            leftmost = leftmost->left;
        }
        
        return root;
    }
    
    // BFS approach with queue
    Node* connectBFS(Node* root) {
        if (!root) return nullptr;
        
        queue<Node*> q;
        q.push(root);
        
        while (!q.empty()) {
            int size = q.size();
            Node* prev = nullptr;
            
            for (int i = 0; i < size; i++) {
                Node* node = q.front();
                q.pop();
                
                if (prev) {
                    prev->next = node;
                }
                prev = node;
                
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        
        return root;
    }
};

int main() {
    Solution sol;
    
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    
    sol.connect(root);
    
    cout << "Connected! Root->right->next: ";
    cout << (root->right->next ? "nullptr" : "not null") << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Populating Next Right Pointers II (LeetCode #117)
2. Binary Tree Level Order Traversal (LeetCode #102)
3. Binary Tree Right Side View (LeetCode #199)
4. Binary Tree Zigzag Level Order (LeetCode #103)
5. Flatten Binary Tree to Linked List (LeetCode #114)
6. Add One Row to Tree (LeetCode #623)
7. Maximum Width of Binary Tree (LeetCode #662)
8. Find Bottom Left Tree Value (LeetCode #513)
9. Average of Levels (LeetCode #637)
10. Cousins in Binary Tree (LeetCode #993)
*/
