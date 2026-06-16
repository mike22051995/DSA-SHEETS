/*
================================================================================
PROBLEM: Lowest Common Ancestor of Binary Tree (LeetCode #236)
DIFFICULTY: Medium
PATTERN: Tree Traversal / Recursion
COMPANIES: Amazon, Microsoft, Facebook, Google, Apple, LinkedIn
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q) {
            return root;
        }
        
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        
        if (left && right) {
            return root;
        }
        
        return left ? left : right;
    }
};

int main() {
    Solution sol;
    
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);
    
    TreeNode* lca = sol.lowestCommonAncestor(root, root->left, root->right);
    
    cout << "LCA of 5 and 1: " << lca->val << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Lowest Common Ancestor of BST (LeetCode #235)
2. Path Sum II (LeetCode #113)
3. Binary Tree Paths (LeetCode #257)
4. Kth Ancestor of a Tree Node (LeetCode #1483)
5. Step-By-Step Directions (LeetCode #2096)
6. Find Distance in Binary Tree (LeetCode #1740)
7. Delete Nodes And Return Forest (LeetCode #1110)
8. All Nodes Distance K (LeetCode #863)
9. Sum Root to Leaf Numbers (LeetCode #129)
10. Verify Preorder Serialization (LeetCode #331)
*/
