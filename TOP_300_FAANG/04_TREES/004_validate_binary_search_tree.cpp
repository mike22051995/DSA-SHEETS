/*
================================================================================
PROBLEM: Validate Binary Search Tree (LeetCode #98)
DIFFICULTY: Medium
PATTERN: Tree DFS with Range Validation
COMPANIES: Amazon, Facebook, Microsoft, Google, Apple, Bloomberg
================================================================================

PROBLEM DESCRIPTION:
Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:
- The left subtree of a node contains only nodes with keys less than the node's key.
- The right subtree of a node contains only nodes with keys greater than the node's key.
- Both the left and right subtrees must also be binary search trees.

================================================================================
PATTERN RECOGNITION:
Use this pattern when:
1. Validate BST property
2. Need range checking for tree nodes
3. Inorder traversal gives sorted sequence
4. Recursive validation with bounds

Key Indicators:
- "Validate BST"
- Check tree properties
- Range-based validation
- Inorder should be sorted

================================================================================
INPUT/OUTPUT EXAMPLES:

Example 1:
Input: root = [2,1,3]
Output: true

Example 2:
Input: root = [5,1,4,null,null,3,6]
Output: false
Explanation: Root's right child 4 < root 5

Example 3:
Input: root = [5,4,6,null,null,3,7]
Output: false
Explanation: Right subtree has 3 < 5

================================================================================
*/

#include <iostream>
#include <climits>
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
    // Approach 1: Range Validation (Optimal)
    bool isValidBST(TreeNode* root) {
        return validate(root, LONG_MIN, LONG_MAX);
    }
    
    bool validate(TreeNode* node, long minVal, long maxVal) {
        if (!node) return true;
        
        if (node->val <= minVal || node->val >= maxVal) {
            return false;
        }
        
        return validate(node->left, minVal, node->val) &&
               validate(node->right, node->val, maxVal);
    }
    
    // Approach 2: Inorder Traversal
    bool isValidBSTInorder(TreeNode* root) {
        TreeNode* prev = nullptr;
        return inorder(root, prev);
    }
    
    bool inorder(TreeNode* node, TreeNode*& prev) {
        if (!node) return true;
        
        if (!inorder(node->left, prev)) return false;
        
        if (prev && prev->val >= node->val) return false;
        prev = node;
        
        return inorder(node->right, prev);
    }
};

int main() {
    Solution sol;
    
    // Test case 1: Valid BST
    TreeNode* root1 = new TreeNode(2);
    root1->left = new TreeNode(1);
    root1->right = new TreeNode(3);
    cout << "Tree 1 is valid BST: " << (sol.isValidBST(root1) ? "true" : "false") << endl;
    
    // Test case 2: Invalid BST
    TreeNode* root2 = new TreeNode(5);
    root2->left = new TreeNode(1);
    root2->right = new TreeNode(4);
    root2->right->left = new TreeNode(3);
    root2->right->right = new TreeNode(6);
    cout << "Tree 2 is valid BST: " << (sol.isValidBST(root2) ? "true" : "false") << endl;
    
    return 0;
}

/*
================================================================================
SIMILAR PROBLEMS:
1. Validate Binary Tree Nodes (LeetCode #1361)
2. Recover Binary Search Tree (LeetCode #99)
3. Minimum Absolute Difference in BST (LeetCode #530)
4. Find Mode in BST (LeetCode #501)
5. Kth Smallest Element in BST (LeetCode #230)
6. Convert Sorted Array to BST (LeetCode #108)
7. Balance a BST (LeetCode #1382)
8. Trim a BST (LeetCode #669)
9. Closest Binary Search Tree Value (LeetCode #270)
10. Inorder Successor in BST (LeetCode #285)
================================================================================
*/
