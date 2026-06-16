/*
PROBLEM: Binary Tree Postorder Traversal (LeetCode 145)
DIFFICULTY: Easy
PATTERN: Tree Traversal - DFS

DESCRIPTION:
Given the root of a binary tree, return the postorder traversal of its nodes' values.
Postorder: Left -> Right -> Root

EXAMPLE:
Input: root = [1,null,2,3]
       1
        \
         2
        /
       3
Output: [3,2,1]

Input: root = [1,2,3,4,5]
       1
      / \
     2   3
    / \
   4   5
Output: [4,5,2,3,1]

TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(h)
*/

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
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
    void postorderHelper(TreeNode* root, vector<int>& result) {
        if (root == nullptr) return;
        
        postorderHelper(root->left, result);   // Left
        postorderHelper(root->right, result);  // Right
        result.push_back(root->val);           // Root
    }
    
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        postorderHelper(root, result);
        return result;
    }
    
    // Iterative Approach (using two stacks concept)
    vector<int> postorderTraversalIterative(TreeNode* root) {
        vector<int> result;
        if (root == nullptr) return result;
        
        stack<TreeNode*> stk;
        stk.push(root);
        
        while (!stk.empty()) {
            TreeNode* node = stk.top();
            stk.pop();
            
            result.push_back(node->val);
            
            // Push left first, then right
            if (node->left) stk.push(node->left);
            if (node->right) stk.push(node->right);
        }
        
        // Reverse to get postorder (we got reverse postorder)
        reverse(result.begin(), result.end());
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
    
    vector<int> result = sol.postorderTraversal(root);
    cout << "Postorder Traversal (Recursive): ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
    
    vector<int> result2 = sol.postorderTraversalIterative(root);
    cout << "Postorder Traversal (Iterative): ";
    for (int val : result2) {
        cout << val << " ";
    }
    cout << endl;
    
    return 0;
}

/*
EXPLANATION:
Postorder: Process children before parent (Left-Right-Root)

Recursive:
- Process left subtree
- Process right subtree
- Finally process root

Iterative:
- Similar to preorder but reverse the result
- Process Root-Right-Left and reverse to get Left-Right-Root

USE CASES:
- Deleting the tree (delete children before parent)
- Postfix expression evaluation
- Used in tree deletion and cleanup

OUTPUT:
Postorder Traversal (Recursive): 3 2 1
Postorder Traversal (Iterative): 3 2 1
*/
