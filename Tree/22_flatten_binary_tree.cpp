/*
PROBLEM: Flatten Binary Tree to Linked List (LeetCode 114)
DIFFICULTY: Medium
PATTERN: Tree Modification - Morris Traversal Style

DESCRIPTION:
Given the root of a binary tree, flatten the tree into a "linked list":
- The "linked list" should use TreeNode where right child is next, left is null
- The "linked list" should be in preorder traversal order

EXAMPLE:
Input: root = [1,2,5,3,4,null,6]
       1
      / \
     2   5
    / \   \
   3   4   6

Output: [1,null,2,null,3,null,4,null,5,null,6]
   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6

TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(1) for iterative, O(h) for recursive
*/

#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    // Approach 1: Recursive - Reverse Postorder
    TreeNode* prev = nullptr;
    
    void flatten(TreeNode* root) {
        if (root == nullptr) return;
        
        // Process in reverse preorder (right, left, root)
        flatten(root->right);
        flatten(root->left);
        
        // Modify current node
        root->right = prev;
        root->left = nullptr;
        prev = root;
    }
    
    // Approach 2: Iterative - O(1) space (Morris-like)
    void flattenIterative(TreeNode* root) {
        TreeNode* curr = root;
        
        while (curr != nullptr) {
            if (curr->left != nullptr) {
                // Find rightmost node in left subtree
                TreeNode* rightmost = curr->left;
                while (rightmost->right != nullptr) {
                    rightmost = rightmost->right;
                }
                
                // Connect rightmost to current's right
                rightmost->right = curr->right;
                
                // Move left subtree to right
                curr->right = curr->left;
                curr->left = nullptr;
            }
            
            // Move to next node
            curr = curr->right;
        }
    }
};

void printFlattened(TreeNode* root) {
    TreeNode* curr = root;
    while (curr != nullptr) {
        cout << curr->val << " -> ";
        curr = curr->right;
    }
    cout << "null" << endl;
}

TreeNode* createSampleTree() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(6);
    return root;
}

int main() {
    Solution sol;
    
    // Test recursive approach
    TreeNode* root1 = createSampleTree();
    cout << "Flattening tree (recursive):" << endl;
    sol.flatten(root1);
    printFlattened(root1);
    
    // Test iterative approach
    TreeNode* root2 = createSampleTree();
    cout << "\nFlattening tree (iterative):" << endl;
    sol.flattenIterative(root2);
    printFlattened(root2);
    
    return 0;
}

/*
EXPLANATION:

Two Approaches:

1. Recursive (Reverse Postorder):
   - Process in reverse preorder: right, left, root
   - Use prev pointer to track previously processed node
   - Set current's right to prev, left to null
   - Update prev to current
   
   Why reverse? Because we're building from back to front!
   Preorder: 1,2,3,4,5,6
   We build: 6 -> 5 -> 4 -> 3 -> 2 -> 1

2. Iterative O(1) Space (Morris-style):
   - For each node with left child:
     * Find rightmost node in left subtree
     * Connect it to current's right child
     * Move left subtree to right
     * Set left to null
   - Move to next (right) node
   
   Example:
        1              1
       / \              \
      2   5    =>        2
     / \   \            / \
    3   4   6          3   4
                            \
                             5
                              \
                               6
   
   Then process 2, then 3, etc.

KEY INSIGHT (Iterative):
We're essentially doing preorder but:
1. Moving left subtree to right
2. Connecting old right subtree to end of moved left subtree

WHICH IS BETTER?
- Recursive: Cleaner code, O(h) space
- Iterative: O(1) space, but more complex logic

Both are O(n) time.

OUTPUT:
Flattening tree (recursive):
1 -> 2 -> 3 -> 4 -> 5 -> 6 -> null

Flattening tree (iterative):
1 -> 2 -> 3 -> 4 -> 5 -> 6 -> null
*/
