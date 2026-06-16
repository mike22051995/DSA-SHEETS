/*
================================================================================
PROBLEM: Lowest Common Ancestor of BST (LeetCode #235)
DIFFICULTY: Medium
PATTERN: Tree Traversal with BST Property
COMPANIES: Amazon, Facebook, Microsoft, Google, Apple
================================================================================
*/

#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // Recursive
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) return nullptr;
        
        // Both nodes are in left subtree
        if (p->val < root->val && q->val < root->val) {
            return lowestCommonAncestor(root->left, p, q);
        }
        
        // Both nodes are in right subtree
        if (p->val > root->val && q->val > root->val) {
            return lowestCommonAncestor(root->right, p, q);
        }
        
        // Split point (or one of the nodes is root)
        return root;
    }
    
    // Iterative
    TreeNode* lowestCommonAncestorIterative(TreeNode* root, TreeNode* p, TreeNode* q) {
        while (root != nullptr) {
            if (p->val < root->val && q->val < root->val) {
                root = root->left;
            } else if (p->val > root->val && q->val > root->val) {
                root = root->right;
            } else {
                return root;
            }
        }
        return nullptr;
    }
};

int main() {
    Solution sol;
    
    // Create BST:      6
    //                /   \
    //               2     8
    //              / \   / \
    //             0   4 7   9
    //                / \
    //               3   5
    TreeNode* root = new TreeNode(6);
    root->left = new TreeNode(2);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);
    root->left->right->left = new TreeNode(3);
    root->left->right->right = new TreeNode(5);
    
    TreeNode* lca = sol.lowestCommonAncestor(root, root->left, root->left->right);
    cout << "LCA of 2 and 4: " << lca->val << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Lowest Common Ancestor Binary Tree (LeetCode #236)
2. Lowest Common Ancestor III (LeetCode #1650)
3. Lowest Common Ancestor IV (LeetCode #1676)
4. Lowest Common Ancestor Deepest Leaves (LeetCode #1123)
5. Distance Between BST Nodes (LeetCode #783)
6. Find Distance in Binary Tree (LeetCode #1740)
7. Kth Ancestor of Tree Node (LeetCode #1483)
8. Step-By-Step Directions Binary Tree (LeetCode #2096)
9. Validate Binary Search Tree (LeetCode #98)
10. Inorder Successor in BST (LeetCode #285)
*/
