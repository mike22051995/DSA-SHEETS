/*
PROBLEM: Binary Tree Inorder Traversal (LeetCode 94)
DIFFICULTY: Easy
PATTERN: Tree Traversal - DFS

DESCRIPTION:
Given the root of a binary tree, return the inorder traversal of its nodes' values.
Inorder: Left -> Root -> Right

EXAMPLE:
Input: root = [1,null,2,3]
       1
        \
         2
        /
       3
Output: [1,3,2]

Input: root = [1,2,3,4,5]
       1
      / \
     2   3
    / \
   4   5
Output: [4,2,5,1,3]

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
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    // Recursive Approach
    void inorderHelper(TreeNode* root, vector<int>& result) {
        if (root == nullptr) return;
        
        inorderHelper(root->left, result);   // Left
        result.push_back(root->val);          // Root
        inorderHelper(root->right, result);   // Right
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        inorderHelper(root, result);
        return result;
    }
    
    // Iterative Approach using stack
    vector<int> inorderTraversalIterative(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> stk;
        TreeNode* curr = root;
        
        while (curr != nullptr || !stk.empty()) {
            // Go to leftmost node
            while (curr != nullptr) {
                stk.push(curr);
                curr = curr->left;
            }
            
            // Process current node
            curr = stk.top();
            stk.pop();
            result.push_back(curr->val);
            
            // Move to right subtree
            curr = curr->right;
        } 
        
        return result;
    }
};

// Helper function to create a sample tree
TreeNode* createSampleTree() {
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    return root;
}

int main() {
    Solution sol;
    TreeNode* root = createSampleTree();
    
    // Test recursive approach
    vector<int> result = sol.inorderTraversal(root);
    cout << "Inorder Traversal (Recursive): ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
    
    // Test iterative approach
    vector<int> result2 = sol.inorderTraversalIterative(root);
    cout << "Inorder Traversal (Iterative): ";
    for (int val : result2) {
        cout << val << " ";
    }
    cout << endl;
    
    return 0;
}

/*
EXPLANATION:
1. Recursive Approach:
   - Base case: if node is null, return
   - Recursively traverse left subtree
   - Process current node (add to result)
   - Recursively traverse right subtree

2. Iterative Approach:
   - Use a stack to simulate recursion
   - Keep going left and pushing nodes to stack
   - When can't go left, pop from stack and process
   - Move to right subtree

KEY POINTS:
- Inorder traversal gives sorted order for BST
- Master this pattern as it's foundation for many tree problems
- Both recursive and iterative approaches are important to know

OUTPUT:
Inorder Traversal (Recursive): 1 3 2
Inorder Traversal (Iterative): 1 3 2
*/
