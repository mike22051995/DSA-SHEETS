/*
================================================================================
PROBLEM: Recover Binary Search Tree (LeetCode #99)
DIFFICULTY: Medium
PATTERN: Inorder Traversal / Morris Traversal
COMPANIES: Amazon, Microsoft, Google
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
private:
    TreeNode* first = nullptr;
    TreeNode* second = nullptr;
    TreeNode* prev = nullptr;
    
public:
    void recoverTree(TreeNode* root) {
        inorder(root);
        
        if (first && second) {
            swap(first->val, second->val);
        }
    }
    
    void inorder(TreeNode* node) {
        if (!node) return;
        
        inorder(node->left);
        
        if (prev && prev->val > node->val) {
            if (!first) {
                first = prev;
            }
            second = node;
        }
        prev = node;
        
        inorder(node->right);
    }
    
    // Morris Traversal - O(1) space
    void recoverTreeMorris(TreeNode* root) {
        TreeNode *first = nullptr, *second = nullptr, *prev = nullptr;
        TreeNode* curr = root;
        
        while (curr) {
            if (!curr->left) {
                if (prev && prev->val > curr->val) {
                    if (!first) first = prev;
                    second = curr;
                }
                prev = curr;
                curr = curr->right;
            } else {
                TreeNode* pred = curr->left;
                
                while (pred->right && pred->right != curr) {
                    pred = pred->right;
                }
                
                if (!pred->right) {
                    pred->right = curr;
                    curr = curr->left;
                } else {
                    pred->right = nullptr;
                    
                    if (prev && prev->val > curr->val) {
                        if (!first) first = prev;
                        second = curr;
                    }
                    prev = curr;
                    curr = curr->right;
                }
            }
        }
        
        if (first && second) {
            swap(first->val, second->val);
        }
    }
};

int main() {
    Solution sol;
    
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->right->left = new TreeNode(2);
    
    cout << "Before recovery: " << root->right->left->val << endl;
    sol.recoverTree(root);
    cout << "After recovery: " << root->right->left->val << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Validate Binary Search Tree (LeetCode #98)
2. Binary Tree Inorder Traversal (LeetCode #94)
3. Find Mode in BST (LeetCode #501)
4. Two Sum IV - BST (LeetCode #653)
5. Minimum Distance Between BST Nodes (LeetCode #783)
6. Increasing Order Search Tree (LeetCode #897)
7. Range Sum of BST (LeetCode #938)
8. Balance a BST (LeetCode #1382)
9. Convert BST to Greater Tree (LeetCode #538)
10. All Elements in Two BSTs (LeetCode #1305)
*/
