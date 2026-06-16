/*
PROBLEM: Binary Tree Preorder Traversal (LeetCode 144)
DIFFICULTY: Easy
PATTERN: Tree Traversal - DFS

DESCRIPTION:
Given the root of a binary tree, return the preorder traversal of its nodes' values.
Preorder: Root -> Left -> Right

EXAMPLE:
Input: root = [1,null,2,3]
       1
        \
         2
        /
       3
Output: [1,2,3]

Input: root = [1,2,3,4,5]
       1
      / \
     2   3
    / \
   4   5
Output: [1,2,4,5,3]

TIME COMPLEXITY: O(n) - visit each node once
SPACE COMPLEXITY: O(h) - recursion stack, h is height
*/

#include <iostream>
#include <vector>
#include <stack>
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
    // Recursive Approach
    void preorderHelper(TreeNode* root, vector<int>& result) {
        if (root == nullptr) return;
        
        result.push_back(root->val);          // Root
        preorderHelper(root->left, result);   // Left
        preorderHelper(root->right, result);  // Right
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        preorderHelper(root, result);
        return result;
    }
    
    // Iterative Approach using stack
    vector<int> preorderTraversalIterative(TreeNode* root) {
        vector<int> result;
        if (root == nullptr) return result;
        
        stack<TreeNode*> stk;
        stk.push(root);
        
        while (!stk.empty()) {
            TreeNode* node = stk.top();
            stk.pop();
            
            result.push_back(node->val);  // Process current
            
            // Push right first so left is processed first
            if (node->right) stk.push(node->right);
            if (node->left) stk.push(node->left);
        }
        
        return result;
    }
};

TreeNode* createSampleTree() {
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    return root;
}

int main() {
    Solution sol;
    TreeNode* root = createSampleTree();
    
    vector<int> result = sol.preorderTraversal(root);
    cout << "Preorder Traversal (Recursive): ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
    
    vector<int> result2 = sol.preorderTraversalIterative(root);
    cout << "Preorder Traversal (Iterative): ";
    for (int val : result2) {
        cout << val << " ";
    }
    cout << endl;
    
    return 0;
}

/*
EXPLANATION:
Preorder traversal visits nodes in Root-Left-Right order.

Recursive:
- Process current node first
- Then recursively process left subtree
- Finally recursively process right subtree

Iterative:
- Use stack, push root
- Pop node, process it
- Push right child then left child (so left is processed first)

USE CASES:
- Creating a copy of the tree
- Getting prefix expression of expression tree
- Used in tree serialization

OUTPUT:
Preorder Traversal (Recursive): 1 2 3
Preorder Traversal (Iterative): 1 2 3
*/
