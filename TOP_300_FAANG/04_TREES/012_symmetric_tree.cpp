/*
================================================================================
PROBLEM: Symmetric Tree (LeetCode #101)
DIFFICULTY: Easy
PATTERN: Tree DFS/BFS
COMPANIES: Amazon, Facebook, Google, Microsoft, Apple
================================================================================
*/

#include <iostream>
#include <queue>
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
    // Recursive
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return isMirror(root->left, root->right);
    }
    
    bool isMirror(TreeNode* left, TreeNode* right) {
        if (!left && !right) return true;
        if (!left || !right) return false;
        
        return (left->val == right->val) &&
               isMirror(left->left, right->right) &&
               isMirror(left->right, right->left);
    }
    
    // Iterative BFS
    bool isSymmetricBFS(TreeNode* root) {
        if (!root) return true;
        
        queue<TreeNode*> q;
        q.push(root->left);
        q.push(root->right);
        
        while (!q.empty()) {
            TreeNode* left = q.front(); q.pop();
            TreeNode* right = q.front(); q.pop();
            
            if (!left && !right) continue;
            if (!left || !right) return false;
            if (left->val != right->val) return false;
            
            q.push(left->left);
            q.push(right->right);
            q.push(left->right);
            q.push(right->left);
        }
        
        return true;
    }
};

int main() {
    Solution sol;
    
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);
    
    cout << "Symmetric: " << (sol.isSymmetric(root) ? "true" : "false") << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Same Tree (LeetCode #100)
2. Invert Binary Tree (LeetCode #226)
3. Mirror Reflection (LeetCode #858)
4. Flip Equivalent Binary Trees (LeetCode #951)
5. Check if Tree is Mirror
6. Symmetric Pairs in Array
7. Palindrome Linked List (LeetCode #234)
8. Valid Palindrome (LeetCode #125)
9. Reverse String (LeetCode #344)
10. Maximum Depth of Binary Tree (LeetCode #104)
*/
